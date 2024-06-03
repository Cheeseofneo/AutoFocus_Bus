#include "LIQA.h"
#include "savgol.h"

LIQA::LIQA(QString TXT_PATH){

    //  file.open(TXT_PATH);
    m_file.setFileName(TXT_PATH);
    m_file.open( QIODevice::ReadOnly | QIODevice::Text);
}

LIQA::~LIQA(){
    
    m_file.close();
}

std::vector<float> LIQA::readdata(){

    // read data from txt file in "int" format

    //    if (!m_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //        qWarning() << "Cannot open file for reading:" << file.errorString();
    //        return numbers;
    //    }
    std::vector<float> lineccddata;
    QTextStream in(&m_file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        float data = line.toFloat();
        lineccddata.push_back(data);
    }
    return lineccddata;
}

std::vector<float> LIQA::Median_filter(std::vector<float> lineCCDdata){
    for(auto& vec:lineCCDdata ){
        if(vec<4300) vec=0;
    }
    return lineCCDdata;
}

std::vector<float> Highpass_filter(std::vector<float> lineCCDdata){

    std::vector<float> lineCCDdata_filtered;

    // calculate the mean value
    float mean = std::accumulate(std::begin(lineCCDdata), std::end(lineCCDdata), 0.0)/lineCCDdata.size();

    // calculate the standard deviation
    std::vector<float> temp(lineCCDdata.size());

    std::transform(lineCCDdata.begin(), lineCCDdata.end(), temp.begin(), [mean](float x) { return x - mean; });

    float sq_sum = std::inner_product(temp.begin(), temp.end(), temp.begin(), 0.0);
    float stdev = std::sqrt(sq_sum / lineCCDdata.size());
    return lineCCDdata;    
}

std::vector<float> LIQA::Savi_Golay_filter(std::vector<float> centroid, int window_size=7, int order=3)
{

    savgol savgol_test;
    Eigen::Map<Eigen::VectorXf> m_lineCCD(centroid.data(), centroid.size());
    Eigen::RowVectorXf m_lineCCD_eigen=savgol_test.savgolfilt(m_lineCCD, order, window_size);
    std::vector<float>lineCCDdata_filtered(m_lineCCD_eigen.data(), m_lineCCD_eigen.data() + m_lineCCD_eigen.size());
    return lineCCDdata_filtered;
}

std::pair<std::vector<float>, std::vector<float>> LIQA::windowing(
                std::vector<float> lineCCDdata, int window_size, char* window_type="")
{   
    auto max_element = std::max_element(lineCCDdata.begin(), lineCCDdata.end());
    int max_index=std::distance(std::begin(lineCCDdata),max_element);
    auto min_element = std::min_element(lineCCDdata.begin(), lineCCDdata.end());
    std::vector<float> x_window(window_size*2,0);
    std::vector<float> lineCCDdata_win(window_size*2,0);

    for (auto element : lineCCDdata)
    {
        element = (element-*min_element)/(*max_element-*min_element);}
    
    if (window_type=="rect")
    {
        for (int i = 0; i < x_window.size(); ++i) {
            lineCCDdata_win[i] = lineCCDdata[max_index-window_size+i];
            x_window[i]=max_index-window_size+i;
        } 
        return {lineCCDdata_win,x_window};
    }
    else if (window_type=="hanning")
    {
        std::vector<float> hanning(window_size,0);
        for (int i = 0; i < hanning.size(); ++i) {
            hanning[i] = 0.5*(1-std::cos(2*3.1415926535*i/(window_size-1)));}
        std::transform(lineCCDdata_win.begin(), lineCCDdata_win.end(), hanning.begin(), lineCCDdata_win.begin(), std::multiplies<float>());
        return {lineCCDdata_win,x_window};
    }
    else if (window_type=="")
    {
        std::vector<float> x(lineCCDdata.size(),0);
        for (int i = 0; i <x.size(); ++i) {
            x[i]=i;
        } 
        return {lineCCDdata,x};
    }
    else
    {
        std::cout<<"The window type is not supported"<<std::endl;
        return {lineCCDdata_win,x_window};
    }
}

std::pair<std::vector<double>, std::vector<double>> LIQA::windowing(
    std::vector<double> lineCCDdata, int window_size, char* window_type="")
{
    auto max_element = std::max_element(lineCCDdata.begin(), lineCCDdata.end());
    int max_index=std::distance(std::begin(lineCCDdata),max_element);
    auto min_element = std::min_element(lineCCDdata.begin(), lineCCDdata.end());
    std::vector<double> x_window(window_size*2,0);
    std::vector<double> lineCCDdata_win(window_size*2,0);

    for (auto element : lineCCDdata)
    {
        element = (element-*min_element)/(*max_element-*min_element);}

    if (window_type=="rect")
    {
        for (int i = 0; i < x_window.size(); ++i) {
            lineCCDdata_win[i] = lineCCDdata[max_index-window_size+i];
            x_window[i]=max_index-window_size+i;
        }
        return {lineCCDdata_win,x_window};
    }
    else if (window_type=="hanning")
    {
        std::vector<float> hanning(window_size,0);
        for (int i = 0; i < hanning.size(); ++i) {
            hanning[i] = 0.5*(1-std::cos(2*3.1415926535*i/(window_size-1)));}
        std::transform(lineCCDdata_win.begin(), lineCCDdata_win.end(), hanning.begin(), lineCCDdata_win.begin(), std::multiplies<float>());
        return {lineCCDdata_win,x_window};
    }
    else if (window_type=="")
    {
        std::vector<double> x(lineCCDdata.size(),0);
        for (int i = 0; i <x.size(); ++i) {
            x[i]=i;
        }
        return {lineCCDdata,x};
    }
    else
    {
        std::cout<<"The window type is not supported"<<std::endl;
        return {lineCCDdata_win,x_window};
    }
}


int LIQA::centroid(std::vector<float> lineCCDdata){

    std::pair<std::vector<float>,std::vector<float>> win = windowing(lineCCDdata,100,"rect");
    std::vector<float> x_window=win.second;
    std::vector<float> lineCCDdata_win=win.first;
    float sumxy= std::inner_product(x_window.begin(),x_window.end(),lineCCDdata_win.begin(),0);
    float sumy= std::accumulate(lineCCDdata_win.begin(),lineCCDdata_win.end(),0);
    float sumx= std::accumulate(x_window.begin(),x_window.end(),0);
    return int(sumxy/sumx);
}

int LIQA::centroid(std::vector<double> lineCCDdata){

    std::pair<std::vector<double>,std::vector<double>> win = windowing(lineCCDdata,100,"rect");
    std::vector<double> x_window=win.second;
    std::vector<double> lineCCDdata_win=win.first;
    float sumxy= std::inner_product(x_window.begin(),x_window.end(),lineCCDdata_win.begin(),0);
    float sumy= std::accumulate(lineCCDdata_win.begin(),lineCCDdata_win.end(),0);
    float sumx= std::accumulate(x_window.begin(),x_window.end(),0);
    return int(sumxy/sumx);
}

std::vector<float> LIQA::Calibration_params(std::vector<float> input, int head, int len){
    
    std::vector<float> m_data(input.begin()+head,input.begin()+head+len);
    std::vector<float> params(2,0);
    std::vector<int> x(m_data.size(),0);
    for (int i = 0; i < x.size(); ++i) {
        x[i] = head+i;
    }
    // calculate the slope
    float sumxy= std::inner_product(x.begin(),x.end(),m_data.begin(),0);
    float sumx2= std::inner_product(x.begin(),x.end(),x.begin(),0);
    float sumx= std::accumulate(x.begin(),x.end(),0);
    float sumy= std::accumulate(m_data.begin(),m_data.end(),0);
    float num=x.size();
    float a = (double)(sumx2*sumy - sumx*sumxy)/(double)(num*sumx2-sumx*sumx);
    float b = (double)(num*sumxy - sumx*sumy)/(double)(num*sumx2 - sumx*sumx);

    // store the params
    params[0]=b;
    params[1]=a;
    return params;
}

/**
    * module: plot the centroid data and the fitted line
    * input:  params(cof); head, tail(拟合区间)
*/
void LIQA::plotdata(std::vector<float> key, std::vector<float> value,std::vector<float> centroid,std::vector<float> params,int head,int tail){

    // plt::named_plot("SG filterd centroid data",key, value);
    // plt::named_plot("origin centroid data",key, centroid);

    //  std::vector<float> zero(key.size(),0),y(tail-head,0),error(tail-head,0);
    //  std::vector subkey(key.begin()+head,key.begin()+tail);
    //  for (int i=0;i<subkey.size();i++){
    //      y[i]=(subkey[i]*params[0]+params[1]);
    //      error[i]=abs(value[head+i]-y[i]);
    //  }

    //  auto errmax=std::max_element(error.begin(),error.end());
    //  std::cout<<"Max element is " << *errmax<< " at position " << std::distance(error.begin(),errmax) << std::endl;

    // plt::named_plot("fitting curve",subkey,y);
    // plt::annotate("("+std::to_string(params[1])+",0)",params[1],0);
    // plt::plot(key,zero,"k--");
    // plt::named_plot("error",subkey,error,"r*");
    // plt::xlabel("z position_index");
    // plt::ylabel("LIQA_Centroid_pos/pixel");
    // plt::legend();
    // plt::show();

}
