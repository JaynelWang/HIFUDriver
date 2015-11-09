#include "mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    port_label = new QLabel(this);
    state_label = new QLabel(this);
    port_edit = new QLineEdit(this);
    state_edit = new QLineEdit(this);
    start_btn = new QPushButton(this);
    clear_btn = new QPushButton(this);
    QHBoxLayout* port_layout = new QHBoxLayout(this);
    QHBoxLayout* state_layout = new QHBoxLayout(this);
    QHBoxLayout* btn_layout = new QHBoxLayout(this);
    QVBoxLayout* main_layout = new QVBoxLayout(this);
    QWidget * widget = new QWidget (this) ;

    port_label->setText("Port: ");
    state_label->setText("State: ");
    start_btn->setText("start");
    clear_btn->setText("clear");
    port_layout->addWidget(port_label);
    port_layout->addWidget(port_edit);
    state_layout->addWidget(state_label);
    state_layout->addWidget(state_edit);
    btn_layout->addWidget(start_btn);
    btn_layout->addWidget(clear_btn);

    main_layout->addLayout(port_layout);
    main_layout->addLayout(state_layout);
    main_layout->addLayout(btn_layout);
    widget->setLayout(main_layout);
    this->setCentralWidget(widget);

    m_DOController = new DOController;
    connect(start_btn,SIGNAL(clicked()),SLOT(btnStartClicked()));
    connect(clear_btn,SIGNAL(clicked()),SLOT(btnClearClicked()));
}

MainWindow::~MainWindow()
{
    m_DOController->~DOController();
}

void MainWindow::btnStartClicked()
{
    if(port_edit->text().isEmpty() || state_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input port and state.",QMessageBox::Ok);
    else
    {
        int port = port_edit->text().toInt();
        quint8 state = quint8(state_edit->text().toInt());
        m_DOController->writeData(port,state);
    }
}

void MainWindow::btnClearClicked()
{
    port_edit->clear();
    state_edit->clear();
}
