#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "poweramp.h"

Q_DECLARE_LOGGING_CATEGORY(Test)

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLabel* channel_label;
    QLabel* volt_label;
    QLabel* echo_label;
    QLabel* status_label;
    QLabel* echo_text;
    QLabel* status_text;
    QLineEdit* channel_edit;
    QLineEdit* volt_edit;
    QPushButton* startSingle_btn;
    QPushButton* startAll1_btn;
    QPushButton* startAll2_btn;
    QPushButton* resetSingle_btn;
    QPushButton* resetAll1_btn;
    QPushButton* resetAll2_btn;
    QPushButton* echoVolt_btn;
    QPushButton* echoTemp_btn;
    QPushButton* testAll_btn;
    QPushButton* stopTest_btn;

    PowerAmp* m_PAController;
    int genRandomNum();
    int genRandomID();
    VOLT genRandomVolt();
    bool checkUnique(int random, int data[]);

private slots:
    void btnStartSingleClicked();
    void btnStartAll1Clicked();
    void btnStartAll2Clicked();
    void btnResetSingleClicked();
    void btnResetAll1Clicked();
    void btnResetAll2Clicked();
    void btnEchoVoltClicked();
    void btnEchoTempClicked();
    void btnTestAllClicked();
    void btnStopTestClicked();
};

#endif // MAINWINDOW_H
