#ifndef DATAPROCESS_H
#define DATAPROCESS_H
#include <regex>
#include <string>
#include <algorithm>
#include <QFileInfo>
#include "IQA.h"
#include "LIQA.h"
#include "lineccdview/headers/lineccdview.h"

//#define img_path "D:/dataset/0123/fig"
//#define lineCCDdata_path "D:/dataset/0123/lineccd"

using namespace cv;

// Separate the method and execution
//class ProcessThread : public QThread
//{
//    Q_OBJECT
//public:
//    ProcessThread(QObject *parent = 0)
//        : QThread(parent){ }

//protected:
//    void run() override;
//    void stop();

//signals:
//    void ThreadMyCom(QByteArray);

//private:
//    void readData();
//};


class DataProcess
{
public:
    DataProcess();
    ~DataProcess();

    void get_CCDdata(QVector<double>);
    int FindFocus(QString img_path);
    std::vector<int> Calibrate(QString img_path, QString lineCCDdata_path);

private:

    // void renamefile(std::string path);
    static int digit_extract(std::string input);

public:
    QVector<double> m_ccddata;
};

#endif // DATAPROCESS_H
