#include "tracker.h"
#include <QDebug>

using namespace cv;
using namespace std;

Tracker::Tracker()
{
    initializeKnobs();
    binaryFrames = QVector<cv::Mat>(5);
    activeView = 0;
    radius = 0;
    useBlur = true;
    useErode = true;
    useDilate = true;
}

Mat Tracker::process(const Mat &input) {

    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);

    for (int i = 0; i < 4; i++) {
        if (knobs[i].active) {
            binaryFrames[i] = colorKeying(i, hsvFrame);
            if (useBlur) medianBlur(binaryFrames[i], binaryFrames[i], 5);
            if (useErode) erode(binaryFrames[i], binaryFrames[i], Mat());
            if (useDilate) dilate(binaryFrames[i], binaryFrames[i], Mat());
            centerOfMass(i, binaryFrames[i]);
            getRadius(i, binaryFrames[i]);
        }
        // Reset knob data if knob is turned off.
        // This is done here since blur, erode and dilate may take up to a second to calculate
        // and state might have changed during that
        if (!knobs[i].active) {
            knobs[i].xCoords = 0;
            knobs[i].yCoords = 0;
            knobs[i].zCoords = 0;
        }
    }

    // convert binary Image to 3 channel image
    Mat output;
    cvtColor(binaryFrames[activeView], output, CV_GRAY2BGR);
    drawCross(output, center, 5, Scalar(0, 0, 255));
    circle(output, center, radius, Scalar(0, 0, 255));

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

void Tracker::getCoordDataToSend(int knobID, uchar &x, uchar &y, uchar &z) {
    x = knobs[knobID].xCoords;
    y = knobs[knobID].yCoords;
    z = knobs[knobID].zCoords;
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
}

void Tracker::drawCross(Mat& image, Point center, int length, Scalar color){
    line(image, center-Point(0, length), center+Point(0,length), color, 1);
    line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
}

void Tracker::getRadius(int knobID, cv::Mat& image) {
    int sum = 0;
    // Measure radius from center right
    int y = center.y;
    for (int x = center.x + 1; x < image.cols; x++) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Measure radius from center left
    for (int x = center.x - 1; x >= 0; x--) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Measure radius from center down
    int x = center.x;
    for (int y = center.y + 1; y < image.rows; y++) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Measure radius from center up
    for (int y = center.y - 1; y >= 0; y--) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Divide by 4 to get average radius in all directions
    radius = sum / 4;
    // Apply to knob record and break down to fit a 1-byte-value (up to 127)
    knobs[knobID].xCoords = center.x / 5;
    knobs[knobID].yCoords = center.y / 3.76;
    knobs[knobID].zCoords = radius / 2.2;
    if (knobs[knobID].zCoords > 127) knobs[knobID].zCoords = 127;
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
