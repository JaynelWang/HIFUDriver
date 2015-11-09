#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTime>
#include <QThread>
#include <QList>
#include "mainwindow.h"
#include "time.h"

Q_LOGGING_CATEGORY(Test,"Test PA_Module")

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    channel_label = new QLabel(this);
    volt_label = new QLabel(this);
    echo_label = new QLabel(this);
    echo_text = new QLabel(this);
    status_label = new QLabel(this);
    status_text = new QLabel(this);
    channel_edit = new QLineEdit(this);
    volt_edit = new QLineEdit(this);
    startSingle_btn = new QPushButton(this);
    startAll1_btn = new QPushButton(this);
    startAll2_btn = new QPushButton(this);
    resetSingle_btn = new QPushButton(this);
    resetAll1_btn = new QPushButton(this);
    resetAll2_btn = new QPushButton(this);
    echoVolt_btn = new QPushButton(this);
    echoTemp_btn = new QPushButton(this);
    testAll_btn = new QPushButton(this);
    stopTest_btn = new QPushButton(this);

    channel_label->setText("Channel ID: ");
    volt_label->setText("Voltage: ");
    echo_label->setText("EchoData: ");
    status_label->setText("Status: ");
    startSingle_btn->setText("StartSingle");
    startAll1_btn->setText("StartAll_1");
    startAll2_btn->setText("StartAll_2");
    resetSingle_btn->setText("ResetSingle");
    resetAll1_btn->setText("ResetAll_1");
    resetAll2_btn->setText("ResetAll_2");
    echoVolt_btn->setText("EchoVolt");
    echoTemp_btn->setText("EchoTemp");
    testAll_btn->setText("TestAll");
    stopTest_btn->setText("StopTest");

    QHBoxLayout* channel_layout = new QHBoxLayout(this);
    channel_layout->addWidget(channel_label);
    channel_layout->addWidget(channel_edit);
    QHBoxLayout* volt_layout = new QHBoxLayout(this);
    volt_layout->addWidget(volt_label);
    volt_layout->addWidget(volt_edit);
    QHBoxLayout* start_layout = new QHBoxLayout(this);
    start_layout->addWidget(startSingle_btn);
    start_layout->addWidget(startAll1_btn);
    start_layout->addWidget(startAll2_btn);
    QHBoxLayout* reset_layout = new QHBoxLayout(this);
    reset_layout->addWidget(resetSingle_btn);
    reset_layout->addWidget(resetAll1_btn);
    reset_layout->addWidget(resetAll2_btn);
    QHBoxLayout* echo_layout = new QHBoxLayout(this);
    echo_layout->addWidget(echoVolt_btn);
    echo_layout->addWidget(echoTemp_btn);
    QHBoxLayout* echoData_layout = new QHBoxLayout(this);
    echoData_layout->addWidget(echo_label);
    echoData_layout->addWidget(echo_text);
    QHBoxLayout* status_layout = new QHBoxLayout(this);
    status_layout->addWidget(status_label);
    status_layout->addWidget(status_text);
    QHBoxLayout* test_layout = new QHBoxLayout(this);
    test_layout->addWidget(testAll_btn);
    test_layout->addWidget(stopTest_btn);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addLayout(channel_layout);
    main_layout->addLayout(volt_layout);
    main_layout->addLayout(start_layout);
    main_layout->addLayout(reset_layout);
    main_layout->addLayout(status_layout);
    main_layout->addLayout(echo_layout);
    main_layout->addLayout(echoData_layout);
    main_layout->addLayout(test_layout);

    QWidget* widget = new QWidget(this);
    widget->setLayout(main_layout);
    this->setCentralWidget(widget);

    m_PAController = new PowerAmp;
    connect(startSingle_btn,SIGNAL(clicked()),SLOT(btnStartSingleClicked()));
    connect(startAll1_btn,SIGNAL(clicked()),SLOT(btnStartAll1Clicked()));
    connect(startAll2_btn,SIGNAL(clicked()),SLOT(btnStartAll2Clicked()));
    connect(resetSingle_btn,SIGNAL(clicked()),SLOT(btnResetSingleClicked()));
    connect(resetAll1_btn,SIGNAL(clicked()),SLOT(btnResetAll1Clicked()));
    connect(resetAll2_btn,SIGNAL(clicked()),SLOT(btnResetAll2Clicked()));
    connect(echoVolt_btn,SIGNAL(clicked()),SLOT(btnEchoVoltClicked()));
    connect(echoTemp_btn,SIGNAL(clicked()),SLOT(btnEchoTempClicked()));
    connect(testAll_btn,SIGNAL(clicked()),SLOT(btnTestAllClicked()));
    connect(stopTest_btn,SIGNAL(clicked()),SLOT(btnStopTestClicked()));
}

MainWindow::~MainWindow()
{
    m_PAController->~PowerAmp();
}

void MainWindow::btnStartSingleClicked()
{
    status_text->clear();
    if (channel_edit->text().isEmpty() || volt_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input channel ID and voltage value.",QMessageBox::Ok);
    else
    {
        int channel = channel_edit->text().toInt();
        VOLT volt = volt_edit->text().toDouble();
        bool success = m_PAController->startSingle(channel,volt);
        status_text->text() = success;
    }
}

void MainWindow::btnStartAll1Clicked()
{
    status_text->clear();
    if (volt_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input voltage value.",QMessageBox::Ok);
    else
    {
        VOLT volt = volt_edit->text().toDouble();
        bool success = m_PAController->startAll(volt);
        status_text->text() = success;
    }
}

void MainWindow::btnStartAll2Clicked()
{
    status_text->clear();
    if (volt_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input voltage value.",QMessageBox::Ok);
    else
    {
        VOLT volt = volt_edit->text().toDouble();
        bool success = m_PAController->startAll2(volt);
        status_text->text() = success;
    }
}

void MainWindow::btnResetSingleClicked()
{
    status_text->clear();
    if (channel_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input channel ID.",QMessageBox::Ok);
    else
    {
        int channel = channel_edit->text().toInt();
        bool success = m_PAController->resetSingle(channel);
        status_text->text() = success;
    }
}

void MainWindow::btnResetAll1Clicked()
{
    status_text->clear();
    bool success = m_PAController->resetAll();
    status_text->text() = success;
}

void MainWindow::btnResetAll2Clicked()
{
    status_text->clear();
    bool success = m_PAController->resetAll2();
    status_text->text() = success;
}

void MainWindow::btnEchoVoltClicked()
{
    echo_text->clear();
    if (channel_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input channel ID.",QMessageBox::Ok);
    else
    {
        int channel = channel_edit->text().toInt();
        QString echoData = QString::number(m_PAController->echoVolt(channel));
        echo_text->setText(echoData);
    }
}

void MainWindow::btnEchoTempClicked()
{
    echo_text->clear();
    if (channel_edit->text().isEmpty())
        QMessageBox::warning(NULL,"warning","Please input channel ID.",QMessageBox::Ok);
    else
    {
        int channel = channel_edit->text().toInt();
        QString echoData = QString::number(m_PAController->echoTemp(channel));
        echo_text->setText(echoData);
    }
}

void MainWindow::btnTestAllClicked()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * MS_UNIT);

    int runTimes = 1;
    while(true)
    {
        //start testing
        qCDebug(Test()) << Test().categoryName() <<":" << "Starting testing";
        qCWarning(Test()) << Test().categoryName() <<":" << "Starting testing";
        qCWarning(Test()) << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ").toLocal8Bit() << "    Current run times: " << runTimes;

        //randomly generate 12 unique channel IDs within the range of 1-144
//        #define TEST
        #ifdef TEST

        int i, channel[12];
        i = 0;
        while (i < 12)
        {
            int random = genRandomID();
            if (checkUnique(random,channel))
            {
                channel[i] = random;
                qCDebug(Test()) << "Number of channel" << i+1 << ":" << channel[i];
                i += 1;
            }
            else
            {
                qCDebug(Test()) << "Generate the same channel ID.";
            }
        }

        #else
        int i = 0;
        QList<int> channel;
        while (i < 12)
        {
            int random = genRandomID();
            if (!channel.contains(random))
            {
                channel.append(random);
                qCDebug(Test()) << "Number of channel" << i+1 << ":" << channel[i];
                i += 1;
            }
        }
        #endif

        qCDebug(Test())<<"======================================";

        //randomly generate voltage values within the range of 0-18 V
        QList<VOLT> volt;
        i = 0;
        VOLT random;
        while (i < 12)
        {
            random = (qrand() % 180) / 10.0;
            while (random == 0.0)
            {
                random = (qrand() % 180) / 10.0;
            }
            volt.append(random);
            qCDebug(Test()) << "Voltage value" << i+1 << ":" << volt[i];
            i += 1;
        }
        qCDebug(Test())<<"======================================";

        //start setting single power amplifier
        qCDebug(Test()) << "startSinglePowerAmp: ";
        bool success;
        for (i = 0; i < 12; i++)
        {
            QThread::msleep(100);
            success = m_PAController->startSingle(channel[i], volt[i]);
            qCDebug(Test()) << "Result" << i+1 << ":" << success;
            if (!success)
                qCWarning(Test()) << "Start single result" << i+1 << ":" << success;
        }
        qCDebug(Test())<<"======================================";

        //start echoing voltage value
        qCDebug(Test()) << "echoVolt: ";
        VOLT echoVolt;
        for (i = 0; i < 12; i++)
        {
            QThread::msleep(100);
            echoVolt = m_PAController->echoVolt(channel[i]);
            qCDebug(Test()) << "Echo Volt" << i+1 << ":" << echoVolt;
            if (!success)
                qCWarning(Test()) << "Echo volt result" << i+1 << ":" << success;
        }
        qCDebug(Test())<<"======================================";

        //start echoing temperature value
        qCDebug(Test()) << "echoTemp: ";
        VOLT echoTemp;
        for (i = 0; i < 12; i++)
        {
            QThread::msleep(100);
            echoTemp = m_PAController->echoTemp(channel[i]);
            qCDebug(Test()) << "Echo Temp" << i+1 << ":" << echoTemp;
            if (!success)
                qCWarning(Test()) << "Echo temp result" << i+1 << ":" << success;
        }
        qCDebug(Test())<<"======================================";

        //starting reseting single power amplifier
        qCDebug(Test()) << "resetSinglePowerAmp: ";
        for (i = 0; i < 12; i++)
        {
            QThread::msleep(100);
            success = m_PAController->resetSingle(channel[i]);
            qCDebug(Test()) << "Result" << i+1 << ":" << success;
            if (!success)
                qCWarning(Test()) << "Reset single result" << i+1 << ":" << success;
        }
        qCDebug(Test())<<"======================================";

        //start setting all power amplifiers: method one
        qCDebug(Test()) << "startAllPowerAmp_1: ";
        double time_Start = (double)clock();
        success = m_PAController->startAll(volt[6]);
        double time_End = (double)clock();
        qCDebug(Test()) << "Result" << ":" << success;
        if (!success)
            qCWarning(Test()) << "Start all result:" << success;
        qCWarning(Test()) <<"startAllPowerTime: "<< (time_End - time_Start) / 1000.0 << "s";
        qCDebug(Test())<<"======================================";

        //start reseting all power amplifiers: method one
        qCDebug(Test()) << "resetAllPowerAmp_1: ";
        time_Start = (double)clock();
        success = m_PAController->resetAll();
        time_End = (double)clock();
        qCDebug(Test()) << "Result" << ":" << success;
        if (!success)
            qCWarning(Test()) << "Reset all result:" << success;
        qCWarning(Test()) <<"resetAllPowerAmpTime: "<< (time_End - time_Start) / 1000.0 << "s";
        qCDebug(Test())<<"======================================";

        //start setting all power amplifiers: method two
        qCDebug(Test()) << "startAllPowerAmp_2: ";
        time_Start = (double)clock();
        success = m_PAController->startAll2(volt[6]);
        time_End = (double)clock();
        qCDebug(Test()) << "Result" << ":" << success;
        if (!success)
            qCWarning(Test()) << "Start all result:" << success;
        qCWarning(Test()) <<"startAllPowerTime2: "<< (time_End - time_Start) / 1000.0 << "s";
        qCDebug(Test())<<"======================================";  

        //start reseting all power amplifiers: method two
        qCDebug(Test()) << "resetAllPowerAmp_2: ";
        time_Start = (double)clock();
        success = m_PAController->resetAll2();
        time_End = (double)clock();
        qCDebug(Test()) << "Result" << ":" << success;
        if (!success)
            qCWarning(Test()) << "Reset all result:" << success;
        qCWarning(Test()) <<"resetAllPowerAmpTime2: "<< (time_End - time_Start) / 1000.0 << "s";
        qCDebug(Test())<<"======================================";

        //end testing
        qCDebug(Test()) << Test().categoryName() <<":" << "End testing";
        qCDebug(Test())<<"======================================";
        qCWarning(Test()) << Test().categoryName() <<":" << "End testing";
        qCWarning(Test())<<"======================================";
        runTimes += 1;
    }
}

void MainWindow::btnStopTestClicked()
{
    exit(0);
}

int MainWindow::genRandomNum()
{
    QTime time = QTime::currentTime();
    qsrand(time.msec() + time.second() * MS_UNIT);
    return qrand();
}

int MainWindow::genRandomID()
{
    int ranId = genRandomNum() % 145;
    while (ranId == 0 || ranId == 22 || ranId == 23 || ranId == 56 || ranId == 65 || ranId == 74 || ranId == 80 || ranId == 81 || ranId == 99 || ranId == 113 || ranId == 124 || ranId == 132 || ranId == 134)
    {
        ranId = genRandomNum() % 145;
    }
    return ranId;
}

VOLT MainWindow::genRandomVolt()
{
    VOLT volt = (genRandomNum() % 180) / 10.0;
    while (volt == 0.0)
    {
        volt = (genRandomNum() % 180) / 10.0;
    }
    return volt;
}

bool MainWindow::checkUnique(int random, int data[])
{
    bool isUnique = true;
    int length = sizeof(data) / sizeof(int);
    if (!length == 0)
    {
        for(int i = 0; i < length; i++)
        {
            if (random == data[i])
            {
                isUnique = false;
                break;
            }
        }
    }
    return isUnique;
}
