#ifndef DIALOG_USER_H
#define DIALOG_USER_H

#include <QDialog>

namespace Ui {
class Dialog_user;
}

class Dialog_user : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_user(QWidget *parent = 0);
    ~Dialog_user();
    void init();
private slots:
    void on_pushButton_w1_clicked();

    void on_pushButton_w2_clicked();

    void on_pushButton_w3_clicked();

    void on_pushButton_r1_clicked();

    void on_pushButton_r2_clicked();

    void on_pushButton_r3_clicked();

    void on_pushButton_c1_clicked();

    void on_pushButton_c2_clicked();

    void on_pushButton_c3_clicked();
private:
    Ui::Dialog_user *ui;
};

#endif // DIALOG_USER_H
