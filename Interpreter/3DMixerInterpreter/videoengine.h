#ifndef VIDEOENGINE_H
#define VIDEOENGINE_H

#include <QThread>
#include <QImage>
#include <QMutex>
#include "videoprocessor.h"
#include "cvmattoqimage.h"
#include "videoformat.h"
#include "tracker.h"


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
    Tracker* tracker;
    cv::VideoCapture videoCapture;
    VideoFormat _videoFormat;
    bool stopped;
    QMutex mutex;
};


#endif // VIDEOENGINE_H
