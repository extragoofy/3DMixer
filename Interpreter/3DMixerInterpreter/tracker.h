#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include <QVector>
#include "videoprocessor.h"

class Tracker : public VideoProcessor
{

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
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat& source);
    void updateKnobParameters(const QVector<int> &paramData);
    void updateCoordData(QVector<int>& target);

private:
    knob knobs[4];
    void initializeKnobs();
    cv::Point center;
    void centerOfMass(cv::Mat& image);
    cv::Mat colorKeying(int knobIndex, cv::Mat& hsvFrame);
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
};

#endif // TRACKER_H
