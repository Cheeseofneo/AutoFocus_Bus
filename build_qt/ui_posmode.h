/********************************************************************************
** Form generated from reading UI file 'posmode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSMODE_H
#define UI_POSMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_posmode
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxstep;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonstartstep;
    QPushButton *pushButtonendstep;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonbackzero;
    QSpacerItem *horizontalSpacer_2;
    QProgressBar *progressBar;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelbarstart;
    QSpacerItem *horizontalSpacer_5;
    QLabel *labelbarend;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *lineEditcurpos;
    QLineEdit *lineEditstep;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEditstart;
    QLabel *label_2;
    QLineEdit *lineEditend;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBoxstart;
    QCheckBox *checkBoxtimedelay;
    QSpinBox *spinBoxtimedelay;
    QFrame *line;
    QCheckBox *checkBoxcapture;
    QGroupBox *groupBoxonepos;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelpos;
    QTextBrowser *textBrowserpos;
    QLabel *labeldir;
    QComboBox *comboBoxdir;
    QLabel *labeldistance;
    QSpinBox *spinBoxdistance;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButtonstartp2p;
    QPushButton *pushButtonendp2p;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonbackZero;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *posmode)
    {
        if (posmode->objectName().isEmpty())
            posmode->setObjectName(QString::fromUtf8("posmode"));
        posmode->resize(624, 829);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(posmode->sizePolicy().hasHeightForWidth());
        posmode->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        posmode->setFont(font);
        verticalLayout = new QVBoxLayout(posmode);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBoxstep = new QGroupBox(posmode);
        groupBoxstep->setObjectName(QString::fromUtf8("groupBoxstep"));
        groupBoxstep->setMinimumSize(QSize(580, 350));
        groupBoxstep->setMaximumSize(QSize(550, 350));
        horizontalLayoutWidget = new QWidget(groupBoxstep);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 290, 461, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButtonstartstep = new QPushButton(horizontalLayoutWidget);
        pushButtonstartstep->setObjectName(QString::fromUtf8("pushButtonstartstep"));
        QFont font1;
        font1.setPointSize(10);
        pushButtonstartstep->setFont(font1);

        horizontalLayout->addWidget(pushButtonstartstep);

        pushButtonendstep = new QPushButton(horizontalLayoutWidget);
        pushButtonendstep->setObjectName(QString::fromUtf8("pushButtonendstep"));
        pushButtonendstep->setFont(font1);

        horizontalLayout->addWidget(pushButtonendstep);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonbackzero = new QPushButton(horizontalLayoutWidget);
        pushButtonbackzero->setObjectName(QString::fromUtf8("pushButtonbackzero"));
        pushButtonbackzero->setFont(font1);

        horizontalLayout->addWidget(pushButtonbackzero);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        progressBar = new QProgressBar(groupBoxstep);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(100, 230, 400, 23));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy1);
        progressBar->setMinimumSize(QSize(400, 0));
        progressBar->setMaximumSize(QSize(400, 16777215));
        progressBar->setValue(0);
        progressBar->setTextVisible(false);
        progressBar->setInvertedAppearance(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);
        horizontalLayoutWidget_3 = new QWidget(groupBoxstep);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(100, 260, 416, 30));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelbarstart = new QLabel(horizontalLayoutWidget_3);
        labelbarstart->setObjectName(QString::fromUtf8("labelbarstart"));
        labelbarstart->setMinimumSize(QSize(36, 0));
        labelbarstart->setMaximumSize(QSize(36, 16777215));

        horizontalLayout_2->addWidget(labelbarstart);

        horizontalSpacer_5 = new QSpacerItem(328, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        labelbarend = new QLabel(horizontalLayoutWidget_3);
        labelbarend->setObjectName(QString::fromUtf8("labelbarend"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelbarend->sizePolicy().hasHeightForWidth());
        labelbarend->setSizePolicy(sizePolicy2);
        labelbarend->setMinimumSize(QSize(36, 0));
        labelbarend->setMaximumSize(QSize(36, 16777215));

        horizontalLayout_2->addWidget(labelbarend);

        gridLayoutWidget = new QWidget(groupBoxstep);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 50, 570, 144));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(30);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(100, 0));
        label_7->setMaximumSize(QSize(150, 16777215));
        QFont font2;
        font2.setPointSize(12);
        label_7->setFont(font2);

        gridLayout_2->addWidget(label_7, 1, 2, 1, 1);

        lineEditcurpos = new QLineEdit(gridLayoutWidget);
        lineEditcurpos->setObjectName(QString::fromUtf8("lineEditcurpos"));
        lineEditcurpos->setMinimumSize(QSize(120, 0));
        lineEditcurpos->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(lineEditcurpos, 1, 3, 1, 1);

        lineEditstep = new QLineEdit(gridLayoutWidget);
        lineEditstep->setObjectName(QString::fromUtf8("lineEditstep"));
        lineEditstep->setMinimumSize(QSize(120, 0));
        lineEditstep->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(lineEditstep, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setMinimumSize(QSize(100, 0));
        label_5->setMaximumSize(QSize(100, 16777215));
        label_5->setFont(font2);

        gridLayout_2->addWidget(label_5, 0, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy2.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy2);
        label_6->setMinimumSize(QSize(84, 0));
        label_6->setMaximumSize(QSize(150, 16777215));
        label_6->setFont(font2);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEditstart = new QLineEdit(gridLayoutWidget);
        lineEditstart->setObjectName(QString::fromUtf8("lineEditstart"));
        lineEditstart->setMinimumSize(QSize(120, 0));
        lineEditstart->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(lineEditstart, 0, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setMaximumSize(QSize(100, 16777215));
        label_2->setFont(font2);

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        lineEditend = new QLineEdit(gridLayoutWidget);
        lineEditend->setObjectName(QString::fromUtf8("lineEditend"));
        lineEditend->setMinimumSize(QSize(120, 0));
        lineEditend->setMaximumSize(QSize(120, 16777215));

        gridLayout_2->addWidget(lineEditend, 0, 3, 1, 1);

        layoutWidget = new QWidget(groupBoxstep);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 180, 571, 30));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBoxstart = new QCheckBox(layoutWidget);
        checkBoxstart->setObjectName(QString::fromUtf8("checkBoxstart"));
        sizePolicy1.setHeightForWidth(checkBoxstart->sizePolicy().hasHeightForWidth());
        checkBoxstart->setSizePolicy(sizePolicy1);
        checkBoxstart->setMinimumSize(QSize(200, 0));
        checkBoxstart->setFont(font);

        horizontalLayout_4->addWidget(checkBoxstart);

        checkBoxtimedelay = new QCheckBox(layoutWidget);
        checkBoxtimedelay->setObjectName(QString::fromUtf8("checkBoxtimedelay"));
        sizePolicy1.setHeightForWidth(checkBoxtimedelay->sizePolicy().hasHeightForWidth());
        checkBoxtimedelay->setSizePolicy(sizePolicy1);
        checkBoxtimedelay->setMinimumSize(QSize(60, 0));
        checkBoxtimedelay->setFont(font);

        horizontalLayout_4->addWidget(checkBoxtimedelay);

        spinBoxtimedelay = new QSpinBox(layoutWidget);
        spinBoxtimedelay->setObjectName(QString::fromUtf8("spinBoxtimedelay"));
        spinBoxtimedelay->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(spinBoxtimedelay);

        line = new QFrame(layoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line);

        checkBoxcapture = new QCheckBox(layoutWidget);
        checkBoxcapture->setObjectName(QString::fromUtf8("checkBoxcapture"));
        checkBoxcapture->setMinimumSize(QSize(50, 0));

        horizontalLayout_4->addWidget(checkBoxcapture);


        verticalLayout->addWidget(groupBoxstep);

        groupBoxonepos = new QGroupBox(posmode);
        groupBoxonepos->setObjectName(QString::fromUtf8("groupBoxonepos"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBoxonepos->sizePolicy().hasHeightForWidth());
        groupBoxonepos->setSizePolicy(sizePolicy3);
        groupBoxonepos->setMinimumSize(QSize(580, 250));
        groupBoxonepos->setMaximumSize(QSize(580, 250));
        formLayoutWidget = new QWidget(groupBoxonepos);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 668, 459));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelpos = new QLabel(formLayoutWidget);
        labelpos->setObjectName(QString::fromUtf8("labelpos"));
        labelpos->setFont(font2);

        formLayout->setWidget(0, QFormLayout::LabelRole, labelpos);

        textBrowserpos = new QTextBrowser(formLayoutWidget);
        textBrowserpos->setObjectName(QString::fromUtf8("textBrowserpos"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(textBrowserpos->sizePolicy().hasHeightForWidth());
        textBrowserpos->setSizePolicy(sizePolicy4);
        textBrowserpos->setMinimumSize(QSize(0, 20));
        textBrowserpos->setMaximumSize(QSize(500, 24));

        formLayout->setWidget(0, QFormLayout::FieldRole, textBrowserpos);

        labeldir = new QLabel(formLayoutWidget);
        labeldir->setObjectName(QString::fromUtf8("labeldir"));
        labeldir->setFont(font2);

        formLayout->setWidget(1, QFormLayout::LabelRole, labeldir);

        comboBoxdir = new QComboBox(formLayoutWidget);
        comboBoxdir->setObjectName(QString::fromUtf8("comboBoxdir"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBoxdir);

        labeldistance = new QLabel(formLayoutWidget);
        labeldistance->setObjectName(QString::fromUtf8("labeldistance"));
        labeldistance->setFont(font2);

        formLayout->setWidget(2, QFormLayout::LabelRole, labeldistance);

        spinBoxdistance = new QSpinBox(formLayoutWidget);
        spinBoxdistance->setObjectName(QString::fromUtf8("spinBoxdistance"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxdistance);

        horizontalLayoutWidget_2 = new QWidget(groupBoxonepos);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(20, 190, 461, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButtonstartp2p = new QPushButton(horizontalLayoutWidget_2);
        pushButtonstartp2p->setObjectName(QString::fromUtf8("pushButtonstartp2p"));
        pushButtonstartp2p->setFont(font1);

        horizontalLayout_3->addWidget(pushButtonstartp2p);

        pushButtonendp2p = new QPushButton(horizontalLayoutWidget_2);
        pushButtonendp2p->setObjectName(QString::fromUtf8("pushButtonendp2p"));
        pushButtonendp2p->setFont(font1);

        horizontalLayout_3->addWidget(pushButtonendp2p);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonbackZero = new QPushButton(horizontalLayoutWidget_2);
        pushButtonbackZero->setObjectName(QString::fromUtf8("pushButtonbackZero"));
        pushButtonbackZero->setFont(font1);

        horizontalLayout_3->addWidget(pushButtonbackZero);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


        verticalLayout->addWidget(groupBoxonepos);


        retranslateUi(posmode);

        QMetaObject::connectSlotsByName(posmode);
    } // setupUi

    void retranslateUi(QDialog *posmode)
    {
        posmode->setWindowTitle(QCoreApplication::translate("posmode", "Dialog", nullptr));
        groupBoxstep->setTitle(QCoreApplication::translate("posmode", "\346\255\245\350\277\233\346\250\241\345\274\217", nullptr));
        pushButtonstartstep->setText(QCoreApplication::translate("posmode", "\345\274\200\345\247\213", nullptr));
        pushButtonendstep->setText(QCoreApplication::translate("posmode", "\345\201\234\346\255\242", nullptr));
        pushButtonbackzero->setText(QCoreApplication::translate("posmode", "\345\233\236\351\233\266", nullptr));
        labelbarstart->setText(QCoreApplication::translate("posmode", "Start", nullptr));
        labelbarend->setText(QCoreApplication::translate("posmode", "End", nullptr));
        label_7->setText(QCoreApplication::translate("posmode", "\345\275\223\345\211\215\344\275\215\347\275\256/mm", nullptr));
        label_5->setText(QCoreApplication::translate("posmode", "\347\273\210\346\255\242\344\275\215\347\275\256/mm", nullptr));
        label_6->setText(QCoreApplication::translate("posmode", "\346\255\245\351\225\277(\316\274m)\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("posmode", "\350\265\267\345\247\213\344\275\215\347\275\256/mm\357\274\232", nullptr));
        checkBoxstart->setText(QCoreApplication::translate("posmode", "\344\273\216\345\275\223\345\211\215\344\275\215\347\275\256\345\274\200\345\247\213", nullptr));
        checkBoxtimedelay->setText(QCoreApplication::translate("posmode", "\345\273\266\346\227\266(ms)", nullptr));
        checkBoxcapture->setText(QCoreApplication::translate("posmode", "\351\207\207\351\233\206\346\225\260\346\215\256", nullptr));
        groupBoxonepos->setTitle(QCoreApplication::translate("posmode", "\347\202\271\345\257\271\347\202\271\346\250\241\345\274\217", nullptr));
        labelpos->setText(QCoreApplication::translate("posmode", "\345\275\223\345\211\215\344\275\215\347\275\256\357\274\232", nullptr));
        labeldir->setText(QCoreApplication::translate("posmode", "\347\247\273\345\212\250\346\226\271\345\220\221\357\274\232", nullptr));
        labeldistance->setText(QCoreApplication::translate("posmode", "\347\247\273\345\212\250\350\267\235\347\246\273\357\274\232", nullptr));
        pushButtonstartp2p->setText(QCoreApplication::translate("posmode", "\345\274\200\345\247\213", nullptr));
        pushButtonendp2p->setText(QCoreApplication::translate("posmode", "\345\201\234\346\255\242", nullptr));
        pushButtonbackZero->setText(QCoreApplication::translate("posmode", "\345\233\236\351\233\266", nullptr));
    } // retranslateUi

};

namespace Ui {
    class posmode: public Ui_posmode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSMODE_H
