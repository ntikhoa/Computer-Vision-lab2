#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

Mat readImg(String fileName);

Mat grayImg(Mat img);

void drawKpGreen(Mat img, vector<KeyPoint> kp, Mat& res);