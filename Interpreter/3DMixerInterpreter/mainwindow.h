#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QTimer>
#include <QVector>
#include "videoengine.h"
#include "tracker.h"

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
    void on_knobA_colorHue_editingFinished();
    void on_knobA_colorSaturation_editingFinished();
    void on_knobA_colorValue_editingFinished();
    void on_knobA_isActive_clicked(bool checked);
    void updateCoordLabels();

private:
    Ui::MainWindow *ui;
    VideoEngine *videoEngine;
    Tracker *tracker;
    QTimer *updateTimer;
    QVector<int> knobCoords;
    void setUpVideo();
    void setUpValidators();
    void updateParameters();
};

#endif // MAINWINDOW_H
