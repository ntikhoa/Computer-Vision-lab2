#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/features2d/features2d.hpp>
using namespace std;
using namespace cv;

class LBP {
    void compute(Mat src, Mat& dst);
};