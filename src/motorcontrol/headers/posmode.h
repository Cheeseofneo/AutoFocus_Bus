#ifndef POSMODE_H
#define POSMODE_H

#include <QDialog>
#include <QLayout>
#include <QTimer>
#include <QVector>
#include <QMessageBox>
#include <QModbusDevice>


#include "lb_grab.h"
#include "lineccdview/headers/lineccdview.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

namespace Ui {
class posmode;
}

class MainWindow;

class DataCaptureThread : public QThread
{
    Q_OBJECT
    public:
        DataCaptureThread(QModbusClient *device, QString imagesavapath, QString lineccdsavepath, QObject *parent);
        void stop();
    protected:
        void run() override;
        
    private slots:
        void capturethread(QVector<quint16> data);
        void receiveccddata(QVector<double> data);

    private:
        int lineccdcapture(int index);
        void WriteCommand(int stationAddress,int startAddress, QVector<quint16> command);

        volatile bool stopped;
        int offset = 0;
        int step = 0;
        int stepNum = 0;
        QModbusClient *m_device;
        QSerialPort *m_Com;
        QString m_imagesavapath;
        QString m_lineccdsavepath;
        QVector<double> m_CCDData;
};

class posmode : public QDialog
{
    Q_OBJECT
public:
    explicit posmode(QWidget *parent = nullptr);
    ~posmode();
    void Initial_Setting();
    void WriteCommand(int stationAddress,int startAddress, QVector<quint16> command);
    void ReadRequest(int startAddress,quint16 numberOfEntries);
    void ReadSerialData();
    void back2zero();

signals:
    void readycapture(QVector<quint16> data);    
    void stopcapture();

private slots:
    void on_pushButtonbackzero_clicked();
    void on_pushButtonstartstep_clicked();
    void on_pushButtonendstep_clicked();
    void on_pushButtonstartp2p_clicked();
    void on_pushButtonendp2p_clicked();
    void timedelay();
    int postopulse(double pos);
private:
    Ui::posmode *ui;
    MainWindow *m_mainwindow;
    lineccdview *m_widget;
    QTimer *dataprocessTimer;
    DataCaptureThread *m_capturethread;
};

#endif // POSMODE_H
