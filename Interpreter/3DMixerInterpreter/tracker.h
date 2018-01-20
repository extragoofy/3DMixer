#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include <QVector>
#include <stdio.h>     /* for printf() function */
//#include "videoprocessor.h"
#include <QObject>
#include <opencv2/opencv.hpp>

class Tracker : public QObject
{
    Q_OBJECT

    struct knob {
        bool active;
        int color_minHue;
        int color_maxHue;
        int color_minSat;
        int color_maxSat;
        int color_minVal;
        int color_maxVal;
        int xCoords;
        int yCoords;
        int zCoords;
    };

public:
    // SETTINGS
    int maxDistance;    // Maximum distance the tracker should track on the z axis
    Tracker();
    //void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat& source);
    void updateKnobParameters(const QVector<int> &paramData);
    void updateCoordData(QVector<int>& target);
    void setView(int id);
    void getCoordDataToSend(int knobID, uchar &x, uchar &y, uchar &z);
    bool useBlur;
    bool useErode;
    bool useDilate;

private:
    QVector<knob> knobs;
    QVector<cv::Mat> binaryFrames;
    int activeView;
    cv::Point center;
    int radius;
    void initializeKnobs();
    void centerOfMass(int knobID, cv::Mat& image);
    cv::Mat colorKeying(int knobID, cv::Mat& hsvFrame);
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
    void getRadius(int knobID, cv::Mat& image);
};

#endif // TRACKER_H
