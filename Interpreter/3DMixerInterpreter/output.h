/*
 * by Eric Goofers
 * 2017, HAW Hamburg
 */

#ifndef OUTPUT_H
#define OUTPUT_H

// Uses code from: http://www.ccarh.org/courses/253/lab/midiprog/keymidi/keymidi.c

#include <QObject>     // Since this is using a QTimer, it needs to be a QObject
#include <QTimer>      // Update timer
#include <windows.h>   // required before including mmsystem.h
#include <mmsystem.h>  // multimedia functions (such as MIDI) for Windows
#include "tracker.h"

/*
 * Class responsible for output of tracker data
 * This is done using MIDI events - midi packets are sent containing coord data of tracker
 * Sends latest data in user-defined intervals
 */

class Output : public QObject
{
    Q_OBJECT

public:
    Output(Tracker* trackerInstance);
    ~Output();
    void setMidiSendInterval(int value);
    int midiDeviceID;       // ID midi device used to send midi data

private slots:
    void sendTrackerData();

private:
    Tracker* tracker;       // Instance of tracker class
    QTimer* outputTimer;    // Timer that calls sendTrackerData() in regular intervals
    HMIDIOUT device;        // MIDI device interface for sending MIDI output
    union {
        unsigned long word;
        unsigned char data[4];
    } message;              // Midi message to be sent
};

#endif // OUTPUT_H
