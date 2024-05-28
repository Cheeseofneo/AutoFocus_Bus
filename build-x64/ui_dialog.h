/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog
{
public:
    QDialogButtonBox *buttonBox;
    QFrame *line;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *comboBoxPort;
    QLabel *label_6;
    QComboBox *comboBoxBaud;
    QLabel *label_4;
    QComboBox *comboBoxData;
    QLabel *label_5;
    QComboBox *comboBoxStop;
    QLabel *label_2;
    QComboBox *comboBoxParity;
    QLabel *label_3;
    QComboBox *comboBoxHand;
    QLabel *label_8;
    QWidget *lineccdpath;
    QLineEdit *lineEdit_lineccd;
    QPushButton *pushButton_lineccd;
    QLabel *label_10;
    QLabel *label_9;
    QWidget *camerapath;
    QLineEdit *lineEdit_camera;
    QPushButton *pushButton_camera;
    QWidget *commandpath;
    QLineEdit *lineEdit_command;
    QPushButton *pushButton_command;
    QWidget *tab_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit;

    void setupUi(QDialog *dialog)
    {
        if (dialog->objectName().isEmpty())
            dialog->setObjectName(QString::fromUtf8("dialog"));
        dialog->resize(500, 600);
        buttonBox = new QDialogButtonBox(dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(139, 560, 350, 35));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(12);
        buttonBox->setFont(font);
        buttonBox->setFocusPolicy(Qt::NoFocus);
        buttonBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        line = new QFrame(dialog);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 480, 460, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(dialog);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 480, 450));
        QFont font1;
        font1.setPointSize(11);
        tabWidget->setFont(font1);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        formLayoutWidget = new QWidget(tab);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 10, 471, 406));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setHorizontalSpacing(15);
        formLayout->setVerticalSpacing(15);
        formLayout->setContentsMargins(10, 10, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        comboBoxPort = new QComboBox(formLayoutWidget);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxPort);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        comboBoxBaud = new QComboBox(formLayoutWidget);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));
        comboBoxBaud->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxBaud);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_4);

        comboBoxData = new QComboBox(formLayoutWidget);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        comboBoxData->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBoxData);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_5);

        comboBoxStop = new QComboBox(formLayoutWidget);
        comboBoxStop->setObjectName(QString::fromUtf8("comboBoxStop"));
        comboBoxStop->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxStop);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_2);

        comboBoxParity = new QComboBox(formLayoutWidget);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        comboBoxParity->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxParity);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        formLayout->setWidget(5, QFormLayout::LabelRole, label_3);

        comboBoxHand = new QComboBox(formLayoutWidget);
        comboBoxHand->setObjectName(QString::fromUtf8("comboBoxHand"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxHand->sizePolicy().hasHeightForWidth());
        comboBoxHand->setSizePolicy(sizePolicy2);
        comboBoxHand->setMaximumSize(QSize(335, 16777215));

        formLayout->setWidget(5, QFormLayout::FieldRole, comboBoxHand);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        formLayout->setWidget(6, QFormLayout::LabelRole, label_8);

        lineccdpath = new QWidget(formLayoutWidget);
        lineccdpath->setObjectName(QString::fromUtf8("lineccdpath"));
        lineccdpath->setMinimumSize(QSize(0, 27));
        lineccdpath->setMaximumSize(QSize(16777215, 27));
        lineEdit_lineccd = new QLineEdit(lineccdpath);
        lineEdit_lineccd->setObjectName(QString::fromUtf8("lineEdit_lineccd"));
        lineEdit_lineccd->setGeometry(QRect(0, 0, 335, 27));
        pushButton_lineccd = new QPushButton(lineccdpath);
        pushButton_lineccd->setObjectName(QString::fromUtf8("pushButton_lineccd"));
        pushButton_lineccd->setGeometry(QRect(304, 0, 31, 27));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineccdpath);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font1);

        formLayout->setWidget(7, QFormLayout::LabelRole, label_10);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        camerapath = new QWidget(formLayoutWidget);
        camerapath->setObjectName(QString::fromUtf8("camerapath"));
        camerapath->setMinimumSize(QSize(0, 27));
        camerapath->setMaximumSize(QSize(16777215, 27));
        lineEdit_camera = new QLineEdit(camerapath);
        lineEdit_camera->setObjectName(QString::fromUtf8("lineEdit_camera"));
        lineEdit_camera->setGeometry(QRect(0, 0, 335, 27));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineEdit_camera->sizePolicy().hasHeightForWidth());
        lineEdit_camera->setSizePolicy(sizePolicy3);
        pushButton_camera = new QPushButton(camerapath);
        pushButton_camera->setObjectName(QString::fromUtf8("pushButton_camera"));
        pushButton_camera->setGeometry(QRect(304, 0, 31, 27));

        formLayout->setWidget(7, QFormLayout::FieldRole, camerapath);

        commandpath = new QWidget(formLayoutWidget);
        commandpath->setObjectName(QString::fromUtf8("commandpath"));
        commandpath->setMinimumSize(QSize(0, 27));
        commandpath->setMaximumSize(QSize(16777215, 27));
        lineEdit_command = new QLineEdit(commandpath);
        lineEdit_command->setObjectName(QString::fromUtf8("lineEdit_command"));
        lineEdit_command->setGeometry(QRect(0, 0, 335, 27));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineEdit_command->sizePolicy().hasHeightForWidth());
        lineEdit_command->setSizePolicy(sizePolicy4);
        lineEdit_command->setMinimumSize(QSize(0, 27));
        pushButton_command = new QPushButton(commandpath);
        pushButton_command->setObjectName(QString::fromUtf8("pushButton_command"));
        pushButton_command->setGeometry(QRect(304, 0, 31, 27));

        formLayout->setWidget(8, QFormLayout::FieldRole, commandpath);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        horizontalLayoutWidget = new QWidget(dialog);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 500, 481, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(horizontalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy5);
        label_7->setMinimumSize(QSize(161, 0));
        QFont font2;
        font2.setPointSize(10);
        label_7->setFont(font2);

        horizontalLayout->addWidget(label_7);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy5.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy5);
        lineEdit->setSizeIncrement(QSize(0, 0));
        lineEdit->setBaseSize(QSize(0, 0));

        horizontalLayout->addWidget(lineEdit);


        retranslateUi(dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(dialog);
    } // setupUi

    void retranslateUi(QDialog *dialog)
    {
        dialog->setWindowTitle(QCoreApplication::translate("dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("dialog", "COM Port", nullptr));
        label_6->setText(QCoreApplication::translate("dialog", "Baudrate", nullptr));
        label_4->setText(QCoreApplication::translate("dialog", "Data Bits", nullptr));
        label_5->setText(QCoreApplication::translate("dialog", "Stop Bits", nullptr));
        label_2->setText(QCoreApplication::translate("dialog", "Parity", nullptr));
        label_3->setText(QCoreApplication::translate("dialog", "Handshake", nullptr));
        label_8->setText(QCoreApplication::translate("dialog", "LineCCD Path", nullptr));
        pushButton_lineccd->setText(QCoreApplication::translate("dialog", "...", nullptr));
        label_10->setText(QCoreApplication::translate("dialog", "Camera Path", nullptr));
        label_9->setText(QCoreApplication::translate("dialog", "Command Path", nullptr));
        pushButton_camera->setText(QCoreApplication::translate("dialog", "...", nullptr));
        pushButton_command->setText(QCoreApplication::translate("dialog", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("dialog", "RS422/485", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("dialog", "EtherCat", nullptr));
        label_7->setText(QCoreApplication::translate("dialog", "Timeout [milli seconds]", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog: public Ui_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
