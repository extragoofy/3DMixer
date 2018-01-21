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

private:
    Ui::MainWindow* ui;
    VideoEngine* videoEngine;
    Tracker* tracker;
    Output* output;
    QTimer* updateTimer;
    QVector<uchar> knobParams;
    QVector<uchar> knobCoords;
    void setUpVideo();
    void setUpValidators();
    void setUpUiEvents();
    QString createStylesheetColorString(ushort knobIndex);
};

#endif // MAINWINDOW_H
