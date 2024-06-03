QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += console c++11
QT += serialport
QT += serialbus
QT += printsupport

#QT += charts
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += C:/Users/Neo/Desktop/C++/C++lib/eigen-3.3.9
INCLUDEPATH += D:/opencv4.5.5/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/include

INCFILES = $$files($$PWD/src/*.h, true)
DIRS = $$dirname(INCFILES)
SORTEDDIRS =$$sorted(DIRS)
INCLUDEPATH += $$unique(SORTEDDIRS)

win32: LIBS +=  -LD:/opencv4.5.5/OpenCV-MinGW-Build-OpenCV-4.5.2-x64/x64/mingw/bin/ \
                -llibopencv_calib3d452 \
                -llibopencv_core452 \
                -llibopencv_dnn452 \
                -llibopencv_features2d452 \
                -llibopencv_flann452 \
                -llibopencv_gapi452 \
                -llibopencv_highgui452 \
                -llibopencv_imgcodecs452 \
                -llibopencv_imgproc452 \
                -llibopencv_ml452 \
                -llibopencv_objdetect452 \
                -llibopencv_photo452 \
                -llibopencv_stitching452 \
                -llibopencv_video452 \
                -llibopencv_videoio452


win32: LIBS += -L$$PWD/Libraries/win64/ -lMvCameraControl

INCLUDEPATH += $$PWD/src/cameracontrol/headers
DEPENDPATH += $$PWD/src/cameracontrol/headers


SOURCES += $$files($$PWD/src/*.cpp) \
           $$files($$PWD/src/cameracontrol/src/*.cpp) \
           $$files($$PWD/src/motorcontrol/src/*.cpp) \
           $$files($$PWD/src/func/src/*.cpp) \
           $$files($$PWD/src/lineccdview/src/*.cpp) \

FORMS += \
    ui/dialog.ui \
    ui/dialog_config.ui \
    ui/dialog_user.ui \
    ui/lineccdview.ui \
    ui/mainwindow.ui \
    ui/posmode.ui \
    ui/velocitymode.ui

HEADERS += \
    src/cameracontrol/headers/CameraParams.h \
    src/cameracontrol/headers/MvCamera.h \
    src/cameracontrol/headers/MvCameraControl.h \
    src/cameracontrol/headers/MvDeviceBase.h \
    src/cameracontrol/headers/MvErrorDefine.h \
    src/cameracontrol/headers/MvGigEDevice.h \
    src/cameracontrol/headers/MvISPErrorDefine.h \
    src/cameracontrol/headers/MvInclude.h \
    src/cameracontrol/headers/MvObsoleteInterfaces.h \
    src/cameracontrol/headers/MvSdkExport.h \
    src/cameracontrol/headers/MvUsb3VDevice.h \
    src/cameracontrol/headers/ObsoleteCamParams.h \
    src/cameracontrol/headers/PixelType.h \
    src/cameracontrol/headers/TlFactory.h \
    src/cameracontrol/headers/lb_grab.h \
    src/func/headers/Daubechies.h \
    src/func/headers/IQA.h \
    src/func/headers/LIQA.h \
    src/func/headers/dataprocess.h \
    src/func/headers/savgol.h \
    src/lineccdview/headers/dialog_config.h \
    src/lineccdview/headers/dialog_user.h \
    src/lineccdview/headers/lineccdview.h \
    src/lineccdview/headers/qcustomplot.h \
    src/mainwindow.h \
    src/motorcontrol/headers/dial.h \
    src/motorcontrol/headers/dialog.h \
    src/motorcontrol/headers/posmode.h \
    src/motorcontrol/headers/velocitymode.h

RC_ICONS = ModbusMaster.ico

RESOURCES += \
    Resources.qrc



