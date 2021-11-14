#pragma once
#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
using namespace cv;
using namespace std;

void harrisDetectorWithSiftDescriptor(String fileName1, String fileName2);

void OnTrackbarSiftHarris(int pos, void* userData);