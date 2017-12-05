#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    test();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::test()
{
    VideoCapture stream1(0);   // Get webcam stream

    if (!stream1.isOpened()) { // Check if video device has been initialised
        cout << "cannot open camera";
    }

    // Display webcam feed until any button is pressed
    //while (true) {
        Mat cameraFrame;
        stream1.read(cameraFrame);
        cvtColor(cameraFrame, cameraFrame, CV_BGR2RGB);
        ui->sourceVideo->setPixmap(QPixmap::fromImage(QImage(cameraFrame.data, cameraFrame.cols, cameraFrame.rows, cameraFrame.step, QImage::Format_RGB888)));
        //imshow("cam", cameraFrame);
        //if (waitKey(30) >= 0)
        //break;
    //}
}
