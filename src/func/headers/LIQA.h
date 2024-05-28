#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <iostream>
#include <Eigen/Dense>

#include <QDir>
#include <QFile>
#include <QTextStream>

// #include "matplotlibcpp.h"
// namespace plt = matplotlibcpp;

class LIQA{

public:
    //LIQA(std::filesystem::path TXT_PATH);
    LIQA(QString TXT_PATH);
    ~LIQA();

public:
    std::vector<float> readdata();
    std::vector<float> Median_filter(std::vector<float> lineCCDdata);
    std::vector<float> Highpass_filter(std::vector<float> lineCCDdata);
    int centroid(std::vector<float> lineCCDdata);
    std::vector<float> Savi_Golay_filter(std::vector<float> centroid, int window_size, int order);
    std::vector<float> Calibration_params(std::vector<float> lineCCDdata, int head, int len);
    std::pair<std::vector<float>,std::vector<float>> windowing(
        std::vector<float> lineCCDdata, int window_size, char* window_type);
    void plotdata(
        std::vector<float> key,std::vector<float> value,std::vector<float> centroid,std::vector<float> params,int head,int tail);

private:
//    std::ifstream file;
    QFile m_file;
};
