#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include "docontroller.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLabel* port_label;
    QLabel* state_label;
    QLineEdit* port_edit;
    QLineEdit* state_edit;
    QPushButton* start_btn;
    QPushButton* clear_btn;
    DOController *m_DOController;

private slots:
    void btnStartClicked();
    void btnClearClicked();
};

#endif // MAINWINDOW_H
