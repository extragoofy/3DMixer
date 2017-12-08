#ifndef TRACKER_H
#define TRACKER_H

#include "videoprocessor.h"

class Tracker : public VideoProcessor
{
public:
    Tracker();
    void startProcessing(const VideoFormat& format){}
    cv::Mat process(const cv::Mat&source);

private:
    void drawCross(cv::Mat& mat, cv::Point center, int length, cv::Scalar color);
};

#endif // TRACKER_H
