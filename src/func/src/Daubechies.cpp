#include "Daubechies.h"
#include <math.h>
#include <iostream>

Daubechies::Daubechies(cv::Mat input_img)
{
	nWidth = input_img.cols;
	nHeight = input_img.rows;
    width = nWidth;
    height = nHeight;
    if (input_img.rows<6 || input_img.cols<6) {

        std::cout<<"The size of the image is too small"<<std::endl;
	}
    else{
        // Set the number of image rows and columns to an even number
        Mat temp_Img=input_img.clone();
        if(input_img.rows%2==1){
            height=input_img.rows-1;
            Rect roi(0, 0, width, height);
            temp_Img=temp_Img(roi);
        }
        if(input_img.cols%2==1){
            width=input_img.cols-1;
            Rect roi(0, 0, width, height);
            temp_Img=temp_Img(roi);
        }
    }

    // initialize 
	m_TempImg = new double*[height]; 
	m_LowImg = new double*[height];
	for (auto i = 0; i < height; i++)
	{
		m_TempImg[i] = new double[width];
		m_LowImg[i] = new double[width];

		memset(m_TempImg[i], 0, sizeof(double)*width);
		memset(m_LowImg[i], 0, sizeof(double)*width);
	}
    Mat Hout1(height,width,CV_16FC1,Scalar(0)); 
    Mat Hout2(height,width,CV_16FC1,Scalar(0)); 
    Mat Hout3(height,width,CV_16FC1,Scalar(0)); 
    Mat Hout4(height,width,CV_16FC1,Scalar(0)); 

	LL_Img = cv::Mat::zeros(cv::Size(height / 2, width / 2), CV_8UC1);
	LH_Img = cv::Mat::zeros(cv::Size(height / 2, width / 2), CV_8UC1);
	HH_Img = cv::Mat::zeros(cv::Size(height / 2, width / 2), CV_8UC1);
	HL_Img = cv::Mat::zeros(cv::Size(height / 2, width / 2), CV_8UC1);
    Daub6b(input_img);
}

Daubechies::~Daubechies()
{
	for (auto i = 0; i < height; i++)
	{
		delete[] m_TempImg[i];
		delete[] m_LowImg[i];
	}
	delete[] m_TempImg; 
	delete[] m_LowImg;
}

/**
    * module:
    * input: grayImg
    * output: 
*/
void Daubechies::Daub6b(cv::Mat inImage)
{
	int n, k;

	convert_mat_to_array(inImage);

    // create the d6 wavelet matrix
    C0 = 0.3326705529500;
	C1 = 0.80689150;
	C2 = 0.45987750;
	C3 = -0.135011020;
    C4 = -0.08544127;
    C5 = 0.03522629;

    Mat md6row(width,width,CV_16FC1,Scalar(0));
    for(int i=0;i<width;i=i+2){
        md6row.at<float>(i, i) = C0;
        md6row.at<float>(i, i+1) = C1;
        md6row.at<float>(i, (i+2)%width) = C2;
        md6row.at<float>(i, (i+3)%width) = C3;
        md6row.at<float>(i, (i+4)%width) = C4;
        md6row.at<float>(i, (i+5)%width) = C5;
        md6row.at<float>(i+1, i) = C5;
        md6row.at<float>(i+1, i+1) = -C4;
        md6row.at<float>(i+1, (i+2)%width) = C3;
        md6row.at<float>(i+1, (i+3)%width) = -C2;
        md6row.at<float>(i+1, (i+4)%width) = C1;
        md6row.at<float>(i+1, (i+5)%width) = -C0;
    }

    Mat md6col(height,height,CV_16FC1,Scalar(0));
    for(int i=0;i<height;i=i+2){
        md6col.at<float>(i, i) = C0;
        md6col.at<float>(i, i+1) = C1;
        md6col.at<float>(i, (i+2)%height) = C2;
        md6col.at<float>(i, (i+3)%height) = C3;
        md6col.at<float>(i, (i+4)%height) = C4;
        md6col.at<float>(i, (i+5)%height) = C5;
        md6col.at<float>(i+1, i) = C5;
        md6col.at<float>(i+1, i+1) = -C4;
        md6col.at<float>(i+1, (i+2)%height) = C3;
        md6col.at<float>(i+1, (i+3)%height) = -C2;
        md6col.at<float>(i+1, (i+4)%height) = C1;
        md6col.at<float>(i+1, (i+5)%height) = -C0;
    }
    
    Mat temp_mat_row(1,width,CV_16FC1,Scalar(0));
    for(int i=0;i<height;i++){
        multiply(md6row.row(i),temp_Img.row(i),temp_mat_row);
        // create a 1-D array ,size = height, content = sum(temp_mat_row)
        Mat temp_col=Mat::ones(height,1,CV_16FC1);
        temp_col.mul(sum(temp_mat_row));
        Hout1.col(i) = temp_col;
    }
    
    for (int m = 0; m < height; ++m) {
        for(int i=0,j=0;i<width,j<width/2;i++,j+=2)
        {
            Hout2.at<float16_t>(m, j) = Hout1.at<float16_t>(m, i);
            Hout2.at<float16_t>(m, j+width/2) = Hout1.at<float16_t>(m, i+1);
        }
    }
    // transform in cols
    for(int i=0;i<width;i++){
        multiply(md6col,Hout2.col(i),Hout3.col(i));
    }

    for (int m = 0; m < width; ++m) {
        for(int i=0,j=0;i<height,j<height/2;i++,j+=2)
        {
            Hout4.at<float16_t>(j, m) = Hout3.at<float16_t>(i, m);
            Hout4.at<float16_t>(j+height/2,m) = Hout3.at<float16_t>(i+1,m);
        }
    }
	change_int(Hout4);
}

/**
    * module: change the float to int in the result
    * input: inImage
    * output:
*/
void Daubechies::change_int(cv::Mat inImage)
{
	double max = 0;
	double min = 0;
	int x, y;
	
	BYTE tmpVal;
    // 二维数组转为一维长数组
	BYTE* inImg = (BYTE*)inImage.data;
	BYTE* ll_img = (BYTE*)LL_Img.data;
	BYTE* lh_img = (BYTE*)LH_Img.data;
	BYTE* hh_img = (BYTE*)HH_Img.data;
	BYTE* hl_img = (BYTE*)HL_Img.data;

	for (x = 0; x < height /2; x++)
		for (y = 0; y < nWidth/2; y++) {
			if (max < fabs(m_TempImg[x][y]))
				max = fabs(m_TempImg[x][y]);
		}
	for (x = 0; x < height /2; x++)
		for (y = 0; y < width/2; y++) {
			tmpVal = (BYTE)((fabs(m_TempImg[x][y]) / max) * 255.0);
			inImg[x*inImage.cols + y] = tmpVal;
			ll_img[x*LL_Img.cols + y] = tmpVal;
		}

	max = 0;

	for (x = 0; x < height /2; x++)
		for (y = width/2; y < width; y++) {
			if (max < fabs(m_TempImg[x][y]))
				max = fabs(m_TempImg[x][y]);
		}
	for (x = 0; x < height /2; x++)
		for (y = width/2; y < width; y++) {
			tmpVal = (BYTE)((fabs(m_TempImg[x][y]) / max) * 255.0);
			inImg[x*inImage.cols + y] = tmpVal;
			hl_img[x*HL_Img.cols + (y-width/2)] = tmpVal;
		}

	max = 0;

	for (x = height /2; x < height; x++)
		for (y = 0; y < width; y++) {
			if (max < fabs(m_TempImg[x][y]))
				max = fabs(m_TempImg[x][y]);
		}
	for (x = height /2; x < height; x++)
		for (y = 0; y < width / 2; y++) {
			tmpVal = (BYTE)((fabs(m_TempImg[x][y]) / max) * 255.0);
			inImg[x*inImage.cols + y] = tmpVal;
			lh_img[(x- height /2)*LH_Img.cols + y] = tmpVal;
		}
	max = 0;

	for (x = height / 2; x < height; x++)
		for (y = width / 2; y < width; y++) {
			if (max < fabs(m_TempImg[x][y]))
				max = fabs(m_TempImg[x][y]);
		}
	for (x = height /2; x < height; x++)
		for (y = width / 2; y < width; y++) {
			tmpVal = (BYTE)((fabs(m_TempImg[x][y]) / max) * 255.0);
			inImg[x*inImage.cols + y] = tmpVal;
			hh_img[(x- height /2)*HH_Img.cols + (y-width/2)] = tmpVal;
		}

	cv::resize(LL_Img, LL_Img, cv::Size(nHeight, nWidth), 0, 0, INTER_NEAREST);
	cv::resize(LH_Img, LH_Img, cv::Size(nHeight, nWidth), 0, 0, INTER_NEAREST);
	cv::resize(HH_Img, HH_Img, cv::Size(nHeight, nWidth), 0, 0, INTER_NEAREST);
	cv::resize(HL_Img, HL_Img, cv::Size(nHeight, nWidth), 0, 0, INTER_NEAREST);
}

void Daubechies::convert_mat_to_array(cv::Mat inImage)
{
	// BYTE* inImg = (BYTE*)inImage.data;
	for (auto i = 0; i < height; i++)
	{
		for (auto j = 0; j < width; j++)
		{
			m_TempImg[i][j] = inImage.at<uchar>(i, j);
		}
	}
}