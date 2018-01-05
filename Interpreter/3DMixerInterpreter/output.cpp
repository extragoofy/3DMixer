#include "output.h"

using namespace std;

Output::Output(Tracker * trackerInstance):
    tracker(trackerInstance),
    outputTimer(new QTimer(this))
{
    interval = 500;
    connect(outputTimer, SIGNAL(timeout()), this, SLOT(sendTrackerData()));
    outputTimer->start(interval);
    stopNote = false;
}

Output::~Output() {
    delete outputTimer;
}

void Output::sendTrackerData() {
    int flag = midiOutOpen(&device, 1, 0, 0, CALLBACK_NULL);
    if (flag != MMSYSERR_NOERROR) {
        printf("Error opening MIDI Output: %d \n", flag);
        printf("Number of devices: %d \n", midiOutGetNumDevs());
    }
    if (stopNote) {
        midiOutShortMsg(device, 0x00003C90);
        stopNote = false;
    } else {
        midiOutShortMsg(device, 0x00403C90);
        stopNote = true;
    }
    midiOutClose(device);
}
