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
    cout << "bing";
}
