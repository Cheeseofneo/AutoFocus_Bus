/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionExit;
    QAction *actionConfig;
    QAction *actionSave;
    QAction *actionRefresh;
    QAction *actionvelocity;
    QAction *actiondisplace;
    QAction *actionchannel_config;
    QAction *actioncamera;
    QAction *actionmotorenable;
    QAction *actiondisable;
    QAction *actionfocus;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *comboBoxParity;
    QComboBox *comboBoxStop;
    QComboBox *comboBoxBaud;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *comboBoxData;
    QLabel *label_3;
    QComboBox *comboBoxPort;
    QLabel *label_2;
    QGroupBox *groupBox_5;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QComboBox *comboBoxDataType;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *spinBoxStation;
    QSpinBox *spinBoxStartRead;
    QSpinBox *spinBoxNumberRead;
    QCheckBox *checkBoxAuto;
    QSpinBox *spinBoxInterval;
    QLabel *label_8;
    QPushButton *pushButtonRead;
    QSpinBox *spinBoxStartWrite;
    QLabel *label_11;
    QLabel *label_12;
    QSpinBox *spinBoxNumberWrite;
    QPushButton *pushButtonWrite;
    QLineEdit *lineEditWriteValue;
    QLabel *label_15;
    QComboBox *comboBoxFormat;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLineEdit *lineEditSend;
    QPushButton *pushButtonSend;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1560, 1026);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QString::fromUtf8("actionConnect"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/disconnect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon1);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName(QString::fromUtf8("actionConfig"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConfig->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName(QString::fromUtf8("actionRefresh"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRefresh->setIcon(icon5);
        actionvelocity = new QAction(MainWindow);
        actionvelocity->setObjectName(QString::fromUtf8("actionvelocity"));
        QIcon icon6;
        QString iconThemeName = QString::fromUtf8("applications-games");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon6 = QIcon::fromTheme(iconThemeName);
        } else {
            icon6.addFile(QString::fromUtf8(":/images/images/forward.png"), QSize(), QIcon::Normal, QIcon::Off);
            icon6.addFile(QString::fromUtf8(":/images/images/tools.png"), QSize(), QIcon::Normal, QIcon::On);
        }
        actionvelocity->setIcon(icon6);
        actiondisplace = new QAction(MainWindow);
        actiondisplace->setObjectName(QString::fromUtf8("actiondisplace"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/images/1D.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondisplace->setIcon(icon7);
        actionchannel_config = new QAction(MainWindow);
        actionchannel_config->setObjectName(QString::fromUtf8("actionchannel_config"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/images/tools.png"), QSize(), QIcon::Normal, QIcon::On);
        actionchannel_config->setIcon(icon8);
        actioncamera = new QAction(MainWindow);
        actioncamera->setObjectName(QString::fromUtf8("actioncamera"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/images/camera.png"), QSize(), QIcon::Normal, QIcon::Off);
        actioncamera->setIcon(icon9);
        actionmotorenable = new QAction(MainWindow);
        actionmotorenable->setObjectName(QString::fromUtf8("actionmotorenable"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/images/enable.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmotorenable->setIcon(icon10);
        actiondisable = new QAction(MainWindow);
        actiondisable->setObjectName(QString::fromUtf8("actiondisable"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/images/disable.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondisable->setIcon(icon11);
        actionfocus = new QAction(MainWindow);
        actionfocus->setObjectName(QString::fromUtf8("actionfocus"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/images/focus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfocus->setIcon(icon12);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 181, 220));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        groupBox->setMinimumSize(QSize(150, 0));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 50, 30));
        comboBoxParity = new QComboBox(groupBox);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));
        comboBoxParity->setGeometry(QRect(70, 140, 100, 30));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxParity->sizePolicy().hasHeightForWidth());
        comboBoxParity->setSizePolicy(sizePolicy2);
        comboBoxParity->setMinimumSize(QSize(0, 20));
        comboBoxStop = new QComboBox(groupBox);
        comboBoxStop->setObjectName(QString::fromUtf8("comboBoxStop"));
        comboBoxStop->setGeometry(QRect(70, 180, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxStop->sizePolicy().hasHeightForWidth());
        comboBoxStop->setSizePolicy(sizePolicy2);
        comboBoxBaud = new QComboBox(groupBox);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));
        comboBoxBaud->setGeometry(QRect(70, 60, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxBaud->sizePolicy().hasHeightForWidth());
        comboBoxBaud->setSizePolicy(sizePolicy2);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 50, 30));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 180, 50, 30));
        comboBoxData = new QComboBox(groupBox);
        comboBoxData->setObjectName(QString::fromUtf8("comboBoxData"));
        comboBoxData->setGeometry(QRect(70, 100, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxData->sizePolicy().hasHeightForWidth());
        comboBoxData->setSizePolicy(sizePolicy2);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 50, 30));
        comboBoxPort = new QComboBox(groupBox);
        comboBoxPort->setObjectName(QString::fromUtf8("comboBoxPort"));
        comboBoxPort->setGeometry(QRect(70, 20, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxPort->sizePolicy().hasHeightForWidth());
        comboBoxPort->setSizePolicy(sizePolicy2);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 60, 50, 30));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(200, 620, 841, 141));
        textBrowser = new QTextBrowser(groupBox_5);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 821, 121));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 240, 180, 641));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(180, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 641));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 22, 60, 30));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy3);
        label_6->setMinimumSize(QSize(60, 0));
        comboBoxDataType = new QComboBox(groupBox_2);
        comboBoxDataType->setObjectName(QString::fromUtf8("comboBoxDataType"));
        comboBoxDataType->setGeometry(QRect(70, 60, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxDataType->sizePolicy().hasHeightForWidth());
        comboBoxDataType->setSizePolicy(sizePolicy2);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 180, 60, 30));
        sizePolicy3.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy3);
        label_7->setMinimumSize(QSize(60, 0));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 140, 60, 30));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMinimumSize(QSize(60, 0));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 60, 60, 30));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setMinimumSize(QSize(60, 0));
        spinBoxStation = new QSpinBox(groupBox_2);
        spinBoxStation->setObjectName(QString::fromUtf8("spinBoxStation"));
        spinBoxStation->setGeometry(QRect(70, 20, 100, 30));
        spinBoxStation->setAlignment(Qt::AlignCenter);
        spinBoxStation->setMinimum(1);
        spinBoxStation->setMaximum(254);
        spinBoxStartRead = new QSpinBox(groupBox_2);
        spinBoxStartRead->setObjectName(QString::fromUtf8("spinBoxStartRead"));
        spinBoxStartRead->setGeometry(QRect(70, 140, 100, 30));
        spinBoxStartRead->setAlignment(Qt::AlignCenter);
        spinBoxStartRead->setMaximum(65535);
        spinBoxNumberRead = new QSpinBox(groupBox_2);
        spinBoxNumberRead->setObjectName(QString::fromUtf8("spinBoxNumberRead"));
        spinBoxNumberRead->setGeometry(QRect(70, 180, 100, 30));
        spinBoxNumberRead->setAlignment(Qt::AlignCenter);
        spinBoxNumberRead->setMinimum(1);
        spinBoxNumberRead->setMaximum(125);
        checkBoxAuto = new QCheckBox(groupBox_2);
        checkBoxAuto->setObjectName(QString::fromUtf8("checkBoxAuto"));
        checkBoxAuto->setGeometry(QRect(10, 250, 100, 30));
        spinBoxInterval = new QSpinBox(groupBox_2);
        spinBoxInterval->setObjectName(QString::fromUtf8("spinBoxInterval"));
        spinBoxInterval->setGeometry(QRect(70, 220, 100, 30));
        spinBoxInterval->setAlignment(Qt::AlignCenter);
        spinBoxInterval->setMinimum(1);
        spinBoxInterval->setMaximum(3600000);
        spinBoxInterval->setValue(1000);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 220, 60, 30));
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMinimumSize(QSize(60, 0));
        pushButtonRead = new QPushButton(groupBox_2);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setGeometry(QRect(60, 280, 100, 30));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/images/books.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonRead->setIcon(icon13);
        spinBoxStartWrite = new QSpinBox(groupBox_2);
        spinBoxStartWrite->setObjectName(QString::fromUtf8("spinBoxStartWrite"));
        spinBoxStartWrite->setGeometry(QRect(70, 320, 100, 30));
        spinBoxStartWrite->setAlignment(Qt::AlignCenter);
        spinBoxStartWrite->setMaximum(65535);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 320, 60, 30));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 360, 60, 30));
        spinBoxNumberWrite = new QSpinBox(groupBox_2);
        spinBoxNumberWrite->setObjectName(QString::fromUtf8("spinBoxNumberWrite"));
        spinBoxNumberWrite->setGeometry(QRect(70, 360, 100, 30));
        spinBoxNumberWrite->setAlignment(Qt::AlignCenter);
        spinBoxNumberWrite->setMinimum(1);
        spinBoxNumberWrite->setMaximum(125);
        pushButtonWrite = new QPushButton(groupBox_2);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setGeometry(QRect(60, 440, 100, 30));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/images/Write.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonWrite->setIcon(icon14);
        lineEditWriteValue = new QLineEdit(groupBox_2);
        lineEditWriteValue->setObjectName(QString::fromUtf8("lineEditWriteValue"));
        lineEditWriteValue->setGeometry(QRect(70, 400, 100, 30));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(10, 400, 60, 30));
        comboBoxFormat = new QComboBox(groupBox_2);
        comboBoxFormat->setObjectName(QString::fromUtf8("comboBoxFormat"));
        comboBoxFormat->setGeometry(QRect(70, 100, 100, 30));
        sizePolicy2.setHeightForWidth(comboBoxFormat->sizePolicy().hasHeightForWidth());
        comboBoxFormat->setSizePolicy(sizePolicy2);
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 100, 60, 30));
        sizePolicy3.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy3);
        label_13->setMinimumSize(QSize(60, 0));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(200, 770, 841, 111));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 30, 71, 30));
        lineEditSend = new QLineEdit(groupBox_3);
        lineEditSend->setObjectName(QString::fromUtf8("lineEditSend"));
        lineEditSend->setGeometry(QRect(90, 30, 421, 30));
        pushButtonSend = new QPushButton(groupBox_3);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));
        pushButtonSend->setGeometry(QRect(740, 30, 100, 30));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/images/images/send.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSend->setIcon(icon15);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 10, 1050, 601));
        stackedWidget->setMinimumSize(QSize(1050, 0));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1560, 21));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(actionConnect);
        menu->addAction(actionDisconnect);
        menu->addAction(actionRefresh);
        menu->addSeparator();
        menu->addAction(actionExit);
        menu_2->addAction(actionConfig);
        menu_2->addAction(actionSave);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        mainToolBar->addAction(actionRefresh);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionConfig);
        mainToolBar->addAction(actionfocus);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionmotorenable);
        mainToolBar->addAction(actiondisable);
        mainToolBar->addAction(actionvelocity);
        mainToolBar->addAction(actiondisplace);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionchannel_config);
        mainToolBar->addAction(actioncamera);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
#if QT_CONFIG(tooltip)
        actionConnect->setToolTip(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\344\273\216\347\253\231", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200", nullptr));
#if QT_CONFIG(tooltip)
        actionDisconnect->setToolTip(QCoreApplication::translate("MainWindow", "\346\226\255\345\274\200\350\277\236\346\216\245", nullptr));
#endif // QT_CONFIG(tooltip)
        actionExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        actionExit->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272\350\275\257\344\273\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionConfig->setText(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actionConfig->setToolTip(QCoreApplication::translate("MainWindow", "\351\205\215\347\275\256\345\217\202\346\225\260", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSave->setText(QCoreApplication::translate("MainWindow", "\345\255\230\346\241\243", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "\346\212\245\346\226\207\344\277\235\345\255\230", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260", nullptr));
#if QT_CONFIG(tooltip)
        actionRefresh->setToolTip(QCoreApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243\345\210\227\350\241\250", nullptr));
#endif // QT_CONFIG(tooltip)
        actionvelocity->setText(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\347\216\257", nullptr));
#if QT_CONFIG(tooltip)
        actionvelocity->setToolTip(QCoreApplication::translate("MainWindow", "\351\200\237\345\272\246\347\216\257\346\216\247\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actiondisplace->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\347\216\257", nullptr));
#if QT_CONFIG(tooltip)
        actiondisplace->setToolTip(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\347\216\257\346\216\247\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
        actionchannel_config->setText(QCoreApplication::translate("MainWindow", "LineCCD\351\205\215\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actionchannel_config->setToolTip(QCoreApplication::translate("MainWindow", "LineCCD\351\205\215\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        actioncamera->setText(QCoreApplication::translate("MainWindow", "\347\233\270\346\234\272\350\256\276\347\275\256", nullptr));
        actionmotorenable->setText(QCoreApplication::translate("MainWindow", "\345\274\200\344\275\277\350\203\275", nullptr));
        actiondisable->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\275\277\350\203\275", nullptr));
        actionfocus->setText(QCoreApplication::translate("MainWindow", "\345\257\271\347\204\246", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "\346\224\266\345\217\221\346\230\276\347\244\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\344\272\244\344\272\222\351\205\215\347\275\256", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\344\273\216\347\253\231\345\234\260\345\235\200\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\346\225\260\351\207\217\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        checkBoxAuto->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\350\257\273\345\217\226", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\351\227\264\351\232\224\345\221\250\346\234\237\357\274\232", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("MainWindow", "  \350\257\273\345\217\226", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\350\265\267\345\247\213\345\234\260\345\235\200\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\346\225\260\351\207\217\357\274\232", nullptr));
        pushButtonWrite->setText(QCoreApplication::translate("MainWindow", "  \345\206\231\345\205\245", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "\345\206\231\345\205\245\346\225\260\345\200\274\357\274\232", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\346\212\245\346\226\207\346\240\274\345\274\217\357\274\232", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\223\215\344\275\234\345\214\272\345\237\237", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\221\275\344\273\244\357\274\232", nullptr));
        pushButtonSend->setText(QCoreApplication::translate("MainWindow", "  \345\217\221\351\200\201", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        mainToolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
