#include "mainwindow.h"
#include <QApplication>
#include <QSerialPortInfo>
#include "QtSerialPort"
#include "stdio.h"
#include "iostream"
#include "qobject.h"

int main(int argc, char *argv[])
{
    //std::cout << "programm started!!\n\n";

    //Handler *handler = new Handler();
    // QThreadPool takes ownership and deletes 'hello' automatically
    //QThreadPool::globalInstance()->start(handler);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
