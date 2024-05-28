
#ifndef DIAL_H
#define DIAL_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <complex>

class dial : public QWidget
{
    Q_OBJECT
public:
    dial(QWidget *parent = nullptr);
    ~dial();

private:
    int value;
    int radius;
    int Angle;
    int percent;

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void valueChanged(int value);
    void drawBg(QPainter *painter);
    void drawDial(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawText(QPainter *painter);
};

#endif // DIAL_H
