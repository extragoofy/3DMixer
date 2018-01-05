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
    Output(Tracker * trackerInstance);
    ~Output();
    int interval;

private slots:
    void sendTrackerData();

private:
    Tracker* tracker;
    QTimer* outputTimer;
    HMIDIOUT device;    // MIDI device interface for sending MIDI output
    bool stopNote;
};

#endif // OUTPUT_H
