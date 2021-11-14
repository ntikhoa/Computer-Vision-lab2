#include "SiftBlob.h"
#include "SiftDescriptor.h"
#include "ImageHelper.h"
#include "Blob.h"


void blobDetectorWithSiftDescriptor(String fileName1, String fileName2) {
    Mat img1 = readImg(fileName1);
    Mat img2 = readImg(fileName2);

    vector<KeyPoint> kp1, kp2;
    kp1 = getBlobKeyPoints(img1, 0);
    kp2 = getBlobKeyPoints(img2, 0);

    vector<DMatch> good = sift(img1, kp1, img2, kp2);

    Mat result;
    drawMatches(img1, kp1, img2, kp2, good, result);

    imshow("Show Image", result);
    waitKey(0);
}