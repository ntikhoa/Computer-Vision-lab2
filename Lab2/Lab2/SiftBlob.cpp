#include "SiftBlob.h"
#include "SiftDescriptor.h"
#include "Blob.h"
#include "ImageHelper.h"
#include "VideoHelper.h"


void blobDetectorWithSiftDescriptor(String fileName1, String fileName2) {
    Mat img1 = readImg(fileName1);
    Mat gray1 = grayImg(img1);

    Mat img2, gray2;

    VideoCapture cap;

    bool isCamera = false;
    if (fileName2 == "") {
        isCamera = true;
        cap = getVideoCapture();
    }
    else {
        img2 = readImg(fileName2);
        gray2 = grayImg(img2);
    }

    int pos = 1;
    int prevPos = -1;
    namedWindow("Show Image");
    createTrackbar("Tracbar", "Show Image", &pos, 100);

    while (getWindowProperty("Show Image", WND_PROP_VISIBLE) > 0) {
        if (isCamera) {
            cap.read(img2);
            gray2 = grayImg(img2);
        }

        if (prevPos != pos || isCamera) {
            vector<KeyPoint> kp1, kp2;
            kp1 = getBlobKeyPoints(gray1, pos);
            kp2 = getBlobKeyPoints(gray2, pos);

            vector<DMatch> good = sift(gray1, kp1, gray2, kp2);

            Mat result;
            drawMatches(img1, kp1, img2, kp2, good, result);
            imshow("Show Image", result);

            prevPos = pos;
        }
        waitKey(2000);
    }
    waitKey(0);
}