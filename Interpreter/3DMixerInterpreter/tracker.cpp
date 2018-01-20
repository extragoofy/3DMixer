#include "tracker.h"

using namespace std;
using namespace cv;

Tracker::Tracker()
    : useBlur(true)
    , useErode(true)
    , useDilate(true)
    , activeView(0)
    , knobParams(QVector<KnobParams>(4))
    , knobData(QVector<KnobData>(4))
    , knobCoords(QVector<KnobCoords>(4))
{
}

Mat Tracker::process(const Mat& input) {

    // convert BGR -> HSV
    Mat hsvFrame;
    cvtColor(input, hsvFrame, CV_BGR2HSV);
/*
    for (int i = 0; i < 4; i++) {
        if (knobParams[i].active) {
            knobData[i].binaryFrame = colorKeying(i, hsvFrame);
            if (useBlur) medianBlur(knobData[i].binaryFrame, knobData[i].binaryFrame, 5);
            if (useErode) erode(knobData[i].binaryFrame, knobData[i].binaryFrame, Mat());
            if (useDilate) dilate(knobData[i].binaryFrame, knobData[i].binaryFrame, Mat());
            centerOfMass(i, knobData[i].binaryFrame);
            radius(i, knobData[i].binaryFrame);
            // convert binary Image to 3 channel image
            cvtColor(knobData[activeView].binaryFrame, knobData[activeView].binaryFrame, CV_GRAY2BGR);
            drawCross(knobData[activeView].binaryFrame, knobData[i].center, 5, knobData[i].rgbColor);
            circle(knobData[activeView].binaryFrame, knobData[i].center, knobData[i].radius, knobData[i].rgbColor);
        }
        // Reset knob data if knob is turned off.
        // This is done here since blur, erode and dilate may take up to a second to calculate
        // and state might have changed during that
        if (!knobParams[i].active) {
            knobCoords[i].x = 0;
            knobCoords[i].y = 0;
            knobCoords[i].z = 0;
        }
    }

    return knobData[activeView].binaryFrame;
*/
    return input;

}

void Tracker::updateKnobParams(const QVector<uchar>& paramData) {

    for (int i = 0; i < 4; i++) {
        knobParams[i].active = paramData[i*7];
        knobParams[i].minHue = paramData[i*7+1];
        knobParams[i].maxHue = paramData[i*7+2];
        knobParams[i].minSat = paramData[i*7+3];
        knobParams[i].maxSat = paramData[i*7+4];
        knobParams[i].minVal = paramData[i*7+5];
        knobParams[i].maxVal = paramData[i*7+6];

        uchar averageHue = 0;
        if (knobParams[i].minHue < knobParams[i].maxHue) {
            averageHue = (knobParams[i].minHue + knobParams[i].maxHue) / 2;
        } else {
            averageHue = (knobParams[i].minHue + knobParams[i].maxHue + 180) / 2 - 180;
        }
        hueToBGR(averageHue, knobData[i].rgbColor);
    }

}

const QVector<Tracker::KnobCoords>& Tracker::getKnobCoords() {
    return knobCoords;
}

/*
void Tracker::updateCoordData(QVector<int> &data) {
    for (int i = 0; i < 4; i++) {
        data[i*3] = knobs[i].xCoords;
        data[i*3+1] = knobs[i].yCoords;
        data[i*3+2] = knobs[i].zCoords;
    }
}
*/

/*
void Tracker::getCoordDataToSend(const int& knobID, uchar& x, uchar& y, uchar& z) {
    x = knobs[knobID].xCoords;
    y = knobs[knobID].yCoords;
    z = knobs[knobID].zCoords;
}
*/

Mat Tracker::colorKeying(const int& knobID, const Mat& hsvFrame) {

    // Initialize Mat object for output
    Mat output(hsvFrame.rows, hsvFrame.cols, CV_8UC1);

    Vec3b hsvPixel;
    int hue;
    int sat;
    int val;
    bool drawWhite;

    for(int x = 0; x < hsvFrame.cols; x++){
        for(int y = 0; y < hsvFrame.rows; y++){
            hsvPixel = hsvFrame.at<Vec3b>(y,x);
            hue = hsvPixel[0];
            sat = hsvPixel[1];
            val = hsvPixel[2];
            drawWhite = false;
            if (knobParams[knobID].minVal <= val && val <= knobParams[knobID].maxVal) {
                if (knobParams[knobID].minSat <= sat && sat <= knobParams[knobID].maxSat) {
                    if (knobParams[knobID].minHue < knobParams[knobID].maxHue) {
                        if (knobParams[knobID].minHue <= hue && hue <= knobParams[knobID].maxHue){
                            drawWhite = true;
                        }
                    }
                    else {
                        if (hue >= knobParams[knobID].minHue || hue <= knobParams[knobID].maxHue){
                            drawWhite = true;
                        }
                    }
                }
            }
            if (drawWhite){
                output.at<uchar>(y,x) = 255;
            }
            // NÖTIG?
            else{
                output.at<uchar>(y,x) = 0;
            }
        }
    }

    return output;

}

void Tracker::centerOfMass(const int& knobID, const Mat& image) {

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
        knobData[knobID].center = Point(sumx/count, sumy/count);
    } else {
        knobData[knobID].center = Point(0,0);
    }
}

void Tracker::radius(const int& knobID, const Mat& image) {

    int sum = 0;
    int x = 0;
    int y = 0;

    // Measure radius from center right
    y = knobData[knobID].center.y;
    for (x = knobData[knobID].center.x + 1; x < image.cols; x++) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Measure radius from center left
    for (x = knobData[knobID].center.x - 1; x >= 0; x--) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }

    // Measure radius from center down
    x = knobData[knobID].center.x;
    for (y = knobData[knobID].center.y + 1; y < image.rows; y++) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }
    // Measure radius from center up
    for (y = knobData[knobID].center.y - 1; y >= 0; y--) {
        if (image.at<uchar>(y,x) == 255) {
            sum++;
        } else {
            break;
        }
    }

    // Divide by 4 to get average radius in all directions
    knobData[knobID].radius = sum / 4;

}

// Convert data to knob coords and break down to fit a 7-bit-value (up to 127)
void Tracker::calculateCoords(const int& knobID) {
    knobCoords[knobID].x = knobData[knobID].center.x / 5;
    knobCoords[knobID].y = knobData[knobID].center.y / 3.76;
    knobCoords[knobID].z = knobData[knobID].radius / 2.2;           // DYNAMISCH!?
    if (knobCoords[knobID].z > 127) knobCoords[knobID].z = 127;     // Catch rare case where radius might be too big
}

void Tracker::drawCross(Mat& image, const Point& center, const int& length, const Scalar& color){
    line(image, center-Point(0, length), center+Point(0,length), color, 1);
    line(image, center-Point(length, 0), center+Point(length, 0), color, 1);
}

void Tracker::hueToBGR(const uchar& hue, Scalar& bgr) {
    if (hue <= 30) {
        bgr[0] = 0;                         // 0
        bgr[1] = 255 - (30 - hue) * 8.5;    // Rising
        bgr[2] = 255;                       // 255
    } else if (hue <= 60) {
        bgr[0] = 0;                         // 0
        bgr[1] = 255;                       // 255
        bgr[2] = (60 - hue) * 8.5;          // Falling
    } else if (hue <= 90) {
        bgr[0] = 255 - (90 - hue) * 8.5;    // Rising
        bgr[1] = 255;                       // 255
        bgr[2] = 0;                         // 0
    } else if (hue <= 120) {
        bgr[0] = 255;                       // 255
        bgr[1] = (120 - hue) * 8.5;         // Falling
        bgr[2] = 0;                         // 0
    } else if (hue <= 150) {
        bgr[0] = 255;                       // 255
        bgr[1] = 0;                         // 0
        bgr[2] = 255 - (150 - hue) * 8.5;   // Rising
    } else if (hue <= 180) {
        bgr[0] = (180 - hue) * 8.5;         // Falling
        bgr[1] = 0;                         // 0
        bgr[2] = 255;                       // 255
    }
}
