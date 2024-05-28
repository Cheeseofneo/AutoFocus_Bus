#include "lb_grab.h"


#define MAX_IMAGE_DATA_SIZE   (10*1280*2560)

LB_Grab::LB_Grab()
{

}

bool LB_Grab::PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo)
{
    if (NULL == pstMVDevInfo)
    {
        printf("%s\n" , "The Pointer of pstMVDevInfoList is NULL!");
        return false;
    }
    if (pstMVDevInfo->nTLayerType == MV_GIGE_DEVICE)
    {
        printf("%s %x\n" , "nCurrentIp:" , pstMVDevInfo->SpecialInfo.stGigEInfo.nCurrentIp);                   //当前IP
        printf("%s %s\n\n" , "chUserDefinedName:" , pstMVDevInfo->SpecialInfo.stGigEInfo.chUserDefinedName);     //用户定义名
    }
    else if (pstMVDevInfo->nTLayerType == MV_USB_DEVICE)
    {
        printf("UserDefinedName:%s\n\n", pstMVDevInfo->SpecialInfo.stUsb3VInfo.chUserDefinedName);
    }
    else
    {
        printf("Not support.\n");
    }
    return true;
}

int LB_Grab::grabImg(unsigned int nImageNum, bool flag)
{
    int nRet = MV_OK;

    void* handle = NULL;

    MV_CC_DEVICE_INFO_LIST stDeviceList;
    memset(&stDeviceList, 0, sizeof(MV_CC_DEVICE_INFO_LIST));

    // 1. 枚举设备
    nRet = MV_CC_EnumDevices(MV_GIGE_DEVICE | MV_USB_DEVICE, &stDeviceList);
    if (MV_OK != nRet)
    {
        printf("MV_CC_EnumDevices fail! nRet [%x]\n", nRet);
        return -1;
    }
    unsigned int nIndex = 0;
    if (stDeviceList.nDeviceNum > 0)
    {
        for (int i = 0; i < stDeviceList.nDeviceNum; i++)
        {
            printf("[device %d]:\n", i);
            MV_CC_DEVICE_INFO* pDeviceInfo = stDeviceList.pDeviceInfo[i];
            if (NULL == pDeviceInfo)
            {
                break;
            }
            PrintDeviceInfo(pDeviceInfo);
        }
    }
    else
    {
        printf("Find No GIGE Devices!\n");
        return -1;
    }

    scanf("%d", &nIndex);  //手动输入选择设备号 

    // 2. 选择设备并创建句柄
    nRet = MV_CC_CreateHandle(&handle, stDeviceList.pDeviceInfo[nIndex]);
    if (MV_OK != nRet)
    {
        printf("MV_CC_CreateHandle fail! nRet [%x]\n", nRet);
        return -1;
    }

    // 3.打开设备
    nRet = MV_CC_OpenDevice(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_OpenDevice fail! nRet [%x]\n", nRet);
        return -1;
    }
    MV_CC_SetPixelFormat(handle, PixelType_Gvsp_Mono8);

    // 4.开始抓图
    nRet = MV_CC_StartGrabbing(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_StartGrabbing fail! nRet [%x]\n", nRet);
        return -1;
    }

    // 5.获取图
    MV_FRAME_OUT_INFO stImageInfo = {0};
    int nLength = sizeof(MV_FRAME_OUT_INFO);
    memset(&stImageInfo, 0, sizeof(MV_FRAME_OUT_INFO));
    unsigned char * pData = (unsigned char *)malloc(sizeof(unsigned char) * MAX_IMAGE_DATA_SIZE);
    unsigned int nDataSize = MAX_IMAGE_DATA_SIZE;


    unsigned char* pImage = (unsigned char*)malloc(MAX_IMAGE_DATA_SIZE);
    while(nImageNum)
    {
        nRet = MV_CC_GetOneFrame(handle, pData, nDataSize, &stImageInfo);
        if (nRet == MV_OK)
        {
            printf("Width[%d],Height[%d],FrameNum[%d]\r\n", stImageInfo.nWidth, stImageInfo.nHeight, stImageInfo.nFrameNum);
            nImageNum--;

            //设置对应的相机参数
            MV_SAVE_IMAGE_PARAM stParam;
            stParam.enImageType = MV_Image_Bmp; //需要保存的图像类型
            stParam.enPixelType = PixelType_Gvsp_Mono8;  //相机对应的像素格式
            stParam.nBufferSize = MAX_IMAGE_DATA_SIZE;  //存储节点的大小
            stParam.nWidth      = stImageInfo.nWidth;         //相机对应的宽
            stParam.nHeight     = stImageInfo.nHeight;          //相机对应的高
            stParam.nDataLen    = stImageInfo.nFrameLen;
            stParam.pData       = pData;
            stParam.pImageBuffer = pImage;

            nRet = MV_CC_SaveImage(&stParam);
            if(MV_OK != nRet)
           {
                printf("failed in MV_CC_SaveImage,nRet[%x]\n", nRet);
            }
            char *pImageName = (char *)malloc(20);
            sprintf_s(pImageName, 20, "%03d.bmp", 1);   //stImageInfo.nFrameNum
            FILE* fp = fopen(pImageName, "wb");
            fwrite(pImage, 1, stParam.nImageLen, fp);
            fclose(fp);
            free(pImageName);
        }
        else
        {
            Sleep(2);
        }
    }
    free(pData);
    free(pImage);


    // 6.结束抓图
    nRet = MV_CC_StopGrabbing(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_StopGrabbing fail! nRet [%x]\n", nRet);
        return -1;
    }

    // 7.关闭设备
    nRet = MV_CC_CloseDevice(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_CloseDevice fail! nRet [%x]\n", nRet);
        return -1;
    }

    // 8.销毁句柄
    nRet = MV_CC_DestroyHandle(handle);
    if (MV_OK != nRet)
    {
        printf("MV_CC_DestroyHandle fail! nRet [%x]\n", nRet);
        return -1;
    }

    return 0;
}
