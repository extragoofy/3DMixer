#ifndef TRACKER_H
#define TRACKER_H

#include <opencv2/opencv.hpp>
//#include <QLabel>
//#include <QVector>
#include <vector>
#include <stdio.h>     /* for printf() function */

/*
 * This is the core class of the interepreter.
 * It does all image tracking, calculation of knob positions and so on.
 */

class Tracker
{

public:

    // Constructor
    Tracker();

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
            : rgbColor(0)
            , binaryFrame(0)        // Größe setzen?
            , center(cv::Point())
            , radius(0)
        {}
        cv::Scalar rgbColor;
        cv::Mat binaryFrame;    // Latest binary frame of knob
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

    // Main processing function
    cv::Mat process(const cv::Mat& source);

    // Data handling
    vector<KnobCoords>& getKnobParams();
    //void updateKnobParams(const vector<ushort> &paramData);
    const vector<KnobCoords>& getKnobCoords();
    //void updateCoordData(QVector<int>& target);
    //void getCoordDataToSend(int knobID, uchar &x, uchar &y, uchar &z);

    // Options
    bool useBlur;       // Shall median blur be used to improve tracking? (Expensive!)
    bool useErode;      // Shall the binary frames be eroded to improve tracking?
    bool useDilate;     // Shall the binary frames be dilated to improve tracking?
    uchar activeView;   // Which knob is currently visible in the UI

private:

    // Processing algorithms
    cv::Mat colorKeying(const int& knobID, const cv::Mat& hsvFrame);
    void centerOfMass(const int& knobID, const cv::Mat& image);
    void radius(const int& knobID, const cv::Mat& image);

    // Drawing functions
    void drawCross(cv::Mat& mat, const cv::Point& center, const int& length, const cv::Scalar& color);

    // Helper functions
    void hueToRGB(const ushort& hue, cv::Scalar& bgr);

    // Data storage for each knob
    vector<KnobParams> knobParams;
    vector<KnobData> knobData;
    vector<KnobCoords> knobCoords;

};

#endif // TRACKER_H
