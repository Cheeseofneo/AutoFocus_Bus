#include "dialog_config.h"
#include "ui_dialog_config.h"
//#include "dialog_user.h"
#include "lineccdview.h"

extern lineccdview *ptrMainWindow;
extern unsigned char cmd[];
Dialog_config::Dialog_config(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_config)
{
    ui->setupUi(this);
    ui->pushButton_getPara->setToolTip(tr("Get hardware parameters"));
    ui->pushButton_SavePara->setToolTip(tr("Save hardware parameters"));
    ui->lineEdit_DAC->setText("0");
    ui->checkBox_HdTrigger->setEnabled(false);
    ui->groupBox_2->setEnabled(false);
    ui->groupBox->setEnabled(false);
     ui->groupBox_5->setEnabled(false);
}

Dialog_config::~Dialog_config()
{
    delete ui;
}

void Dialog_config::on_checkBox_HdTrigger_stateChanged(int arg1)
{
    if(ui->checkBox_HdTrigger->isChecked())
    {
        ui->groupBox_2->setEnabled(true);
        ui->checkBox_Trig_Con->setChecked(false);
        ui->checkBox_Trig_Single->setChecked(false);
    }
    else
    {
        ui->groupBox_2->setEnabled(false);
        ui->checkBox_Trig_Con->setChecked(false);
        ui->checkBox_Trig_Single->setChecked(false);
        QByteArray ba((char*)cmd, 5);
        ba[1] = 7;
        ba[2] = 0;
        ptrMainWindow->serial->writeMyCom(ba);
    }
}

void Dialog_config::on_pushButton_SetDAC_clicked()
{
    float fv = ui->lineEdit_DAC->text().toFloat()*1.0;
    quint16 iv = fv*1000;
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x0d;
    ba[2] = iv>>8;
    ba[3] = iv;
   ptrMainWindow->serial->writeMyCom(ba);
}

void Dialog_config::on_checkBox_Trigger2_stateChanged(int arg1)
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x10;
    if(ui->checkBox_Trigger2->isChecked())
    {
        ba[2] = 1;
    }
    else {
        ba[2] = 0;
    }
    ptrMainWindow->serial->writeMyCom(ba);
}

void Dialog_config::on_checkBox_Trig_Con_clicked()
{
    if(ui->checkBox_Trig_Con->isChecked())
    {
        ui->checkBox_Trig_Single->setChecked(false);
        QByteArray ba((char*)cmd, 5);
        ba[1] = 7;
        ba[2] = 1;
        ptrMainWindow->serial->writeMyCom(ba);
    }
}

void Dialog_config::on_checkBox_Trig_Single_stateChanged(int arg1)
{

}

void Dialog_config::on_checkBox_Trig_Single_clicked()
{
    if(ui->checkBox_Trig_Single->isChecked())
    {
        ui->checkBox_Trig_Con->setChecked(false);
        QByteArray ba((char*)cmd, 5);
        ba[1] = 7;
        ba[2] = 2;
        ptrMainWindow->serial->writeMyCom(ba);
    }
}

void Dialog_config::on_pushButton_Bandrate_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x13;
    if(ui->radioButton_1->isChecked())
    {
        ba[2] = 0x01;
    }
    else if(ui->radioButton_2->isChecked())
    {
        ba[2] = 0x02;
    }
    else if(ui->radioButton_3->isChecked())
    {
        ba[2] = 0x03;
    }

    ptrMainWindow->serial->writeMyCom(ba);
}

void Dialog_config::on_pushButton_SetGain_clicked()
{
    uint8_t gain = ui->lineEdit_Gain->text().toInt();

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x04;
    ba[2] = (quint8)gain;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];

    ptrMainWindow->serial->writeMyCom(ba);
}

void Dialog_config::on_pushButton_SetOffset_clicked()
{
    int offset = ui->lineEdit_Offset->text().toInt();

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x05;
    if(offset>0)
    {
        ba[2] = (quint8)offset;
        ba[3] = 1;
    }
    else
    {
        ba[2] = (quint8)(0-offset);
        ba[3] = 0;
    }
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    ptrMainWindow->serial->writeMyCom(ba);
}

void Dialog_config::on_pushButton_SavePara_clicked()
{
    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x22;
    ba[4] = ba[0]+ba[1]+ba[2]+ba[3];
    ptrMainWindow->serial->writeMyCom(ba);

    ui->pushButton_SavePara->setEnabled(false);
    Delay_MSec(1000);
    ui->pushButton_SavePara->setEnabled(true);
}

void Dialog_config::Delay_MSec(unsigned int msec)
{
    QThread::msleep(100);
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while (QTime::currentTime() < _Timer)
        QThread::usleep(1000);

}
void Dialog_config::on_pushButton_Setting_clicked()
{
    m_Dlg.init();
    if(m_Dlg.exec()==QDialog::Accepted)
    {
    }
}

void Dialog_config::on_checkBox_sync_clicked()
{

}

void Dialog_config::on_checkBox_sync_stateChanged(int arg1)
{

    QByteArray ba((char*)cmd, 5);
    ba[1] = 0x0f;
    if(ui->checkBox_sync->isChecked())
    {
        ba[2] = 1;

    }
    else {
        ba[2] = 0;
    }
    ptrMainWindow->serial->writeMyCom(ba);
}


void Dialog_config::SetRadio_1(int arg1)
{

  ui->radioButton_1->setChecked(arg1);
}

void Dialog_config::SetRadio_2(int arg1)
{

  ui->radioButton_2->setChecked(arg1);
}
void Dialog_config::SetRadio_3(int arg1)
{

  ui->radioButton_3->setChecked(arg1);
}

void Dialog_config::SetlineEdit_Gain(int index)
{
    ui->lineEdit_Gain->setText(QString::number(index));
}

void Dialog_config::SetlineEdit_Ofset(int index)
{
    ui->lineEdit_Offset->setText(QString::number(index));
}

void Dialog_config::SetcheckBox_HdTrigger(int index)
{
    ui->checkBox_HdTrigger->setEnabled(index);
}

void Dialog_config::SetgroupBox(int index)
{
    ui->groupBox->setEnabled(index);
}

void Dialog_config::SetgroupBox2(int index)
{
    ui->groupBox_2->setEnabled(index);
}

void Dialog_config::SetgroupBox5(int index)
{
    ui->groupBox_5->setEnabled(index);
}
