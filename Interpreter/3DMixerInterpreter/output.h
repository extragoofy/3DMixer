#ifndef OUTPUT_H
#define OUTPUT_H

// Uses code from: http://www.ccarh.org/courses/253/lab/midiprog/keymidi/keymidi.c

#include <QObject>
#include <QTimer>
#include <conio.h>     /* include for kbhit() and getch() functions */
#include <stdio.h>     /* for printf() function */
#include <windows.h>   /* required before including mmsystem.h */
#include <mmsystem.h>  /* multimedia functions (such as MIDI) for Windows */
#include "tracker.h"

class Output : public QObject
{
    Q_OBJECT

public:
    struct knobCoordData {
        knobCoordData()
            : x(0)
            , y(0)
            , z(0)
        {}
        uchar x;
        uchar y;
        uchar z;
    };
    Output(Tracker* trackerInstance);
    ~Output();
    int interval;
    void setMidiDeviceID(int id);

private slots:
    void sendTrackerData();

private:
    Tracker* tracker;
    QTimer* outputTimer;
    HMIDIOUT device;    // MIDI device interface for sending MIDI output
    int midiDeviceID;
    union {
        unsigned long word;
        unsigned char data[4];
    } message;
    unsigned char trackData[4];
};

#endif // OUTPUT_H
