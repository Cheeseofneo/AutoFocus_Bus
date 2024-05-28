#ifndef DIALOG_CONFIG_H
#define DIALOG_CONFIG_H

#include <QDialog>
#include <QtCore/QTime>
#include "dialog_user.h"
namespace Ui {
class Dialog_config;
}

class Dialog_config : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_config(QWidget *parent = 0);
    ~Dialog_config();
public:
    void SetRadio_1(int arg1);
    void SetRadio_2(int arg1);
    void SetRadio_3(int arg1);
    void SetlineEdit_Gain(int index);
    void SetlineEdit_Ofset(int index);
    void SetcheckBox_HdTrigger(int index);
    void SetgroupBox(int index);
    void SetgroupBox2(int index);
    void SetgroupBox5(int index);
private slots:


    void on_checkBox_HdTrigger_stateChanged(int arg1);

    void on_pushButton_SetDAC_clicked();

    void on_checkBox_Trigger2_stateChanged(int arg1);

    void on_checkBox_Trig_Con_clicked();

    void on_checkBox_Trig_Single_stateChanged(int arg1);

    void on_checkBox_Trig_Single_clicked();

    void on_pushButton_Bandrate_clicked();

    void on_pushButton_SetGain_clicked();

    void on_pushButton_SetOffset_clicked();

    void on_pushButton_SavePara_clicked();

    void on_pushButton_Setting_clicked();

    void on_checkBox_sync_clicked();

    void on_checkBox_sync_stateChanged(int arg1);

private:
      void Delay_MSec(unsigned int msec);
     Dialog_user m_Dlg;
    Ui::Dialog_config *ui;
};

#endif // DIALOG_CONFIG_H
