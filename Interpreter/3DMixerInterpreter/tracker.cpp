#include "tracker.h"
#include <QDebug>

using namespace cv;
using namespace std;

Tracker::Tracker():
    hueUpperThreshold(90),
    hueLowerThreshold(70),
    saturationThreshold(220),
    alpha(0),
    useMedian(false),
    useOpening(false)
{
    initializeKnobs();
}

void Tracker::updateKnobParameters(int knobIndex, bool active, float hue, float sat, float val) {
    knobs[knobIndex].active = active;
    knobs[knobIndex].color_hue = hue;
    knobs[knobIndex].color_sat = sat;
    knobs[knobIndex].color_val = val;
}

Mat Tracker::process(const Mat &input) {
    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    // perform color keying
    Mat binaryMask = colorKeying(hsvFrame);

    if (useMedian){
        medianBlur(binaryMask, binaryMask, 5);
    }

    if (useOpening){
        erode(binaryMask, binaryMask, Mat());
        dilate(binaryMask, binaryMask, Mat());
    }

    // calculate center of mass
    centerOfMass(binaryMask);

    // convert binary Image to 3 channel image
    Mat output;
    cvtColor(binaryMask, output, CV_GRAY2BGR);
    drawCross(output, center, 5, Scalar(0, 0, 255));

    return output;
}

Mat Tracker::colorKeying(Mat& hsvFrame) {
    // initialize Mat object for output
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            /*
            // Maskierung und Schwerpunktsberechnung
            bool isWhite = false;
            if (saturation > saturationThreshold){
                if (hueLowerThreshold < hueUpperThreshold){
                    if (hue >= hueLowerThreshold && hue <= hueUpperThreshold){
                        isWhite = true;
                    }
                }
                else {
                    if (hue >= hueLowerThreshold || hue <= hueUpperThreshold){
                        isWhite = true;
                    }
                }
            }
            */

            bool isWhite = false;
            if (saturation > knobs[0].color_sat) {
                if (hue >= knobs[0].color_hue - 10 && hue <= knobs[0].color_hue + 10) {
                    isWhite = true;
                }
            }

            if (isWhite){
                output.at<uchar>(y,x) = 255;
            }
            else{
                output.at<uchar>(y,x) = 0;
            }
        }
    }
    return output;
}

void Tracker::initializeKnobs() {
    for (int i = 0; i < 4; i++) {
        knobs[i].active = false;
        knobs[i].color_hue = 0.0;
        knobs[i].color_sat = 0.0;
        knobs[i].color_val = 0.0;
    }
}

void Tracker::centerOfMass(Mat& image){
    int sumx = 0;
    int sumy = 0;
    int count = 0;
    for(int x = 0; x < image.cols; x++){
        for (int y = 0; y < image.rows; y++){
            if (image.at<uchar>(y,x) == 255){
                sumx += x;
                sumy += y;
                count++;
            }
        }
    }
    if (count > 0){
        center = (1 - alpha) * center + alpha * Point(sumx/count, sumy/count);

    }
}

void Tracker::drawCross(Mat& image, Point center, int length, Scalar color){
    line(image, center-Point(0, length), center+Point(0,length), color, 1);
    line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
}
