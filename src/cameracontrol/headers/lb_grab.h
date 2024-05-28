#ifndef LB_GRAB_H
#define LB_GRAB_H

#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include "MvCameraControl.h"

class LB_Grab
{
public:
    LB_Grab();
    int grabImg(unsigned int nImageNum, bool flag);

private:
    bool PrintDeviceInfo(MV_CC_DEVICE_INFO* pstMVDevInfo);
};

#endif // LB_GRAB_H
