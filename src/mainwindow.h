#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialBus/QModbusRtuSerialMaster>
#include <QtSerialBus/QModbusClient>
#include <QtCore/QTimer>
#include <QFileDialog>

#include "lineccdview/headers/lineccdview.h"
#include "motorcontrol/headers/velocitymode.h"
#include "motorcontrol/headers/posmode.h"
#include "motorcontrol/headers/dialog.h"

class dialog;
class posmode;
class velocitymode;
class DataCaptureThread;

//QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_actionExit_triggered();

    void on_actionConnect_triggered();

    void on_actionDisconnect_triggered();

    void on_actionRefresh_triggered();

    //void on_actionConfig_triggered();

    void on_actionfocus_triggered();

    void on_actionSave_triggered();

    void on_actionmotorenable_triggered();

    void on_actiondisable_triggered();

    void on_actionvelocity_triggered();

    void on_actiondisplace_triggered();

    void on_actionchannel_config_triggered();

    void on_actioncamera_triggered();

    void on_pushButtonRead_clicked();

    void on_pushButtonWrite_clicked();

    void on_pushButtonSend_clicked();

    void on_checkBoxAuto_clicked(bool checked);

    void ReadSerialData();

    //    void ChartDisplay();
    //    void InitChart();

private:

    void InitialSetting();

    void SearchSerialPorts();

    //QModbusDataUnit readRequest() const;
    void ReadRequest();

    void WriteCommand(QList<quint16> values);

    void WriteCommand(int stationAddress,int startAddress, QVector<quint16> command);

    void Continuemove();

    void Toonepostion();

    void Steppermode();

    void ReceiveCCDdata(QVector<double> data);

public:
    Ui::MainWindow *ui;

    // 遵循原则：将线程和控件在mainwindow下统一管理
    // Widget and thread
    dialog* Commtype;
    lineccdview *m_widget;
    velocitymode* m_vmode;
    posmode *m_pmode;

    // 成员变量通过继承得到调用
    QModbusClient *modbusDevice = nullptr;
    QString command_savepath;
    QString lineccddata_savepath;
    QString image_savepath;

private:

    //QSerialPort *serialPort;
    QModbusReply *lastRequest = nullptr;
    QVector<double> m_CCDData;
    QTimer *pollTimer;
    // QChart *mChart;
    // QValueAxis *axisY;
    // QValueAxis *axisX;
    // QLineSeries *lineSeries[8];
    QTimer *chartTimer;
    uint16_t values[8];
};
#endif // MAINWINDOW_H
