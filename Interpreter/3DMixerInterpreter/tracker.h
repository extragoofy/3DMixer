#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include "videoprocessor.h"

class Tracker : public VideoProcessor
{

    struct knob {
        bool active;
        float color_hue;
        float color_sat;
        float color_val;
    };

public:
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);
    void updateKnobParameters(int knobIndex, bool active, float hue, float sat, float val);

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
