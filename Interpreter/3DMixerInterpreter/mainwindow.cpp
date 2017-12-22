#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QIntValidator>
#include <QVector>
#include "tracker.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    videoEngine(new VideoEngine),
    tracker(new Tracker),
    updateTimer(new QTimer(this))
{
    knobCoords = QVector<int>(12);
    ui->setupUi(this);
    setUpVideo();
    setUpValidators();
    setUpUiEvents();
    updateParameters();
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(updateCoordLabels()));
    updateTimer->start(500);
}

MainWindow::~MainWindow()
{
    delete videoEngine;
    delete tracker;
    delete ui;
    delete updateTimer;
}

void MainWindow::setUpVideo() {
    videoEngine->setProcessor(tracker);
    connect(videoEngine, &VideoEngine::sendInputImage, ui->inputFrame, &VideoWidget::setImage);
    connect(videoEngine, &VideoEngine::sendProcessedImage, ui->outputFrame, &VideoWidget::setImage);
    videoEngine->openCamera(0);
    videoEngine->start();
}

void MainWindow::setUpValidators() {

    ui->knobA_colorHueMin->setValidator(new QIntValidator(0, 360, this));
    ui->knobA_colorHueMax->setValidator(new QIntValidator(0, 360, this));
    ui->knobA_colorSatMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobA_colorSatMax->setValidator(new QIntValidator(0, 100, this));
    ui->knobA_colorValMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobA_colorValMax->setValidator(new QIntValidator(0, 100, this));

    ui->knobB_colorHueMin->setValidator(new QIntValidator(0, 360, this));
    ui->knobB_colorHueMax->setValidator(new QIntValidator(0, 360, this));
    ui->knobB_colorSatMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobB_colorSatMax->setValidator(new QIntValidator(0, 100, this));
    ui->knobB_colorValMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobB_colorValMax->setValidator(new QIntValidator(0, 100, this));

    ui->knobC_colorHueMin->setValidator(new QIntValidator(0, 360, this));
    ui->knobC_colorHueMax->setValidator(new QIntValidator(0, 360, this));
    ui->knobC_colorSatMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobC_colorSatMax->setValidator(new QIntValidator(0, 100, this));
    ui->knobC_colorValMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobC_colorValMax->setValidator(new QIntValidator(0, 100, this));

    ui->knobD_colorHueMin->setValidator(new QIntValidator(0, 360, this));
    ui->knobD_colorHueMax->setValidator(new QIntValidator(0, 360, this));
    ui->knobD_colorSatMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobD_colorSatMax->setValidator(new QIntValidator(0, 100, this));
    ui->knobD_colorValMin->setValidator(new QIntValidator(0, 100, this));
    ui->knobD_colorValMax->setValidator(new QIntValidator(0, 100, this));

}

void MainWindow::setUpUiEvents() {

    connect(ui->knobA_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobA_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));

    connect(ui->knobB_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));

    connect(ui->knobC_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));

    connect(ui->knobD_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));

}

// SIGNALS/SLOTS

void MainWindow::updateParameters() {
    tracker->updateKnobParameters(
                0,
                ui->knobA_isActive->isChecked(),
                ui->knobA_colorHueMin->text().toInt() / 2,
                ui->knobA_colorHueMax->text().toInt() / 2,
                ui->knobA_colorSatMin->text().toFloat() * 2.55,
                ui->knobA_colorSatMax->text().toFloat() * 2.55,
                ui->knobA_colorValMin->text().toFloat() * 2.55,
                ui->knobA_colorValMax->text().toFloat() * 2.55
                );
    tracker->updateKnobParameters(
                1,
                ui->knobB_isActive->isChecked(),
                ui->knobB_colorHueMin->text().toInt() / 2,
                ui->knobB_colorHueMax->text().toInt() / 2,
                ui->knobB_colorSatMin->text().toShort() * 2.55,
                ui->knobB_colorSatMax->text().toShort() * 2.55,
                ui->knobB_colorValMin->text().toShort() * 2.55,
                ui->knobB_colorValMax->text().toShort() * 2.55
                );
    tracker->updateKnobParameters(
                2,
                ui->knobC_isActive->isChecked(),
                ui->knobC_colorHueMin->text().toInt() / 2,
                ui->knobC_colorHueMax->text().toInt() / 2,
                ui->knobC_colorSatMin->text().toShort() * 2.55,
                ui->knobC_colorSatMax->text().toShort() * 2.55,
                ui->knobC_colorValMin->text().toShort() * 2.55,
                ui->knobC_colorValMax->text().toShort() * 2.55
                );
    tracker->updateKnobParameters(
                3,
                ui->knobD_isActive->isChecked(),
                ui->knobD_colorHueMin->text().toInt() / 2,
                ui->knobD_colorHueMax->text().toInt() / 2,
                ui->knobD_colorSatMin->text().toShort() * 2.55,
                ui->knobD_colorSatMax->text().toShort() * 2.55,
                ui->knobD_colorValMin->text().toShort() * 2.55,
                ui->knobD_colorValMax->text().toShort() * 2.55
                );

    ui->knobA_colorLabel->setStyleSheet(
                "QLabel {background-color: hsv(224, 100, 100); }");
    cout << (ui->knobA_colorSatMin->text().toInt() / 2);
}

void MainWindow::updateCoordLabels() {
    tracker->updateCoordData(knobCoords);
    ui->knobA_xCoordsLabel->setText(QString::number(knobCoords[0]));
    ui->knobA_yCoordsLabel->setText(QString::number(knobCoords[1]));
    ui->knobA_zCoordsLabel->setText(QString::number(knobCoords[2]));
    ui->knobB_xCoordsLabel->setText(QString::number(knobCoords[3]));
    ui->knobB_yCoordsLabel->setText(QString::number(knobCoords[4]));
    ui->knobB_zCoordsLabel->setText(QString::number(knobCoords[5]));
    ui->knobC_xCoordsLabel->setText(QString::number(knobCoords[6]));
    ui->knobC_yCoordsLabel->setText(QString::number(knobCoords[7]));
    ui->knobC_zCoordsLabel->setText(QString::number(knobCoords[8]));
    ui->knobD_xCoordsLabel->setText(QString::number(knobCoords[9]));
    ui->knobD_yCoordsLabel->setText(QString::number(knobCoords[10]));
    ui->knobD_zCoordsLabel->setText(QString::number(knobCoords[11]));
    updateTimer->start(500);
}
