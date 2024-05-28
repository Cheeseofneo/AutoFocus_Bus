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
#include "dialog.h"

class dialog;
class velocitymode;
class posmode;

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

    void on_actionConfig_triggered();

    void on_actionSave_triggered();

    void on_actionenable_triggered();

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

    void ChartDisplay();

private:

    void InitialSetting();

    void SearchSerialPorts();

    void InitChart();

    //QModbusDataUnit readRequest() const;
    void ReadRequest();

    void WriteRequest(QList<quint16> values);

    void WriteCommand(int stationAddress,int startAddress, QVector<quint16> command);

    void Continuemove();

    void Toonepostion();

    void Steppermode();

public:
    Ui::MainWindow *ui;
    QModbusClient *modbusDevice = nullptr;
    lineccdview * m_widget;
    QString command_savepath;
    QString lineccddata_savepath;
    QString image_savepath;

private:
    dialog* Commtype;
    velocitymode* m_vmode;
    posmode *m_pmode;

    //QSerialPort *serialPort;
    QModbusReply *lastRequest = nullptr;

    QTimer *pollTimer;
    //QChart *mChart;
    //  QValueAxis *axisY;
    //  QValueAxis *axisX;
    // QLineSeries *lineSeries[8];
    QTimer *chartTimer;
    uint16_t values[8];
};
#endif // MAINWINDOW_H
