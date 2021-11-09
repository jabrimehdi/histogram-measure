#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>
usingnamespace std;
int main(){
cv::Mat img1 = cv::imread("C:/Users/jabri/Desktop/pic20154.jpg");
vector<cv::Mat>bgr_planes;
split( img1, bgr_planes );
inthistosize = 256;
float rang[] = { 0, 256 } ;
constfloat* histogrmme = { rang };
cv::Mat b_hist, v_hist, r_hist;
calcHist( &bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histosize, &histogrmme, true, false );
calcHist( &bgr_planes[1], 1, 0, cv::Mat(), v_hist, 1, &histosize, &histogrmme, true, false );
calcHist( &bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histosize, &histogrmme, true , false );
inthist_w = 512; inthist_h = 400;
intbin_w = cvRound( (double) hist_w/histosize );
cv::Mat histImage( hist_h, hist_w, CV_8UC3, cv::Scalar( 0,0,0) );
normalize(b_hist, b_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
normalize(v_hist, v_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
normalize(r_hist, r_hist, 0, histImage.rows, cv::NORM_MINMAX, -1, cv::Mat() );
for(int i = 1; i <histosize; i++ )
{ cv::line(histImage, cv::Point( bin_w*(i -1), 400 - cvRound(b_hist.at<float>(i-1)) ) ,
cv::Point(bin_w*(i), 400 - cvRound(b_hist.at<float>(i)) ),
cv::Scalar( 255, 0, 0), 2, 8, 0 );
cv::line(histImage, cv::Point( bin_w*(i -1), 400 - cvRound(v_hist.at<float>(i -1)) ) ,
cv::Point(bin_w*(i), 400 - cvRound(v_hist.at<float>(i)) ),
cv::Scalar( 0, 255, 0), 2, 8, 0 );
cv::line(histImage, cv::Point( bin_w*(i -1), 400 - cvRound(r_hist.at<float>(i -1)) ) ,
cv::Point(bin_w*(i), 400 - cvRound(r_hist.at<float>(i)) ),
cv::Scalar( 0, 0, 255), 2, 8, 0 ); }
cv::imshow ( "Mehdi Pic" , img1);
cv::imshow ( "histogramme" , histImage);
cv::waitKey ();
return EXIT_SUCCESS;
}