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
    for (int i = 0; i < 12; i++) {
        data[i] = knobs[i/3].xCoords;
        data[i] = knobs[i/3].yCoords;
        data[i] = knobs[i/3].zCoords;
    }
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
            if (saturation > knobs[0].color_minSat) {
                if (hue >= knobs[0].color_minHue - 10 && hue <= knobs[0].color_minHue + 10) {
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
    for (int i = 0; i < 12; i++) {
        knobs[i/3].xCoords = qrand();
        knobs[i/3].yCoords = qrand();
        knobs[i/3].zCoords = qrand();
    }
    return output;
}

void Tracker::initializeKnobs() {
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
