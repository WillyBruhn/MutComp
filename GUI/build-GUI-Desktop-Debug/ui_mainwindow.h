/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
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
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1123, 555);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ReferenceButton = new QPushButton(centralWidget);
        ReferenceButton->setObjectName(QStringLiteral("ReferenceButton"));
        ReferenceButton->setGeometry(QRect(0, 100, 131, 26));
        ReferenceStructurePath = new QLineEdit(centralWidget);
        ReferenceStructurePath->setObjectName(QStringLiteral("ReferenceStructurePath"));
        ReferenceStructurePath->setGeometry(QRect(140, 100, 461, 26));
        SelectPpbs = new QPushButton(centralWidget);
        SelectPpbs->setObjectName(QStringLiteral("SelectPpbs"));
        SelectPpbs->setGeometry(QRect(0, 40, 131, 26));
        SelectPqrs = new QPushButton(centralWidget);
        SelectPqrs->setObjectName(QStringLiteral("SelectPqrs"));
        SelectPqrs->setGeometry(QRect(0, 70, 131, 26));
        Run = new QPushButton(centralWidget);
        Run->setObjectName(QStringLiteral("Run"));
        Run->setGeometry(QRect(10, 300, 61, 26));
        Input = new QPushButton(centralWidget);
        Input->setObjectName(QStringLiteral("Input"));
        Input->setGeometry(QRect(0, 130, 131, 26));
        InputPath = new QLineEdit(centralWidget);
        InputPath->setObjectName(QStringLiteral("InputPath"));
        InputPath->setGeometry(QRect(140, 130, 461, 26));
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
        apbsInButton->setGeometry(QRect(140, 40, 61, 26));
        apbsInText = new QLineEdit(centralWidget);
        apbsInText->setObjectName(QStringLiteral("apbsInText"));
        apbsInText->setGeometry(QRect(210, 40, 391, 26));
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
        OutputPath->setGeometry(QRect(140, 160, 461, 26));
        Output = new QPushButton(centralWidget);
        Output->setObjectName(QStringLiteral("Output"));
        Output->setGeometry(QRect(0, 160, 131, 26));
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
        ViewPointsButton->setGeometry(QRect(0, 190, 131, 26));
        ViewPoints = new QLineEdit(centralWidget);
        ViewPoints->setObjectName(QStringLiteral("ViewPoints"));
        ViewPoints->setGeometry(QRect(140, 190, 461, 26));
        FontSizeValue = new QLineEdit(centralWidget);
        FontSizeValue->setObjectName(QStringLiteral("FontSizeValue"));
        FontSizeValue->setGeometry(QRect(560, 450, 41, 26));
        FontSizeButton = new QPushButton(centralWidget);
        FontSizeButton->setObjectName(QStringLiteral("FontSizeButton"));
        FontSizeButton->setGeometry(QRect(490, 450, 61, 26));
        ParametersFileButton = new QPushButton(centralWidget);
        ParametersFileButton->setObjectName(QStringLiteral("ParametersFileButton"));
        ParametersFileButton->setGeometry(QRect(0, 10, 131, 26));
        ParametersFileValue = new QLineEdit(centralWidget);
        ParametersFileValue->setObjectName(QStringLiteral("ParametersFileValue"));
        ParametersFileValue->setGeometry(QRect(140, 10, 461, 26));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1123, 30));
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
        ReferenceButton->setText(QApplication::translate("MainWindow", "Reference Structure", Q_NULLPTR));
        ReferenceStructurePath->setText(QApplication::translate("MainWindow", "<reference>", Q_NULLPTR));
        SelectPpbs->setText(QApplication::translate("MainWindow", "Select Pdbs", Q_NULLPTR));
        SelectPqrs->setText(QApplication::translate("MainWindow", "Select Pqrs", Q_NULLPTR));
        Run->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        Input->setText(QApplication::translate("MainWindow", "Input", Q_NULLPTR));
        InputPath->setText(QApplication::translate("MainWindow", "Input", Q_NULLPTR));
        DisplayX->setText(QApplication::translate("MainWindow", "DisplayX", Q_NULLPTR));
        DisplayXValue->setText(QApplication::translate("MainWindow", "1175", Q_NULLPTR));
        DisplayYValue->setText(QApplication::translate("MainWindow", "1000", Q_NULLPTR));
        DisplayY->setText(QApplication::translate("MainWindow", "DisplayY", Q_NULLPTR));
        apbsInButton->setText(QApplication::translate("MainWindow", "apbs.in", Q_NULLPTR));
        apbsInText->setText(QApplication::translate("MainWindow", "apbs.in", Q_NULLPTR));
        RunImageCreator->setText(QApplication::translate("MainWindow", "Run ImageCreator", Q_NULLPTR));
        Stop->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        ColumnsValue->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        Columns->setText(QApplication::translate("MainWindow", "Columns", Q_NULLPTR));
        ImageCreatorQuality_2->setText(QApplication::translate("MainWindow", "100", Q_NULLPTR));
        ImageCreatorQuality->setText(QApplication::translate("MainWindow", "Quality", Q_NULLPTR));
        pdb2pqr->setText(QApplication::translate("MainWindow", "pdb2pqr", Q_NULLPTR));
        vmd->setText(QApplication::translate("MainWindow", "vmd", Q_NULLPTR));
        doImageCreator->setText(QApplication::translate("MainWindow", "imageCreator", Q_NULLPTR));
        doMovieCreator->setText(QApplication::translate("MainWindow", "movieCreator", Q_NULLPTR));
        doCreateTrainingsSet->setText(QApplication::translate("MainWindow", "trainingsSet", Q_NULLPTR));
        OutputPath->setText(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        Output->setText(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        xRot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        xRotButton->setText(QApplication::translate("MainWindow", "xRotation", Q_NULLPTR));
        yRot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        xRotButton_2->setText(QApplication::translate("MainWindow", "yRotation", Q_NULLPTR));
        zRotButton->setText(QApplication::translate("MainWindow", "zRotation", Q_NULLPTR));
        zRot->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        xTrans->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        zTrans->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        xTransButton->setText(QApplication::translate("MainWindow", "xTranslation", Q_NULLPTR));
        yTransButton->setText(QApplication::translate("MainWindow", "yTranslation", Q_NULLPTR));
        yTrans->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        zTransButton->setText(QApplication::translate("MainWindow", "zTranslation", Q_NULLPTR));
        ViewPointsButton->setText(QApplication::translate("MainWindow", "ViewPoints", Q_NULLPTR));
        ViewPoints->setText(QApplication::translate("MainWindow", "ViewPoints", Q_NULLPTR));
        FontSizeValue->setText(QApplication::translate("MainWindow", "20", Q_NULLPTR));
        FontSizeButton->setText(QApplication::translate("MainWindow", "FontSize", Q_NULLPTR));
        ParametersFileButton->setText(QApplication::translate("MainWindow", "ParametersFile", Q_NULLPTR));
        ParametersFileValue->setText(QApplication::translate("MainWindow", "ParametersFile", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
