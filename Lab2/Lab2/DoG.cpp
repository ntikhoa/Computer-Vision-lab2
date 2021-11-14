#include "DoG.h"
#include "ImageHelper.h"

void performDoG(String fileName) {
    Mat img = readImg(fileName);

    namedWindow("Show Image");
    int pos = 50;
    createTrackbar("Tracbar", "Show Image", &pos, 50,
        OnTrackbarDoG, &img);

    waitKey(0);
}

void OnTrackbarDoG(int pos, void* userData) {
    Mat img = *(static_cast <Mat*>(userData));

    vector<KeyPoint> kp;
    kp = getDoGkeyPoints(img, pos);

    Mat res;
    drawKpGreen(img, kp, res);

    imshow("Show Image", res);
}

vector<KeyPoint> getDoGkeyPoints(Mat img, double sigma) {
    vector<KeyPoint> keyPoints;

    Mat gray = grayImg(img);
    
    Ptr<SIFT> sift = SIFT::create(0, 3, 0.04, 10, sigma);
    sift->detect(gray, keyPoints);
    
    return keyPoints;
}