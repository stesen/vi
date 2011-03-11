#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    /*Initialize UART*/
    myCom = new Posix_QextSerialPort("/dev/ttyUSB0");
    myCom ->open(QIODevice::ReadWrite);
    myCom->setBaudRate(BAUD9600);
    myCom->setDataBits(DATA_8);
    myCom->setParity(PAR_NONE);
    myCom->setStopBits(STOP_1);
    myCom->setFlowControl(FLOW_OFF);
    myCom->setTimeout(10);

    readTimer = new QTimer(this);
    readTimer->stop();
    connect(readTimer,SIGNAL(timeout()),this,SLOT(readMyCom()));

    QStringList args = QCoreApplication::arguments();
    if (args.count() != 2) {
        printf("ERROR args\n");
        exit(0);
    }

    sendCommand(args[1]);
    counter = 10;
    cnt = 0;
    readTimer->start(100);
}

void MainWindow::readMyCom()
{
    int ctrfortest;
    QByteArray temp = myCom->readAll();

    printf("%s", (const  char*)temp);
    cnt++;
    if(cnt > 100) {
	    exit(0);
    }

    readTimer->stop();

    if (counter >= 0) {
        counter--;
        if (counter == 0) {
            counter = 5;
        }
        ctrfortest = counter;

        if(counter == 5) {
            sendCommand("VAL1?");
        }
    }
    readTimer->start(100);
}

void MainWindow::sendCommand(QString command)
{
    command += "\r\n";
    myCom->write(command.toAscii());
}
