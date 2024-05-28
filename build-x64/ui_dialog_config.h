/********************************************************************************
** Form generated from reading UI file 'dialog_config.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_CONFIG_H
#define UI_DIALOG_CONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_config
{
public:
    QScrollArea *scrollArea_detect;
    QWidget *scrollAreaWidgetContents_2;
    QWidget *widget_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QCheckBox *checkBox_HdTrigger;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_Trig_Single;
    QCheckBox *checkBox_Trig_Con;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_DAC;
    QLabel *label_9;
    QPushButton *pushButton_SetDAC;
    QLabel *label_8;
    QRadioButton *radioButton_1;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkBox_Trigger2;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBox_sync;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_Bandrate;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_Bandrate_read;
    QRadioButton *radioButton_3;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_3;
    QLineEdit *lineEdit_Offset;
    QLineEdit *lineEdit_Gain;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *pushButton_SetGain;
    QPushButton *pushButton_SetOffset;
    QPushButton *pushButton_Setting;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_getPara;
    QPushButton *pushButton_SavePara;

    void setupUi(QDialog *Dialog_config)
    {
        if (Dialog_config->objectName().isEmpty())
            Dialog_config->setObjectName(QString::fromUtf8("Dialog_config"));
        Dialog_config->resize(423, 450);
        scrollArea_detect = new QScrollArea(Dialog_config);
        scrollArea_detect->setObjectName(QString::fromUtf8("scrollArea_detect"));
        scrollArea_detect->setGeometry(QRect(0, 0, 421, 451));
        scrollArea_detect->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea_detect->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_detect->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea_detect->setWidgetResizable(false);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1165, 1320));
        widget_2 = new QWidget(scrollAreaWidgetContents_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 10, 411, 1291));
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 400, 1291));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(400, 0));
        groupBox->setMaximumSize(QSize(230, 16777215));
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        checkBox_HdTrigger = new QCheckBox(groupBox);
        checkBox_HdTrigger->setObjectName(QString::fromUtf8("checkBox_HdTrigger"));
        checkBox_HdTrigger->setChecked(false);

        verticalLayout_7->addWidget(checkBox_HdTrigger);

        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_Trig_Single = new QCheckBox(groupBox_2);
        checkBox_Trig_Single->setObjectName(QString::fromUtf8("checkBox_Trig_Single"));
        checkBox_Trig_Single->setChecked(false);

        verticalLayout->addWidget(checkBox_Trig_Single);

        checkBox_Trig_Con = new QCheckBox(groupBox_2);
        checkBox_Trig_Con->setObjectName(QString::fromUtf8("checkBox_Trig_Con"));
        checkBox_Trig_Con->setChecked(false);

        verticalLayout->addWidget(checkBox_Trig_Con);


        verticalLayout_7->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_DAC = new QLineEdit(groupBox_3);
        lineEdit_DAC->setObjectName(QString::fromUtf8("lineEdit_DAC"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_DAC->sizePolicy().hasHeightForWidth());
        lineEdit_DAC->setSizePolicy(sizePolicy1);
        lineEdit_DAC->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(lineEdit_DAC, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        pushButton_SetDAC = new QPushButton(groupBox_3);
        pushButton_SetDAC->setObjectName(QString::fromUtf8("pushButton_SetDAC"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_SetDAC->sizePolicy().hasHeightForWidth());
        pushButton_SetDAC->setSizePolicy(sizePolicy3);
        pushButton_SetDAC->setMaximumSize(QSize(50, 16777215));

        gridLayout->addWidget(pushButton_SetDAC, 1, 2, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(label_8, 0, 0, 1, 3);


        verticalLayout_7->addWidget(groupBox_3);

        radioButton_1 = new QRadioButton(groupBox);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setChecked(true);

        verticalLayout_7->addWidget(radioButton_1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_2 = new QVBoxLayout(groupBox_4);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        checkBox_Trigger2 = new QCheckBox(groupBox_4);
        checkBox_Trigger2->setObjectName(QString::fromUtf8("checkBox_Trigger2"));

        verticalLayout_2->addWidget(checkBox_Trigger2);


        verticalLayout_7->addWidget(groupBox_4);

        groupBox_8 = new QGroupBox(groupBox);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        verticalLayout_6 = new QVBoxLayout(groupBox_8);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        checkBox_sync = new QCheckBox(groupBox_8);
        checkBox_sync->setObjectName(QString::fromUtf8("checkBox_sync"));

        verticalLayout_6->addWidget(checkBox_sync);


        verticalLayout_7->addWidget(groupBox_8);

        groupBox_5 = new QGroupBox(groupBox);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        gridLayout_2 = new QGridLayout(groupBox_5);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_Bandrate = new QPushButton(groupBox_5);
        pushButton_Bandrate->setObjectName(QString::fromUtf8("pushButton_Bandrate"));
        sizePolicy3.setHeightForWidth(pushButton_Bandrate->sizePolicy().hasHeightForWidth());
        pushButton_Bandrate->setSizePolicy(sizePolicy3);
        pushButton_Bandrate->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_Bandrate, 0, 1, 2, 1);

        radioButton_2 = new QRadioButton(groupBox_5);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 1, 0, 2, 1);

        pushButton_Bandrate_read = new QPushButton(groupBox_5);
        pushButton_Bandrate_read->setObjectName(QString::fromUtf8("pushButton_Bandrate_read"));
        sizePolicy3.setHeightForWidth(pushButton_Bandrate_read->sizePolicy().hasHeightForWidth());
        pushButton_Bandrate_read->setSizePolicy(sizePolicy3);
        pushButton_Bandrate_read->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButton_Bandrate_read, 2, 1, 2, 1);

        radioButton_3 = new QRadioButton(groupBox_5);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        gridLayout_2->addWidget(radioButton_3, 3, 0, 1, 1);


        verticalLayout_7->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(groupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        gridLayout_3 = new QGridLayout(groupBox_6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        lineEdit_Offset = new QLineEdit(groupBox_6);
        lineEdit_Offset->setObjectName(QString::fromUtf8("lineEdit_Offset"));
        sizePolicy1.setHeightForWidth(lineEdit_Offset->sizePolicy().hasHeightForWidth());
        lineEdit_Offset->setSizePolicy(sizePolicy1);
        lineEdit_Offset->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_Offset, 2, 6, 1, 1);

        lineEdit_Gain = new QLineEdit(groupBox_6);
        lineEdit_Gain->setObjectName(QString::fromUtf8("lineEdit_Gain"));
        sizePolicy1.setHeightForWidth(lineEdit_Gain->sizePolicy().hasHeightForWidth());
        lineEdit_Gain->setSizePolicy(sizePolicy1);
        lineEdit_Gain->setMaximumSize(QSize(60, 16777215));

        gridLayout_3->addWidget(lineEdit_Gain, 0, 6, 1, 1);

        label_11 = new QLabel(groupBox_6);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMaximumSize(QSize(110, 16777215));

        gridLayout_3->addWidget(label_11, 0, 1, 1, 2);

        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(110, 16777215));

        gridLayout_3->addWidget(label_12, 2, 1, 1, 2);

        pushButton_SetGain = new QPushButton(groupBox_6);
        pushButton_SetGain->setObjectName(QString::fromUtf8("pushButton_SetGain"));
        sizePolicy3.setHeightForWidth(pushButton_SetGain->sizePolicy().hasHeightForWidth());
        pushButton_SetGain->setSizePolicy(sizePolicy3);
        pushButton_SetGain->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(pushButton_SetGain, 0, 8, 1, 1);

        pushButton_SetOffset = new QPushButton(groupBox_6);
        pushButton_SetOffset->setObjectName(QString::fromUtf8("pushButton_SetOffset"));
        sizePolicy3.setHeightForWidth(pushButton_SetOffset->sizePolicy().hasHeightForWidth());
        pushButton_SetOffset->setSizePolicy(sizePolicy3);
        pushButton_SetOffset->setMaximumSize(QSize(40, 16777215));

        gridLayout_3->addWidget(pushButton_SetOffset, 2, 8, 1, 1);


        verticalLayout_7->addWidget(groupBox_6);

        pushButton_Setting = new QPushButton(groupBox);
        pushButton_Setting->setObjectName(QString::fromUtf8("pushButton_Setting"));
        sizePolicy3.setHeightForWidth(pushButton_Setting->sizePolicy().hasHeightForWidth());
        pushButton_Setting->setSizePolicy(sizePolicy3);
        pushButton_Setting->setMinimumSize(QSize(0, 30));
        pushButton_Setting->setMaximumSize(QSize(210, 16777215));

        verticalLayout_7->addWidget(pushButton_Setting);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_getPara = new QPushButton(groupBox);
        pushButton_getPara->setObjectName(QString::fromUtf8("pushButton_getPara"));
        sizePolicy3.setHeightForWidth(pushButton_getPara->sizePolicy().hasHeightForWidth());
        pushButton_getPara->setSizePolicy(sizePolicy3);
        pushButton_getPara->setMinimumSize(QSize(100, 30));
        pushButton_getPara->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(pushButton_getPara);

        pushButton_SavePara = new QPushButton(groupBox);
        pushButton_SavePara->setObjectName(QString::fromUtf8("pushButton_SavePara"));
        sizePolicy3.setHeightForWidth(pushButton_SavePara->sizePolicy().hasHeightForWidth());
        pushButton_SavePara->setSizePolicy(sizePolicy3);
        pushButton_SavePara->setMinimumSize(QSize(100, 30));
        pushButton_SavePara->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_8->addWidget(pushButton_SavePara);


        verticalLayout_7->addLayout(horizontalLayout_8);

        scrollArea_detect->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(Dialog_config);

        QMetaObject::connectSlotsByName(Dialog_config);
    } // setupUi

    void retranslateUi(QDialog *Dialog_config)
    {
        Dialog_config->setWindowTitle(QCoreApplication::translate("Dialog_config", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog_config", "Control panel", nullptr));
        checkBox_HdTrigger->setText(QCoreApplication::translate("Dialog_config", "Hard trigger mode", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog_config", "Trigger mode", nullptr));
        checkBox_Trig_Single->setText(QCoreApplication::translate("Dialog_config", "Single trigger(11Pin)", nullptr));
        checkBox_Trig_Con->setText(QCoreApplication::translate("Dialog_config", "Continuous triggering(12Pin)", nullptr));
        groupBox_3->setTitle(QString());
        lineEdit_DAC->setText(QCoreApplication::translate("Dialog_config", "0.000", nullptr));
        label_9->setText(QCoreApplication::translate("Dialog_config", "V", nullptr));
        pushButton_SetDAC->setText(QCoreApplication::translate("Dialog_config", "Set", nullptr));
        label_8->setText(QCoreApplication::translate("Dialog_config", "Analog Voltage 15Pin(0-5V:1mV):", nullptr));
        radioButton_1->setText(QCoreApplication::translate("Dialog_config", "115200", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("Dialog_config", "Trigger2(14Pin) level control", nullptr));
        checkBox_Trigger2->setText(QCoreApplication::translate("Dialog_config", "H", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("Dialog_config", "Output sync signal(13Pin)", nullptr));
        checkBox_sync->setText(QCoreApplication::translate("Dialog_config", "EN", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("Dialog_config", "TTL serial port baud rate", nullptr));
        pushButton_Bandrate->setText(QCoreApplication::translate("Dialog_config", "Set", nullptr));
        radioButton_2->setText(QCoreApplication::translate("Dialog_config", "384000", nullptr));
        pushButton_Bandrate_read->setText(QCoreApplication::translate("Dialog_config", "Read", nullptr));
        radioButton_3->setText(QCoreApplication::translate("Dialog_config", "921600", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("Dialog_config", "Gain", nullptr));
        lineEdit_Offset->setText(QCoreApplication::translate("Dialog_config", "0", nullptr));
        lineEdit_Gain->setText(QCoreApplication::translate("Dialog_config", "0", nullptr));
        label_11->setText(QCoreApplication::translate("Dialog_config", "Gain(0-255):", nullptr));
        label_12->setText(QCoreApplication::translate("Dialog_config", "Offset(\302\261255)", nullptr));
        pushButton_SetGain->setText(QCoreApplication::translate("Dialog_config", "Set", nullptr));
        pushButton_SetOffset->setText(QCoreApplication::translate("Dialog_config", "Set", nullptr));
        pushButton_Setting->setText(QCoreApplication::translate("Dialog_config", "Seting coefficient", nullptr));
        pushButton_getPara->setText(QCoreApplication::translate("Dialog_config", "Get Par.", nullptr));
        pushButton_SavePara->setText(QCoreApplication::translate("Dialog_config", "Save Par.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_config: public Ui_Dialog_config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_CONFIG_H
