#include "output.h"

using namespace std;

Output::Output(Tracker * trackerInstance):
    tracker(trackerInstance),
    outputTimer(new QTimer(this))
{
    connect(outputTimer, SIGNAL(timeout()), this, SLOT(sendTrackerData()));
    outputTimer->start(100);
    message.data[0] = 0x90;
    message.data[3] = 0x01;
    midiDeviceID = 0;
    printf("Number of midi devices: %d\n", midiOutGetNumDevs());
}

Output::~Output() {
    outputTimer->stop();
    delete outputTimer;
}

void Output::sendTrackerData() {
    int flag = midiOutOpen(&device, midiDeviceID, 0, 0, CALLBACK_NULL);
    if (flag != MMSYSERR_NOERROR) {
        printf("Error opening MIDI Output, Error: %d \n", flag);
        printf("Number of devices: %d \n", midiOutGetNumDevs());
    }

    QVector<Tracker::KnobCoords> trackerData = tracker->getKnobCoords();

    for (int i = 0; i < 4; i++) {
        message.data[0] = 0x90;
        message.data[1] = i;
        message.data[2] = trackerData[i].x;
        midiOutShortMsg(device, message.word);
        message.data[0] = 0x80;
        message.data[1] = trackerData[i].y;
        message.data[2] = trackerData[i].z;
        midiOutShortMsg(device, message.word);
    }
    midiOutClose(device);
}

void Output::setMidiSendInterval(int value) {
    outputTimer->stop();
    outputTimer->start(value);
}
