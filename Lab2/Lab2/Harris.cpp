#include "Harris.h"
#include "ImageHelper.h"

void performHarris(String fileName) {
    Mat img = readImg(fileName);
    Mat gray = grayImg(img);

    int prevPos = -1;
    int pos = 3;
    namedWindow("Show Image");
    createTrackbar("Tracbar", "Show Image", &pos, 30);

    while (getWindowProperty("Show Image", WND_PROP_VISIBLE) > 0) {
        if (pos % 2 == 0) {
            pos = pos + 1;
        }
        if (prevPos != pos) {
            vector<KeyPoint> kp;
            kp = getHarrisKeyPoints(gray, pos);

            Mat res;
            drawKpGreen(img, kp, res);

            imshow("Show Image", res);
            prevPos = pos;
        }
        waitKey(2000);
    }

    waitKey(0);
}

vector<KeyPoint> getHarrisKeyPoints(Mat gray, int apertureSize) {
    vector<KeyPoint> kp;

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
            if (img.at<float>(i, j) >= max * 0.04) {
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
