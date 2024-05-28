#ifndef IQA_H
#define IQA_H

#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include "Daubechies.h"
using namespace cv; 

class IQA
{
public:
    IQA(const Mat& src_img);
    ~IQA();
    
    //Derivate-based Method
    double Threshold_Absolute_Gradient();
    double Squared_Gradient();
    double Brenner_Gradient();
    double Tenenbaum_Gradient();
    double Sum_of_Modified_Laplace();
    double Daubechies_wavelet();

    //Statistical Algorithms
    double AutoCorrelation(Mat& grayImg);
    double Entropy();

    //Histogram-Based Algorithms
    double contrast_extract(Mat& src_img);  

private:
    Mat ideal_highpass_filter(Mat& highpass_img,double cutoff_freq);
    Mat butterworth_highpass(Mat& butterworth_img,double cutoff_freq,int order);
    double blur_coffcient(Mat& src_img);

private:
    void img_statistical_params(Mat& img);
    void Canny_grad(Mat& Canny_grad,double thrd1,double thrd2);
    void Sobel_grad(Mat& Sobel_grad_x, Mat& Sobel_grad_y);
    void Laplace_grad(Mat& Laplace_grad_x,Mat& Laplace_grad_y);

private:
    Mat src_img;
    int length;
    int width;
    Mat grayImg;
    Scalar mean,var;
};

#endif