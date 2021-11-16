#pragma once
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void performBlob(String fileName);

vector<KeyPoint> getBlobKeyPoints(Mat gray, int minArea);

Ptr<SimpleBlobDetector> createSimpleBlobDetector(int minArea);