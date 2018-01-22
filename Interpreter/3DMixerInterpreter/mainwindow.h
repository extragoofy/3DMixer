#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QVector>
#include "videoengine.h"
#include "tracker.h"
#include "output.h"

namespace Ui {
    class MainWindow;
}

/*
 * Main UI class.
 * Updates UI values and passes user input to tracker class.
 * Also initializes tracker and output.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:

    void updateKnobParameters();
    void updateCoordLabels();

private:

    Ui::MainWindow* ui;
    Tracker* tracker;
    VideoEngine* videoEngine;
    Output* output;
    QTimer* updateTimer;
    QVector<uchar> knobParams;                  // Stores all knob parameters in a vector for easy passing to tracker
    QVector<Tracker::KnobCoords> trackerData;   // Holds tracker data - used to display updated values in UI

    // Set up functions
    void setUpValidators();
    void setUpUiEvents();
    void setUpVideo();

    // Helper functions
    QString createStylesheetColorString(ushort knobIndex);
};

#endif // MAINWINDOW_H
