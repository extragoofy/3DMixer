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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateParameters();
    void updateCoordLabels();
    void updateMidiOutputDeviceID();
    void on_knobA_isView_clicked();
    void on_knobB_isView_clicked();
    void on_knobC_isView_clicked();
    void on_knobD_isView_clicked();

private:
    Ui::MainWindow * ui;
    VideoEngine * videoEngine;
    Tracker * tracker;
    Output * output;
    QTimer * updateTimer;
    QVector<Output::knobCoordData> knobCoords;
    QVector<uchar> knobParams;
    QVector<uchar> knobCoords;
    void setUpVideo();
    void setUpValidators();
    void setUpUiEvents();
    void resetRadioButtons();
    QString createStylesheetColorString(ushort knobIndex);
};

#endif // MAINWINDOW_H
