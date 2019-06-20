/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *ReferenceButton;
    QLineEdit *ReferenceStructurePath;
    QPushButton *SelectPpbs;
    QPushButton *SelectPqrs;
    QPushButton *Run;
    QPushButton *Input;
    QLineEdit *InputPath;
    QPushButton *DisplayX;
    QLineEdit *DisplayXValue;
    QLineEdit *DisplayYValue;
    QPushButton *DisplayY;
    QPushButton *apbsInButton;
    QLineEdit *apbsInText;
    QPushButton *RunImageCreator;
    QPushButton *Stop;
    QLineEdit *ColumnsValue;
    QPushButton *Columns;
    QLineEdit *ImageCreatorQuality_2;
    QPushButton *ImageCreatorQuality;
    QTextEdit *Console;
    QCheckBox *pdb2pqr;
    QCheckBox *vmd;
    QCheckBox *doImageCreator;
    QCheckBox *doMovieCreator;
    QCheckBox *doCreateTrainingsSet;
    QLineEdit *OutputPath;
    QPushButton *Output;
    QLineEdit *xRot;
    QPushButton *xRotButton;
    QLineEdit *yRot;
    QPushButton *xRotButton_2;
    QPushButton *zRotButton;
    QLineEdit *zRot;
    QLineEdit *xTrans;
    QLineEdit *zTrans;
    QPushButton *xTransButton;
    QPushButton *yTransButton;
    QLineEdit *yTrans;
    QPushButton *zTransButton;
    QPushButton *ViewPointsButton;
    QLineEdit *ViewPoints;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1123, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ReferenceButton = new QPushButton(centralWidget);
        ReferenceButton->setObjectName(QStringLiteral("ReferenceButton"));
        ReferenceButton->setGeometry(QRect(0, 70, 131, 26));
        ReferenceStructurePath = new QLineEdit(centralWidget);
        ReferenceStructurePath->setObjectName(QStringLiteral("ReferenceStructurePath"));
        ReferenceStructurePath->setGeometry(QRect(140, 70, 461, 26));
        SelectPpbs = new QPushButton(centralWidget);
        SelectPpbs->setObjectName(QStringLiteral("SelectPpbs"));
        SelectPpbs->setGeometry(QRect(0, 10, 131, 26));
        SelectPqrs = new QPushButton(centralWidget);
        SelectPqrs->setObjectName(QStringLiteral("SelectPqrs"));
        SelectPqrs->setGeometry(QRect(0, 40, 131, 26));
        Run = new QPushButton(centralWidget);
        Run->setObjectName(QStringLiteral("Run"));
        Run->setGeometry(QRect(10, 300, 61, 26));
        Input = new QPushButton(centralWidget);
        Input->setObjectName(QStringLiteral("Input"));
        Input->setGeometry(QRect(0, 100, 131, 26));
        InputPath = new QLineEdit(centralWidget);
        InputPath->setObjectName(QStringLiteral("InputPath"));
        InputPath->setGeometry(QRect(140, 100, 461, 26));
        DisplayX = new QPushButton(centralWidget);
        DisplayX->setObjectName(QStringLiteral("DisplayX"));
        DisplayX->setGeometry(QRect(490, 290, 61, 26));
        DisplayXValue = new QLineEdit(centralWidget);
        DisplayXValue->setObjectName(QStringLiteral("DisplayXValue"));
        DisplayXValue->setGeometry(QRect(560, 290, 41, 26));
        DisplayYValue = new QLineEdit(centralWidget);
        DisplayYValue->setObjectName(QStringLiteral("DisplayYValue"));
        DisplayYValue->setGeometry(QRect(560, 320, 41, 26));
        DisplayY = new QPushButton(centralWidget);
        DisplayY->setObjectName(QStringLiteral("DisplayY"));
        DisplayY->setGeometry(QRect(490, 320, 61, 26));
        apbsInButton = new QPushButton(centralWidget);
        apbsInButton->setObjectName(QStringLiteral("apbsInButton"));
        apbsInButton->setGeometry(QRect(140, 10, 61, 26));
        apbsInText = new QLineEdit(centralWidget);
        apbsInText->setObjectName(QStringLiteral("apbsInText"));
        apbsInText->setGeometry(QRect(210, 10, 391, 26));
        RunImageCreator = new QPushButton(centralWidget);
        RunImageCreator->setObjectName(QStringLiteral("RunImageCreator"));
        RunImageCreator->setGeometry(QRect(490, 360, 121, 26));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QStringLiteral("Stop"));
        Stop->setGeometry(QRect(80, 300, 61, 26));
        ColumnsValue = new QLineEdit(centralWidget);
        ColumnsValue->setObjectName(QStringLiteral("ColumnsValue"));
        ColumnsValue->setGeometry(QRect(560, 390, 41, 26));
        Columns = new QPushButton(centralWidget);
        Columns->setObjectName(QStringLiteral("Columns"));
        Columns->setGeometry(QRect(490, 390, 61, 26));
        ImageCreatorQuality_2 = new QLineEdit(centralWidget);
        ImageCreatorQuality_2->setObjectName(QStringLiteral("ImageCreatorQuality_2"));
        ImageCreatorQuality_2->setGeometry(QRect(560, 420, 41, 26));
        ImageCreatorQuality = new QPushButton(centralWidget);
        ImageCreatorQuality->setObjectName(QStringLiteral("ImageCreatorQuality"));
        ImageCreatorQuality->setGeometry(QRect(490, 420, 61, 26));
        Console = new QTextEdit(centralWidget);
        Console->setObjectName(QStringLiteral("Console"));
        Console->setGeometry(QRect(650, 10, 361, 391));
        pdb2pqr = new QCheckBox(centralWidget);
        pdb2pqr->setObjectName(QStringLiteral("pdb2pqr"));
        pdb2pqr->setGeometry(QRect(10, 330, 71, 21));
        vmd = new QCheckBox(centralWidget);
        vmd->setObjectName(QStringLiteral("vmd"));
        vmd->setGeometry(QRect(10, 350, 71, 21));
        doImageCreator = new QCheckBox(centralWidget);
        doImageCreator->setObjectName(QStringLiteral("doImageCreator"));
        doImageCreator->setGeometry(QRect(10, 370, 111, 21));
        doMovieCreator = new QCheckBox(centralWidget);
        doMovieCreator->setObjectName(QStringLiteral("doMovieCreator"));
        doMovieCreator->setGeometry(QRect(10, 390, 111, 21));
        doCreateTrainingsSet = new QCheckBox(centralWidget);
        doCreateTrainingsSet->setObjectName(QStringLiteral("doCreateTrainingsSet"));
        doCreateTrainingsSet->setGeometry(QRect(10, 410, 111, 21));
        OutputPath = new QLineEdit(centralWidget);
        OutputPath->setObjectName(QStringLiteral("OutputPath"));
        OutputPath->setGeometry(QRect(140, 130, 461, 26));
        Output = new QPushButton(centralWidget);
        Output->setObjectName(QStringLiteral("Output"));
        Output->setGeometry(QRect(0, 130, 131, 26));
        xRot = new QLineEdit(centralWidget);
        xRot->setObjectName(QStringLiteral("xRot"));
        xRot->setGeometry(QRect(220, 330, 31, 26));
        xRotButton = new QPushButton(centralWidget);
        xRotButton->setObjectName(QStringLiteral("xRotButton"));
        xRotButton->setGeometry(QRect(150, 330, 71, 26));
        yRot = new QLineEdit(centralWidget);
        yRot->setObjectName(QStringLiteral("yRot"));
        yRot->setGeometry(QRect(220, 360, 31, 26));
        xRotButton_2 = new QPushButton(centralWidget);
        xRotButton_2->setObjectName(QStringLiteral("xRotButton_2"));
        xRotButton_2->setGeometry(QRect(150, 360, 71, 26));
        zRotButton = new QPushButton(centralWidget);
        zRotButton->setObjectName(QStringLiteral("zRotButton"));
        zRotButton->setGeometry(QRect(150, 390, 71, 26));
        zRot = new QLineEdit(centralWidget);
        zRot->setObjectName(QStringLiteral("zRot"));
        zRot->setGeometry(QRect(220, 390, 31, 26));
        xTrans = new QLineEdit(centralWidget);
        xTrans->setObjectName(QStringLiteral("xTrans"));
        xTrans->setGeometry(QRect(340, 330, 31, 26));
        zTrans = new QLineEdit(centralWidget);
        zTrans->setObjectName(QStringLiteral("zTrans"));
        zTrans->setGeometry(QRect(340, 390, 31, 26));
        xTransButton = new QPushButton(centralWidget);
        xTransButton->setObjectName(QStringLiteral("xTransButton"));
        xTransButton->setGeometry(QRect(260, 330, 81, 26));
        yTransButton = new QPushButton(centralWidget);
        yTransButton->setObjectName(QStringLiteral("yTransButton"));
        yTransButton->setGeometry(QRect(260, 360, 81, 26));
        yTrans = new QLineEdit(centralWidget);
        yTrans->setObjectName(QStringLiteral("yTrans"));
        yTrans->setGeometry(QRect(340, 360, 31, 26));
        zTransButton = new QPushButton(centralWidget);
        zTransButton->setObjectName(QStringLiteral("zTransButton"));
        zTransButton->setGeometry(QRect(260, 390, 81, 26));
        ViewPointsButton = new QPushButton(centralWidget);
        ViewPointsButton->setObjectName(QStringLiteral("ViewPointsButton"));
        ViewPointsButton->setGeometry(QRect(0, 160, 131, 26));
        ViewPoints = new QLineEdit(centralWidget);
        ViewPoints->setObjectName(QStringLiteral("ViewPoints"));
        ViewPoints->setGeometry(QRect(140, 160, 461, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 20));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        ReferenceButton->setText(QApplication::translate("MainWindow", "Reference Structure", 0));
        ReferenceStructurePath->setText(QApplication::translate("MainWindow", "<reference>", 0));
        SelectPpbs->setText(QApplication::translate("MainWindow", "Select Pdbs", 0));
        SelectPqrs->setText(QApplication::translate("MainWindow", "Select Pqrs", 0));
        Run->setText(QApplication::translate("MainWindow", "Run", 0));
        Input->setText(QApplication::translate("MainWindow", "Input", 0));
        InputPath->setText(QApplication::translate("MainWindow", "Input", 0));
        DisplayX->setText(QApplication::translate("MainWindow", "DisplayX", 0));
        DisplayXValue->setText(QApplication::translate("MainWindow", "1175", 0));
        DisplayYValue->setText(QApplication::translate("MainWindow", "1000", 0));
        DisplayY->setText(QApplication::translate("MainWindow", "DisplayY", 0));
        apbsInButton->setText(QApplication::translate("MainWindow", "apbs.in", 0));
        apbsInText->setText(QApplication::translate("MainWindow", "apbs.in", 0));
        RunImageCreator->setText(QApplication::translate("MainWindow", "Run ImageCreator", 0));
        Stop->setText(QApplication::translate("MainWindow", "Stop", 0));
        ColumnsValue->setText(QApplication::translate("MainWindow", "10", 0));
        Columns->setText(QApplication::translate("MainWindow", "Columns", 0));
        ImageCreatorQuality_2->setText(QApplication::translate("MainWindow", "100", 0));
        ImageCreatorQuality->setText(QApplication::translate("MainWindow", "Quality", 0));
        pdb2pqr->setText(QApplication::translate("MainWindow", "pdb2pqr", 0));
        vmd->setText(QApplication::translate("MainWindow", "vmd", 0));
        doImageCreator->setText(QApplication::translate("MainWindow", "imageCreator", 0));
        doMovieCreator->setText(QApplication::translate("MainWindow", "movieCreator", 0));
        doCreateTrainingsSet->setText(QApplication::translate("MainWindow", "trainingsSet", 0));
        OutputPath->setText(QApplication::translate("MainWindow", "Output", 0));
        Output->setText(QApplication::translate("MainWindow", "Output", 0));
        xRot->setText(QApplication::translate("MainWindow", "0", 0));
        xRotButton->setText(QApplication::translate("MainWindow", "xRotation", 0));
        yRot->setText(QApplication::translate("MainWindow", "0", 0));
        xRotButton_2->setText(QApplication::translate("MainWindow", "yRotation", 0));
        zRotButton->setText(QApplication::translate("MainWindow", "zRotation", 0));
        zRot->setText(QApplication::translate("MainWindow", "0", 0));
        xTrans->setText(QApplication::translate("MainWindow", "0", 0));
        zTrans->setText(QApplication::translate("MainWindow", "0", 0));
        xTransButton->setText(QApplication::translate("MainWindow", "xTranslation", 0));
        yTransButton->setText(QApplication::translate("MainWindow", "yTranslation", 0));
        yTrans->setText(QApplication::translate("MainWindow", "0", 0));
        zTransButton->setText(QApplication::translate("MainWindow", "zTranslation", 0));
        ViewPointsButton->setText(QApplication::translate("MainWindow", "ViewPoints", 0));
        ViewPoints->setText(QApplication::translate("MainWindow", "ViewPoints", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
