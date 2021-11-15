#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

void harrisDetectorWithSiftDescriptor(String fileName1, String fileName2);

vector<DMatch> sift(Mat gray1, vector<KeyPoint> kp1, Mat gray2, vector<KeyPoint> kp2);