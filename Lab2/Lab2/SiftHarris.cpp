#include "SiftHarris.h"
#include "SiftDescriptor.h"
#include "ImageHelper.h"
#include "Harris.h"

void harrisDetectorWithSiftDescriptor(String fileName1, String fileName2) {
    Mat img1 = readImg(fileName1);
    Mat img2 = readImg(fileName2);
    Mat gray1 = grayImg(img1);
    Mat gray2 = grayImg(img2);

    int prevPos = -1;
    int pos = 3;
    namedWindow("Show Image");
    createTrackbar("Tracbar", "Show Image", &pos, 30);

    while (getWindowProperty("Show Image", WND_PROP_VISIBLE) > 0) {
        if (pos % 2 == 0) {
            pos = pos + 1;
        }
        if (prevPos != pos) {

            vector<KeyPoint> kp1, kp2;

            kp1 = getHarrisKeyPoints(gray1, pos);
            kp2 = getHarrisKeyPoints(gray2, pos);

            vector<DMatch> good = sift(gray1, kp1, gray2, kp2);

            Mat res;
            drawMatches(img1, kp1, img2, kp2, good, res);

            imshow("Show Image", res);

            prevPos = pos;
        }
        waitKey(2000);
    }
    waitKey(0);
}