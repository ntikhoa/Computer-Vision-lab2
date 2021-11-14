#include "Harris.h"
#include "ImageHelper.h"

void performHarris(String fileName) {
    Mat img = readImg(fileName);

    namedWindow("Show Image");
    int pos = 3;
    createTrackbar("Tracbar", "Show Image", &pos, 30, 
        OnTrackbarHarris, &img);

    waitKey(0);
}

void OnTrackbarHarris(int pos, void* userData) {
    Mat img = *(static_cast <Mat*>(userData));

    if (pos % 2 == 0) {
        pos = pos - 1;
    }

    vector<KeyPoint> kp;
    kp = getHarrisKeyPoints(img, pos);

    Mat res;
    drawKpGreen(img, kp, res);

    imshow("Show Image", res);
}

vector<KeyPoint> getHarrisKeyPoints(Mat img, int apertureSize) {
    vector<KeyPoint> kp;

    Mat gray = grayImg(img);

    Mat res;
    cornerHarris(gray, res, 2, apertureSize, 0.04);
    kp = calculateHarrisKeyPoints(res);
    return kp;
}

vector<KeyPoint> calculateHarrisKeyPoints(Mat img) {
    float max = findMaxResVal(img);

    vector<KeyPoint> kp;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            if (img.at<float>(i, j) >= max * 0.01) {
                kp.push_back(KeyPoint(j, i, 1));
            }
        }
    }
    return kp;
}

float findMaxResVal(Mat img) {
    float maxValue = -1e9;
    for (int i = 0; i < img.rows; i++) {
        for (int j = 0; j < img.cols; j++) {
            maxValue = max(maxValue, img.at<float>(i, j));
        }
    }
    return maxValue;
}
