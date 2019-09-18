#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <opencv2/videoio.hpp>
#include <opencv/cv.hpp>
#include <stdio.h>
#include "FrameDifferenceBGS.h"

using namespace cv;

int main(int argc, char **argv) {
    VideoCapture m = VideoCapture(0);
    IBGS *bgs;
    bgs = new FrameDifferenceBGS;
    Mat frame;
    while (1) {
        m >> frame;
        cv::Mat img_input = frame.clone();
        cv::imshow("Input", img_input);
        cv::Mat img_mask;
        cv::Mat img_bkgmodel;
        // by default, it shows automatically the foreground mask image
        bgs->process(img_input, img_mask, img_bkgmodel);
        //if(!img_mask.empty())
        //  cv::imshow("Foreground", img_mask);
        //  do something
        if (cvWaitKey(33) >= 0)
            break;
    }

    delete bgs;

    cvDestroyAllWindows();

    return 0;
}