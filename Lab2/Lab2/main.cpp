#include "Harris.h"
#include "Blob.h"
#include "DoG.h"
#include "SiftDescriptor.h"
#include "SiftHarris.h"
#include "SiftDoG.h"
#include "SiftBlob.h"
#include <opencv2/videoio.hpp>


int main(int argc, char* argv[])
{
    //performHarris("headpat_rem.jpg");
    //performDoG("headpat_rem.jpg");
    //performBlob("headpat_rem.jpg");

    //harrisDetectorWithSiftDescriptor("text_in_scene.jpg", "headpat_rem.jpg");
    //DoGdetectorWithSiftDescriptor("text_in_scene.jpg", "headpat_rem.jpg");
    //blobDetectorWithSiftDescriptor("headpat_rem_croped.jpg", "headpat_rem.jpg");

    
    Mat frame;
    VideoCapture cap;
    int deviceID = 0;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    cap.open(deviceID, apiID);
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    namedWindow("Live");
    while(getWindowProperty("Live", WND_PROP_VISIBLE) > 0)
    {
        cap.read(frame);
        imshow("Live", frame);
        waitKey(5);
    }
    
    return 0;
}