#include "computedata.h"
#include "communication.h"


union Convert{
    char char_temp[20];
    uint8_t integer1_temp;
    uint16_t integer2_temp;
    int integer4_temp;
    float float_temp;

};

ComputeData::ComputeData()
{
}

void ComputeData::computeData(QByteArray data){
    handleData(data);
}

void ComputeData::handleData(QByteArray data){
    Convert convert;
    switch(Communication::getDataMode()){
    case DataMode::analog:{
        int currentIndex = 2;
        QVector<double> channel1;
        QVector<double> channel2;
        QVector<double> channel3;
        QVector<double> channel4;


        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        uint16_t ch1Bytes = convert.integer2_temp;
        currentIndex++;
        uint16_t channel1Int[ch1Bytes];
        float channel1Float[ch1Bytes];
        for(int i=0 ; i<ch1Bytes ;i+=2){
            convert.char_temp[0] = data[currentIndex];
            currentIndex++;
            convert.char_temp[1] = data[currentIndex];
            channel1Int[i] = convert.integer2_temp;
            channel1Float[i] = float(channel1Int[i])/ADCResoulotion;
            double temp = channel1Float[i]*100;
            temp = int(temp);
            temp /= 100;
            channel1.push_back(temp*5);
            currentIndex++;
        }


        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch2Bytes = convert.integer2_temp;
        uint16_t channel2Int[ch2Bytes];
        float channel2Float[ch2Bytes];
        for(int i=0 ; i<ch2Bytes ;i+=2){
            convert.char_temp[0] = data[currentIndex];
            currentIndex++;
            convert.char_temp[1] = data[currentIndex];
            channel2Int[i] = convert.integer2_temp;
            channel2Float[i] = float(channel2Int[i])/ADCResoulotion;
            double temp = channel2Float[i]*100;
            temp = int(temp);
            temp /= 100;
            channel2.push_back(temp*5);
            currentIndex++;
        }

        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch3Bytes = convert.integer2_temp;
        uint16_t channel3Int[ch3Bytes];
        float channel3Float[ch3Bytes];
        for(int i=0 ; i<ch3Bytes ;i+=2){
            convert.char_temp[0] = data[currentIndex];
            currentIndex++;
            convert.char_temp[1] = data[currentIndex];
            channel3Int[i] = convert.integer2_temp;
            channel3Float[i] = float(channel3Int[i])/ADCResoulotion;
            double temp = channel3Float[i]*100;
            temp = int(temp);
            temp /= 100;
            channel3.push_back(temp*5);
            currentIndex++;
        }


        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch4Bytes = convert.integer2_temp;
        uint16_t channel4Int[ch4Bytes];
        float channel4Float[ch4Bytes];
        for(int i=0 ; i<ch4Bytes ;i+=2){
            convert.char_temp[0] = data[currentIndex];
            currentIndex++;
            convert.char_temp[1] = data[currentIndex];
            channel4Int[i] = convert.integer2_temp;
            channel4Float[i] = float(channel4Int[i])/ADCResoulotion;
            double temp = channel4Float[i]*100;
            temp = int(temp);
            temp /= 100;
            channel4.push_back(temp*5);
            currentIndex++;
        }

        //std::cout << "channel1 has : " << ch1Bytes << " channel2 has : " << ch2Bytes<< " channel3 has : " << ch3Bytes<< " channel4 has : " << ch4Bytes << "\n";
        //packetNumber++;

        emit showDataAnalog(channel1,channel2,channel3,channel4);

        break;
    }
    case DataMode::digital:{
        int currentIndex = 2;
        std::cout << "length : " << data.length() <<"\n";

        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        uint16_t ch1Bytes = convert.integer2_temp;
        QVector<double> channel1;
        currentIndex++;
        uint8_t channel1Int[ch1Bytes];
        for(int i=0 ; i<ch1Bytes ;i++){
            channel1Int[i] = data[currentIndex];
            channel1.push_back(channel1Int[i]);
            currentIndex++;
        }

        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch2Bytes = convert.integer2_temp;
        uint8_t channel2Int[ch2Bytes];
        QVector<double> channel2;
        for(int i=0 ; i<ch2Bytes ;i++){
            channel2Int[i] = data[currentIndex];
            channel2.push_back(channel2Int[i]);
            currentIndex++;
        }

        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch3Bytes = convert.integer2_temp;
        uint8_t channel3Int[ch3Bytes];
        QVector<double> channel3;
        for(int i=0 ; i<ch3Bytes ;i++){
            channel3Int[i] = data[currentIndex];
            channel3.push_back(channel3Int[i]);
            currentIndex++;
        }

        convert.char_temp[0] = data[currentIndex];
        currentIndex++;
        convert.char_temp[1] = data[currentIndex];
        currentIndex++;
        uint16_t ch4Bytes = convert.integer2_temp;
        uint8_t channel4Int[ch4Bytes];
        QVector<double> channel4;
        for(int i=0 ; i<ch4Bytes ;i++){
            channel4Int[i] = data[currentIndex];
            channel4.push_back(channel4Int[i]);
            currentIndex++;
        }

        std::cout << "channel1 has : " << ch1Bytes << " channel2 has : " << ch2Bytes<< " channel3 has : " << ch3Bytes<< " channel4 has : " << ch4Bytes << "\n";
        emit showDataDigital(channel1,channel2,channel3,channel4);

        break;
    }
    case DataMode::connection:{
        convert.char_temp[0] = data[2];
        convert.char_temp[1] = data[3];

        uint16_t isConnected = convert.integer2_temp;

        emit showDataConnection(isConnected);

        break;
    }
    case DataMode::resistor:{
        convert.char_temp[0] = data[2];
        convert.char_temp[1] = data[3];

        uint16_t isConnected = convert.integer2_temp;

        emit showDataResistor(isConnected);

        break;
    }
    case DataMode::capacitor:{
        convert.char_temp[0] = data[2];
        convert.char_temp[1] = data[3];

        uint16_t isConnected = convert.integer2_temp;

        emit showDataCapacitor(isConnected);

        break;
    }
    case DataMode::diode:{
        convert.char_temp[0] = data[2];
        convert.char_temp[1] = data[3];

        uint16_t isConnected = convert.integer2_temp;

        emit showDataDiode(isConnected);

        break;
    }
    case DataMode::current:{
        convert.char_temp[0] = data[2];
        convert.char_temp[1] = data[3];

        uint16_t isConnected = convert.integer2_temp;

        emit showDataCurrent(isConnected);

        break;
    }

    }
}
