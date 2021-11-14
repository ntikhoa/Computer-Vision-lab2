#include "Blob.h"
#include "ImageHelper.h"

void performBlob(String fileName) {
    Mat img = readImg(fileName);

    namedWindow("Show Image");
    int pos = 1;
    createTrackbar("Tracbar", "Show Image", &pos, 100,
        OnTrackbarBlob, &img);

    waitKey(0);
}

void OnTrackbarBlob(int pos, void* userData) {
    Mat img = *(static_cast <Mat*>(userData));

    vector<KeyPoint> kp;
    kp = getBlobKeyPoints(img, pos);

    Mat res;
    drawKpGreen(img, kp, res);

    imshow("Show Image", res);
}

vector<KeyPoint> getBlobKeyPoints(Mat img, int minArea) {
    vector<KeyPoint> keyPoints;

    Mat gray = grayImg(img);

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