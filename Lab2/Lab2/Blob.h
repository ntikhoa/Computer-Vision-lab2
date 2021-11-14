#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void performBlob(String fileName);

vector<KeyPoint> getBlobKeyPoints(Mat img, int minArea);

void OnTrackbarBlob(int pos, void* userData);

Ptr<SimpleBlobDetector> createSimpleBlobDetector(int minArea);