#ifndef DIALOG_H
#define DIALOG_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QMessageBox>
#include <QFileDevice>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui{ class dialog;}
QT_END_NAMESPACE

class MainWindow;

class
    dialog : public QDialog
{
    Q_OBJECT
public:
    explicit dialog(QWidget *parent = nullptr);
    ~dialog();

public:
    void InitialSetting();
    void SearchSerialPorts();

    QString camera_path;
    QString lineccd_path;
    QString command_path;

private slots:
    void connectconfig();
    void connectclose();
    void on_pushButton_camera_clicked();
    void on_pushButton_lineccd_clicked();
    void on_pushButton_command_clicked();

private:
    Ui::dialog *ui;
    MainWindow *m_mainwindow;


signals:

};

#endif // DIALOG_H
