#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QIntValidator>
#include <QVector>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tracker(new Tracker),
    videoEngine(new VideoEngine(tracker)),
    output(new Output(tracker)),
    updateTimer(new QTimer(this))
{
    knobParams = QVector<int>(28);
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
    //videoEngine->setProcessor(tracker);
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

    ui->midiDeviceID->setValidator(new QIntValidator(0, 10, this));

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

    connect(ui->options_blur, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->options_erode, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->options_dilate, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->midiDeviceID, SIGNAL(editingFinished()), this, SLOT(updateMidiOutputDeviceID()));

}

void MainWindow::resetRadioButtons() {
    ui->knobA_isView->setChecked(false);
    ui->knobB_isView->setChecked(false);
    ui->knobC_isView->setChecked(false);
    ui->knobD_isView->setChecked(false);
}

// SIGNALS/SLOTS

void MainWindow::updateParameters() {

    // Update knobParams vector containing all parameter data
    knobParams[0] = ui->knobA_isActive->isChecked();
    knobParams[1] = ui->knobA_colorHueMin->text().toInt();
    knobParams[2] = ui->knobA_colorHueMax->text().toInt();
    knobParams[3] = ui->knobA_colorSatMin->text().toInt();
    knobParams[4] = ui->knobA_colorSatMax->text().toInt();
    knobParams[5] = ui->knobA_colorValMin->text().toInt();
    knobParams[6] = ui->knobA_colorValMax->text().toInt();
    knobParams[7] = ui->knobB_isActive->isChecked();
    knobParams[8] = ui->knobB_colorHueMin->text().toInt();
    knobParams[9] = ui->knobB_colorHueMax->text().toInt();
    knobParams[10] = ui->knobB_colorSatMin->text().toInt();
    knobParams[11] = ui->knobB_colorSatMax->text().toInt();
    knobParams[12] = ui->knobB_colorValMin->text().toInt();
    knobParams[13] = ui->knobB_colorValMax->text().toInt();
    knobParams[14] = ui->knobC_isActive->isChecked();
    knobParams[15] = ui->knobC_colorHueMin->text().toInt();
    knobParams[16] = ui->knobC_colorHueMax->text().toInt();
    knobParams[17] = ui->knobC_colorSatMin->text().toInt();
    knobParams[18] = ui->knobC_colorSatMax->text().toInt();
    knobParams[19] = ui->knobC_colorValMin->text().toInt();
    knobParams[20] = ui->knobC_colorValMax->text().toInt();
    knobParams[21] = ui->knobD_isActive->isChecked();
    knobParams[22] = ui->knobD_colorHueMin->text().toInt();
    knobParams[23] = ui->knobD_colorHueMax->text().toInt();
    knobParams[24] = ui->knobD_colorSatMin->text().toInt();
    knobParams[25] = ui->knobD_colorSatMax->text().toInt();
    knobParams[26] = ui->knobD_colorValMin->text().toInt();
    knobParams[27] = ui->knobD_colorValMax->text().toInt();

    // Call tracker to update its parameters using this data
    tracker->updateKnobParameters(knobParams);

    // Update color labels
    ui->knobA_colorLabel->setStyleSheet(createStylesheetColorString(0));
    ui->knobB_colorLabel->setStyleSheet(createStylesheetColorString(1));
    ui->knobC_colorLabel->setStyleSheet(createStylesheetColorString(2));
    ui->knobD_colorLabel->setStyleSheet(createStylesheetColorString(3));

    tracker->useBlur = ui->options_blur->isChecked();
    tracker->useErode = ui->options_erode->isChecked();
    tracker->useDilate = ui->options_dilate->isChecked();
/*
    // Enable/Disable radio buttons for views
    ui->knobA_isView->setCheckable(knobParams[0]);
    ui->knobB_isView->setCheckable(knobParams[7]);
    ui->knobC_isView->setCheckable(knobParams[14]);
    ui->knobD_isView->setCheckable(knobParams[21]);
    if (!knobParams[0] && ui->knobA_isView->isChecked()) {
        on_all_isView_clicked();
    }
    cout << knobParams[7];
    if (!knobParams[7] && ui->knobB_isView->isChecked()) {
        on_all_isView_clicked();
        cout << "Happened";
    }
    if (!knobParams[14] && ui->knobC_isView->isChecked()) {
        on_all_isView_clicked();
    }
    if (!knobParams[21] && ui->knobD_isView->isChecked()) {
        on_all_isView_clicked();
    }
*/
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

void MainWindow::updateMidiOutputDeviceID() {
    output->setMidiDeviceID(ui->knobA_colorHueMin->text().toInt());
}

void MainWindow::on_knobA_isView_clicked()
{
    if (ui->knobA_isView->isCheckable()) {
        resetRadioButtons();
        ui->knobA_isView->setChecked(true);
        tracker->setView(0);
    }
}

void MainWindow::on_knobB_isView_clicked()
{
    if (ui->knobB_isView->isCheckable()) {
        resetRadioButtons();
        ui->knobB_isView->setChecked(true);
        tracker->setView(1);
    }
}

void MainWindow::on_knobC_isView_clicked()
{
    if (ui->knobC_isView->isCheckable()) {
        resetRadioButtons();
        ui->knobC_isView->setChecked(true);
        tracker->setView(2);
    }
}

void MainWindow::on_knobD_isView_clicked()
{
    if (ui->knobD_isView->isCheckable()) {
        resetRadioButtons();
        ui->knobD_isView->setChecked(true);
        tracker->setView(3);
    }
}

QString MainWindow::createStylesheetColorString(ushort knobIndex) {
    // May god forgive me for this
    if (knobParams[knobIndex*7+1] < knobParams[knobIndex*7+2]) {
        return QString::fromStdString("QLabel {background-color: hsv(" +
                                  to_string((knobParams[knobIndex*7+1] + knobParams[knobIndex*7+2]) / 2) + "," +
                                  to_string((knobParams[knobIndex*7+3] + knobParams[knobIndex*7+4]) / 2 * 2.55) + "," +
                                  to_string((knobParams[knobIndex*7+5] + knobParams[knobIndex*7+6]) / 2 * 2.55) + "); }"
                );
    } else {
        return QString::fromStdString("QLabel {background-color: hsv(" +
                                  to_string(((knobParams[knobIndex*7+1] + knobParams[knobIndex*7+2] + 360) / 2) % 360) + "," +
                                  to_string((knobParams[knobIndex*7+3] + knobParams[knobIndex*7+4]) / 2 * 2.55) + "," +
                                  to_string((knobParams[knobIndex*7+5] + knobParams[knobIndex*7+6]) / 2 * 2.55) + "); }"
                );
    }
}
