/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

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
    QLineEdit *FontSizeValue;
    QPushButton *FontSizeButton;
    QPushButton *ParametersFileButton;
    QLineEdit *ParametersFileValue;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1123, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        ReferenceButton = new QPushButton(centralWidget);
        ReferenceButton->setObjectName(QString::fromUtf8("ReferenceButton"));
        ReferenceButton->setGeometry(QRect(0, 100, 131, 26));
        ReferenceStructurePath = new QLineEdit(centralWidget);
        ReferenceStructurePath->setObjectName(QString::fromUtf8("ReferenceStructurePath"));
        ReferenceStructurePath->setGeometry(QRect(140, 100, 461, 26));
        SelectPpbs = new QPushButton(centralWidget);
        SelectPpbs->setObjectName(QString::fromUtf8("SelectPpbs"));
        SelectPpbs->setGeometry(QRect(0, 40, 131, 26));
        SelectPqrs = new QPushButton(centralWidget);
        SelectPqrs->setObjectName(QString::fromUtf8("SelectPqrs"));
        SelectPqrs->setGeometry(QRect(0, 70, 131, 26));
        Run = new QPushButton(centralWidget);
        Run->setObjectName(QString::fromUtf8("Run"));
        Run->setGeometry(QRect(10, 300, 61, 26));
        Input = new QPushButton(centralWidget);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(0, 130, 131, 26));
        InputPath = new QLineEdit(centralWidget);
        InputPath->setObjectName(QString::fromUtf8("InputPath"));
        InputPath->setGeometry(QRect(140, 130, 461, 26));
        DisplayX = new QPushButton(centralWidget);
        DisplayX->setObjectName(QString::fromUtf8("DisplayX"));
        DisplayX->setGeometry(QRect(490, 290, 61, 26));
        DisplayXValue = new QLineEdit(centralWidget);
        DisplayXValue->setObjectName(QString::fromUtf8("DisplayXValue"));
        DisplayXValue->setGeometry(QRect(560, 290, 41, 26));
        DisplayYValue = new QLineEdit(centralWidget);
        DisplayYValue->setObjectName(QString::fromUtf8("DisplayYValue"));
        DisplayYValue->setGeometry(QRect(560, 320, 41, 26));
        DisplayY = new QPushButton(centralWidget);
        DisplayY->setObjectName(QString::fromUtf8("DisplayY"));
        DisplayY->setGeometry(QRect(490, 320, 61, 26));
        apbsInButton = new QPushButton(centralWidget);
        apbsInButton->setObjectName(QString::fromUtf8("apbsInButton"));
        apbsInButton->setGeometry(QRect(140, 40, 61, 26));
        apbsInText = new QLineEdit(centralWidget);
        apbsInText->setObjectName(QString::fromUtf8("apbsInText"));
        apbsInText->setGeometry(QRect(210, 40, 391, 26));
        RunImageCreator = new QPushButton(centralWidget);
        RunImageCreator->setObjectName(QString::fromUtf8("RunImageCreator"));
        RunImageCreator->setGeometry(QRect(490, 360, 121, 26));
        Stop = new QPushButton(centralWidget);
        Stop->setObjectName(QString::fromUtf8("Stop"));
        Stop->setGeometry(QRect(80, 300, 61, 26));
        ColumnsValue = new QLineEdit(centralWidget);
        ColumnsValue->setObjectName(QString::fromUtf8("ColumnsValue"));
        ColumnsValue->setGeometry(QRect(560, 390, 41, 26));
        Columns = new QPushButton(centralWidget);
        Columns->setObjectName(QString::fromUtf8("Columns"));
        Columns->setGeometry(QRect(490, 390, 61, 26));
        ImageCreatorQuality_2 = new QLineEdit(centralWidget);
        ImageCreatorQuality_2->setObjectName(QString::fromUtf8("ImageCreatorQuality_2"));
        ImageCreatorQuality_2->setGeometry(QRect(560, 420, 41, 26));
        ImageCreatorQuality = new QPushButton(centralWidget);
        ImageCreatorQuality->setObjectName(QString::fromUtf8("ImageCreatorQuality"));
        ImageCreatorQuality->setGeometry(QRect(490, 420, 61, 26));
        Console = new QTextEdit(centralWidget);
        Console->setObjectName(QString::fromUtf8("Console"));
        Console->setGeometry(QRect(650, 10, 361, 391));
        pdb2pqr = new QCheckBox(centralWidget);
        pdb2pqr->setObjectName(QString::fromUtf8("pdb2pqr"));
        pdb2pqr->setGeometry(QRect(10, 330, 71, 21));
        vmd = new QCheckBox(centralWidget);
        vmd->setObjectName(QString::fromUtf8("vmd"));
        vmd->setGeometry(QRect(10, 350, 71, 21));
        doImageCreator = new QCheckBox(centralWidget);
        doImageCreator->setObjectName(QString::fromUtf8("doImageCreator"));
        doImageCreator->setGeometry(QRect(10, 370, 111, 21));
        doMovieCreator = new QCheckBox(centralWidget);
        doMovieCreator->setObjectName(QString::fromUtf8("doMovieCreator"));
        doMovieCreator->setGeometry(QRect(10, 390, 111, 21));
        doCreateTrainingsSet = new QCheckBox(centralWidget);
        doCreateTrainingsSet->setObjectName(QString::fromUtf8("doCreateTrainingsSet"));
        doCreateTrainingsSet->setGeometry(QRect(10, 410, 111, 21));
        OutputPath = new QLineEdit(centralWidget);
        OutputPath->setObjectName(QString::fromUtf8("OutputPath"));
        OutputPath->setGeometry(QRect(140, 160, 461, 26));
        Output = new QPushButton(centralWidget);
        Output->setObjectName(QString::fromUtf8("Output"));
        Output->setGeometry(QRect(0, 160, 131, 26));
        xRot = new QLineEdit(centralWidget);
        xRot->setObjectName(QString::fromUtf8("xRot"));
        xRot->setGeometry(QRect(220, 330, 31, 26));
        xRotButton = new QPushButton(centralWidget);
        xRotButton->setObjectName(QString::fromUtf8("xRotButton"));
        xRotButton->setGeometry(QRect(150, 330, 71, 26));
        yRot = new QLineEdit(centralWidget);
        yRot->setObjectName(QString::fromUtf8("yRot"));
        yRot->setGeometry(QRect(220, 360, 31, 26));
        xRotButton_2 = new QPushButton(centralWidget);
        xRotButton_2->setObjectName(QString::fromUtf8("xRotButton_2"));
        xRotButton_2->setGeometry(QRect(150, 360, 71, 26));
        zRotButton = new QPushButton(centralWidget);
        zRotButton->setObjectName(QString::fromUtf8("zRotButton"));
        zRotButton->setGeometry(QRect(150, 390, 71, 26));
        zRot = new QLineEdit(centralWidget);
        zRot->setObjectName(QString::fromUtf8("zRot"));
        zRot->setGeometry(QRect(220, 390, 31, 26));
        xTrans = new QLineEdit(centralWidget);
        xTrans->setObjectName(QString::fromUtf8("xTrans"));
        xTrans->setGeometry(QRect(340, 330, 31, 26));
        zTrans = new QLineEdit(centralWidget);
        zTrans->setObjectName(QString::fromUtf8("zTrans"));
        zTrans->setGeometry(QRect(340, 390, 31, 26));
        xTransButton = new QPushButton(centralWidget);
        xTransButton->setObjectName(QString::fromUtf8("xTransButton"));
        xTransButton->setGeometry(QRect(260, 330, 81, 26));
        yTransButton = new QPushButton(centralWidget);
        yTransButton->setObjectName(QString::fromUtf8("yTransButton"));
        yTransButton->setGeometry(QRect(260, 360, 81, 26));
        yTrans = new QLineEdit(centralWidget);
        yTrans->setObjectName(QString::fromUtf8("yTrans"));
        yTrans->setGeometry(QRect(340, 360, 31, 26));
        zTransButton = new QPushButton(centralWidget);
        zTransButton->setObjectName(QString::fromUtf8("zTransButton"));
        zTransButton->setGeometry(QRect(260, 390, 81, 26));
        ViewPointsButton = new QPushButton(centralWidget);
        ViewPointsButton->setObjectName(QString::fromUtf8("ViewPointsButton"));
        ViewPointsButton->setGeometry(QRect(0, 190, 131, 26));
        ViewPoints = new QLineEdit(centralWidget);
        ViewPoints->setObjectName(QString::fromUtf8("ViewPoints"));
        ViewPoints->setGeometry(QRect(140, 190, 461, 26));
        FontSizeValue = new QLineEdit(centralWidget);
        FontSizeValue->setObjectName(QString::fromUtf8("FontSizeValue"));
        FontSizeValue->setGeometry(QRect(560, 450, 41, 26));
        FontSizeButton = new QPushButton(centralWidget);
        FontSizeButton->setObjectName(QString::fromUtf8("FontSizeButton"));
        FontSizeButton->setGeometry(QRect(490, 450, 61, 26));
        ParametersFileButton = new QPushButton(centralWidget);
        ParametersFileButton->setObjectName(QString::fromUtf8("ParametersFileButton"));
        ParametersFileButton->setGeometry(QRect(0, 10, 131, 26));
        ParametersFileValue = new QLineEdit(centralWidget);
        ParametersFileValue->setObjectName(QString::fromUtf8("ParametersFileValue"));
        ParametersFileValue->setGeometry(QRect(140, 10, 461, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 30));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        ReferenceButton->setText(QApplication::translate("MainWindow", "Reference Structure", 0, QApplication::UnicodeUTF8));
        ReferenceStructurePath->setText(QApplication::translate("MainWindow", "<reference>", 0, QApplication::UnicodeUTF8));
        SelectPpbs->setText(QApplication::translate("MainWindow", "Select Pdbs", 0, QApplication::UnicodeUTF8));
        SelectPqrs->setText(QApplication::translate("MainWindow", "Select Pqrs", 0, QApplication::UnicodeUTF8));
        Run->setText(QApplication::translate("MainWindow", "Run", 0, QApplication::UnicodeUTF8));
        Input->setText(QApplication::translate("MainWindow", "Input", 0, QApplication::UnicodeUTF8));
        InputPath->setText(QApplication::translate("MainWindow", "Input", 0, QApplication::UnicodeUTF8));
        DisplayX->setText(QApplication::translate("MainWindow", "DisplayX", 0, QApplication::UnicodeUTF8));
        DisplayXValue->setText(QApplication::translate("MainWindow", "1175", 0, QApplication::UnicodeUTF8));
        DisplayYValue->setText(QApplication::translate("MainWindow", "1000", 0, QApplication::UnicodeUTF8));
        DisplayY->setText(QApplication::translate("MainWindow", "DisplayY", 0, QApplication::UnicodeUTF8));
        apbsInButton->setText(QApplication::translate("MainWindow", "apbs.in", 0, QApplication::UnicodeUTF8));
        apbsInText->setText(QApplication::translate("MainWindow", "apbs.in", 0, QApplication::UnicodeUTF8));
        RunImageCreator->setText(QApplication::translate("MainWindow", "Run ImageCreator", 0, QApplication::UnicodeUTF8));
        Stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        ColumnsValue->setText(QApplication::translate("MainWindow", "10", 0, QApplication::UnicodeUTF8));
        Columns->setText(QApplication::translate("MainWindow", "Columns", 0, QApplication::UnicodeUTF8));
        ImageCreatorQuality_2->setText(QApplication::translate("MainWindow", "100", 0, QApplication::UnicodeUTF8));
        ImageCreatorQuality->setText(QApplication::translate("MainWindow", "Quality", 0, QApplication::UnicodeUTF8));
        pdb2pqr->setText(QApplication::translate("MainWindow", "pdb2pqr", 0, QApplication::UnicodeUTF8));
        vmd->setText(QApplication::translate("MainWindow", "vmd", 0, QApplication::UnicodeUTF8));
        doImageCreator->setText(QApplication::translate("MainWindow", "imageCreator", 0, QApplication::UnicodeUTF8));
        doMovieCreator->setText(QApplication::translate("MainWindow", "movieCreator", 0, QApplication::UnicodeUTF8));
        doCreateTrainingsSet->setText(QApplication::translate("MainWindow", "trainingsSet", 0, QApplication::UnicodeUTF8));
        OutputPath->setText(QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        Output->setText(QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        xRot->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        xRotButton->setText(QApplication::translate("MainWindow", "xRotation", 0, QApplication::UnicodeUTF8));
        yRot->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        xRotButton_2->setText(QApplication::translate("MainWindow", "yRotation", 0, QApplication::UnicodeUTF8));
        zRotButton->setText(QApplication::translate("MainWindow", "zRotation", 0, QApplication::UnicodeUTF8));
        zRot->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        xTrans->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        zTrans->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        xTransButton->setText(QApplication::translate("MainWindow", "xTranslation", 0, QApplication::UnicodeUTF8));
        yTransButton->setText(QApplication::translate("MainWindow", "yTranslation", 0, QApplication::UnicodeUTF8));
        yTrans->setText(QApplication::translate("MainWindow", "0", 0, QApplication::UnicodeUTF8));
        zTransButton->setText(QApplication::translate("MainWindow", "zTranslation", 0, QApplication::UnicodeUTF8));
        ViewPointsButton->setText(QApplication::translate("MainWindow", "ViewPoints", 0, QApplication::UnicodeUTF8));
        ViewPoints->setText(QApplication::translate("MainWindow", "ViewPoints", 0, QApplication::UnicodeUTF8));
        FontSizeValue->setText(QApplication::translate("MainWindow", "20", 0, QApplication::UnicodeUTF8));
        FontSizeButton->setText(QApplication::translate("MainWindow", "FontSize", 0, QApplication::UnicodeUTF8));
        ParametersFileButton->setText(QApplication::translate("MainWindow", "ParametersFile", 0, QApplication::UnicodeUTF8));
        ParametersFileValue->setText(QApplication::translate("MainWindow", "ParametersFile", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
