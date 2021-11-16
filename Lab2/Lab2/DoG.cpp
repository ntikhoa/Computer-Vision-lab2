#include "DoG.h"
#include "ImageHelper.h"
#include "VideoHelper.h"

void performDoG(String fileName) {
    Mat img, gray;
    VideoCapture cap;

    bool isCamera = false;
    if (fileName == "") {
        isCamera = true;
        cap = getVideoCapture();
    }
    else {
        img = readImg(fileName);
        gray = grayImg(img);
    }

    int prevPos = -1;
    int pos = 2;
    namedWindow("Show Image");
    createTrackbar("Tracbar", "Show Image", &pos, 50);

    while (getWindowProperty("Show Image", WND_PROP_VISIBLE) > 0) {
        
        if (isCamera) {
            cap.read(img);
            gray = grayImg(img);
        }

        if (prevPos != pos || isCamera) {
            vector<KeyPoint> kp;
            kp = getDoGkeyPoints(gray, pos);

            Mat res;
            drawKpGreen(img, kp, res);

            imshow("Show Image", res);
            prevPos = pos;
        }
        waitKey(2000);
    }

    waitKey(0);
}

vector<KeyPoint> getDoGkeyPoints(Mat gray, double sigma) {
    vector<KeyPoint> keyPoints;
    
    Ptr<SIFT> sift = SIFT::create(0, 3, 0.04, 10, sigma);
    sift->detect(gray, keyPoints);
    
    return keyPoints;
}