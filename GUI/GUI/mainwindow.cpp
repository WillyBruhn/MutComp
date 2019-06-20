#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "iostream"

#include <QFileDialog>
#include <QUrl>
//#include <QStandardPaths>

#include <QMessageBox>
#include <QDebug>

#include <QProcess>

//#include <QOpen

#include <QTime>

#include <QFileSystemWatcher>

#include <QScrollBar>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("MutComp");

    ui->ReferenceStructurePath->setReadOnly(true);


    // MutComp
    addParameter("OutputFolder", "/home/willy/RedoxChallenges/MutComp/GUI/Parameters/");
    addParameter("PathToMutComp", "/home/willy/RedoxChallenges/MutComp/");
    addParameter("MutCompCall", "./process.sh");

//    addParameter("MutCompInputFolder","/home/willy/RedoxChallenges/MutComp/GUI/Test/Test/Input/");

//    addParameter("MutCompPdbs","/home/willy/RedoxChallenges/MutComp/GUI/Test/Test/Input/pdb/");
//    addParameter("MutCompPqrs","/home/willy/RedoxChallenges/MutComp/GUI/Test/Test/Input/pqr/");

    addParameter("MutCompOutputFolder","/home/willy/RedoxChallenges/MutComp/GUI/Test/Test/Output/");
    addParameter("MutCompInputFolder","/home/willy/RedoxChallenges/MutComp/GUI/Test/Test/Input/");

    addParameter("MutCompApbsReference","/home/willy/RedoxChallenges/MutComp/APBS/apbsReference.in");

    addParameter("MutCompPqrReference", "/home/willy/RedoxChallenges/MutComp/Output/000_Ars/000_Ars.pqr");

    addParameter("MutCompViewPoints","/home/");

//    addParameter("parametersFile","/home/willy/RedoxChallenges/MutComp/GUI/Parameters/parameters.txt");
//    parametersFile = "../Parameters/parameters.txt";

    parametersFile = "parameters.txt";
    parametersPath = "/home/sysgen/Documents/LWB/TCL/MutComp/GUI/Parameters/";

    ui->ParametersFileValue->setText(parametersPath+parametersFile);


//    QString dir = QDir::currentPath();

//    qDebug() << dir << endl;
//    parametersFile = "../Parameters/bull";

    addParameter("doPdbToPqr","false");
    addParameter("doImageCreator","false");
    addParameter("doMovieCreator","false");
    addParameter("doCreateTrainingsSet","false");
    addParameter("doVMD","false");

    QString s_log = parameters["MutCompOutputFolder"] + "/mutComp.log";
    QString s_err = parameters["MutCompOutputFolder"] + "/mutComp.err";

    addParameter("MutCompLog", s_log);
    addParameter("MutCompError", s_err);

    qDebug() << "added log and err";

    // VMD
    addParameter("VMDcall", "./vmd");
    addParameter("PathToVMD", "/opt/vmd-1.9.3/");

    addParameter("xRotation", "0");
    addParameter("yRotation", "0");
    addParameter("zRotation", "0");

    addParameter("xTrans", "0");
    addParameter("yTrans", "0");
    addParameter("zTrans", "0");

    addParameter("columns","14");
    addParameter("FontSize","20");


//    parametersFile = "/home/willy/RedoxChallenges/MutComp/GUI/Parameters/parameters.txt";

//    writeParametersToFile(parametersFile, parameters);

    readParametersFromFile(parametersPath+parametersFile, parameters);

    writeParametersToFile(parametersPath+parametersFile, parameters);

//    QObject::connect(this, SIGNAL(parametersChanged(QString&)),
//                         this, SLOT(readParametersFromFile(QString&)));

    QObject::connect(this, SIGNAL(parametersChanged(const QString&)),
                         this, SLOT(writeParametersToFile(const QString&)));

    MutComp = new QProcess();
//    MutComp->setStandardOutputFile(parameters["MutCompLog"], QIODevice::Append);
//    QFile::remove(parameters["MutCompLog"]);
//    QDateTime time = QDateTime::currentDateTime();

//    QFile file(parameters["MutCompLog"]);
//    if ( file.open(QIODevice::ReadWrite) )
//    {
//        QTextStream stream( &file );

//        stream << "# Started MutComprun" << endl;
//        stream << "# " << time.toString() << endl;
//        stream << "#--------------------------------------------------" << endl;
//    }


//    QObject::connect(MutComp, SIGNAL(fileChanged(parameters["MutCompLog"])), this, SLOT(updateConsole()));

    watcher = new QFileSystemWatcher(this);
    connect(watcher, SIGNAL(fileChanged(const QString &)), this, SLOT(updateConsole()));
//connect(watcher, SIGNAL(directoryChanged(const QString &)), this, SLOT(directoryChanged(const QString &)));
    //watcher->addPath("path to directory");
    watcher->addPath(parameters["MutCompLog"]);





    MutComp->setStandardErrorFile(parameters["MutCompError"]);
    QFile::remove(parameters["MutCompError"]);

    connect(MutComp, SIGNAL(finished(int , QProcess::ExitStatus)),
            this, SLOT(mutCompFinished()));

    connect(MutComp, SIGNAL(stateChanged(QProcess::ProcessState)),
            this, SLOT(updateConsole()));


//    QObject::connect(MutComp, SIGNAL(readyReadStandardOutput()), this, SLOT(displayOutput()));
//    QObject::connect(MutComp, SIGNAL(readyReadStandardError()), this, SLOT(displayError()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::map<QString, QString> MainWindow::getParameters() const{
    return parameters;
}

void MainWindow::addParameter(const QString &str, const QString &val){
    parameters[str] = val;
}

void MainWindow::mutCompFinished(){
    qDebug() << "Mutcomp finnished!";

}

void MainWindow::displayOutput(){
    QByteArray outData = MutComp->readAllStandardOutput();
    qDebug()<<QString(outData);

//    writeSystemOutputToFile(parameters["MutCompLog"], MutComp);
}

void MainWindow::displayError(){
    QByteArray outData = MutComp->readAllStandardError();
    qDebug()<<QString(outData);
}

void MainWindow::writeSystemOutputToFile(const QString &fileName, QProcess *process){
    QByteArray outData = process->readAllStandardOutput();
//    QByteArray errorData = process->readAllStandardError();

    QFile file( fileName );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream << outData << endl;
    }
}

void MainWindow::writeParametersToFile(const QString &fileName, std::map<QString,QString> &parameters){

    qDebug() << "writing parametersFile " << fileName << endl;

    QString s_log = parameters["MutCompOutputFolder"] + "/mutComp.log";
    QString s_err = parameters["MutCompOutputFolder"] + "/mutComp.err";

    addParameter("MutCompLog", s_log);
    addParameter("MutCompError", s_err);


    QFile file( fileName );
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        std::map<QString,QString>::iterator i;
        for(i=parameters.begin(); i != parameters.end(); i++){
            stream << i->first << ";" << i->second << "\n";
        }
    }

    file.close();
}

void MainWindow::writeParametersToFile(const QString &fileName){
    writeParametersToFile(fileName, parameters);
}

void MainWindow::readParametersFromFile(const QString &fileName, std::map<QString,QString> &parameters){

    qDebug() << "Reading parametersFile " << fileName << endl;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly)) {
//        QMessageBox::information(0, "error", file.errorString());

        qDebug() << "couldn't open parametersFile " << fileName << endl;
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();

        if(line.isEmpty() == false){
            QStringList fields = line.split(";");
            qDebug() << fields[0] << fields[1] << endl;

            parameters[fields[0]] = fields[1];
        }
    }

    file.close();


    if(parameters["doVMD"] == "true"){
        ui->vmd->setChecked(true);
    } else {
        ui->vmd->setChecked(false);
    }

    if(parameters["doCreateTrainingsSet"] == "true"){
        ui->doCreateTrainingsSet->setChecked(true);
    } else {
        ui->doCreateTrainingsSet->setChecked(false);
    }

    if(parameters["doImageCreator"] == "true"){
        ui->doImageCreator->setChecked(true);
    } else {
        ui->doImageCreator->setChecked(false);
    }

    if(parameters["doMovieCreator"] == "true"){
        ui->doMovieCreator->setChecked(true);
    } else {
        ui->doMovieCreator->setChecked(false);
    }

    if(parameters["doPdbToPqr"] == "true"){
        ui->pdb2pqr->setChecked(true);
    } else {
        ui->pdb2pqr->setChecked(false);
    }

    ui->OutputPath->setText(parameters["MutCompOutputFolder"]);

    ui->apbsInText->setText(parameters["MutCompApbsReference"]);

    ui->ReferenceStructurePath->setText(parameters["MutCompPqrReference"]);

    ui->InputPath->setText(parameters["MutCompInputFolder"]);

    ui->xRot->setText(parameters["xRot"]);
    ui->yRot->setText(parameters["yRot"]);
    ui->zRot->setText(parameters["zRot"]);

    ui->xTrans->setText(parameters["xTrans"]);
    ui->yTrans->setText(parameters["yTrans"]);
    ui->zTrans->setText(parameters["zTrans"]);

    ui->ViewPoints->setText(parameters["MutCompViewPoints"]);

    ui->ColumnsValue->setText(parameters["columns"]);

    ui->FontSizeValue->setText(parameters["FontSize"]);


    QString s_log = parameters["MutCompOutputFolder"] + "/mutComp.log";
    QString s_err = parameters["MutCompOutputFolder"] + "/mutComp.err";

    addParameter("MutCompLog", s_log);
    addParameter("MutCompError", s_err);


//    addParameter("MutCompPdbs",parameters["MutCompPdbs"]);

//    addParameter("MutCompPqrs",parameters["MutCompPqrs"]);

//    ui->Parameters->setText(parameters["parametersFile"]);
}

void MainWindow::readParametersFromFile(QString &fileName){
    readParametersFromFile(fileName, parameters);
}

void MainWindow::on_ReferenceButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                parameters["MutCompPqrReference"],
                "All files (*.*);;Text File (*.txt)"

                );

    //QMessageBox::information(this,tr("File Name"), filename);

    on_ReferenceStructurePath_textChanged(filename);

    updateParameters("MutCompPqrReference", filename);
}

void MainWindow::on_ReferenceStructurePath_textChanged(const QString &arg1)
{
    ui->ReferenceStructurePath->setText(arg1);

}

void MainWindow::on_SelectPpbs_clicked()
{

    QFileDialog dialog(this);
    dialog.setDirectory("/home/faruq/Documents/Opensuse/MFH/100 Redoxins/Reoriented/");
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(trUtf8("(*.pdb)"));
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    qDebug() << fileNames;

    emit parametersChanged(parametersPath+parametersFile);

//    on_ReferenceStructurePath_textChanged(filename);
}

void MainWindow::on_SelectPqrs_clicked()
{
    QFileDialog dialog(this);
    dialog.setDirectory("/home/faruq/Documents/Opensuse/MFH/100 Redoxins/Reoriented/");
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setNameFilter(trUtf8("(*.pqr)"));
    QStringList fileNames;
    if (dialog.exec())
        fileNames = dialog.selectedFiles();

    qDebug() << fileNames;

}

void MainWindow::on_Run_clicked()
{
    qDebug("Pressed Run-button...");

    MutComp->setStandardOutputFile(parameters["MutCompLog"], QIODevice::Append);
    QFile::remove(parameters["MutCompLog"]);
    QDateTime time = QDateTime::currentDateTime();

    QFile file(parameters["MutCompLog"]);
    if ( file.open(QIODevice::ReadWrite) )
    {
        QTextStream stream( &file );

        stream << "# Started MutComprun" << endl;
        stream << "# " << time.toString() << endl;
        stream << "#--------------------------------------------------" << endl;
    }

    watcher->addPath(parameters["MutCompLog"]);

//    MutComp = new QProcess();

    QString call = parameters["PathToMutComp"] + parameters["MutCompCall"];
    qDebug() << call << endl;
    MutComp->start(call);

    //MutComp->waitForFinished(-1);
}

void MainWindow::on_Output_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 parameters["MutCompOutputFolder"],
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    //QMessageBox::information(this,tr("File Name"), filename);

    on_OutputPath_textChanged(dir);

    qDebug() << "Output clicked" << endl;

    parameters["MutCompOutputFolder"] = ui->OutputPath->text();

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_OutputPath_textChanged(const QString &arg1)
{
    ui->OutputPath->setText(arg1);

}

void MainWindow::on_Input_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 "/home",
                                                 QFileDialog::ShowDirsOnly
                                                 | QFileDialog::DontResolveSymlinks);

    //QMessageBox::information(this,tr("File Name"), filename);

    on_InputPath_textChanged(dir);

    qDebug() << "Input clicked" << endl;

    parameters["MutCompInputFolder"] = ui->InputPath->text();

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_InputPath_textChanged(const QString &arg1)
{
    ui->InputPath->setText(arg1);

}

void MainWindow::on_ParametersFileButton_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                 parametersPath);

    //QMessageBox::information(this,tr("File Name"), filename);

    ui->ParametersFileValue->setText(dir);
    parametersPath = dir+"/";

    qDebug() << "ParametersFileValue clicked" << endl;

    readParametersFromFile(parametersPath+parametersFile, parameters);
    writeParametersToFile(parametersPath+parametersFile);
}

void MainWindow::on_DisplayX_clicked()
{

}

void MainWindow::on_DisplayXValue_returnPressed()
{
    qDebug() << "DisplayXvalue changed ...";
}

void MainWindow::on_DisplayYValue_returnPressed()
{
    qDebug() << "DisplayYvalue changed ...";
}

void MainWindow::on_apbsInButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                parameters["MutCompApbsReference"],
                "All files (*.*);;Text File (*.txt)"

                );

    //QMessageBox::information(this,tr("File Name"), filename);

    on_apbsInText_textChanged(filename);
}

void MainWindow::updateParameters(const QString &key, const QString &val){
    if(parameters.find(key) != parameters.end()) parameters[key] = val;
    else qDebug() << "ERROR:Parameter " << key << " does not exist!" << endl;

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_apbsInText_textChanged(const QString &arg1)
{
    ui->apbsInText->setText(arg1);

//    qDebug() << "apbs: " << arg1 << endl;

    updateParameters("MutCompApbsReference",arg1);
}

void MainWindow::on_ColumnsValue_returnPressed()
{
    qDebug() << "changed rows for ImageCreator ...";


//    ui->ColumnsValue->setText( = 10;

    qDebug() << ui->ColumnsValue;
}

void MainWindow::on_ColumnsValue_textEdited(const QString &arg1)
{
    qDebug() << "changed ColumnsValue" << endl;

    updateParameters("columns", arg1);
}


void MainWindow::on_ParametersFileValue_textEdited(const QString &arg1)
{
    qDebug() << "changed ParametersFileValue" << endl;

    parametersPath = arg1;
}

void MainWindow::on_ImageCreatorQuality_2_returnPressed()
{
    qDebug() << "changed quality for ImageCreator ...";
}

void MainWindow::updateConsole(){
    qDebug() << "Console updated" << endl;

    QFile file(parameters["MutCompLog"]);
    if(!file.open(QIODevice::ReadOnly)) {

        qDebug() << "couldn't open log-file for console " << parameters["MutCompLog"] << endl;
    }

    QTextStream in(&file);

    QString lines;
    while(!in.atEnd()) {
        QString line = in.readLine();
        lines += "\n" + line;
    }

    file.close();

    ui->Console->setText(lines);
    ui->Console->verticalScrollBar()->setValue(ui->Console->verticalScrollBar()->maximum());
}

void MainWindow::on_pdb2pqr_toggled(bool checked)
{
    if(checked) parameters["doPdbToPqr"] = "true";
    else parameters["doPdbToPqr"] = "false";

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_vmd_toggled(bool checked)
{
    if(checked) parameters["doVMD"] = "true";
    else parameters["doVMD"] = "false";

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_doImageCreator_toggled(bool checked)
{
    if(checked) parameters["doImageCreator"] = "true";
    else parameters["doImageCreator"] = "false";

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_doMovieCreator_toggled(bool checked)
{
    if(checked) parameters["doMovieCreator"] = "true";
    else parameters["doMovieCreator"] = "false";

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_doCreateTrainingsSet_toggled(bool checked)
{
    if(checked) parameters["doCreateTrainingsSet"] = "true";
    else parameters["doCreateTrainingsSet"] = "false";

    emit parametersChanged(parametersPath+parametersFile);
}

void MainWindow::on_Stop_pressed()
{
    MutComp->close();
}

void MainWindow::on_FontSizeValue_textEdited(const QString &arg1)
{
    qDebug() << "changed FontSize" << endl;

    updateParameters("FontSize", arg1);
}

void MainWindow::on_xRot_textEdited(const QString &arg1)
{
    qDebug() << "changed xRot" << endl;

    updateParameters("xRot", arg1);
}

void MainWindow::on_yRot_textEdited(const QString &arg1)
{
    qDebug() << "changed yRot" << endl;

    updateParameters("yRot", arg1);
}

void MainWindow::on_zRot_textEdited(const QString &arg1)
{
    qDebug() << "changed zRot" << endl;

    updateParameters("zRot", arg1);
}

void MainWindow::on_xTrans_textEdited(const QString &arg1)
{
    qDebug() << "changed xTrans" << endl;

    updateParameters("xTrans", arg1);
}

void MainWindow::on_yTrans_textEdited(const QString &arg1)
{
    qDebug() << "changed yTrans" << endl;

    updateParameters("yTrans", arg1);
}

void MainWindow::on_zTrans_textEdited(const QString &arg1)
{
    qDebug() << "changed zTrans" << endl;

    updateParameters("zTrans", arg1);
}

void MainWindow::on_ViewPointsButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                parameters["MutCompViewpoints"],
                "All files (*.*);;Text File (*.csv)"

                );

    ui->ViewPoints->setText(file);

    updateParameters("MutCompViewPoints",file);
}

