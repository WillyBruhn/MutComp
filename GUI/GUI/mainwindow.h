#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

#include <map>

#include <QProcess>

#include <QFileSystemWatcher>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeParametersToFile(const QString &fileName, std::map<QString,QString> &parameters);
    void readParametersFromFile(const QString &fileName, std::map<QString,QString> &parameters);


    void writeSystemOutputToFile(const QString &fileName, QProcess *process);

    void addParameter(const QString &str, const QString &val);
    std::map<QString, QString> getParameters() const;

public slots:
    void readParametersFromFile(QString &fileName);
    void writeParametersToFile(const QString &fileName);

    void displayOutput();
    void displayError();

    void updateConsole();

signals:
    void parametersChanged(const QString &fileName);

private slots:

    void on_ReferenceButton_clicked();

    void on_ReferenceStructurePath_textChanged(const QString &arg1);

    void on_SelectPpbs_clicked();

    void on_SelectPqrs_clicked();

    void on_Run_clicked();

    void on_Output_clicked();

    void on_ViewPointsButton_clicked();

    void on_OutputPath_textChanged(const QString &arg1);

    void on_Input_clicked();

    void on_InputPath_textChanged(const QString &arg1);

    void on_ParametersFileButton_clicked();


    void on_DisplayX_clicked();


    void on_DisplayXValue_returnPressed();

    void on_DisplayYValue_returnPressed();

    void on_apbsInButton_clicked();

    void on_apbsInText_textChanged(const QString &arg1);

    void on_ColumnsValue_returnPressed();

    void on_ImageCreatorQuality_2_returnPressed();

    void on_pdb2pqr_toggled(bool checked);

    void on_vmd_toggled(bool checked);

    void on_doImageCreator_toggled(bool checked);

    void on_doMovieCreator_toggled(bool checked);

    void on_doCreateTrainingsSet_toggled(bool checked);

    void on_Stop_pressed();

    void mutCompFinished();


    void on_xRot_textEdited(const QString &arg1);
    void on_yRot_textEdited(const QString &arg1);
    void on_zRot_textEdited(const QString &arg1);

    void on_xTrans_textEdited(const QString &arg1);
    void on_yTrans_textEdited(const QString &arg1);
    void on_zTrans_textEdited(const QString &arg1);

    void on_ColumnsValue_textEdited(const QString &arg1);

    void on_FontSizeValue_textEdited(const QString &arg1);

    void on_ParametersFileValue_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;

    std::map<QString, QString> parameters;

    QString parametersFile;
    QString parametersPath;

    QProcess* MutComp;

    QFileSystemWatcher *watcher;

    void updateParameters(const QString &key, const QString &val);
};

#endif // MAINWINDOW_H
