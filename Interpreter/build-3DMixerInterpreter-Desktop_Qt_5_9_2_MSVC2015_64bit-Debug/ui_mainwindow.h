/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "videowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    VideoWidget *inputFrame;
    VideoWidget *outputFrame;
    QGroupBox *knobABox;
    QCheckBox *knobA_isActive;
    QLineEdit *knobA_colorHueMin;
    QLineEdit *knobA_colorSatMin;
    QLineEdit *knobA_colorValMin;
    QLabel *knobA_xCoordsLabel;
    QLabel *knobA_yCoordsLabel;
    QLabel *knobA_zCoordsLabel;
    QLabel *knobA_colorLabel;
    QLineEdit *knobA_colorHueMax;
    QLineEdit *knobA_colorSatMax;
    QLineEdit *knobA_colorValMax;
    QRadioButton *knobA_isView;
    QLabel *label_hueMax;
    QLabel *label_satMin;
    QLabel *label_valMin;
    QLabel *label_active;
    QLabel *label_xCoords;
    QLabel *label_yCoords;
    QLabel *label_zCoords;
    QLabel *label_color;
    QLabel *label_hueMin;
    QLabel *label_satMax;
    QLabel *label_valMax;
    QGroupBox *knobBBox;
    QCheckBox *knobB_isActive;
    QLineEdit *knobB_colorHueMin;
    QLineEdit *knobB_colorSatMin;
    QLineEdit *knobB_colorValMin;
    QLabel *knobB_xCoordsLabel;
    QLabel *knobB_yCoordsLabel;
    QLabel *knobB_zCoordsLabel;
    QLabel *knobB_colorLabel;
    QLineEdit *knobB_colorHueMax;
    QLineEdit *knobB_colorSatMax;
    QLineEdit *knobB_colorValMax;
    QRadioButton *knobB_isView;
    QGroupBox *knobCBox;
    QCheckBox *knobC_isActive;
    QLineEdit *knobC_colorHueMin;
    QLineEdit *knobC_colorSatMin;
    QLineEdit *knobC_colorValMin;
    QLabel *knobC_xCoordsLabel;
    QLabel *knobC_yCoordsLabel;
    QLabel *knobC_zCoordsLabel;
    QLabel *knobC_colorLabel;
    QLineEdit *knobC_colorHueMax;
    QLineEdit *knobC_colorSatMax;
    QLineEdit *knobC_colorValMax;
    QRadioButton *knobC_isView;
    QGroupBox *knobDBox;
    QCheckBox *knobD_isActive;
    QLineEdit *knobD_colorHueMin;
    QLineEdit *knobD_colorSatMin;
    QLineEdit *knobD_colorValMin;
    QLabel *knobD_xCoordsLabel;
    QLabel *knobD_yCoordsLabel;
    QLabel *knobD_zCoordsLabel;
    QLabel *knobD_colorLabel;
    QLineEdit *knobD_colorHueMax;
    QLineEdit *knobD_colorSatMax;
    QLineEdit *knobD_colorValMax;
    QRadioButton *knobD_isView;
    QLabel *label_zCoords_2;
    QCheckBox *options_blur;
    QCheckBox *options_erode;
    QCheckBox *options_dilate;
    QLineEdit *midiDeviceID;
    QLabel *label_midiDevID;
    QRadioButton *isView_all;
    QLabel *label_midiSendRate;
    QLineEdit *midiSendRate;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QButtonGroup *viewButtonGroup;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 900);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1440, 900));
        MainWindow->setMaximumSize(QSize(1440, 900));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(40, 10, 640, 480));
        outputFrame = new VideoWidget(centralWidget);
        outputFrame->setObjectName(QStringLiteral("outputFrame"));
        outputFrame->setGeometry(QRect(760, 10, 640, 480));
        knobABox = new QGroupBox(centralWidget);
        knobABox->setObjectName(QStringLiteral("knobABox"));
        knobABox->setGeometry(QRect(50, 550, 1341, 51));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        knobABox->setFont(font);
        knobA_isActive = new QCheckBox(knobABox);
        knobA_isActive->setObjectName(QStringLiteral("knobA_isActive"));
        knobA_isActive->setGeometry(QRect(100, 20, 16, 20));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        knobA_isActive->setFont(font1);
        knobA_isActive->setChecked(true);
        knobA_colorHueMin = new QLineEdit(knobABox);
        knobA_colorHueMin->setObjectName(QStringLiteral("knobA_colorHueMin"));
        knobA_colorHueMin->setGeometry(QRect(180, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorHueMin->sizePolicy().hasHeightForWidth());
        knobA_colorHueMin->setSizePolicy(sizePolicy);
        knobA_colorHueMin->setMinimumSize(QSize(0, 0));
        knobA_colorHueMin->setBaseSize(QSize(0, 0));
        knobA_colorSatMin = new QLineEdit(knobABox);
        knobA_colorSatMin->setObjectName(QStringLiteral("knobA_colorSatMin"));
        knobA_colorSatMin->setGeometry(QRect(320, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorSatMin->sizePolicy().hasHeightForWidth());
        knobA_colorSatMin->setSizePolicy(sizePolicy);
        knobA_colorValMin = new QLineEdit(knobABox);
        knobA_colorValMin->setObjectName(QStringLiteral("knobA_colorValMin"));
        knobA_colorValMin->setGeometry(QRect(460, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorValMin->sizePolicy().hasHeightForWidth());
        knobA_colorValMin->setSizePolicy(sizePolicy);
        knobA_xCoordsLabel = new QLabel(knobABox);
        knobA_xCoordsLabel->setObjectName(QStringLiteral("knobA_xCoordsLabel"));
        knobA_xCoordsLabel->setGeometry(QRect(800, 21, 51, 20));
        knobA_xCoordsLabel->setFont(font1);
        knobA_yCoordsLabel = new QLabel(knobABox);
        knobA_yCoordsLabel->setObjectName(QStringLiteral("knobA_yCoordsLabel"));
        knobA_yCoordsLabel->setGeometry(QRect(950, 20, 61, 20));
        knobA_yCoordsLabel->setFont(font1);
        knobA_zCoordsLabel = new QLabel(knobABox);
        knobA_zCoordsLabel->setObjectName(QStringLiteral("knobA_zCoordsLabel"));
        knobA_zCoordsLabel->setGeometry(QRect(1100, 20, 61, 20));
        knobA_zCoordsLabel->setFont(font1);
        knobA_colorLabel = new QLabel(knobABox);
        knobA_colorLabel->setObjectName(QStringLiteral("knobA_colorLabel"));
        knobA_colorLabel->setGeometry(QRect(660, 20, 20, 20));
        knobA_colorLabel->setFrameShape(QFrame::Box);
        knobA_colorLabel->setLineWidth(2);
        knobA_colorHueMax = new QLineEdit(knobABox);
        knobA_colorHueMax->setObjectName(QStringLiteral("knobA_colorHueMax"));
        knobA_colorHueMax->setGeometry(QRect(230, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorHueMax->sizePolicy().hasHeightForWidth());
        knobA_colorHueMax->setSizePolicy(sizePolicy);
        knobA_colorHueMax->setMinimumSize(QSize(0, 0));
        knobA_colorHueMax->setBaseSize(QSize(0, 0));
        knobA_colorSatMax = new QLineEdit(knobABox);
        knobA_colorSatMax->setObjectName(QStringLiteral("knobA_colorSatMax"));
        knobA_colorSatMax->setGeometry(QRect(370, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorSatMax->sizePolicy().hasHeightForWidth());
        knobA_colorSatMax->setSizePolicy(sizePolicy);
        knobA_colorValMax = new QLineEdit(knobABox);
        knobA_colorValMax->setObjectName(QStringLiteral("knobA_colorValMax"));
        knobA_colorValMax->setGeometry(QRect(510, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobA_colorValMax->sizePolicy().hasHeightForWidth());
        knobA_colorValMax->setSizePolicy(sizePolicy);
        knobA_isView = new QRadioButton(knobABox);
        viewButtonGroup = new QButtonGroup(MainWindow);
        viewButtonGroup->setObjectName(QStringLiteral("viewButtonGroup"));
        viewButtonGroup->addButton(knobA_isView);
        knobA_isView->setObjectName(QStringLiteral("knobA_isView"));
        knobA_isView->setGeometry(QRect(1250, 20, 17, 17));
        knobA_isView->setChecked(true);
        knobA_isView->setAutoExclusive(false);
        label_hueMax = new QLabel(centralWidget);
        label_hueMax->setObjectName(QStringLiteral("label_hueMax"));
        label_hueMax->setGeometry(QRect(230, 530, 50, 16));
        label_hueMax->setFont(font);
        label_hueMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_satMin = new QLabel(centralWidget);
        label_satMin->setObjectName(QStringLiteral("label_satMin"));
        label_satMin->setGeometry(QRect(370, 530, 50, 16));
        label_satMin->setFont(font);
        label_satMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_valMin = new QLabel(centralWidget);
        label_valMin->setObjectName(QStringLiteral("label_valMin"));
        label_valMin->setGeometry(QRect(510, 530, 50, 16));
        label_valMin->setFont(font);
        label_valMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_active = new QLabel(centralWidget);
        label_active->setObjectName(QStringLiteral("label_active"));
        label_active->setGeometry(QRect(150, 530, 51, 16));
        label_active->setFont(font);
        label_active->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_xCoords = new QLabel(centralWidget);
        label_xCoords->setObjectName(QStringLiteral("label_xCoords"));
        label_xCoords->setGeometry(QRect(850, 530, 71, 16));
        label_xCoords->setFont(font);
        label_xCoords->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_yCoords = new QLabel(centralWidget);
        label_yCoords->setObjectName(QStringLiteral("label_yCoords"));
        label_yCoords->setGeometry(QRect(1000, 530, 71, 16));
        label_yCoords->setFont(font);
        label_yCoords->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_zCoords = new QLabel(centralWidget);
        label_zCoords->setObjectName(QStringLiteral("label_zCoords"));
        label_zCoords->setGeometry(QRect(1150, 530, 71, 16));
        label_zCoords->setFont(font);
        label_zCoords->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_color = new QLabel(centralWidget);
        label_color->setObjectName(QStringLiteral("label_color"));
        label_color->setGeometry(QRect(695, 530, 51, 16));
        label_color->setFont(font);
        label_color->setAlignment(Qt::AlignCenter);
        label_hueMin = new QLabel(centralWidget);
        label_hueMin->setObjectName(QStringLiteral("label_hueMin"));
        label_hueMin->setGeometry(QRect(280, 530, 50, 16));
        label_hueMin->setFont(font);
        label_hueMin->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_satMax = new QLabel(centralWidget);
        label_satMax->setObjectName(QStringLiteral("label_satMax"));
        label_satMax->setGeometry(QRect(420, 530, 50, 16));
        label_satMax->setFont(font);
        label_satMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_valMax = new QLabel(centralWidget);
        label_valMax->setObjectName(QStringLiteral("label_valMax"));
        label_valMax->setGeometry(QRect(560, 530, 50, 16));
        label_valMax->setFont(font);
        label_valMax->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        knobBBox = new QGroupBox(centralWidget);
        knobBBox->setObjectName(QStringLiteral("knobBBox"));
        knobBBox->setGeometry(QRect(50, 620, 1341, 51));
        knobBBox->setFont(font);
        knobB_isActive = new QCheckBox(knobBBox);
        knobB_isActive->setObjectName(QStringLiteral("knobB_isActive"));
        knobB_isActive->setGeometry(QRect(100, 20, 16, 20));
        knobB_isActive->setFont(font1);
        knobB_isActive->setChecked(false);
        knobB_colorHueMin = new QLineEdit(knobBBox);
        knobB_colorHueMin->setObjectName(QStringLiteral("knobB_colorHueMin"));
        knobB_colorHueMin->setGeometry(QRect(180, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorHueMin->sizePolicy().hasHeightForWidth());
        knobB_colorHueMin->setSizePolicy(sizePolicy);
        knobB_colorHueMin->setMinimumSize(QSize(0, 0));
        knobB_colorHueMin->setBaseSize(QSize(0, 0));
        knobB_colorSatMin = new QLineEdit(knobBBox);
        knobB_colorSatMin->setObjectName(QStringLiteral("knobB_colorSatMin"));
        knobB_colorSatMin->setGeometry(QRect(320, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorSatMin->sizePolicy().hasHeightForWidth());
        knobB_colorSatMin->setSizePolicy(sizePolicy);
        knobB_colorValMin = new QLineEdit(knobBBox);
        knobB_colorValMin->setObjectName(QStringLiteral("knobB_colorValMin"));
        knobB_colorValMin->setGeometry(QRect(460, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorValMin->sizePolicy().hasHeightForWidth());
        knobB_colorValMin->setSizePolicy(sizePolicy);
        knobB_xCoordsLabel = new QLabel(knobBBox);
        knobB_xCoordsLabel->setObjectName(QStringLiteral("knobB_xCoordsLabel"));
        knobB_xCoordsLabel->setGeometry(QRect(800, 21, 51, 20));
        knobB_xCoordsLabel->setFont(font1);
        knobB_yCoordsLabel = new QLabel(knobBBox);
        knobB_yCoordsLabel->setObjectName(QStringLiteral("knobB_yCoordsLabel"));
        knobB_yCoordsLabel->setGeometry(QRect(950, 20, 61, 20));
        knobB_yCoordsLabel->setFont(font1);
        knobB_zCoordsLabel = new QLabel(knobBBox);
        knobB_zCoordsLabel->setObjectName(QStringLiteral("knobB_zCoordsLabel"));
        knobB_zCoordsLabel->setGeometry(QRect(1100, 20, 61, 20));
        knobB_zCoordsLabel->setFont(font1);
        knobB_colorLabel = new QLabel(knobBBox);
        knobB_colorLabel->setObjectName(QStringLiteral("knobB_colorLabel"));
        knobB_colorLabel->setGeometry(QRect(660, 20, 20, 20));
        knobB_colorLabel->setFrameShape(QFrame::Box);
        knobB_colorLabel->setLineWidth(2);
        knobB_colorHueMax = new QLineEdit(knobBBox);
        knobB_colorHueMax->setObjectName(QStringLiteral("knobB_colorHueMax"));
        knobB_colorHueMax->setGeometry(QRect(230, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorHueMax->sizePolicy().hasHeightForWidth());
        knobB_colorHueMax->setSizePolicy(sizePolicy);
        knobB_colorHueMax->setMinimumSize(QSize(0, 0));
        knobB_colorHueMax->setBaseSize(QSize(0, 0));
        knobB_colorSatMax = new QLineEdit(knobBBox);
        knobB_colorSatMax->setObjectName(QStringLiteral("knobB_colorSatMax"));
        knobB_colorSatMax->setGeometry(QRect(370, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorSatMax->sizePolicy().hasHeightForWidth());
        knobB_colorSatMax->setSizePolicy(sizePolicy);
        knobB_colorValMax = new QLineEdit(knobBBox);
        knobB_colorValMax->setObjectName(QStringLiteral("knobB_colorValMax"));
        knobB_colorValMax->setGeometry(QRect(510, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobB_colorValMax->sizePolicy().hasHeightForWidth());
        knobB_colorValMax->setSizePolicy(sizePolicy);
        knobB_isView = new QRadioButton(knobBBox);
        viewButtonGroup->addButton(knobB_isView);
        knobB_isView->setObjectName(QStringLiteral("knobB_isView"));
        knobB_isView->setGeometry(QRect(1250, 20, 17, 17));
        knobB_isView->setAutoExclusive(false);
        knobCBox = new QGroupBox(centralWidget);
        knobCBox->setObjectName(QStringLiteral("knobCBox"));
        knobCBox->setGeometry(QRect(50, 690, 1341, 51));
        knobCBox->setFont(font);
        knobC_isActive = new QCheckBox(knobCBox);
        knobC_isActive->setObjectName(QStringLiteral("knobC_isActive"));
        knobC_isActive->setGeometry(QRect(100, 20, 16, 20));
        knobC_isActive->setFont(font1);
        knobC_isActive->setChecked(false);
        knobC_colorHueMin = new QLineEdit(knobCBox);
        knobC_colorHueMin->setObjectName(QStringLiteral("knobC_colorHueMin"));
        knobC_colorHueMin->setGeometry(QRect(180, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorHueMin->sizePolicy().hasHeightForWidth());
        knobC_colorHueMin->setSizePolicy(sizePolicy);
        knobC_colorHueMin->setMinimumSize(QSize(0, 0));
        knobC_colorHueMin->setBaseSize(QSize(0, 0));
        knobC_colorSatMin = new QLineEdit(knobCBox);
        knobC_colorSatMin->setObjectName(QStringLiteral("knobC_colorSatMin"));
        knobC_colorSatMin->setGeometry(QRect(320, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorSatMin->sizePolicy().hasHeightForWidth());
        knobC_colorSatMin->setSizePolicy(sizePolicy);
        knobC_colorValMin = new QLineEdit(knobCBox);
        knobC_colorValMin->setObjectName(QStringLiteral("knobC_colorValMin"));
        knobC_colorValMin->setGeometry(QRect(460, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorValMin->sizePolicy().hasHeightForWidth());
        knobC_colorValMin->setSizePolicy(sizePolicy);
        knobC_xCoordsLabel = new QLabel(knobCBox);
        knobC_xCoordsLabel->setObjectName(QStringLiteral("knobC_xCoordsLabel"));
        knobC_xCoordsLabel->setGeometry(QRect(800, 21, 51, 20));
        knobC_xCoordsLabel->setFont(font1);
        knobC_yCoordsLabel = new QLabel(knobCBox);
        knobC_yCoordsLabel->setObjectName(QStringLiteral("knobC_yCoordsLabel"));
        knobC_yCoordsLabel->setGeometry(QRect(950, 20, 61, 20));
        knobC_yCoordsLabel->setFont(font1);
        knobC_zCoordsLabel = new QLabel(knobCBox);
        knobC_zCoordsLabel->setObjectName(QStringLiteral("knobC_zCoordsLabel"));
        knobC_zCoordsLabel->setGeometry(QRect(1100, 20, 61, 20));
        knobC_zCoordsLabel->setFont(font1);
        knobC_colorLabel = new QLabel(knobCBox);
        knobC_colorLabel->setObjectName(QStringLiteral("knobC_colorLabel"));
        knobC_colorLabel->setGeometry(QRect(660, 20, 20, 20));
        knobC_colorLabel->setFrameShape(QFrame::Box);
        knobC_colorLabel->setLineWidth(2);
        knobC_colorHueMax = new QLineEdit(knobCBox);
        knobC_colorHueMax->setObjectName(QStringLiteral("knobC_colorHueMax"));
        knobC_colorHueMax->setGeometry(QRect(230, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorHueMax->sizePolicy().hasHeightForWidth());
        knobC_colorHueMax->setSizePolicy(sizePolicy);
        knobC_colorHueMax->setMinimumSize(QSize(0, 0));
        knobC_colorHueMax->setBaseSize(QSize(0, 0));
        knobC_colorSatMax = new QLineEdit(knobCBox);
        knobC_colorSatMax->setObjectName(QStringLiteral("knobC_colorSatMax"));
        knobC_colorSatMax->setGeometry(QRect(370, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorSatMax->sizePolicy().hasHeightForWidth());
        knobC_colorSatMax->setSizePolicy(sizePolicy);
        knobC_colorValMax = new QLineEdit(knobCBox);
        knobC_colorValMax->setObjectName(QStringLiteral("knobC_colorValMax"));
        knobC_colorValMax->setGeometry(QRect(510, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobC_colorValMax->sizePolicy().hasHeightForWidth());
        knobC_colorValMax->setSizePolicy(sizePolicy);
        knobC_isView = new QRadioButton(knobCBox);
        viewButtonGroup->addButton(knobC_isView);
        knobC_isView->setObjectName(QStringLiteral("knobC_isView"));
        knobC_isView->setGeometry(QRect(1250, 20, 17, 17));
        knobC_isView->setAutoExclusive(false);
        knobDBox = new QGroupBox(centralWidget);
        knobDBox->setObjectName(QStringLiteral("knobDBox"));
        knobDBox->setGeometry(QRect(50, 760, 1341, 51));
        knobDBox->setFont(font);
        knobD_isActive = new QCheckBox(knobDBox);
        knobD_isActive->setObjectName(QStringLiteral("knobD_isActive"));
        knobD_isActive->setGeometry(QRect(100, 20, 16, 20));
        knobD_isActive->setFont(font1);
        knobD_isActive->setChecked(false);
        knobD_colorHueMin = new QLineEdit(knobDBox);
        knobD_colorHueMin->setObjectName(QStringLiteral("knobD_colorHueMin"));
        knobD_colorHueMin->setGeometry(QRect(180, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorHueMin->sizePolicy().hasHeightForWidth());
        knobD_colorHueMin->setSizePolicy(sizePolicy);
        knobD_colorHueMin->setMinimumSize(QSize(0, 0));
        knobD_colorHueMin->setBaseSize(QSize(0, 0));
        knobD_colorSatMin = new QLineEdit(knobDBox);
        knobD_colorSatMin->setObjectName(QStringLiteral("knobD_colorSatMin"));
        knobD_colorSatMin->setGeometry(QRect(320, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorSatMin->sizePolicy().hasHeightForWidth());
        knobD_colorSatMin->setSizePolicy(sizePolicy);
        knobD_colorValMin = new QLineEdit(knobDBox);
        knobD_colorValMin->setObjectName(QStringLiteral("knobD_colorValMin"));
        knobD_colorValMin->setGeometry(QRect(460, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorValMin->sizePolicy().hasHeightForWidth());
        knobD_colorValMin->setSizePolicy(sizePolicy);
        knobD_xCoordsLabel = new QLabel(knobDBox);
        knobD_xCoordsLabel->setObjectName(QStringLiteral("knobD_xCoordsLabel"));
        knobD_xCoordsLabel->setGeometry(QRect(800, 21, 51, 20));
        knobD_xCoordsLabel->setFont(font1);
        knobD_yCoordsLabel = new QLabel(knobDBox);
        knobD_yCoordsLabel->setObjectName(QStringLiteral("knobD_yCoordsLabel"));
        knobD_yCoordsLabel->setGeometry(QRect(950, 20, 61, 20));
        knobD_yCoordsLabel->setFont(font1);
        knobD_zCoordsLabel = new QLabel(knobDBox);
        knobD_zCoordsLabel->setObjectName(QStringLiteral("knobD_zCoordsLabel"));
        knobD_zCoordsLabel->setGeometry(QRect(1100, 20, 61, 20));
        knobD_zCoordsLabel->setFont(font1);
        knobD_colorLabel = new QLabel(knobDBox);
        knobD_colorLabel->setObjectName(QStringLiteral("knobD_colorLabel"));
        knobD_colorLabel->setGeometry(QRect(660, 20, 20, 20));
        knobD_colorLabel->setFrameShape(QFrame::Box);
        knobD_colorLabel->setLineWidth(2);
        knobD_colorHueMax = new QLineEdit(knobDBox);
        knobD_colorHueMax->setObjectName(QStringLiteral("knobD_colorHueMax"));
        knobD_colorHueMax->setGeometry(QRect(230, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorHueMax->sizePolicy().hasHeightForWidth());
        knobD_colorHueMax->setSizePolicy(sizePolicy);
        knobD_colorHueMax->setMinimumSize(QSize(0, 0));
        knobD_colorHueMax->setBaseSize(QSize(0, 0));
        knobD_colorSatMax = new QLineEdit(knobDBox);
        knobD_colorSatMax->setObjectName(QStringLiteral("knobD_colorSatMax"));
        knobD_colorSatMax->setGeometry(QRect(370, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorSatMax->sizePolicy().hasHeightForWidth());
        knobD_colorSatMax->setSizePolicy(sizePolicy);
        knobD_colorValMax = new QLineEdit(knobDBox);
        knobD_colorValMax->setObjectName(QStringLiteral("knobD_colorValMax"));
        knobD_colorValMax->setGeometry(QRect(510, 20, 30, 20));
        sizePolicy.setHeightForWidth(knobD_colorValMax->sizePolicy().hasHeightForWidth());
        knobD_colorValMax->setSizePolicy(sizePolicy);
        knobD_isView = new QRadioButton(knobDBox);
        viewButtonGroup->addButton(knobD_isView);
        knobD_isView->setObjectName(QStringLiteral("knobD_isView"));
        knobD_isView->setGeometry(QRect(1250, 20, 17, 17));
        knobD_isView->setAutoExclusive(false);
        label_zCoords_2 = new QLabel(centralWidget);
        label_zCoords_2->setObjectName(QStringLiteral("label_zCoords_2"));
        label_zCoords_2->setGeometry(QRect(1300, 530, 31, 16));
        label_zCoords_2->setFont(font);
        label_zCoords_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        options_blur = new QCheckBox(centralWidget);
        options_blur->setObjectName(QStringLiteral("options_blur"));
        options_blur->setGeometry(QRect(80, 820, 91, 20));
        options_blur->setFont(font1);
        options_blur->setChecked(true);
        options_erode = new QCheckBox(centralWidget);
        options_erode->setObjectName(QStringLiteral("options_erode"));
        options_erode->setGeometry(QRect(170, 820, 91, 20));
        options_erode->setFont(font1);
        options_erode->setChecked(true);
        options_dilate = new QCheckBox(centralWidget);
        options_dilate->setObjectName(QStringLiteral("options_dilate"));
        options_dilate->setGeometry(QRect(260, 820, 91, 20));
        options_dilate->setFont(font1);
        options_dilate->setChecked(true);
        midiDeviceID = new QLineEdit(centralWidget);
        midiDeviceID->setObjectName(QStringLiteral("midiDeviceID"));
        midiDeviceID->setGeometry(QRect(950, 820, 30, 20));
        sizePolicy.setHeightForWidth(midiDeviceID->sizePolicy().hasHeightForWidth());
        midiDeviceID->setSizePolicy(sizePolicy);
        midiDeviceID->setMinimumSize(QSize(0, 0));
        midiDeviceID->setBaseSize(QSize(0, 0));
        label_midiDevID = new QLabel(centralWidget);
        label_midiDevID->setObjectName(QStringLiteral("label_midiDevID"));
        label_midiDevID->setGeometry(QRect(800, 820, 141, 20));
        label_midiDevID->setFont(font);
        label_midiDevID->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        isView_all = new QRadioButton(centralWidget);
        viewButtonGroup->addButton(isView_all);
        isView_all->setObjectName(QStringLiteral("isView_all"));
        isView_all->setGeometry(QRect(1300, 820, 71, 17));
        isView_all->setFont(font);
        isView_all->setAutoExclusive(false);
        label_midiSendRate = new QLabel(centralWidget);
        label_midiSendRate->setObjectName(QStringLiteral("label_midiSendRate"));
        label_midiSendRate->setGeometry(QRect(1010, 820, 141, 20));
        label_midiSendRate->setFont(font);
        label_midiSendRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        midiSendRate = new QLineEdit(centralWidget);
        midiSendRate->setObjectName(QStringLiteral("midiSendRate"));
        midiSendRate->setGeometry(QRect(1160, 820, 30, 20));
        sizePolicy.setHeightForWidth(midiSendRate->sizePolicy().hasHeightForWidth());
        midiSendRate->setSizePolicy(sizePolicy);
        midiSendRate->setMinimumSize(QSize(0, 0));
        midiSendRate->setBaseSize(QSize(0, 0));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1440, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(knobA_isActive, knobA_colorHueMin);
        QWidget::setTabOrder(knobA_colorHueMin, knobA_colorHueMax);
        QWidget::setTabOrder(knobA_colorHueMax, knobA_colorSatMin);
        QWidget::setTabOrder(knobA_colorSatMin, knobA_colorSatMax);
        QWidget::setTabOrder(knobA_colorSatMax, knobA_colorValMin);
        QWidget::setTabOrder(knobA_colorValMin, knobA_colorValMax);
        QWidget::setTabOrder(knobA_colorValMax, knobA_isView);
        QWidget::setTabOrder(knobA_isView, knobB_isActive);
        QWidget::setTabOrder(knobB_isActive, knobB_colorHueMin);
        QWidget::setTabOrder(knobB_colorHueMin, knobB_colorHueMax);
        QWidget::setTabOrder(knobB_colorHueMax, knobB_colorSatMin);
        QWidget::setTabOrder(knobB_colorSatMin, knobB_colorSatMax);
        QWidget::setTabOrder(knobB_colorSatMax, knobB_colorValMin);
        QWidget::setTabOrder(knobB_colorValMin, knobB_colorValMax);
        QWidget::setTabOrder(knobB_colorValMax, knobB_isView);
        QWidget::setTabOrder(knobB_isView, knobC_isActive);
        QWidget::setTabOrder(knobC_isActive, knobC_colorHueMin);
        QWidget::setTabOrder(knobC_colorHueMin, knobC_colorHueMax);
        QWidget::setTabOrder(knobC_colorHueMax, knobC_colorSatMin);
        QWidget::setTabOrder(knobC_colorSatMin, knobC_colorSatMax);
        QWidget::setTabOrder(knobC_colorSatMax, knobC_colorValMin);
        QWidget::setTabOrder(knobC_colorValMin, knobC_colorValMax);
        QWidget::setTabOrder(knobC_colorValMax, knobC_isView);
        QWidget::setTabOrder(knobC_isView, knobD_isActive);
        QWidget::setTabOrder(knobD_isActive, knobD_colorHueMin);
        QWidget::setTabOrder(knobD_colorHueMin, knobD_colorHueMax);
        QWidget::setTabOrder(knobD_colorHueMax, knobD_colorSatMin);
        QWidget::setTabOrder(knobD_colorSatMin, knobD_colorSatMax);
        QWidget::setTabOrder(knobD_colorSatMax, knobD_colorValMin);
        QWidget::setTabOrder(knobD_colorValMin, knobD_colorValMax);
        QWidget::setTabOrder(knobD_colorValMax, knobD_isView);
        QWidget::setTabOrder(knobD_isView, options_blur);
        QWidget::setTabOrder(options_blur, options_erode);
        QWidget::setTabOrder(options_erode, options_dilate);
        QWidget::setTabOrder(options_dilate, midiDeviceID);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "3DMixer Tracker", Q_NULLPTR));
        inputFrame->setText(QString());
        outputFrame->setText(QString());
        knobABox->setTitle(QApplication::translate("MainWindow", "Knob A", Q_NULLPTR));
        knobA_isActive->setText(QString());
        knobA_colorHueMin->setText(QApplication::translate("MainWindow", "350", Q_NULLPTR));
        knobA_colorSatMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobA_colorValMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobA_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_colorLabel->setText(QString());
        knobA_colorHueMax->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        knobA_colorSatMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobA_colorValMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobA_isView->setText(QString());
        label_hueMax->setText(QApplication::translate("MainWindow", "MinHue", Q_NULLPTR));
        label_satMin->setText(QApplication::translate("MainWindow", "MinSat", Q_NULLPTR));
        label_valMin->setText(QApplication::translate("MainWindow", "MinVal", Q_NULLPTR));
        label_active->setText(QApplication::translate("MainWindow", "Active", Q_NULLPTR));
        label_xCoords->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_yCoords->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_zCoords->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_color->setText(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        label_hueMin->setText(QApplication::translate("MainWindow", "MaxHue", Q_NULLPTR));
        label_satMax->setText(QApplication::translate("MainWindow", "MaxSat", Q_NULLPTR));
        label_valMax->setText(QApplication::translate("MainWindow", "MaxVal", Q_NULLPTR));
        knobBBox->setTitle(QApplication::translate("MainWindow", "Knob B", Q_NULLPTR));
        knobB_isActive->setText(QString());
        knobB_colorHueMin->setText(QApplication::translate("MainWindow", "110", Q_NULLPTR));
        knobB_colorSatMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobB_colorValMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobB_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_colorLabel->setText(QString());
        knobB_colorHueMax->setText(QApplication::translate("MainWindow", "130", Q_NULLPTR));
        knobB_colorSatMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobB_colorValMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobB_isView->setText(QString());
        knobCBox->setTitle(QApplication::translate("MainWindow", "Knob C", Q_NULLPTR));
        knobC_isActive->setText(QString());
        knobC_colorHueMin->setText(QApplication::translate("MainWindow", "230", Q_NULLPTR));
        knobC_colorSatMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobC_colorValMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobC_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_colorLabel->setText(QString());
        knobC_colorHueMax->setText(QApplication::translate("MainWindow", "250", Q_NULLPTR));
        knobC_colorSatMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobC_colorValMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobC_isView->setText(QString());
        knobDBox->setTitle(QApplication::translate("MainWindow", "Knob D", Q_NULLPTR));
        knobD_isActive->setText(QString());
        knobD_colorHueMin->setText(QApplication::translate("MainWindow", "50", Q_NULLPTR));
        knobD_colorSatMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobD_colorValMin->setText(QApplication::translate("MainWindow", "80", Q_NULLPTR));
        knobD_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_colorLabel->setText(QString());
        knobD_colorHueMax->setText(QApplication::translate("MainWindow", "70", Q_NULLPTR));
        knobD_colorSatMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobD_colorValMax->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        knobD_isView->setText(QString());
        label_zCoords_2->setText(QApplication::translate("MainWindow", "View", Q_NULLPTR));
        options_blur->setText(QApplication::translate("MainWindow", "Median Blur", Q_NULLPTR));
        options_erode->setText(QApplication::translate("MainWindow", "Erode", Q_NULLPTR));
        options_dilate->setText(QApplication::translate("MainWindow", "Dilate", Q_NULLPTR));
        midiDeviceID->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        label_midiDevID->setText(QApplication::translate("MainWindow", "MIDI Device ID:", Q_NULLPTR));
        isView_all->setText(QApplication::translate("MainWindow", "View All", Q_NULLPTR));
        label_midiSendRate->setText(QApplication::translate("MainWindow", "MIDI Send Rate (ms):", Q_NULLPTR));
        midiSendRate->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
