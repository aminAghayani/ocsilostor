#ifndef Communication_H
#define Communication_H

#include "QtSerialPort"
#include "QObject"
#include <QUdpSocket>
#include <QNetworkDatagram>
#include <QTest>
#include "QThreadPool"
#include "iostream"
#include <QReadWriteLock>

enum ConnectionMode{usb,wifi,notConnected};

enum DataMode{noData,analog,digital,connection,resistor,capacitor,diode,current};

enum waveType{sinusoidal, rect, ramp};

class Communication : public QObject , public QRunnable
{
    Q_OBJECT

public:
    Communication();
    void run() override;
    static bool connectToUsb();
    static bool connectToWifi();
    static bool disconnectUsb();
    static bool disconnectWifi();
    static int getDataMode();
    static int getConnectionMode();
    static int checkWifiConnection();
    static int checkUsbConnection();
    void receiveWifiData();
    void receiveUsbData();
    static bool currentMeasure();
    static bool resistorMeasure(uint8_t mode);
    static bool capacitorMeasure(uint8_t mode);
    static bool diodeCheck();
    static bool connectionCheck();
    static bool analog(uint16_t freqCh1 , uint16_t freqCh2 , uint16_t freqCh3 , uint16_t freqCh4);
    static bool digital(uint16_t freqCh1 , uint16_t freqCh2 , uint16_t freqCh3 , uint16_t freqCh4);
    static bool dac(float peakToPeak,float shift,float freq,uint8_t waveType,uint8_t channel);
    static bool voltageOut(float voltage , uint8_t channel);
    static bool stop(uint8_t mode);


signals:
    void readyToCompute(QByteArray data);
private:
    static QUdpSocket udpSocket;
    static ConnectionMode connectionMode;
    static DataMode dataMode;
    static QString currentPortName;
    static QSerialPort serial;
    static quint16 distinationPort;
    static QHostAddress distinationAddress;
    static quint16 recieverPort;
    static QHostAddress recieverAddress;
    static bool sendData(QByteArray data);



};

#endif // Communication_H
