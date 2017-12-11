#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
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
    void setCoordinateLabels(ushort x, ushort y, ushort z);

private:
    Ui::MainWindow *ui;
    VideoEngine *videoEngine;
    Tracker *tracker;
    void test();
};

#endif // MAINWINDOW_H
