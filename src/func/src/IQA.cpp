#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>
#include "IQA.h"

using namespace cv;

#define Image_480p


#ifdef Image_240p

  #define Pixels_ALL 320*240
  #define Pixels_Length 320
  #define Pixels_Width 240

#endif

#ifdef Image_480p

  #define Pixels_ALL 640*480  
  #define Pixels_Length 640
  #define Pixels_Width 480

#endif

#ifdef Image_720p

  #define Pixels_ALL 1280*720  
  #define Pixels_Length 1280
  #define Pixels_Width 720

#endif

void fftShift(cv::Mat& input,cv::Mat output); 

IQA::IQA(const Mat& src_img):
    src_img(src_img)
{
    // Image pre-process：RGB image
    length=Pixels_Length;
    width=Pixels_Width;
    cv::Size newSize(Pixels_Length, Pixels_Width);
    Mat image;
    cv::resize(src_img, image, newSize);
    cvtColor(image,grayImg,COLOR_RGB2GRAY);

    meanStdDev(grayImg,mean,var);
    Mat Canny_grad(newSize.height,newSize.width, CV_8UC1, Scalar(0)); 
    Mat Sobel_grad(newSize.height,newSize.width, CV_8UC1, Scalar(0));
}

IQA::~IQA()
{
    destroyAllWindows();
}

void IQA::img_statistical_params(Mat& img)
{
    double minv, maxv;
    Point minLoc, maxLoc; 
    std::vector<Mat>mv;
    split(img, mv);
    for (int i = 0; i < mv.size(); i++) 
    {
        minMaxLoc(mv[i], &minv, &maxv, &minLoc, &maxLoc, Mat());
    }
}

double IQA::Threshold_Absolute_Gradient(){

    Mat Col_Vecs = Mat::zeros(grayImg.rows, 1, CV_32F); // 不能使用未初始化的矩阵进行累加
    for(int cols=0;cols<width-1;cols++){
        Col_Vecs+=abs(grayImg.col(cols+1)-grayImg.col(cols));
    }
    Scalar TAG=sum(Col_Vecs);
    return double(TAG[0]);
}

double IQA::Squared_Gradient(){

    Mat Col_Vecs = Mat::zeros(grayImg.rows, 1, CV_32F); 
    for(int cols=0;cols<width-1;cols++){
        Col_Vecs+=(grayImg.col(cols+1)-grayImg.col(cols))^2;
    }
    Scalar TAG=sum(Col_Vecs);
    return double(TAG[0]);
}

double IQA::Brenner_Gradient(){
    
    Mat Col_Vecs = Mat::zeros(grayImg.rows, 1, CV_32F); 
    for(int cols=0;cols<width-2;cols++){
        Col_Vecs+=(grayImg.col(cols+2)-grayImg.col(cols))^2;
    }
    Scalar TAG=sum(Col_Vecs);
    return double(TAG[0]);
}

double IQA::Tenenbaum_Gradient(){
    
    Mat Sobel_grad_x,Sobel_grad_y;
    Sobel_grad(Sobel_grad_x,Sobel_grad_y);
    cv::pow(Sobel_grad_x,2,Sobel_grad_x);
    cv::pow(Sobel_grad_y,2,Sobel_grad_y);
    Scalar tg=sum(Sobel_grad_x)+sum(Sobel_grad_y);
    return double(tg[0]);
}

double IQA::Sum_of_Modified_Laplace(){
    
    Mat Laplace_grad_x,Laplace_grad_y;
    Laplace_grad(Laplace_grad_x,Laplace_grad_y);
    Scalar sml=sum(abs(Laplace_grad_x))+sum(abs(Laplace_grad_y));
    return double(sml[0]);
}

double IQA::Entropy()
{
    Mat hist;
    int histSize = 256;
    float range[] = { 0, 256 };
    const float* histRange = { range };
    calcHist(&grayImg, 1, 0, Mat(), hist, 1, &histSize, &histRange, true, false);
    hist /= Pixels_ALL;
    cv::log(hist+1e-10,hist);
    double entropy = -sum(hist.mul(hist))[0];
    return entropy;
}


/**
    * module: high filter
    * input: img
    * output: output
*/
Mat IQA::ideal_highpass_filter(Mat& img,double cutoff_freq)
{
    Mat output;
    int rows=getOptimalDFTSize(length);
    int cols=getOptimalDFTSize(width);
    Mat dft_img(rows, cols, CV_32FC2, cv::Scalar(0, 0));
    Mat idealHighPassFilter(rows, cols, CV_32FC2, cv::Scalar(0, 0));
    copyMakeBorder(img,img,0,rows-length,0,cols-width,BORDER_CONSTANT,Scalar(0));

    // generate mask
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            double distance = sqrt(pow(i - int(length/2), 2) + pow(j - int(width/2), 2));
            if (distance > cutoff_freq) {
                idealHighPassFilter.at<cv::Vec2f>(i, j)[0] = 1.0;  // 实部设为1
                idealHighPassFilter.at<cv::Vec2f>(i, j)[1] = 1.0;  // 虚部设为1
            }
        }
    }    
    
    dft(img,dft_img,DFT_COMPLEX_OUTPUT);
    fftShift(dft_img,dft_img);
    mulSpectrums(dft_img,idealHighPassFilter,dft_img,0);
    fftShift(dft_img,dft_img);
    dft(dft_img,output,DFT_INVERSE|DFT_SCALE); 
    normalize(output,output,0,255,NORM_MINMAX);
    output.convertTo(output,CV_8UC1);
    return output;
}

double IQA::Daubechies_wavelet()
{
    Daubechies W3(grayImg);
    Scalar mean_LL,mean_LH,mean_HH,var_temp; 
    meanStdDev(W3.LL_Img,mean_LL,var_temp); 
    meanStdDev(W3.LH_Img,mean_LH,var_temp); 
    meanStdDev(W3.HH_Img,mean_HH,var_temp); 
    subtract(abs(W3.HL_Img),mean_LL,W3.HL_Img);
    subtract(abs(W3.LH_Img),mean_LH,W3.LH_Img);
    subtract(abs(W3.HH_Img),mean_HH,W3.HH_Img);
    pow(W3.HL_Img,2,W3.HL_Img);
    pow(W3.LH_Img,2,W3.LH_Img);
    pow(W3.HH_Img,2,W3.HH_Img);
    Scalar d6=(sum(W3.HL_Img)+sum(W3.LH_Img)+sum(W3.HH_Img))/length/width;
    return double(d6[0]);
}

/**
    * module: canny edge detect
    * input: grayImg
    * output: Canny_grad
*/
void IQA::Canny_grad(Mat& Canny_grad,double thrd1,double thrd2)
{
    Mat canny_img=grayImg.clone();
    canny_img=ideal_highpass_filter(canny_img,10); 
    //Mat Canny_grad(canny_img.rows,canny_img.cols, canny_img.type(), cv::Scalar(0));
    Canny(canny_img,Canny_grad,3,thrd1,thrd2);
}

/**
  * module:sobel gradient
  * input:grayImg
  * output:Sobel_grad_x,Sobel_grad_y    
*/
void IQA::Sobel_grad(Mat& Sobel_grad_x, Mat& Sobel_grad_y)
{
    Mat abs_sobel_grad_x,abs_sobel_grad_y,Sobel_grad;
    Mat Sobel_img=grayImg.clone();
    Sobel(Sobel_img, Sobel_grad_x, CV_32FC1, 1, 0);
    Sobel(Sobel_img, Sobel_grad_y, CV_32FC1, 0, 1);
    addWeighted(abs_sobel_grad_x, 0.5, abs_sobel_grad_y, 0.5, 0,Sobel_grad);
}
/**
    * module: laplace gradient
    * input: grayImg
    * output: Laplace_grad_x,Laplace_grad_y
*/
void IQA::Laplace_grad(Mat& Laplace_grad_x,Mat& Laplace_grad_y)
{
    Mat Laplace_img=grayImg.clone();
    Mat Laplace_x_kernal = (Mat_<int>(3, 3) << 0, 0, 0, 1, -2, 1, 0, 0, 0);
    Mat Laplace_y_kernal = (Mat_<int>(3, 3) << 0, 1, 0, 0, -2, 0, 0, 1, 0);
    //Laplace_img=ideal_highpass_filter(Laplace_img,10);
    filter2D(Laplace_img,Laplace_grad_x,CV_8U,Laplace_x_kernal);
    filter2D(Laplace_img,Laplace_grad_y,CV_8U,Laplace_y_kernal);

    Mat Laplace_grad(Laplace_img.rows,Laplace_img.cols, Laplace_img.type(), cv::Scalar(0));
    Laplacian(Laplace_img,Laplace_grad,CV_16S,3);
}

/**
    * module: move the dft spectrum to the center
*/
void fftShift(cv::Mat& input,cv::Mat output) {
    // 获取图像的中心点
    output=input.clone();
    int cx = output.cols / 2;
    int cy = output.rows / 2;

    cv::Rect_<float> q1(cx, cy, cx, cy);
    cv::Rect_<float> q2(0, 0, cx, cy);
    cv::Rect_<float> q3(0, cy, cx, cy);
    cv::Rect_<float> q4(cx, 0, cx, cy);

    // 交换四个象限的内容
    Mat temp;
    output(q1).copyTo(temp);
    output(q2).copyTo(output(q1));
    temp.copyTo(output(q2));

    output(q3).copyTo(temp);
    output(q4).copyTo(output(q3));
    temp.copyTo(output(q4));
}
