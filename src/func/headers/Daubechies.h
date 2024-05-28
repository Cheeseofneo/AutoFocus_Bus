#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

typedef unsigned char BYTE;
using namespace cv;

class Daubechies
{
public:
	double C0, C1, C2, C3, C4, C5;
	int nWidth;
	int nHeight;
    int width;
    int height;
	cv::Mat LL_Img;
	cv::Mat LH_Img;
	cv::Mat HH_Img;
	cv::Mat HL_Img;
public:
	void change_int(cv::Mat inImage);
	void Daub6b(cv::Mat inImage);
	void convert_mat_to_array(cv::Mat inImage);
	Daubechies(cv::Mat input_img);
	~Daubechies();
private:
	double **m_TempImg; 
	double **m_LowImg;
    Mat Hout1,Hout2,Hout3,Hout4;
    Mat temp_Img; // IMAGE TO PROCESS

};