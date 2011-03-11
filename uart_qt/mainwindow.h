#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QMessageBox>
#include <QCoreApplication>
#include <stdio.h>
#include <unistd.h>
#include "posix_qextserialport.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

protected:

private:
    Posix_QextSerialPort *myCom;
    int counter, cnt;
    QTimer *readTimer;
    void sendCommand(QString command);

private slots:
    void readMyCom();
};

#endif // MAINWINDOW_H
