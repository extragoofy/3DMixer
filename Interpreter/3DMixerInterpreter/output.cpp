#include "output.h"

using namespace std;

Output::Output(Tracker * trackerInstance):
    tracker(trackerInstance),
    outputTimer(new QTimer(this))
{
    interval = 500;
    connect(outputTimer, SIGNAL(timeout()), this, SLOT(sendTrackerData()));
    outputTimer->start(interval);
    message.data[0] = 0x90;
    message.data[3] = 0x01;
}

Output::~Output() {
    delete outputTimer;
}

void Output::sendTrackerData() {
    int flag = midiOutOpen(&device, 2, 0, 0, CALLBACK_NULL);
    if (flag != MMSYSERR_NOERROR) {
        printf("Error opening MIDI Output: %d \n", flag);
        printf("Number of devices: %d \n", midiOutGetNumDevs());
    }

    for (int i = 0; i < 4; i++) {
        trackData[0] = i;
        tracker->getCoordDataToSend(trackData[0], trackData[1], trackData[2], trackData[3]);
        printf("Knob: %d, x: %d, y: %d, z: %d \n", trackData[0], trackData[1], trackData[2], trackData[3]);
        message.data[1] = trackData[0];
        message.data[2] = trackData[1];
        midiOutShortMsg(device, message.word);
        message.data[1] = trackData[2];
        message.data[2] = trackData[3];
        midiOutShortMsg(device, message.word);
    }
    printf("\n");
    midiOutClose(device);
}

