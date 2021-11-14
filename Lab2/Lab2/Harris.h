#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void performHarris(String fileName);

void OnTrackbarHarris(int pos, void* userData);

vector<KeyPoint> getHarrisKeyPoints(Mat img, int apertureSize);

vector<KeyPoint> calculateHarrisKeyPoints(Mat img);

float findMaxResVal(Mat img);