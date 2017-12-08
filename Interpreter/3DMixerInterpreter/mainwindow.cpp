#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include "tracker.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    videoEngine(new VideoEngine),
    tracker(new Tracker)
{
    ui->setupUi(this);
    videoEngine->setProcessor(tracker);
    connect(videoEngine, &VideoEngine::sendInputImage, ui->inputFrame, &VideoWidget::setImage);
    connect(videoEngine, &VideoEngine::sendProcessedImage, ui->outputFrame, &VideoWidget::setImage);
    test();
}

MainWindow::~MainWindow()
{
    delete videoEngine;
    delete tracker;
    delete ui;
}

void MainWindow::test()
{
    videoEngine->openCamera(0);
    videoEngine->start();
}
