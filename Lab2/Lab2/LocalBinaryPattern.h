#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/features2d/features2d.hpp>
using namespace std;
using namespace cv;


vector<DMatch> lbp(Mat gray1, vector<KeyPoint> kp1, Mat gray2, vector<KeyPoint> kp2);