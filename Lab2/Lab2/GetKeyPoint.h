#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace std;
using namespace cv;

int findMaxValue(Mat mat);

vector<KeyPoint> convertHarrisMatToKeyPoints(Mat mat);