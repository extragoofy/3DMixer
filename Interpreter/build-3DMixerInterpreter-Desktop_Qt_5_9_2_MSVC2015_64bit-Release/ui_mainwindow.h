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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *xCoordsLabel;
    QLabel *yCoordsLabel;
    QLabel *zCoordsLabel;
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
        xCoordsLabel = new QLabel(centralWidget);
        xCoordsLabel->setObjectName(QStringLiteral("xCoordsLabel"));
        xCoordsLabel->setGeometry(QRect(920, 540, 47, 13));
        yCoordsLabel = new QLabel(centralWidget);
        yCoordsLabel->setObjectName(QStringLiteral("yCoordsLabel"));
        yCoordsLabel->setGeometry(QRect(1020, 540, 47, 13));
        zCoordsLabel = new QLabel(centralWidget);
        zCoordsLabel->setObjectName(QStringLiteral("zCoordsLabel"));
        zCoordsLabel->setGeometry(QRect(1120, 540, 47, 13));
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
        xCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        yCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        zCoordsLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
