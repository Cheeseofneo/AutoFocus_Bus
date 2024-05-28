#include "dialog_user.h"
#include "ui_dialog_user.h"
#include "lineccdview.h"
#include <QMessageBox>

extern lineccdview *ptrMainWindow;
Dialog_user::Dialog_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_user)
{
    ui->setupUi(this);
}

Dialog_user::~Dialog_user()
{
    delete ui;
}
void Dialog_user::init()
{
   ui->lineEdit_f1_0->setText(ptrMainWindow->m_coff_1.f[0]);
   ui->lineEdit_f1_1->setText(ptrMainWindow->m_coff_1.f[1]);
   ui->lineEdit_f1_2->setText(ptrMainWindow->m_coff_1.f[2]);
   ui->lineEdit_f1_3->setText(ptrMainWindow->m_coff_1.f[3]);

   ui->lineEdit_f2_0->setText(ptrMainWindow->m_coff_2.f[0]);
   ui->lineEdit_f2_1->setText(ptrMainWindow->m_coff_2.f[1]);
   ui->lineEdit_f2_2->setText(ptrMainWindow->m_coff_2.f[2]);
   ui->lineEdit_f2_3->setText(ptrMainWindow->m_coff_2.f[3]);

   ui->lineEdit_f3_0->setText(ptrMainWindow->m_coff_3.f[0]);
   ui->lineEdit_f3_1->setText(ptrMainWindow->m_coff_3.f[1]);
   ui->lineEdit_f3_2->setText(ptrMainWindow->m_coff_3.f[2]);
   ui->lineEdit_f3_3->setText(ptrMainWindow->m_coff_3.f[3]);

}

void Dialog_user::on_pushButton_w1_clicked()
{
    QString f[4];
    f[0] = ui->lineEdit_f1_0->text();
    f[1] = ui->lineEdit_f1_1->text();
    f[2] = ui->lineEdit_f1_2->text();
    f[3] = ui->lineEdit_f1_3->text();
    for(int i=0;i<4;i++)
    {
      if(f[i].length()>16)
      {
          QMessageBox::information(NULL, tr("提示"),tr("长度超过16个字符！"));
      }
      else
      {
        if(f[i].length()<16)
          {
            if(f[i].contains('.'))
              {
                for(int k=f[i].length();k<16;k++)
                  {
                    f[i].append(' ');
                  }
              }
            else
              {
                f[i].append('.');
                for(int k=f[i].length();k<16;k++)
                  {
                    f[i].append(' ');
                  }
              }
          }
          ptrMainWindow->m_coff_1.f[i] = f[i];
      }
  }
    ptrMainWindow->writeCoff_1();
}

void Dialog_user::on_pushButton_w2_clicked()
{
  QString f[4];
  f[0] = ui->lineEdit_f2_0->text();
  f[1] = ui->lineEdit_f2_1->text();
  f[2] = ui->lineEdit_f2_2->text();
  f[3] = ui->lineEdit_f2_3->text();
  for(int i=0;i<4;i++)
  {
    if(f[i].length()>16)
    {
        QMessageBox::information(NULL, tr("提示"),tr("长度超过16个字符！"));
    }
    else
    {
      if(f[i].length()<16)
        {
          if(f[i].contains('.'))
            {
              for(int k=f[i].length();k<16;k++)
                {
                  f[i].append(' ');
                }
            }
          else
            {
              f[i].append('.');
              for(int k=f[i].length();k<16;k++)
                {
                  f[i].append(' ');
                }
            }
        }
        ptrMainWindow->m_coff_2.f[i] = f[i];
    }
  }
  ptrMainWindow->writeCoff_2();
}

void Dialog_user::on_pushButton_w3_clicked()
{
  QString f[4];
  f[0] = ui->lineEdit_f3_0->text();
  f[1] = ui->lineEdit_f3_1->text();
  f[2] = ui->lineEdit_f3_2->text();
  f[3] = ui->lineEdit_f3_3->text();
  for(int i=0;i<4;i++)
  {
    if(f[i].length()>16)
    {
        QMessageBox::information(NULL, tr("提示"),tr("长度超过16个字符！"));
    }
    else
    {
      if(f[i].length()<16)
        {
          if(f[i].contains('.'))
            {
              for(int k=f[i].length();k<16;k++)
                {
                  f[i].append(' ');
                }
            }
          else
            {
              f[i].append('.');
              for(int k=f[i].length();k<16;k++)
                {
                  f[i].append(' ');
                }
            }
        }
        ptrMainWindow->m_coff_3.f[i] = f[i];
    }
  }
  ptrMainWindow->writeCoff_3();

}

void Dialog_user::on_pushButton_r1_clicked()
{
    ptrMainWindow->readCoff_1();
}

void Dialog_user::on_pushButton_r2_clicked()
{
    ptrMainWindow->readCoff_2();
}

void Dialog_user::on_pushButton_r3_clicked()
{
    ptrMainWindow->readCoff_3();
}



void Dialog_user::on_pushButton_c1_clicked()
{
    ui->lineEdit_f1_0->clear();
    ui->lineEdit_f1_1->clear();
    ui->lineEdit_f1_2->clear();
    ui->lineEdit_f1_3->clear();
}

void Dialog_user::on_pushButton_c2_clicked()
{
    ui->lineEdit_f2_0->clear();
    ui->lineEdit_f2_1->clear();
    ui->lineEdit_f2_2->clear();
    ui->lineEdit_f2_3->clear();
}

void Dialog_user::on_pushButton_c3_clicked()
{
    ui->lineEdit_f3_0->clear();
    ui->lineEdit_f3_1->clear();
    ui->lineEdit_f3_2->clear();
    ui->lineEdit_f3_3->clear();
}
