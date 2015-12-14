#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{

}

void MainWindow::showWindow()
{
    qDebug() << "entered";
}
