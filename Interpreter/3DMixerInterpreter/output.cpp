#include "output.h"

Output::Output(Tracker * trackerInstance)
    : tracker(trackerInstance)
    , outputTimer(new QTimer(this))
{
    printf("Number of MIDI devices: %d\n", midiOutGetNumDevs());
    // In order for midi packets to be sent, the first and the last byte need to have certain values
    // If they do not, the system will not recognize them as midi packets
    message.data[0] = 0x90;
    message.data[3] = 0x01;
    midiDeviceID = 0;
    // Start output timer (default value of 100ms)
    connect(outputTimer, SIGNAL(timeout()), this, SLOT(sendTrackerData()));
    outputTimer->start(100);
}

Output::~Output() {
    outputTimer->stop();
    delete outputTimer;
}

// Sends latest tracker data via MIDI
void Output::sendTrackerData() {

    // Open MIDI out
    int flag = midiOutOpen(&device, midiDeviceID, 0, 0, CALLBACK_NULL);

    if (flag != MMSYSERR_NOERROR) {
        printf("Error opening MIDI Output, Error: %d\n", flag);
    } else {
        // Get latest tracking data from tracker
        QVector<Tracker::KnobCoords> trackerData = tracker->getKnobCoords();
        // Tracking data gets sent in two MIDI packets:
        // First packet contains knobID and x coordinates
        // Second packets contains y and z coordinates
        // First byte identifies first or second packet:
        // 0x90 means first packet, 0x80 means second packets
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
}

// Change MIDI send interval
void Output::setMidiSendInterval(int value) {
    outputTimer->stop();
    outputTimer->start(value);
}
