/********************************************************************************
** Form generated from reading UI file 'velocitymode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VELOCITYMODE_H
#define UI_VELOCITYMODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_velocitymode
{
public:
    QGroupBox *parameter;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *comboBoxDir;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *spinBoxvspinlim;
    QSpinBox *spinBoxvspin;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxconnect;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonstart;
    QPushButton *pushButtonend;

    void setupUi(QDialog *velocitymode)
    {
        if (velocitymode->objectName().isEmpty())
            velocitymode->setObjectName(QString::fromUtf8("velocitymode"));
        velocitymode->resize(600, 504);
        velocitymode->setModal(true);
        parameter = new QGroupBox(velocitymode);
        parameter->setObjectName(QString::fromUtf8("parameter"));
        parameter->setGeometry(QRect(10, 20, 581, 281));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(parameter->sizePolicy().hasHeightForWidth());
        parameter->setSizePolicy(sizePolicy);
        parameter->setMinimumSize(QSize(580, 280));
        QFont font;
        font.setPointSize(10);
        parameter->setFont(font);
        parameter->setCheckable(false);
        formLayoutWidget = new QWidget(parameter);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 50, 551, 162));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMinimumSize(QSize(80, 0));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        comboBoxDir = new QComboBox(formLayoutWidget);
        comboBoxDir->setObjectName(QString::fromUtf8("comboBoxDir"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBoxDir->sizePolicy().hasHeightForWidth());
        comboBoxDir->setSizePolicy(sizePolicy2);
        comboBoxDir->setMinimumSize(QSize(300, 30));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBoxDir);

        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);
        label->setMinimumSize(QSize(80, 0));
        label->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        spinBoxvspinlim = new QSpinBox(formLayoutWidget);
        spinBoxvspinlim->setObjectName(QString::fromUtf8("spinBoxvspinlim"));
        spinBoxvspinlim->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(1, QFormLayout::FieldRole, spinBoxvspinlim);

        spinBoxvspin = new QSpinBox(formLayoutWidget);
        spinBoxvspin->setObjectName(QString::fromUtf8("spinBoxvspin"));
        spinBoxvspin->setMinimumSize(QSize(0, 30));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxvspin);

        horizontalLayoutWidget = new QWidget(parameter);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 230, 561, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkBoxconnect = new QCheckBox(horizontalLayoutWidget);
        checkBoxconnect->setObjectName(QString::fromUtf8("checkBoxconnect"));
        checkBoxconnect->setMinimumSize(QSize(100, 0));
        checkBoxconnect->setFont(font1);

        horizontalLayout->addWidget(checkBoxconnect);

        horizontalSpacer = new QSpacerItem(80, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonstart = new QPushButton(horizontalLayoutWidget);
        pushButtonstart->setObjectName(QString::fromUtf8("pushButtonstart"));
        pushButtonstart->setFont(font1);

        horizontalLayout->addWidget(pushButtonstart);

        pushButtonend = new QPushButton(horizontalLayoutWidget);
        pushButtonend->setObjectName(QString::fromUtf8("pushButtonend"));
        pushButtonend->setFont(font1);

        horizontalLayout->addWidget(pushButtonend);


        retranslateUi(velocitymode);

        QMetaObject::connectSlotsByName(velocitymode);
    } // setupUi

    void retranslateUi(QDialog *velocitymode)
    {
        velocitymode->setWindowTitle(QCoreApplication::translate("velocitymode", "Dialog", nullptr));
        parameter->setTitle(QCoreApplication::translate("velocitymode", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("velocitymode", "\350\277\220\345\212\250\346\226\271\345\220\221\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("velocitymode", "\350\275\254\351\200\237\351\231\220\345\210\266r/s\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("velocitymode", "\350\275\254\351\200\237\350\256\276\347\275\256r/s:", nullptr));
        checkBoxconnect->setText(QCoreApplication::translate("velocitymode", "\351\251\261\345\212\250\345\231\250\350\277\236\346\216\245", nullptr));
        pushButtonstart->setText(QCoreApplication::translate("velocitymode", "\345\274\200\345\247\213", nullptr));
        pushButtonend->setText(QCoreApplication::translate("velocitymode", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class velocitymode: public Ui_velocitymode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VELOCITYMODE_H
