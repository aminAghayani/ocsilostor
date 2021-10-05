#include "communication.h"
#include <QSerialPortInfo>
#include "stdio.h"
#include "iostream"
#include "computedata.h"

ConnectionMode Communication::connectionMode = notConnected;
DataMode Communication::dataMode = noData;
QString Communication::currentPortName = "notConnected";
QSerialPort Communication::serial;
QUdpSocket Communication::udpSocket;

quint16 Communication::distinationPort = 51919;
QHostAddress Communication::distinationAddress("192.168.4.1");
quint16 Communication::recieverPort = 60000;
QHostAddress Communication::recieverAddress("192.168.4.100");

union Convert{
    char char_temp[20];
    uint8_t integer1_temp;
    uint16_t integer2_temp;
    int integer4_temp;
    float float_temp;

};

Communication::Communication()
{
}

void Communication::run(){
    if(connectionMode == usb)
        receiveUsbData();
    else if(connectionMode == wifi)
        receiveWifiData();
    std::cout << "closed\n\n";
    return;
}

int Communication::getDataMode(){
    return dataMode;
}

int Communication::getConnectionMode(){
    return connectionMode;
}

int Communication::checkWifiConnection(){
    /// zero is ready to connect and not connected to any thing
    /// one is connected to usb
    /// two is already connected to wifi
    /// three is unknown error

    if(connectionMode == notConnected && currentPortName == "notConnected"
            && udpSocket.state() == udpSocket.UnconnectedState)
        return 0;
    else if(connectionMode == usb)
        return 1;
    else if (udpSocket.state() == udpSocket.BoundState){
        ///check if wifi is still connected
        return 2;
    }
    return 3;
}

bool Communication::connectToWifi(){
    bool status;
    status = udpSocket.bind(recieverAddress , recieverPort);

    if(!status){
        return false;
    }

    connectionMode = wifi;
    udpSocket.open(udpSocket.ReadWrite);
    udpSocket.writeDatagram("Hello" , 5 , distinationAddress , distinationPort);
    status = udpSocket.waitForReadyRead(1000);
    if(!status){
        return false;
    }
    else{
        QNetworkDatagram datagram = udpSocket.receiveDatagram(1000);
        if(datagram.data().toStdString() != "Hello")
            return false;
    }
    return true;
}

void Communication::receiveWifiData(){
    while (connectionMode == wifi){
        if(udpSocket.hasPendingDatagrams()){
            QNetworkDatagram datagram = udpSocket.receiveDatagram();
            emit readyToCompute(datagram.data());
        }
        QThread::msleep(50);
    }
}

bool Communication::disconnectWifi(){
    connectionMode = notConnected;
    currentPortName = "notConnected";
    udpSocket.writeDatagram("Bye" , 3 , distinationAddress , distinationPort);
    udpSocket.disconnectFromHost();
    if(udpSocket.state() != udpSocket.UnconnectedState)
        udpSocket.waitForDisconnected();
    return true;
}

int Communication::checkUsbConnection(){
    /// zero is ready to connect and not connected to any thing
    /// one is connected to wifi
    /// two is already connected to usb
    /// three is unknown error

    if(connectionMode == notConnected && currentPortName == "notConnected")
        return 0;
    else if(connectionMode == wifi)
        return 1;
    else{
        ///check if port is still available
        QSerialPortInfo info;
        bool portAvailable = false;
        for(int i = 0 ; i<info.availablePorts().length() ; i++){
            if(info.availablePorts()[i].portName() == currentPortName && info.availablePorts()[i].isBusy() == true){
                portAvailable = true;
            }
        }
        if (portAvailable == false){
            return 3;
        }
    }
    return 2;
}

bool Communication::connectToUsb(){

    QSerialPortInfo info;
    for(int i = 0 ; i<info.availablePorts().length() ; i++){
        serial.close();
        if(!info.availablePorts()[i].isBusy()){

            QString PortName = info.availablePorts()[i].portName();
            serial.setPortName(PortName);
            serial.setReadBufferSize(40000);

            if (!serial.open(QIODevice::ReadWrite))
                continue;

            serial.write("Hello",5);

            serial.waitForReadyRead(1000);

            QByteArray responseData = serial.readAll();

            std::string utf8_text = responseData.toStdString();

            if (utf8_text.find("received") != std::string::npos){
                connectionMode = usb;
                currentPortName = PortName;
                return true;
            }
        }
    }
    serial.close();
    return false;
}

void Communication::receiveUsbData(){

    while(connectionMode == usb){

        serial.waitForReadyRead(1000);

        QByteArray responseData = serial.readAll();

        if (responseData.length() > 0)
            std::cout << responseData[1] << "\n";
            emit readyToCompute(responseData);
    }

    //QThread::msleep(5);
}

bool Communication::disconnectUsb(){
    connectionMode = notConnected;
    currentPortName = "notConnected";
    for (int i=0 ; i<5 ; i++){
        serial.write("Bye",3);
        QThread::msleep(10);
    }
    //serial.close();
    return true;

}

bool Communication::currentMeasure(){
    dataMode = DataMode::current;
    bool status;
    status = sendData("siend");
    return status;
}

bool Communication::resistorMeasure(uint8_t mode){
    dataMode = DataMode::resistor;
    Convert convert;
    convert.integer1_temp = mode;
    QByteArray data = "sr";
    data += convert.char_temp[0];
    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::capacitorMeasure(uint8_t mode){
    dataMode = DataMode::capacitor;
    Convert convert;
    convert.integer1_temp = mode;
    QByteArray data = "sc";
    data += convert.char_temp[0];
    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::diodeCheck(){
    dataMode = DataMode::diode;
    bool status;
    status = sendData("smdend");
    return status;

}

bool Communication::connectionCheck(){
    dataMode = DataMode::connection;
    bool status;
    status = sendData("smcend");
    return status;
}

bool Communication::analog(uint16_t freqCh1 , uint16_t freqCh2 , uint16_t freqCh3 , uint16_t freqCh4){
    dataMode = DataMode::analog;
    Convert convert;
    QByteArray data = "sa";

    convert.integer4_temp = freqCh1;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh2;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh3;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh4;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::digital(uint16_t freqCh1 , uint16_t freqCh2 , uint16_t freqCh3 , uint16_t freqCh4){
    dataMode = DataMode::digital;
    Convert convert;
    QByteArray data = "sd";

    convert.integer4_temp = freqCh1;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh2;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh3;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.integer4_temp = freqCh4;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::dac(float peakToPeak,float shift,float freq,uint8_t waveType,uint8_t channel){
    Convert convert;
    QByteArray data = "sw";

    convert.integer1_temp = channel;
    data += convert.char_temp[0];

    convert.integer1_temp = waveType;
    data += convert.char_temp[0];

    convert.float_temp = peakToPeak;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.float_temp = shift;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    convert.float_temp = freq;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::voltageOut(float voltage , uint8_t channel){
    Convert convert;
    QByteArray data = "sv";

    convert.integer1_temp = channel;
    data += convert.char_temp[0];

    convert.float_temp = voltage;
    data += convert.char_temp[0];
    data += convert.char_temp[1];
    data += convert.char_temp[2];
    data += convert.char_temp[3];

    data += "end";
    bool status;
    status = sendData(data);
    return status;
}

bool Communication::stop(uint8_t mode){
    Convert convert;
    QByteArray data = "ss";

    dataMode = DataMode::noData;
    bool status;

    convert.integer1_temp = mode;
    data += convert.char_temp[0];

    data += "end";
    status = sendData(data);
    return status;
}

bool Communication::sendData(QByteArray data){
    bool status;

    if(connectionMode == usb){
        std::cout << data.toStdString() << "\n";
        serial.write(data,data.length());
        serial.waitForReadyRead(10);
        QByteArray responseData = serial.readAll();
        if (responseData.toStdString().find("received") != std::string::npos){
            return true;
        }
        return false;
    }

    else if(connectionMode == wifi){
        std::cout << data.toStdString() << "\n";
        udpSocket.writeDatagram(data , data.length() , distinationAddress , distinationPort);
        status = udpSocket.waitForReadyRead(10);
        if(!status){
            return false;
        }
        else{
            QNetworkDatagram datagram = udpSocket.receiveDatagram(10);
            if(datagram.data().toStdString() != "Ok")
                return false;
        }
        return true;
    }

    return false;
}

void readyToCompute(QByteArray data){

}
