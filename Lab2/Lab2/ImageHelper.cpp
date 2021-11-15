#include "ImageHelper.h"


Mat readImg(String fileName) {
	return imread(fileName, IMREAD_COLOR);
}

Mat grayImg(Mat img) {
	Mat gray;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	return gray;
}

void drawKpGreen(Mat img, vector<KeyPoint> kp, Mat& res) {
	drawKeypoints(img, kp, res, Scalar(0, 255, 0), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
}