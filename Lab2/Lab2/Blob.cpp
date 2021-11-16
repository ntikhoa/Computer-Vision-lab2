#include "Blob.h"
#include "ImageHelper.h"
#include "VideoHelper.h"

void performBlob(String fileName) {
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

    int pos = 1;
    int prevPos = -1;
    namedWindow("Show Image");
    createTrackbar("Tracbar", "Show Image", &pos, 100);

    while (getWindowProperty("Show Image", WND_PROP_VISIBLE) > 0) {

        if (isCamera) {
            cap.read(img);
            gray = grayImg(img);
        }

        if (prevPos != pos || isCamera) {
            vector<KeyPoint> kp;
            kp = getBlobKeyPoints(gray, pos);

            Mat res;
            drawKpGreen(img, kp, res);

            imshow("Show Image", res);
            prevPos = pos;
        }
        waitKey(2000);
    }

    waitKey(0);
}

vector<KeyPoint> getBlobKeyPoints(Mat gray, int minArea) {
    vector<KeyPoint> keyPoints;

    Ptr<SimpleBlobDetector> detector = createSimpleBlobDetector(minArea);

    detector->detect(gray, keyPoints);

    return keyPoints;
}

Ptr<SimpleBlobDetector> createSimpleBlobDetector(int minArea) {

    SimpleBlobDetector::Params params;


    params.filterByArea = true;
    params.minArea = minArea;
    params.maxArea = 10000;

    //params.filterByColor = true;
    
    params.minThreshold = 0;
    params.maxThreshold = 100;

    params.filterByCircularity = true;
    params.minCircularity = 0.1;
    params.maxCircularity = 1;

    params.filterByConvexity = true;
    params.minConvexity = 0.2;
    params.maxConvexity = 1.0;
    
    params.filterByInertia = true;
    params.minInertiaRatio = 0.01;
    params.maxInertiaRatio = 1.0;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);
    return detector;
}