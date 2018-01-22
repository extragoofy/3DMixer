#include <opencv2/opencv.hpp>
#include <QImage>
#include <QMutexLocker>
#include <QDir>
#include <QDebug>
#include <string>
#include "videoengine.h"

// http://stackoverflow.com/questions/7801522/integrating-opencv-with-larger-programs

VideoEngine::VideoEngine()
    : tracker(0)
    , stopped(false)
{ 
}

VideoEngine::~VideoEngine(){
    stop();
    wait();
}

// Set tracker engine
// This cannot be done in the constructor as this runs in a different thread
void VideoEngine::setTracker(Tracker* trackerInstance) {
    tracker = trackerInstance;
}

void VideoEngine::openCamera(int device){
    try {
        bool success = videoCapture.open(0  + device);
        if (!success){
            qDebug() << "Error: cannot open camera ";
        }
        else{
            _videoFormat.setFormat(videoCapture);
            qDebug() << _videoFormat.toString().c_str();
        }
    } catch (cv::Exception e) {
        qDebug() << e.err.c_str();
    }
}

void VideoEngine::stop()
{
    QMutexLocker locker(&mutex);
    stopped = true;
}

// Main function of image processing
// Includes the core loop of the whole application
void VideoEngine::run()
{
    if (videoCapture.isOpened()){
        int frameNumber = 0;
        while(!stopped)
        {
            cv::Mat cvFrame;
            if (!videoCapture.grab()){
                qDebug() << "grab() failed";
                break;
            }

            if (!videoCapture.retrieve(cvFrame, 0)){
                qDebug() << "retrieve() failed (1)";
                if (!videoCapture.retrieve(cvFrame, 0)){
                    qDebug() << "retrieve() failed (2)";
                    break;
                }
            }

            // Retrieve Mat::type()
            frameNumber++;
            if (frameNumber == 1){
                _videoFormat.setType(cvFrame.type());
            }

            // Queue original image to the gui
            emit sendInputImage(cvMatToQImage(cvFrame));

            // Process Video Frame
            cvFrame = tracker->process(cvFrame);

            // Queue processed image to the gui
            emit sendProcessedImage(cvMatToQImage(cvFrame));

            // Check if stopped
            QMutexLocker locker(&mutex);
            if (stopped) {
                break;
            }
        }
    }
}
