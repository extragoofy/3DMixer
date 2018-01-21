#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <QIntValidator>

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tracker(new Tracker)
    , videoEngine(new VideoEngine)
    , output(new Output(tracker))
    , updateTimer(new QTimer(this))
    , knobParams(QVector<uchar>(28))

{
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
    updateTimer->stop();
    delete updateTimer;
    delete output;
    delete videoEngine;
    delete tracker;
    delete ui;
}

void MainWindow::setUpVideo() {
    videoEngine->setTracker(tracker);
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
    connect(ui->knobA_isView, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->knobB_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobB_isView, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->knobC_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobC_isView, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->knobD_isActive, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorHueMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorHueMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorSatMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorSatMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorValMin, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_colorValMax, SIGNAL(editingFinished()), this, SLOT(updateParameters()));
    connect(ui->knobD_isView, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->isView_all, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->options_blur, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->options_erode, SIGNAL(clicked()), this, SLOT(updateParameters()));
    connect(ui->options_dilate, SIGNAL(clicked()), this, SLOT(updateParameters()));

    connect(ui->midiDeviceID, SIGNAL(editingFinished()), this, SLOT(updateParameters()));

}

// SIGNALS/SLOTS

void MainWindow::updateParameters() {

    // Update knobParams vector containing all parameter data
    // Convert 360 degree hue values to 180 degrees for opencv
    // Convert 0-100 hue values to 0-255 8bit values for opencv
    knobParams[0] = ui->knobA_isActive->isChecked();
    knobParams[1] = ui->knobA_colorHueMin->text().toInt() / 2;
    knobParams[2] = ui->knobA_colorHueMax->text().toInt() / 2;
    knobParams[3] = ui->knobA_colorSatMin->text().toInt() * 255 / 100;      // Just multiplying by 2.55 results in an rounding error
    knobParams[4] = ui->knobA_colorSatMax->text().toInt() * 255 / 100;      // making 255 unreachable
    knobParams[5] = ui->knobA_colorValMin->text().toInt() * 255 / 100;
    knobParams[6] = ui->knobA_colorValMax->text().toInt() * 255 / 100;
    knobParams[7] = ui->knobB_isActive->isChecked();
    knobParams[8] = ui->knobB_colorHueMin->text().toInt() / 2;
    knobParams[9] = ui->knobB_colorHueMax->text().toInt() / 2;
    knobParams[10] = ui->knobB_colorSatMin->text().toInt() * 255 / 100;
    knobParams[11] = ui->knobB_colorSatMax->text().toInt() * 255 / 100;
    knobParams[12] = ui->knobB_colorValMin->text().toInt() * 255 / 100;
    knobParams[13] = ui->knobB_colorValMax->text().toInt() * 255 / 100;
    knobParams[14] = ui->knobC_isActive->isChecked();
    knobParams[15] = ui->knobC_colorHueMin->text().toInt() / 2;
    knobParams[16] = ui->knobC_colorHueMax->text().toInt() / 2;
    knobParams[17] = ui->knobC_colorSatMin->text().toInt() * 255 / 100;
    knobParams[18] = ui->knobC_colorSatMax->text().toInt() * 255 / 100;
    knobParams[19] = ui->knobC_colorValMin->text().toInt() * 255 / 100;
    knobParams[20] = ui->knobC_colorValMax->text().toInt() * 255 / 100;
    knobParams[21] = ui->knobD_isActive->isChecked();
    knobParams[22] = ui->knobD_colorHueMin->text().toInt() / 2;
    knobParams[23] = ui->knobD_colorHueMax->text().toInt() / 2;
    knobParams[24] = ui->knobD_colorSatMin->text().toInt() * 255 / 100;
    knobParams[25] = ui->knobD_colorSatMax->text().toInt() * 255 / 100;
    knobParams[26] = ui->knobD_colorValMin->text().toInt() * 255 / 100;
    knobParams[27] = ui->knobD_colorValMax->text().toInt() * 255 / 100;

    // Update color labels
    ui->knobA_colorLabel->setStyleSheet(createStylesheetColorString(0));
    ui->knobB_colorLabel->setStyleSheet(createStylesheetColorString(1));
    ui->knobC_colorLabel->setStyleSheet(createStylesheetColorString(2));
    ui->knobD_colorLabel->setStyleSheet(createStylesheetColorString(3));

    // Enable/Disable view radio buttons dependent on active state of knob
    ui->knobA_isView->setEnabled(knobParams[0]);
    ui->knobB_isView->setEnabled(knobParams[7]);
    ui->knobC_isView->setEnabled(knobParams[14]);
    ui->knobD_isView->setEnabled(knobParams[21]);

    // Assign new view if button is disabled and view is still checked
    if (
            (ui->knobA_isView->isChecked() && !ui->knobA_isView->isEnabled()) ||
            (ui->knobB_isView->isChecked() && !ui->knobB_isView->isEnabled()) ||
            (ui->knobC_isView->isChecked() && !ui->knobC_isView->isEnabled()) ||
            (ui->knobD_isView->isChecked() && !ui->knobD_isView->isEnabled())
            ) {
        if (ui->knobA_isView->isEnabled()) ui->knobA_isView->click();
        else if (ui->knobB_isView->isEnabled()) ui->knobB_isView->click();
        else if (ui->knobC_isView->isEnabled()) ui->knobC_isView->click();
        else if (ui->knobD_isView->isEnabled()) ui->knobD_isView->click();
        else ui->isView_all->click();
    }

    // Set activeView
    if (ui->knobA_isView->isChecked()) tracker->activeView = 0;
    else if (ui->knobB_isView->isChecked()) tracker->activeView = 1;
    else if (ui->knobC_isView->isChecked()) tracker->activeView = 2;
    else if (ui->knobD_isView->isChecked()) tracker->activeView = 3;
    else tracker->activeView = 4;

    printf("%d\n", ui->knobA_isView->isChecked());
    printf("%d\n", ui->knobB_isView->isChecked());
    printf("%d\n", ui->knobC_isView->isChecked());
    printf("%d\n", ui->knobD_isView->isChecked());

    // Call tracker to update its parameters using this data
    tracker->updateKnobParams(knobParams);
    tracker->useBlur = ui->options_blur->isChecked();
    tracker->useErode = ui->options_erode->isChecked();
    tracker->useDilate = ui->options_dilate->isChecked();
    output->setMidiDeviceID(ui->midiDeviceID->text().toInt());

}

void MainWindow::updateCoordLabels() {

    QVector<Tracker::KnobCoords> coordData = tracker->getKnobCoords();

    ui->knobA_xCoordsLabel->setText(QString::number(coordData[0].x));
    ui->knobA_yCoordsLabel->setText(QString::number(coordData[0].y));
    ui->knobA_zCoordsLabel->setText(QString::number(coordData[0].z));
    ui->knobB_xCoordsLabel->setText(QString::number(coordData[1].x));
    ui->knobB_yCoordsLabel->setText(QString::number(coordData[1].y));
    ui->knobB_zCoordsLabel->setText(QString::number(coordData[1].z));
    ui->knobC_xCoordsLabel->setText(QString::number(coordData[2].x));
    ui->knobC_yCoordsLabel->setText(QString::number(coordData[2].y));
    ui->knobC_zCoordsLabel->setText(QString::number(coordData[2].z));
    ui->knobD_xCoordsLabel->setText(QString::number(coordData[3].x));
    ui->knobD_yCoordsLabel->setText(QString::number(coordData[3].y));
    ui->knobD_zCoordsLabel->setText(QString::number(coordData[3].z));
    updateTimer->start(500);

}

QString MainWindow::createStylesheetColorString(ushort knobIndex) {
    // May god forgive me for this
    if (knobParams[knobIndex*7+1] <= knobParams[knobIndex*7+2]) {
        return QString::fromStdString("QLabel {background-color: hsv(" +
                                  to_string((knobParams[knobIndex*7+1] + knobParams[knobIndex*7+2])) + "," +
                                  to_string((knobParams[knobIndex*7+3] + knobParams[knobIndex*7+4]) / 2) + "," +
                                  to_string((knobParams[knobIndex*7+5] + knobParams[knobIndex*7+6]) / 2) + "); }"
                );
    } else {
        return QString::fromStdString("QLabel {background-color: hsv(" +
                                  to_string((knobParams[knobIndex*7+1] + knobParams[knobIndex*7+2] + 180) % 360) + "," +
                                  to_string((knobParams[knobIndex*7+3] + knobParams[knobIndex*7+4]) / 2) + "," +
                                  to_string((knobParams[knobIndex*7+5] + knobParams[knobIndex*7+6]) / 2) + "); }"
                );
    }
}
