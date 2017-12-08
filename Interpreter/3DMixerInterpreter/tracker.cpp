#include "tracker.h"
#include <QDebug>

using namespace cv;

Tracker::Tracker()
{
}

Mat Tracker::process(const Mat &input) {
    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    // initialize Mat object for output
    Mat output(input.rows, input.cols, CV_8UC3);

    return output;
}

void Tracker::drawCross(Mat& image, Point center, int length, Scalar color){
    line(image, center-Point(0, length), center+Point(0,length), color, 1);
    line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
}
