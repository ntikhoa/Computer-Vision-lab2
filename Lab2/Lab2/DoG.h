#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void performDoG(String fileName);

vector<KeyPoint> getDoGkeyPoints(Mat gray, double sigma);