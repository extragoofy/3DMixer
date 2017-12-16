#ifndef TRACKER_H
#define TRACKER_H

#include <QLabel>
#include "videoprocessor.h"
#include "mainwindow.h"

class Tracker : public VideoProcessor
{
public:
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);

private:
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