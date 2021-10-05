#ifndef COMPUTEDATA_H
#define COMPUTEDATA_H
#include "QObject"
#include "stdio.h"
#include "iostream"
#include "QThread"
#include "QThreadPool"

#define ADCResoulotion 4096

class ComputeData : public QObject
{
    Q_OBJECT

public:
    ComputeData();

signals:
    void showDataAnalog(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4);
    void showDataDigital(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4);
    void showDataConnection(uint16_t isConnected);
    void showDataResistor(uint16_t resValue);
    void showDataCapacitor(uint16_t capValue);
    void showDataDiode(uint16_t diodeValue);
    void showDataCurrent(uint16_t currentValue);

public slots:
    void computeData(QByteArray data);

private:
    void currentMeasure();
    void resistorMeasure();
    void capacitorMeasure();
    void diodeCheck();
    void connectionCheck();
    void analog();
    void digital();
    void dac();
    void voltageOut();
    void handleData(QByteArray data);
};

class ComputeDataThread : public QThread
{
    Q_OBJECT

public:
    ComputeDataThread(){}
    void run() override{
        std::cout << "compute thread is started\n";
        exec();
    }

};

#endif // COMPUTEDATA_H
