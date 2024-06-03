#include "func/headers/dataprocess.h"

DataProcess::DataProcess()
{

}

DataProcess::~DataProcess(){}

int DataProcess::FindFocus(QString img_path)
{
    // specify python interpreter
    //    Py_SetPythonHome(L"D:\\python39");
    //    Py_Initialize();

    // initialize
    std::vector<float> TAG,SG,BG,TG,SML,D6,ENT;
    std::vector<float> z_pos_img;

    QDir dir(img_path);
    QFileInfoList entries_img = dir.entryInfoList(QStringList() << "*.bmp",QDir::Files|QDir::NoDotAndDotDot, QDir::Time);

    //sort files in sequence
    std::sort(entries_img.begin(), entries_img.end(), [](const QFileInfo& a, const QFileInfo& b) {
        return digit_extract(a.fileName().toStdString()) < digit_extract(b.fileName().toStdString());
    });

    for(const auto& entry: entries_img)
    {
        QString FilePath = entry.absoluteFilePath();
        cv::Mat image = cv::imread(FilePath.toStdString());
        z_pos_img.push_back(entry.baseName().toInt());
        if (!image.empty()) {
            IQA test(image);
            TAG.push_back(test.Threshold_Absolute_Gradient());
            SG.push_back(test.Squared_Gradient());
            BG.push_back(test.Brenner_Gradient());
            TG.push_back(test.Tenenbaum_Gradient());
            SML.push_back(test.Sum_of_Modified_Laplace());
            ENT.push_back(test.Entropy());
            // D6.push_back(test.Daubechies_wavelet());
        }
    }

    std::vector<float> focus;
    int focuspos;
    // 将以下语句封装
    normalize(TAG, TAG, 0, 1, cv::NORM_MINMAX);
    auto TAGmax=std::max_element(TAG.begin(),TAG.end());
    focus.push_back(*TAGmax);
    std::cout<<"Max element is " << *TAGmax<< " at position " << std::distance(TAG.begin(),TAGmax) << std::endl;

    normalize(SG,  SG, 0, 1, cv::NORM_MINMAX);
    auto SGmax=std::max_element(SG.begin(),SG.end());
    focus.push_back(*SGmax);
    std::cout<<"Max element is " << *SGmax<< " at position " << std::distance(SG.begin(),SGmax) << std::endl;

    normalize(BG,  BG, 0, 1, cv::NORM_MINMAX);
    auto BGmax=std::max_element(BG.begin(),BG.end());
    focus.push_back(*BGmax);
    std::cout<<"Max element is " << *BGmax<< " at position " << std::distance(BG.begin(),BGmax) << std::endl;

    normalize(TG,  TG, 0, 1, cv::NORM_MINMAX);
    auto TGmax=std::max_element(TG.begin(),TG.end());
    focus.push_back(*TGmax);
    std::cout<<"Max element is " << *TGmax<< " at position " << std::distance(TG.begin(),TGmax) << std::endl;

    normalize(SML, SML, 0, 1, cv::NORM_MINMAX);
    auto SMLmax=std::max_element(SML.begin(),SML.end());
    focus.push_back(*SMLmax);
    std::cout<<"Max element is " << *SMLmax<< " at position " << std::distance(SML.begin(),SMLmax) << std::endl;

    normalize(ENT, ENT, 0, 1, cv::NORM_MINMAX);
    auto ENTmax=std::max_element(ENT.begin(),ENT.end());
    focus.push_back(*ENTmax);
    std::cout<<"Max element is " << *ENTmax<< " at position " << std::distance(ENT.begin(),ENTmax) << std::endl;

    // normalize(D6,  D6, 0, 1, cv::NORM_MINMAX);
    // auto D6max=std::max_element(D6.begin(),D6.end());
    // std::cout<<"Max element is " << *D6max<< " at position " << std::distance(D6.begin(),D6max) << std::endl;

    // remove the error value
    std::sort(focus.begin(),focus.end());
    [&focus,&focuspos]()mutable{
            if (focus.size()%2 == 0) focuspos = int((focus[focus.size()/2]+focus[focus.size()/2-1])/2);
            else focuspos = focus[int(focus.size()/2)]; };
    return focuspos;
}


std::vector<int> DataProcess::Calibrate(QString img_path, QString lineCCDdata_path){

    std::vector<float> z_pos_lineccd;
    std::vector<float> Centroid_DATA;

    QDir dir(lineCCDdata_path);
    QFileInfoList entries_lineccd = dir.entryInfoList(QStringList() << "*.txt", QDir::Files | QDir::NoDotAndDotDot, QDir::Time);

    //sort files in sequence
    std::sort(entries_lineccd.begin(), entries_lineccd.end(), [](const QFileInfo& a, const QFileInfo& b) {
        return digit_extract(a.fileName().toStdString()) < digit_extract(b.fileName().toStdString());
    });

    for (auto& entry : entries_lineccd)
    {
        std::vector<float> lineCCDdata;
        QString filename = entry.absoluteFilePath();
        z_pos_lineccd.push_back(entry.baseName().toInt());
        LIQA temp(filename);
        lineCCDdata=temp.readdata();
        Centroid_DATA.push_back(temp.centroid(lineCCDdata));

    }
    auto focus= Centroid_DATA[FindFocus(img_path)];

    // TODO:优化减法速度
    for (auto& element : Centroid_DATA) {
        element -= focus;
    }

    int head=100, len=20; // 拟合区间
    std::vector<float> m_lineCCD=LIQA(entries_lineccd[0].absoluteFilePath()).Savi_Golay_filter(Centroid_DATA,11,3);
    std::vector<float> params=LIQA(entries_lineccd[0].absoluteFilePath()).Calibration_params(m_lineCCD,head,len);
    std::cout<<"The func of dis is: "<<params[0]<<"x+"<<params[1]<<std::endl;
}

int DataProcess::offset_calculate(QVector<double> data, int focus){

    int centroid = LIQA("C:/").centroid(data.toStdVector());
    return focus-centroid;
}

int DataProcess::digit_extract(std::string input){

    std::regex pattern("\\d+");
    std::smatch match;
    std::string result;
    if (std::regex_search(input, match, pattern)) {
        result = match.str();
    }
    return std::stoi(result);
}
