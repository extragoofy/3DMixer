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
    QLineEdit *knobA_colorHue;
    QLineEdit *knobA_colorSaturation;
    QLineEdit *knobA_colorValue;
    QLabel *knobA_xCoordsLabel;
    QLabel *knobA_yCoordsLabel;
    QLabel *knobA_zCoordsLabel;
    QLabel *knobA_colorLabel;
    QLabel *label_hue;
    QLabel *label_saturation;
    QLabel *label_value;
    QLabel *label_active;
    QLabel *label_xCoords;
    QLabel *label_yCoords;
    QLabel *label_zCoords;
    QLabel *label_color;
    QGroupBox *knobBBox;
    QCheckBox *knobB_isActive;
    QLineEdit *knobB_colorHue;
    QLineEdit *knobB_colorSaturation;
    QLineEdit *knobB_colorValue;
    QLabel *knobB_xCoordsLabel;
    QLabel *knobB_yCoordsLabel;
    QLabel *knobB_zCoordsLabel;
    QLabel *knobB_colorLabel;
    QGroupBox *knobCBox;
    QCheckBox *knobC_isActive;
    QLineEdit *knobC_colorHue;
    QLineEdit *knobC_colorSaturation;
    QLineEdit *knobC_colorValue;
    QLabel *knobC_xCoordsLabel;
    QLabel *knobC_yCoordsLabel;
    QLabel *knobC_zCoordsLabel;
    QLabel *knobC_colorLabel;
    QGroupBox *knobDBox;
    QCheckBox *knobD_isActive;
    QLineEdit *knobD_colorHue;
    QLineEdit *knobD_colorSaturation;
    QLineEdit *knobD_colorValue;
    QLabel *knobD_xCoordsLabel;
    QLabel *knobD_yCoordsLabel;
    QLabel *knobD_zCoordsLabel;
    QLabel *knobD_colorLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1440, 900);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inputFrame = new VideoWidget(centralWidget);
        inputFrame->setObjectName(QStringLiteral("inputFrame"));
        inputFrame->setGeometry(QRect(10, 10, 640, 480));
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
        knobA_isActive->setGeometry(QRect(99, 20, 51, 20));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        knobA_isActive->setFont(font1);
        knobA_colorHue = new QLineEdit(knobABox);
        knobA_colorHue->setObjectName(QStringLiteral("knobA_colorHue"));
        knobA_colorHue->setGeometry(QRect(210, 20, 50, 20));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(knobA_colorHue->sizePolicy().hasHeightForWidth());
        knobA_colorHue->setSizePolicy(sizePolicy);
        knobA_colorHue->setMinimumSize(QSize(0, 0));
        knobA_colorHue->setBaseSize(QSize(0, 0));
        knobA_colorSaturation = new QLineEdit(knobABox);
        knobA_colorSaturation->setObjectName(QStringLiteral("knobA_colorSaturation"));
        knobA_colorSaturation->setGeometry(QRect(360, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobA_colorSaturation->sizePolicy().hasHeightForWidth());
        knobA_colorSaturation->setSizePolicy(sizePolicy);
        knobA_colorValue = new QLineEdit(knobABox);
        knobA_colorValue->setObjectName(QStringLiteral("knobA_colorValue"));
        knobA_colorValue->setGeometry(QRect(510, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobA_colorValue->sizePolicy().hasHeightForWidth());
        knobA_colorValue->setSizePolicy(sizePolicy);
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
        knobA_colorLabel->setGeometry(QRect(650, 20, 20, 20));
        knobA_colorLabel->setFrameShape(QFrame::Box);
        knobA_colorLabel->setLineWidth(2);
        label_hue = new QLabel(centralWidget);
        label_hue->setObjectName(QStringLiteral("label_hue"));
        label_hue->setGeometry(QRect(260, 530, 51, 16));
        label_hue->setFont(font);
        label_hue->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_saturation = new QLabel(centralWidget);
        label_saturation->setObjectName(QStringLiteral("label_saturation"));
        label_saturation->setGeometry(QRect(410, 530, 71, 16));
        label_saturation->setFont(font);
        label_saturation->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_value = new QLabel(centralWidget);
        label_value->setObjectName(QStringLiteral("label_value"));
        label_value->setGeometry(QRect(560, 530, 71, 16));
        label_value->setFont(font);
        label_value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
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
        label_color->setGeometry(QRect(685, 530, 51, 16));
        label_color->setFont(font);
        label_color->setAlignment(Qt::AlignCenter);
        knobBBox = new QGroupBox(centralWidget);
        knobBBox->setObjectName(QStringLiteral("knobBBox"));
        knobBBox->setGeometry(QRect(50, 620, 1341, 51));
        knobBBox->setFont(font);
        knobB_isActive = new QCheckBox(knobBBox);
        knobB_isActive->setObjectName(QStringLiteral("knobB_isActive"));
        knobB_isActive->setGeometry(QRect(99, 20, 51, 20));
        knobB_isActive->setFont(font1);
        knobB_colorHue = new QLineEdit(knobBBox);
        knobB_colorHue->setObjectName(QStringLiteral("knobB_colorHue"));
        knobB_colorHue->setGeometry(QRect(210, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobB_colorHue->sizePolicy().hasHeightForWidth());
        knobB_colorHue->setSizePolicy(sizePolicy);
        knobB_colorHue->setMinimumSize(QSize(0, 0));
        knobB_colorHue->setBaseSize(QSize(0, 0));
        knobB_colorSaturation = new QLineEdit(knobBBox);
        knobB_colorSaturation->setObjectName(QStringLiteral("knobB_colorSaturation"));
        knobB_colorSaturation->setGeometry(QRect(360, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobB_colorSaturation->sizePolicy().hasHeightForWidth());
        knobB_colorSaturation->setSizePolicy(sizePolicy);
        knobB_colorValue = new QLineEdit(knobBBox);
        knobB_colorValue->setObjectName(QStringLiteral("knobB_colorValue"));
        knobB_colorValue->setGeometry(QRect(510, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobB_colorValue->sizePolicy().hasHeightForWidth());
        knobB_colorValue->setSizePolicy(sizePolicy);
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
        knobB_colorLabel->setGeometry(QRect(650, 20, 20, 20));
        knobB_colorLabel->setFrameShape(QFrame::Box);
        knobB_colorLabel->setLineWidth(2);
        knobCBox = new QGroupBox(centralWidget);
        knobCBox->setObjectName(QStringLiteral("knobCBox"));
        knobCBox->setGeometry(QRect(50, 690, 1341, 51));
        knobCBox->setFont(font);
        knobC_isActive = new QCheckBox(knobCBox);
        knobC_isActive->setObjectName(QStringLiteral("knobC_isActive"));
        knobC_isActive->setGeometry(QRect(99, 20, 51, 20));
        knobC_isActive->setFont(font1);
        knobC_colorHue = new QLineEdit(knobCBox);
        knobC_colorHue->setObjectName(QStringLiteral("knobC_colorHue"));
        knobC_colorHue->setGeometry(QRect(210, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobC_colorHue->sizePolicy().hasHeightForWidth());
        knobC_colorHue->setSizePolicy(sizePolicy);
        knobC_colorHue->setMinimumSize(QSize(0, 0));
        knobC_colorHue->setBaseSize(QSize(0, 0));
        knobC_colorSaturation = new QLineEdit(knobCBox);
        knobC_colorSaturation->setObjectName(QStringLiteral("knobC_colorSaturation"));
        knobC_colorSaturation->setGeometry(QRect(360, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobC_colorSaturation->sizePolicy().hasHeightForWidth());
        knobC_colorSaturation->setSizePolicy(sizePolicy);
        knobC_colorValue = new QLineEdit(knobCBox);
        knobC_colorValue->setObjectName(QStringLiteral("knobC_colorValue"));
        knobC_colorValue->setGeometry(QRect(510, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobC_colorValue->sizePolicy().hasHeightForWidth());
        knobC_colorValue->setSizePolicy(sizePolicy);
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
        knobC_colorLabel->setGeometry(QRect(650, 20, 20, 20));
        knobC_colorLabel->setFrameShape(QFrame::Box);
        knobC_colorLabel->setLineWidth(2);
        knobDBox = new QGroupBox(centralWidget);
        knobDBox->setObjectName(QStringLiteral("knobDBox"));
        knobDBox->setGeometry(QRect(50, 760, 1341, 51));
        knobDBox->setFont(font);
        knobD_isActive = new QCheckBox(knobDBox);
        knobD_isActive->setObjectName(QStringLiteral("knobD_isActive"));
        knobD_isActive->setGeometry(QRect(99, 20, 51, 20));
        knobD_isActive->setFont(font1);
        knobD_colorHue = new QLineEdit(knobDBox);
        knobD_colorHue->setObjectName(QStringLiteral("knobD_colorHue"));
        knobD_colorHue->setGeometry(QRect(210, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobD_colorHue->sizePolicy().hasHeightForWidth());
        knobD_colorHue->setSizePolicy(sizePolicy);
        knobD_colorHue->setMinimumSize(QSize(0, 0));
        knobD_colorHue->setBaseSize(QSize(0, 0));
        knobD_colorSaturation = new QLineEdit(knobDBox);
        knobD_colorSaturation->setObjectName(QStringLiteral("knobD_colorSaturation"));
        knobD_colorSaturation->setGeometry(QRect(360, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobD_colorSaturation->sizePolicy().hasHeightForWidth());
        knobD_colorSaturation->setSizePolicy(sizePolicy);
        knobD_colorValue = new QLineEdit(knobDBox);
        knobD_colorValue->setObjectName(QStringLiteral("knobD_colorValue"));
        knobD_colorValue->setGeometry(QRect(510, 20, 50, 20));
        sizePolicy.setHeightForWidth(knobD_colorValue->sizePolicy().hasHeightForWidth());
        knobD_colorValue->setSizePolicy(sizePolicy);
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
        knobD_colorLabel->setGeometry(QRect(650, 20, 20, 20));
        knobD_colorLabel->setFrameShape(QFrame::Box);
        knobD_colorLabel->setLineWidth(2);
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

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        inputFrame->setText(QString());
        outputFrame->setText(QString());
        knobABox->setTitle(QApplication::translate("MainWindow", "Knob A", Q_NULLPTR));
        knobA_isActive->setText(QString());
        knobA_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobA_colorLabel->setText(QString());
        label_hue->setText(QApplication::translate("MainWindow", "Hue", Q_NULLPTR));
        label_saturation->setText(QApplication::translate("MainWindow", "Saturation", Q_NULLPTR));
        label_value->setText(QApplication::translate("MainWindow", "Value", Q_NULLPTR));
        label_active->setText(QApplication::translate("MainWindow", "Active", Q_NULLPTR));
        label_xCoords->setText(QApplication::translate("MainWindow", "X", Q_NULLPTR));
        label_yCoords->setText(QApplication::translate("MainWindow", "Y", Q_NULLPTR));
        label_zCoords->setText(QApplication::translate("MainWindow", "Z", Q_NULLPTR));
        label_color->setText(QApplication::translate("MainWindow", "Color", Q_NULLPTR));
        knobBBox->setTitle(QApplication::translate("MainWindow", "Knob B", Q_NULLPTR));
        knobB_isActive->setText(QString());
        knobB_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobB_colorLabel->setText(QString());
        knobCBox->setTitle(QApplication::translate("MainWindow", "Knob C", Q_NULLPTR));
        knobC_isActive->setText(QString());
        knobC_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobC_colorLabel->setText(QString());
        knobDBox->setTitle(QApplication::translate("MainWindow", "Knob D", Q_NULLPTR));
        knobD_isActive->setText(QString());
        knobD_xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        knobD_colorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
