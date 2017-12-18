#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QDoubleValidator>
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
    setUpVideo();
    setUpValidators();
}

MainWindow::~MainWindow()
{
    delete videoEngine;
    delete tracker;
    delete ui;
}

void MainWindow::setUpVideo() {
    videoEngine->setProcessor(tracker);
    connect(videoEngine, &VideoEngine::sendInputImage, ui->inputFrame, &VideoWidget::setImage);
    connect(videoEngine, &VideoEngine::sendProcessedImage, ui->outputFrame, &VideoWidget::setImage);
    videoEngine->openCamera(0);
    videoEngine->start();
}

void MainWindow::setUpValidators() {

    ui->knobA_colorHue->setValidator(new QDoubleValidator(0, 359, 2, this));
    ui->knobA_colorSaturation->setValidator(new QDoubleValidator(0, 99, 2, this));
    ui->knobA_colorValue->setValidator(new QDoubleValidator(0, 99, 2, this));

    ui->knobB_colorHue->setValidator(new QDoubleValidator(0, 359, 2, this));
    ui->knobB_colorSaturation->setValidator(new QDoubleValidator(0, 99, 2, this));
    ui->knobB_colorValue->setValidator(new QDoubleValidator(0, 99, 2, this));

    ui->knobC_colorHue->setValidator(new QDoubleValidator(0, 359, 2, this));
    ui->knobC_colorSaturation->setValidator(new QDoubleValidator(0, 99, 2, this));
    ui->knobC_colorValue->setValidator(new QDoubleValidator(0, 99, 2, this));

    ui->knobD_colorHue->setValidator(new QDoubleValidator(0, 359, 2, this));
    ui->knobD_colorSaturation->setValidator(new QDoubleValidator(0, 99, 2, this));
    ui->knobD_colorValue->setValidator(new QDoubleValidator(0, 99, 2, this));

}

void MainWindow::updateParameters() {
    tracker->updateKnobParameters(
                0,
                ui->knobA_isActive->isChecked(),
                ui->knobA_colorHue->text().toFloat(),
                ui->knobA_colorSaturation->text().toFloat(),
                ui->knobA_colorValue->text().toFloat()
                );
}

void MainWindow::on_knobA_colorHue_editingFinished()
{
    updateParameters();
}

void MainWindow::on_knobA_colorSaturation_editingFinished()
{
    updateParameters();
}

void MainWindow::on_knobA_colorValue_editingFinished()
{
    updateParameters();
}

void MainWindow::on_knobA_isActive_clicked(bool checked)
{
    updateParameters();
}
