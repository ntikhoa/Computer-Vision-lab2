#include "VideoHelper.h"

VideoCapture getVideoCapture() {
    VideoCapture cap;
    int deviceID = 0;
    int apiID = cv::CAP_ANY;
    cap.open(deviceID, apiID);
    
    return cap;
}