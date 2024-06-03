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

class DataProcess
{
public:
    DataProcess();
    ~DataProcess();
    int FindFocus(QString img_path);
    int offset_calculate(QVector<double> data, int focus);
    std::vector<int> Calibrate(QString img_path, QString lineCCDdata_path);

private:

    // void renamefile(std::string path);
    static int digit_extract(std::string input);

public:
    QVector<double> m_ccddata;
};

#endif // DATAPROCESS_H
