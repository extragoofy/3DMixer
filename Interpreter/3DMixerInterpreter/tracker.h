#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include <QVector>
#include "videoprocessor.h"

class Tracker : public VideoProcessor
{

    struct knob {
        bool active;
        ushort color_minHue;
        ushort color_maxHue;
        ushort color_minSat;
        ushort color_maxSat;
        ushort color_minVal;
        ushort color_maxVal;
        int xCoords;
        int yCoords;
        int zCoords;
    };

public:
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void updateKnobParameters(int knobIndex, bool active, ushort minHue, ushort maxHue, ushort minSat, ushort maxSat, ushort minVal, ushort maxVal);
    void updateCoordData(QVector<int>& target);

private:
    knob knobs[4];
    void initializeKnobs();
    cv::Point center;
    int hueUpperThreshold;
    int hueLowerThreshold;
    int saturationThreshold;
    float alpha;
    bool useMedian;
    bool useOpening;
    void centerOfMass(cv::Mat& image);
    cv::Mat colorKeying(cv::Mat& hsvFrame);
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
};

#endif // TRACKER_H
