#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <QThread>
#include <QImage>
#include <QMutex>
#include "cvmattoqimage.h"
#include "videoformat.h"
#include "tracker.h"

/*
* http://stackoverflow.com/questions/7801522/integrating-opencv-with-larger-programs
* Video engine that runs in a different thread than the GUI
* Gets frames from webcam and calls tracker to process frame
* Emits latest original and processed frame to the GUI for display
* Original class by Prof. Andreas Plaß of HAW Hamburg
* Took out some stuff that is not being used by this application
*/


class VideoEngine : public QThread
{

    Q_OBJECT

public:
    VideoEngine();
    ~VideoEngine();
    void setTracker(Tracker* trackerInstance);
    void openCamera(int device = 0);
    int framePosition();

protected:
    void run();

public slots:
    void stop();

signals:
    void sendInputImage(const QImage&);
    void sendProcessedImage(const QImage&);

private:
    Tracker* tracker;               // Tracker instance
    cv::VideoCapture videoCapture;  // openCV video capturer
    VideoFormat _videoFormat;       // Storing format of video
    bool stopped;                   // To escape core loop processing image
    QMutex mutex;                   // Thread locker
};


#endif // VIDEOENGINE_H
