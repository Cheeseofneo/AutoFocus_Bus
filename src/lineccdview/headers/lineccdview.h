#ifndef LINECCDVIEW_H
#define LINECCDVIEW_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QThread>
#include <QTimer>
#include <QTextEdit>
#include "dialog_config.h"


class MainWindow;

namespace Ui {
    class Widget;
}

typedef struct tagCoff
{
    QString f[4];
}Coff;

enum button_state
{
  single,
  countinuous,
  stop
};

class MyThreadSerial : public QThread
{
    Q_OBJECT
    public:
        MyThreadSerial(QObject *parent = 0)
               : QThread(parent){ }
    protected:
        void run();
    public:
        volatile bool stopped;
    public:
        void ThreadopenMycom(QString port);

        void writeMyCom(QByteArray senddata);

        QSerialPort *m_Com;
    signals:
        void ThreadMyCom(QByteArray);

    private:
        void readData();
};


class lineccdview : public QWidget
{
    Q_OBJECT

    signals:
        void ThreadCCDdata(QVector<double>);

    public:
        explicit lineccdview(QWidget *parent = 0);
        ~lineccdview();

        MyThreadSerial* serial;
    //    Coff m_coff_laser;
    //    Coff m_coff_waveLength;
    //    Coff m_coff_ramanShift;

        Coff m_coff_1;
        Coff m_coff_2;
        Coff m_coff_3;
        void writeCoff_1();
        void readCoff_1();
        void writeCoff_2();
        void readCoff_2();
        void writeCoff_3();
        void readCoff_3();
        
    public:
        int m_radioButton_1;
        int m_radioButton_2;
        int m_radioButton_3;
        int m_lineEdit_Gain;
        int m_lineEdit_Offset;
        int m_checkBox_HdTrigger;
        int m_groupBox;
        int m_groupBox_2;
        int m_groupBox_5;
        Dialog_config* m_DlgConfig;


    private slots:

        void on_pushButton_Close_clicked();

        void readMyCom(QByteArray str);

        void Bandrate_read();

        void timerUpDate();

        void timerUpDate2();

        void timerUpDate3();

        void on_pushButton_Open_clicked();

        void on_pushButton_Send_clicked();

        void on_pushButton_Cou_clicked();

        void on_pushButton_SetInt_clicked();

        void on_pushButton_Save_clicked();

        void on_pushButton_Pause_clicked();

        void on_pushButton_SetAvg_clicked();

        QString ToStr(int number, int size);

        void on_pushButton_fW_clicked();

        void on_pushButton_fR_clicked();

        void on_textEdit_textChanged();

        void on_pushButton_Clean_clicked();

        void on_comboBox_unit_currentIndexChanged(const QString &arg1);

        void on_pushButton_SetSmooth_clicked();

        void on_pushButton_EarseFlash_clicked();

        void on_pushButton_GetDark_clicked();

        void on_checkBox_removeDark_stateChanged(int arg1);

        void on_radioButton_pixels_clicked();

        void on_radioButton_wavelength_clicked();

        void on_radioButton_raman_clicked();

        void on_radioButton_wavenumber_clicked();

        void on_pushButton_SetInterval_clicked();

        void on_pushButton_filter_clicked();

        //    void on_pushButton_Bandrate_read_clicked();
        //    void on_pushButton_Setting_clicked();
        //    void on_checkBox_sync_stateChanged(int arg1);
        //    void on_pushButton_SetGain_clicked();
        //    void on_pushButton_SetOffset_clicked();
        //    void on_pushButton_getPara_clicked();
        //    void on_pushButton_SavePara_clicked();
        //    void on_pushButton_Bandrate_clicked();
        //    void on_pushButton_erase_clicked();
        //    void on_pushButton_SetDAC_clicked();
        //    void on_checkBox_Trigger2_stateChanged(int arg1);
        //    void on_checkBox_Trig_Con_clicked();
        //    void on_checkBox_Trig_Single_clicked();
        //    void on_checkBox_HdTrigger_stateChanged(int arg1);

    private:
        Ui::Widget *ui;

        bool initmyCom();
        void writeMyCom(QString str);
        void String2Hex(QString str, QByteArray &senddata);
        char ConvertHexChar(char ch);
        void setupPlot();
        void GetHardwareInfo();

        void GetIntegrationTime();
        void GetIntegrationUnit();
        void GetAvgTimes();

        void Delay_MSec(unsigned int msec);
        void SetIntUnit(QString unit);
        void GetGain();

        void GetOffset();
        void GetSmooth();
        void getPar();
        void GetInterval();
        void SetInterval();
        void SetFilterLevel();

        QTimer *timer;
        QTimer *timer2;
        Dialog_user m_Dlg;

        int m_len;
        int m_frame;
        int m_speed;
        int m_averageTimes;
        quint8 m_frameDelay;
        short m_integrationTime;
        short m_progressValue;

        QVector<double> m_CCDData;
        QVector<double> m_BaseData;
        QVector<double> m_Xdata;
        QVector<double> m_CCDData_Pixels;

        button_state m_button_state;

        QTextEdit  *m_myEdit;
        bool  m_writeFlash;
        quint8 m_smooth;
        int m_flashWtrieTime ;
};


#endif // LINECCDVIEW_H
