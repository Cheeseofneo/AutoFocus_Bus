/********************************************************************************
** Form generated from reading UI file 'dialog_savepath.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SAVEPATH_H
#define UI_DIALOG_SAVEPATH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_dialog_savepath
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialog_savepath)
    {
        if (dialog_savepath->objectName().isEmpty())
            dialog_savepath->setObjectName(QString::fromUtf8("dialog_savepath"));
        dialog_savepath->resize(400, 300);
        buttonBox = new QDialogButtonBox(dialog_savepath);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(dialog_savepath);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_savepath, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_savepath, SLOT(reject()));

        QMetaObject::connectSlotsByName(dialog_savepath);
    } // setupUi

    void retranslateUi(QDialog *dialog_savepath)
    {
        dialog_savepath->setWindowTitle(QCoreApplication::translate("dialog_savepath", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_savepath: public Ui_dialog_savepath {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SAVEPATH_H
