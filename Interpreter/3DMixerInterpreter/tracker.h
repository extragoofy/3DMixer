#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include <QVector>
#include "videoprocessor.h"

class Tracker : public VideoProcessor
{

    struct knob {
        bool active;
        ushort color_hue;
        ushort color_sat;
        ushort color_val;
        int xCoords;
        int yCoords;
        int zCoords;
    };

public:
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void updateKnobParameters(int knobIndex, bool active, float hue, float sat, float val);
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
