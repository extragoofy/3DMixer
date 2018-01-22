#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/opencv.hpp>
#include <QLabel>
#include <QVector>
#include <stdio.h>     // For printf() // Delete?
#include "videoformat.h"

/*
 * This is the core class of the interepreter.
 * It does all image tracking, calculation of knob positions and so on.
 */

class Tracker
{

public:

    // Struct that holds parameters for knob detection - basically everything that is settable in the UI
    struct KnobParams {
        KnobParams()
            : active(false)
            , minHue(0)
            , maxHue(0)
            , minSat(0)
            , maxSat(0)
            , minVal(0)
            , maxVal(0)
        {}
        bool active;        // Shall this knob be tracked?
        uchar minHue;       // Minimum hue of knob
        uchar maxHue;       // Maximum hue of knob
        uchar minSat;       // Minimum saturation of knob
        uchar maxSat;       // Maximum saturation of knob
        uchar minVal;       // Minimum value of knob
        uchar maxVal;       // Maximum value of knob
    };

    // Struct that holds knob data used for processing
    struct KnobData {
        KnobData()
            : bgrColor(cv::Vec3b(255,255,255))
            , center(cv::Point())
            , radius(10)
        {}
        cv::Vec3b bgrColor;    // Average hue of knob
        cv::Mat frame;          // Latest frame of knob
        cv::Point center;       // Center coordinates of knob
        int radius;             // Radius of knob (from center)
    };

    // Struct that holds calculated x, y and z position data of knobs
    struct KnobCoords {
        KnobCoords()
            : x(0)
            , y(0)
            , z(0)
        {}
        uchar x;
        uchar y;
        uchar z;
    };

    // Constructor
    Tracker();

    // Main processing function
    cv::Mat process(const cv::Mat& source);

    // Data handling
    void updateKnobParams(const QVector<uchar>& paramData);
    const QVector<KnobCoords>& getKnobCoords();

    // Options
    bool useBlur;       // Shall median blur be used to improve tracking? (Expensive!)
    bool useErode;      // Shall binary frames be eroded to improve tracking?
    bool useDilate;     // Shall binary frames be dilated to improve tracking?
    uchar activeView;   // Which knob is currently visible in the UI

private:

    // Processing algorithms
    cv::Mat colorKeying(const int& knobID, const cv::Mat& hsvFrame);
    void centerOfMass(const int& knobID, const cv::Mat& image);
    void radius(const int& knobID, const cv::Mat& image);
    void calculateCoords(const int& knobID);

    // Drawing functions
    void drawCross(cv::Mat& mat, const cv::Point& center, const int& length, const cv::Vec3b& color);

    // Helper functions
    void hueToBGR(const uchar& hue, cv::Vec3b& bgr);

    // Data storage
    QVector<KnobParams> knobParams;
    QVector<KnobData> knobData;
    QVector<KnobCoords> knobCoords;
    cv::Mat output;

};

#endif // TRACKER_H
