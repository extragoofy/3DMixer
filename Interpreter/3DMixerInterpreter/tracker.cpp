#include "tracker.h"
#include <QDebug>

using namespace cv;
using namespace std;

Tracker::Tracker()
{
    initializeKnobs();
    activeView = 0;
}

Mat Tracker::process(const Mat &input) {

    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    //for (int i = 0; i < 4; i++) {
    //    if (knobs[i].active) {
            Mat binaryMask = colorKeying(0, hsvFrame);
            medianBlur(binaryMask, binaryMask, 5);
            erode(binaryMask, binaryMask, Mat());
            dilate(binaryMask, binaryMask, Mat());
            centerOfMass(0, binaryMask);
    //    }
    //}

    // convert binary Image to 3 channel image
    Mat output;
    cvtColor(binaryMask, output, CV_GRAY2BGR);
    drawCross(output, center, 5, Scalar(0, 0, 255));

    return output;
}

void Tracker::updateKnobParameters(const QVector<int> &paramData) {
    for (int i = 0; i < 4; i++) {
        knobs[i].active = paramData[i*7];
        knobs[i].color_minHue = paramData[i*7+1] / 2;
        knobs[i].color_maxHue = paramData[i*7+2] / 2;
        knobs[i].color_minSat = paramData[i*7+3] * 2.55;
        knobs[i].color_maxSat = paramData[i*7+4] * 2.55;
        knobs[i].color_minVal = paramData[i*7+5] * 2.55;
        knobs[i].color_maxVal = paramData[i*7+6] * 2.55;
    }
}

void Tracker::updateCoordData(QVector<int> &data) {
    for (int i = 0; i < 4; i++) {
        data[i*3] = knobs[i].xCoords;
        data[i*3+1] = knobs[i].yCoords;
        data[i*3+2] = knobs[i].zCoords;
    }
}

void Tracker::setView(int id) {
    activeView = id;
}

Mat Tracker::colorKeying(int knobID, Mat& hsvFrame) {
    // initialize Mat object for output
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            Vec3b hsvPixel = hsvFrame.at<Vec3b>(y,x);
            int hue = hsvPixel[0];
            int saturation = hsvPixel[1];
            int value = hsvPixel[2];

            // Maskierung und Schwerpunktsberechnung
            bool isWhite = false;
            if (knobs[knobID].color_minVal <= value <= knobs[knobID].color_maxVal) {
                if (knobs[knobID].color_minSat <= saturation <= knobs[knobID].color_maxSat) {
                    if (knobs[knobID].color_minHue < knobs[knobID].color_maxHue) {
                        if (hue >= knobs[knobID].color_minHue && hue <= knobs[knobID].color_maxHue){
                            isWhite = true;
                        }
                    }
                    else {
                        if (hue >= knobs[knobID].color_minHue || hue <= knobs[knobID].color_maxHue){
                            isWhite = true;
                        }
                    }
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

void Tracker::centerOfMass(int knobID, Mat& image){
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
        center = Point(sumx/count, sumy/count);
    } else {
        center = Point(0,0);
    }
    knobs[knobID].xCoords = center.x;
    knobs[knobID].yCoords = center.y;
}

void Tracker::drawCross(Mat& image, Point center, int length, Scalar color){
    line(image, center-Point(0, length), center+Point(0,length), color, 1);
    line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
}

void Tracker::initializeKnobs() {
    knobs = QVector<knob>(4);
    for (int i = 0; i < 4; i++) {
        knobs[i].active = false;
        knobs[i].color_minHue = 0;
        knobs[i].color_maxHue = 0;
        knobs[i].color_minSat = 0;
        knobs[i].color_maxSat = 0;
        knobs[i].color_minVal = 0;
        knobs[i].color_maxVal = 0;
        knobs[i].xCoords = 0;
        knobs[i].yCoords = 0;
        knobs[i].zCoords = 0;
    }
}
