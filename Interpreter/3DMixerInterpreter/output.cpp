#include "output.h"

using namespace std;

Output::Output(Tracker * trackerInstance):
    tracker(trackerInstance),
    outputTimer(new QTimer(this))
{
    interval = 500;
    connect(outputTimer, SIGNAL(timeout()), this, SLOT(sendTrackerData()));
    outputTimer->start(interval);
}

Output::~Output() {
    delete outputTimer;
}

void Output::sendTrackerData() {
    int flag = midiOutOpen(&device, 0, 0, 0, CALLBACK_NULL);
    if (flag != MMSYSERR_NOERROR) {
        printf("Error opening MIDI Output.\n");
        return;
    }
    //message.data[2] = velocity;
}
