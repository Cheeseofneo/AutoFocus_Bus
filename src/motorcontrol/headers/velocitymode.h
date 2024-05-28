#ifndef VELOCITYMODE_H
#define VELOCITYMODE_H

#include <QTime>
#include <QDebug>
#include <QVector>
#include <QDialog>
#include <QLayout>
#include <QBoxLayout>
#include <QModbusDevice>

#include "dial.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"


class MainWindow;

namespace Ui {
class velocitymode;
}

class velocitymode : public QDialog
{
    Q_OBJECT

public:
    explicit velocitymode(QWidget *parent = nullptr);
    ~velocitymode();
    void Initial_Setting();
    void WriteCommand(int stationAddress,int startAddress, QVector<quint8> command);
    void ReadRequest(int startAddress,quint16 numberOfEntries=2);
    void ReadSerialData();
    QVector<quint8> crc16_modbus(unsigned char* data,int len);

private slots:
    void on_pushButtonstart_clicked();
    void on_pushButtonend_clicked();
    void checkconnect(int state);

private:
    Ui::velocitymode *ui;
    MainWindow *m_mainwindow;


};

#endif // VELOCITYMODE_H
