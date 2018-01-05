#ifndef OUTPUT_H
#define OUTPUT_H

#include <QObject>
#include <QTimer>
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

};

#endif // OUTPUT_H
