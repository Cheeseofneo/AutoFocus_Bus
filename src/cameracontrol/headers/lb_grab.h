#ifndef LB_GRAB_H
#define LB_GRAB_H

#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <string>
#include "MvCameraControl.h"

class LB_Grab
{
public:
    LB_Grab();
    int grabImg(unsigned int nImageNum, const char* savepath);

private:
    bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo);
};

#endif // LB_GRAB_H
