#include "LocalBinaryPattern.h"
#include "ImageHelper.h"

vector<DMatch> lbp(Mat gray1, vector<KeyPoint> kp1, Mat gray2, vector<KeyPoint> kp2) {
    Mat des1, des2;
    vector<vector<DMatch>> matches;
    Ptr<BRISK> brisk = BRISK::create();

    brisk->compute(gray1, kp1, des1);
    brisk->compute(gray2, kp2, des2);

    BFMatcher bf;
    bf.knnMatch(des1, des2, matches, 2);

    vector<DMatch> goodMatches;

    for (int i = 0; i < matches.size(); i++) {
        float rejectRatio = 0.8;
        if (matches[i][0].distance / matches[i][1].distance > rejectRatio)
            continue;
        goodMatches.push_back(matches[i][0]);
    }

    return goodMatches;
}