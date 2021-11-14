#include "SiftHarris.h"
#include "SiftDescriptor.h"
#include "ImageHelper.h"
#include "Harris.h"

void harrisDetectorWithSiftDescriptor(String fileName1, String fileName2) {
    Mat img1 = readImg(fileName1);
    Mat img2 = readImg(fileName2);

    vector<KeyPoint> kp1, kp2;

    kp1 = getHarrisKeyPoints(img1, 3);
    kp2 = getHarrisKeyPoints(img2, 3);

    vector<DMatch> good = sift(img1, kp1, img2, kp2);

    Mat res;
    drawMatches(img1, kp1, img2, kp2, good, res);

    imshow("Show Image", res);
    waitKey(0);
}

void OnTrackbarSiftHarris(int pos, void* userData) {
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