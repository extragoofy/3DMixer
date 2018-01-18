#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include <QVector>
#include <stdio.h>     /* for printf() function */

class Tracker
{

public:
    Tracker();

    // Main struct for knobs
    struct knob {
        knob()
            : active(false)
            , color_minHue(0)
            , color_maxHue(0)
            , color_minSat(0)
            , color_maxSat(0)
            , color_minVal(0)
            , color_maxVal(0)
            , xCoords(0)
            , yCoords(0)
            , zCoords(0)
        {}
        bool active;
        uchar color_minHue;
        uchar color_maxHue;
        uchar color_minSat;
        uchar color_maxSat;
        uchar color_minVal;
        uchar color_maxVal;
        uchar xCoords;
        uchar yCoords;
        uchar zCoords;
    };

    // Main processing function
    cv::Mat process(const cv::Mat& source);

    // Data handling
    void updateKnobParameters(const QVector<int> &paramData);
    void updateCoordData(QVector<int>& target);
    void getCoordDataToSend(int knobID, uchar &x, uchar &y, uchar &z);

    // Options
    bool useBlur;
    bool useErode;
    bool useDilate;
    uchar activeView;

private:
    // Initialization
    void initializeKnobs();

    // Processing algorithms
    cv::Mat colorKeying(int knobID, cv::Mat& hsvFrame);
    void centerOfMass(int knobID, cv::Mat& image);
    void getRadius(int knobID, cv::Mat& image);

    // Drawing functions
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);

    // Data storage for each knob
    QVector<knob> knobs;
    QVector<cv::Mat> binaryFrames;
    QVector<cv::Point> center;
    QVector<int> radius;

};

#endif // TRACKER_H
