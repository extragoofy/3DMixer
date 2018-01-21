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
    Output(Tracker* trackerInstance);
    ~Output();
    void setMidiSendInterval(int value);
    int midiDeviceID;

private slots:
    void sendTrackerData();

private:
    Tracker* tracker;
    QTimer* outputTimer;
    int sendInterval;
    HMIDIOUT device;    // MIDI device interface for sending MIDI output
    union {
        unsigned long word;
        unsigned char data[4];
    } message;
    unsigned char trackData[4];
};

#endif // OUTPUT_H
