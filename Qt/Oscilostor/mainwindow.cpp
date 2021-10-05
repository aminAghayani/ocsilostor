#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "communication.h"
#include "computedata.h"
#include "qobject.h"
#include "qnamespace.h"
#include "iostream"
#include "stdio.h"
#include <QMessageBox>

ComputeData *uiComputeData = new ComputeData();
Communication *uiCommunication = new Communication();
ComputeDataThread computeDataThread;

float freqFloatAnalog[4];
uint16_t freqAnalog[4],freqDigital[4];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralWidget->setWindowTitle("Oscilostor");
    ui->comboBox_Res->addItem("200 Ohm");
    ui->comboBox_Res->addItem("1 KOhm");
    ui->comboBox_Res->addItem("100 KOhm");
    ui->comboBox_Res->addItem("1 MOhm");
    ui->comboBox_Cap->addItem("100 nF");
    ui->comboBox_Cap->addItem("1 uF");
    ui->comboBox_Cap->addItem("47 uF");
    ui->comboBox_Cap->addItem("470 uF");

    ui->comboBox_math1->addItem("none");
    ui->comboBox_math1->addItem("fft");
    ui->comboBox_math1->addItem("log");

    ui->comboBox_math2->addItem("none");
    ui->comboBox_math2->addItem("fft");
    ui->comboBox_math2->addItem("log");

    ui->comboBox_math3->addItem("none");
    ui->comboBox_math3->addItem("fft");
    ui->comboBox_math3->addItem("log");

    ui->comboBox_math4->addItem("none");
    ui->comboBox_math4->addItem("fft");
    ui->comboBox_math4->addItem("log");

    ui->comboBox_dac1->addItem("sinusoidal");
    ui->comboBox_dac1->addItem("rect");
    ui->comboBox_dac1->addItem("ramp");

    ui->comboBox_dac2->addItem("sinusoidal");
    ui->comboBox_dac2->addItem("rect");
    ui->comboBox_dac2->addItem("ramp");

    ui->freq_channel1_value_analog->setText("5000");
    ui->freq_channel2_value_analog->setText("5000");
    ui->freq_channel3_value_analog->setText("5000");
    ui->freq_channel4_value_analog->setText("5000");
    ui->factor_channel1_value->setText("1");
    ui->factor_channel2_value->setText("1");
    ui->factor_channel3_value->setText("1");
    ui->factor_channel4_value->setText("1");
    ui->shift_channel1_value->setText("0");
    ui->shift_channel2_value->setText("0");
    ui->shift_channel3_value->setText("0");
    ui->shift_channel4_value->setText("0");

    ui->freq_channel1_value_digital->setText("100");
    ui->freq_channel2_value_digital->setText("100");
    ui->freq_channel3_value_digital->setText("100");
    ui->freq_channel4_value_digital->setText("100");

    ui->dac1freq_value->setText("50");
    ui->dac2freq_value->setText("50");
    ui->dac1pp_value->setText("3.3");
    ui->dac2pp_value->setText("3.3");
    ui->dac1shift_value->setText("0");
    ui->dac2shift_value->setText("0");
    ui->voltageout1_value->setText("3.3");
    ui->voltageout2_value->setText("3.3");

    graphInit();

    qRegisterMetaType<uint16_t>("uint16_t");
    qRegisterMetaType<QVector<double>>("QVector<double>");


    //uiCommunication->moveToThread(uiCommunication->thread);
    //uiComputeData->moveToThread(uiComputeData->thread);
    connect(uiCommunication,SIGNAL(readyToCompute(QByteArray)),uiComputeData,SLOT(computeData(QByteArray)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataAnalog(QVector<double>,QVector<double>,QVector<double>,QVector<double>)),this,SLOT(showingAnalog(QVector<double>,QVector<double>,QVector<double>,QVector<double>)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataDigital(QVector<double>,QVector<double>,QVector<double>,QVector<double>)),this,SLOT(showingDigital(QVector<double>,QVector<double>,QVector<double>,QVector<double>)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataConnection(uint16_t)),this,SLOT(showingConnection(uint16_t)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataResistor(uint16_t)),this,SLOT(showingResistor(uint16_t)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataCapacitor(uint16_t)),this,SLOT(showingCapacitor(uint16_t)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataDiode(uint16_t)),this,SLOT(showingDiode(uint16_t)),Qt::QueuedConnection);
    connect(uiComputeData,SIGNAL(showDataCurrent(uint16_t)),this,SLOT(showingCurrent(uint16_t)),Qt::QueuedConnection);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateGraphCallBack);
    timer->start(10);

    computeDataThread.start();
    uiCommunication->moveToThread(&computeDataThread);
    //std::cout << ui->comboBox_Res->currentText().toUtf8().toStdString() <<"\n\n";
}

MainWindow::~MainWindow()
{
    computeDataThread.exit();
    delete ui;
}

/////////////
///
/// Connectivity functions
///
/////////////
void MainWindow::on_usb_connect_pushButton_clicked()
{
    ui->usb_connect_pushButton->setEnabled(false);
    ui->wifi_connect_pushButton->setEnabled(false);
    ui->statusBar->showMessage("please wait untill connecting...." , 2000);
    int status;
    status = Communication::checkUsbConnection();
    if (status == 0){

        status = Communication::connectToUsb();

        if(status){

            QThreadPool::globalInstance()->tryStart(uiCommunication);
            uiCommunication->setAutoDelete(true);
            ui->statusBar->showMessage("usb connected" , 2000);
        }
        else
            ui->statusBar->showMessage("failed to connect please try again" , 2000);
    }
    else if(status == 1)
        ui->statusBar->showMessage("disconnect from wifi then connect again" , 2000);
    else if(status == 2)
        ui->statusBar->showMessage("already connected to usb" , 2000);
    else if(status == 3)
        ui->statusBar->showMessage("some thing went wrong disconnect from usb then connect again" , 2000);

    ui->usb_connect_pushButton->setEnabled(true);
    ui->wifi_connect_pushButton->setEnabled(true);
}

void MainWindow::on_usb_disconnect_pushButton_clicked()
{
    bool status;
    status = Communication::disconnectUsb();
    if(status)
        ui->statusBar->showMessage("disconnected successfully from usb" , 2000);
    else
        ui->statusBar->showMessage("disconnection failed try again" , 2000);

}

void MainWindow::on_wifi_connect_pushButton_clicked()
{
    ui->usb_connect_pushButton->setEnabled(false);
    ui->wifi_connect_pushButton->setEnabled(false);
    ui->statusBar->showMessage("please wait untill connecting...." , 2000);
    int status;
    status = Communication::checkWifiConnection();
    if (status == 0){

        status = Communication::connectToWifi();

        if(status){
            QThreadPool::globalInstance()->tryStart(uiCommunication);
            uiCommunication->setAutoDelete(true);
            ui->statusBar->showMessage("connected to wifi" , 2000);
            ui->wifi_status->setStyleSheet("background-color: rgb(55, 255, 105);");
            ui->wifi_status->setText("Connected");
        }
        else
            ui->statusBar->showMessage("failed to connect please try again" , 2000);
    }
    else if(status == 1)
        ui->statusBar->showMessage("disconnect from usb then connect again" , 2000);
    else if(status == 2)
        ui->statusBar->showMessage("already connected to wifi" , 2000);
    else if(status == 3)
        ui->statusBar->showMessage("some thing went wrong disconnect from wifi then connect again" , 2000);

    ui->usb_connect_pushButton->setEnabled(true);
    ui->wifi_connect_pushButton->setEnabled(true);

}

void MainWindow::on_wifi_disconnect_pushButton_clicked()
{
    bool status;
    status = Communication::disconnectWifi();
    if(status){
        ui->statusBar->showMessage("disconnected successfully from wifi" , 2000);
        ui->wifi_status->setStyleSheet("background-color: rgb(255, 73, 76);");
        ui->wifi_status->setText("Not Connected");
    }
    else
        ui->statusBar->showMessage("disconnection failed try again" , 2000);

}

/////////////
///
/// measure functions
///
/////////////
void MainWindow::on_connection_check_pushButton_clicked()
{
    if(ui->connection_check_pushButton->text() == "Check"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                Communication::connectionCheck();
                ui->connection_check_pushButton->setText("Stop");
                ui->connection_check_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }
    }
    else if(ui->connection_check_pushButton->text() == "Stop"){
        ui->connection_check_pushButton->setText("Check");
        ui->connection_check_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(0);
    }

}

void MainWindow::on_diode_check_pushButton_clicked()
{
    if(ui->diode_check_pushButton->text() == "Check"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                Communication::diodeCheck();
                ui->diode_check_pushButton->setText("Stop");
                ui->diode_check_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }
    }
    else if(ui->diode_check_pushButton->text() == "Stop"){
        ui->diode_check_pushButton->setText("Check");
        ui->diode_check_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(0);
    }
}

void MainWindow::on_resistor_measure_pushButton_clicked()
{
    if(ui->resistor_measure_pushButton->text() == "Measure"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                Communication::resistorMeasure(ui->comboBox_Res->currentIndex());
                ui->resistor_measure_pushButton->setText("Stop");
                ui->resistor_measure_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }

    }
    else if(ui->resistor_measure_pushButton->text() == "Stop"){
        ui->resistor_measure_pushButton->setText("Measure");
        ui->resistor_measure_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(0);
    }
}

void MainWindow::on_capacitor_measure_pushButton_clicked()
{
    if(ui->capacitor_measure_pushButton->text() == "Measure"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                Communication::capacitorMeasure(ui->comboBox_Cap->currentIndex());
                ui->capacitor_measure_pushButton->setText("Stop");
                ui->capacitor_measure_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }
    }
    else if(ui->capacitor_measure_pushButton->text() == "Stop"){
        ui->capacitor_measure_pushButton->setText("Measure");
        ui->capacitor_measure_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(0);
    }
}

void MainWindow::on_current_measure_pushButton_clicked()
{
    if(ui->current_measure_pushButton->text() == "Measure"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                Communication::currentMeasure();
                ui->current_measure_pushButton->setText("Stop");
                ui->current_measure_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }
    }
    else if(ui->current_measure_pushButton->text() == "Stop"){
        ui->current_measure_pushButton->setText("Measure");
        ui->current_measure_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(0);
    }
}

/////////////
///
/// digital and analog functions
///
/////////////
void MainWindow::on_analog_start_pushButton_clicked()
{
    if(ui->analog_start_pushButton->text() == "start"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                freqFloatAnalog[0] = ui->freq_channel1_value_analog->text().toFloat();
                freqFloatAnalog[1] = ui->freq_channel2_value_analog->text().toFloat();
                freqFloatAnalog[2] = ui->freq_channel3_value_analog->text().toFloat();
                freqFloatAnalog[3] = ui->freq_channel4_value_analog->text().toFloat();
                freqAnalog[0] = int(freqFloatAnalog[0]);
                freqAnalog[1] = int(freqFloatAnalog[1]);
                freqAnalog[2] = int(freqFloatAnalog[2]);
                freqAnalog[3] = int(freqFloatAnalog[3]);
                if(freqAnalog[0]+freqAnalog[1]+freqAnalog[2]+freqAnalog[3] > 20000 && Communication::getConnectionMode() == usb){
                    QMessageBox::information(this,"warning","sum of all your frequencies should be below 20KHz in usb connection");
                }
                else if(freqAnalog[0]+freqAnalog[1]+freqAnalog[2]+freqAnalog[3] > 200 && Communication::getConnectionMode() == wifi){
                    QMessageBox::information(this,"warning","sum of all your frequencies should be below 200Hz in wifi connection");
                }
                else{
                    Communication::analog(freqAnalog[0],freqAnalog[1],freqAnalog[2],freqAnalog[3]);
                    ui->analog_start_pushButton->setText("Stop");
                    ui->analog_start_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
                }
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }

    }
    else if(ui->analog_start_pushButton->text() == "Stop"){
        ui->analog_start_pushButton->setText("start");
        ui->analog_start_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(5);
    }
}

void MainWindow::on_analog_clear_pushButton_clicked()
{
    analogGraphClear();
}

void MainWindow::on_analog_cursor_pushButton_clicked()
{

}

void MainWindow::on_analog_save_pushButton_clicked()
{

}

void MainWindow::on_digital_start_pushButton_clicked()
{
    if(ui->digital_start_pushButton->text() == "start"){
        if (Communication::getDataMode() == noData){
            if (Communication::getConnectionMode() == notConnected){
                ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
            }
            else{
                freqDigital[0] = ui->freq_channel1_value_digital->text().toUInt();
                freqDigital[1] = ui->freq_channel2_value_digital->text().toUInt();
                freqDigital[2] = ui->freq_channel3_value_digital->text().toUInt();
                freqDigital[3] = ui->freq_channel4_value_digital->text().toUInt();
                if((freqDigital[0] > 10000 || freqDigital[1] > 10000 || freqDigital[2] > 10000 || freqDigital[3] > 10000) && Communication::getConnectionMode() == usb ){
                    QMessageBox::information(this,"warning","Each of frequencies should be below 10KHz in usb connection");
                }
                else if((freqDigital[0] > 1000 || freqDigital[1] > 1000 || freqDigital[2] > 1000 || freqDigital[3] > 1000) && Communication::getConnectionMode() == wifi ){
                    QMessageBox::information(this,"warning","Each of frequencies should be below 10KHz in wifi connection");
                }
                else{
                    Communication::digital(freqDigital[0],freqDigital[1],freqDigital[2],freqDigital[3]);
                    ui->digital_start_pushButton->setText("Stop");
                    ui->digital_start_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
                }
            }
        }
        else{
            QMessageBox::information(this,"warning","you can only run one of the measures or digital or analog at same time");
        }
    }
    else if(ui->digital_start_pushButton->text() == "Stop"){
        ui->digital_start_pushButton->setText("start");
        ui->digital_start_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(6);
    }
}

void MainWindow::on_digital_clear_pushButton_clicked()
{
    digitalGraphClear();
}

void MainWindow::on_digital_cursor_pushButton_clicked()
{

}

void MainWindow::on_digital_save_pushButton_clicked()
{
    digitalGraphSave();
}

void MainWindow::on_analog_channel1_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->analogPlot->graph(0)->setVisible(false);
    else
        ui->analogPlot->graph(0)->setVisible(true);
    ui->analogPlot->replot();
}

void MainWindow::on_analog_channel2_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->analogPlot->graph(1)->setVisible(false);
    else
        ui->analogPlot->graph(1)->setVisible(true);
    ui->analogPlot->replot();
}

void MainWindow::on_analog_channel3_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->analogPlot->graph(2)->setVisible(false);
    else
        ui->analogPlot->graph(2)->setVisible(true);
    ui->analogPlot->replot();
}

void MainWindow::on_analog_channel4_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->analogPlot->graph(3)->setVisible(false);
    else
        ui->analogPlot->graph(3)->setVisible(true);
    ui->analogPlot->replot();
}

void MainWindow::on_digital_channel1_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->digitalPlot->graph(0)->setVisible(false);
    else
        ui->digitalPlot->graph(0)->setVisible(true);
    ui->digitalPlot->replot();
}

void MainWindow::on_digital_channel2_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->digitalPlot->graph(1)->setVisible(false);
    else
        ui->digitalPlot->graph(1)->setVisible(true);
    ui->digitalPlot->replot();
}

void MainWindow::on_digital_channel3_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->digitalPlot->graph(2)->setVisible(false);
    else
        ui->digitalPlot->graph(2)->setVisible(true);
    ui->digitalPlot->replot();
}

void MainWindow::on_digital_channel4_checkBox_clicked(bool checked)
{
    if(checked == false)
        ui->digitalPlot->graph(3)->setVisible(false);
    else
        ui->digitalPlot->graph(3)->setVisible(true);
    ui->digitalPlot->replot();
}

/////////////
///
/// voltage out functions
///
/////////////
void MainWindow::on_voltageout1_pushButton_clicked()
{
    if(ui->voltageout1_pushButton->text() == "Generate"){
        if (Communication::getConnectionMode() == notConnected){
            ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
        }
        else{
            Communication::voltageOut(ui->voltageout1_value->text().toFloat(),0);
            ui->voltageout1_pushButton->setText("Stop");
            ui->voltageout1_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
        }
    }
    else if(ui->voltageout1_pushButton->text() == "Stop"){
        ui->voltageout1_pushButton->setText("Generate");
        ui->voltageout1_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(1);
    }
}

void MainWindow::on_voltageout2_pushButton_clicked()
{
    if(ui->voltageout2_pushButton->text() == "Generate"){
        if (Communication::getConnectionMode() == notConnected){
            ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
        }
        else{
            Communication::voltageOut(ui->voltageout2_value->text().toFloat(),1);
            ui->voltageout2_pushButton->setText("Stop");
            ui->voltageout2_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");

        }
    }
    else if(ui->voltageout2_pushButton->text() == "Stop"){
        ui->voltageout2_pushButton->setText("Generate");
        ui->voltageout2_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(2);
    }
}

void MainWindow::on_dac1_pushButton_clicked()
{
    if(ui->dac1_pushButton->text() == "Generate"){
        if (Communication::getConnectionMode() == notConnected){
            ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
        }
        else{
            Communication::dac(ui->dac1pp_value->text().toFloat(),
                               ui->dac1shift_value->text().toFloat(),
                               ui->dac1freq_value->text().toFloat(),
                               ui->comboBox_dac1->currentIndex(),
                               0);
            ui->dac1_pushButton->setText("Stop");
            ui->dac1_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
        }
    }
    else if(ui->dac1_pushButton->text() == "Stop"){
        ui->dac1_pushButton->setText("Generate");
        ui->dac1_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(3);
    }
}

void MainWindow::on_dac2_pushButton_clicked()
{
    if(ui->dac2_pushButton->text() == "Generate"){
        if (Communication::getConnectionMode() == notConnected){
            ui->statusBar->showMessage("Connect to Usb or Wifi first" , 2000);
        }
        else{
            Communication::dac(ui->dac2pp_value->text().toFloat(),
                               ui->dac2shift_value->text().toFloat(),
                               ui->dac2freq_value->text().toFloat(),
                               ui->comboBox_dac2->currentIndex(),
                               1);
            ui->dac2_pushButton->setText("Stop");
            ui->dac2_pushButton->setStyleSheet("background-color: rgb(255, 8, 94);");
        }
    }
    else if(ui->dac2_pushButton->text() == "Stop"){
        ui->dac2_pushButton->setText("Generate");
        ui->dac2_pushButton->setStyleSheet("background-color: rgb(0, 212, 35);");
        Communication::stop(4);
    }
}


/////////////
///
/// showing functions
///
/////////////

void MainWindow::showingAnalog(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4){
    QVector<double> time[4];

    if(Communication::getConnectionMode() == wifi){
        for(int i=0 ; i<channel1.length() ;i++){
            time[0].append(analogLastGraphTime + i*0.1/double(channel1.length()));
        }
        for(int i=0 ; i<channel2.length() ;i++){
            time[1].append(analogLastGraphTime + i*0.1/double(channel2.length()));
        }
        for(int i=0 ; i<channel3.length() ;i++){
            time[2].append(analogLastGraphTime + i*0.1/double(channel3.length()));
        }
        for(int i=0 ; i<channel4.length() ;i++){
            time[3].append(analogLastGraphTime + i*0.1/double(channel4.length()));
        }
        analogLastGraphTime +=0.1;
    }
    else if(Communication::getConnectionMode() == usb){
        for(int i=0 ; i<channel1.length() ;i++){
            time[0].append(analogLastGraphTime + i*0.01/double(channel1.length()));
        }
        for(int i=0 ; i<channel2.length() ;i++){
            time[1].append(analogLastGraphTime + i*0.01/double(channel2.length()));
        }
        for(int i=0 ; i<channel3.length() ;i++){
            time[2].append(analogLastGraphTime + i*0.01/double(channel3.length()));
        }
        for(int i=0 ; i<channel4.length() ;i++){
            time[3].append(analogLastGraphTime + i*0.01/double(channel4.length()));
        }
        analogLastGraphTime +=0.01;
    }

    analogGraphUpdate(channel1,channel2,channel3,channel4,time[0],time[1],time[2],time[3]);
}

void MainWindow::showingDigital(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4){
    digitalDataPlot[0].append(channel1);
    digitalDataPlot[1].append(channel2);
    digitalDataPlot[2].append(channel3);
    digitalDataPlot[3].append(channel4);

    if(Communication::getConnectionMode() == wifi){
        for(int i=0 ; i<channel1.length() ;i++){
            if(digitalGraphTime[0].length() == 0)
                digitalGraphTime[0].append(0);
            else
                digitalGraphTime[0].append(digitalGraphTime[0].last()+0.1/double(channel1.length()));
        }
        for(int i=0 ; i<channel2.length() ;i++){
            if(digitalGraphTime[1].length() == 0)
                digitalGraphTime[1].append(0);
            else
                digitalGraphTime[1].append(digitalGraphTime[1].last()+0.1/double(channel2.length()));
        }
        for(int i=0 ; i<channel3.length() ;i++){
            if(digitalGraphTime[2].length() == 0)
                digitalGraphTime[2].append(0);
            else
                digitalGraphTime[2].append(digitalGraphTime[2].last()+0.1/double(channel3.length()));
        }
        for(int i=0 ; i<channel4.length() ;i++){
            if(digitalGraphTime[3].length() == 0)
                digitalGraphTime[3].append(0);
            else
                digitalGraphTime[3].append(digitalGraphTime[3].last()+0.1/double(channel4.length()));
        }
    }
    else if(Communication::getConnectionMode() == usb){
        for(int i=0 ; i<channel1.length() ;i++){
            if(digitalGraphTime[0].length() == 0)
                digitalGraphTime[0].append(0);
            else
                digitalGraphTime[0].append(digitalGraphTime[0].last()+0.01/double(channel1.length()));
        }
        for(int i=0 ; i<channel2.length() ;i++){
            if(digitalGraphTime[1].length() == 0)
                digitalGraphTime[1].append(0);
            else
                digitalGraphTime[1].append(digitalGraphTime[1].last()+0.01/double(channel2.length()));
        }
        for(int i=0 ; i<channel3.length() ;i++){
            if(digitalGraphTime[2].length() == 0)
                digitalGraphTime[2].append(0);
            else
                digitalGraphTime[2].append(digitalGraphTime[2].last()+0.01/double(channel3.length()));
        }
        for(int i=0 ; i<channel4.length() ;i++){
            if(digitalGraphTime[3].length() == 0)
                digitalGraphTime[3].append(0);
            else
                digitalGraphTime[3].append(digitalGraphTime[3].last()+0.01/double(channel4.length()));
        }
    }

    digitalGraphUpdate(channel1,channel2,channel3,channel4);
    //std::cout << "here in\n";
}

void MainWindow::showingConnection(uint16_t isConnected){
    std::cout << "I'm here : " << isConnected << "\n";
    ui->connection_state->setText(QString::number(isConnected));
}

void MainWindow::showingResistor(uint16_t resValue){
    std::cout << "I'm here : " << resValue << "\n";
    ui->res_value->setText(QString::number(resValue));
}

void MainWindow::showingCapacitor(uint16_t capValue){
    std::cout << "I'm here : " << capValue << "\n";
    ui->cap_value->setText(QString::number(capValue));
}

void MainWindow::showingDiode(uint16_t diodeValue){
    std::cout << "I'm here : " << diodeValue << "\n";
    ui->diode_value->setText(QString::number(diodeValue));
}

void MainWindow::showingCurrent(uint16_t currentValue){
    std::cout << "I'm here : " << currentValue << "\n";
    ui->current_value->setText(QString::number(currentValue));
}

/////////////
///
/// graph functions
///
/////////////

void MainWindow::graphInit(){
    ui->analogPlot->addGraph();
    ui->analogPlot->addGraph();
    ui->analogPlot->addGraph();
    ui->analogPlot->addGraph();
    ui->digitalPlot->addGraph();
    ui->digitalPlot->addGraph();
    ui->digitalPlot->addGraph();
    ui->digitalPlot->addGraph();

    QPen pen1,pen2,pen3,pen4;
    pen1.setWidth(1);
    pen1.setColor(QColor(255,0,0));
    pen2.setWidth(1);
    pen2.setColor(QColor(100,80,255));
    pen3.setWidth(1);
    pen3.setColor(QColor(85,170,0));
    pen4.setWidth(1);
    pen4.setColor(QColor(0,0,0));

    ui->analogPlot->graph(0)->setPen(pen1);
    ui->digitalPlot->graph(0)->setPen(pen1);
    ui->analogPlot->graph(1)->setPen(pen2);
    ui->digitalPlot->graph(1)->setPen(pen2);
    ui->analogPlot->graph(2)->setPen(pen3);
    ui->digitalPlot->graph(2)->setPen(pen3);
    ui->analogPlot->graph(3)->setPen(pen4);
    ui->digitalPlot->graph(3)->setPen(pen4);

    ui->analogPlot->xAxis->setLabel("Time(second)");
    ui->digitalPlot->xAxis->setLabel("Time(second)");

    ui->analogPlot->setInteraction(QCP::iRangeZoom , true);
    ui->analogPlot->setInteraction(QCP::iRangeDrag , true);
    ui->digitalPlot->setInteraction(QCP::iRangeZoom , true);
    ui->digitalPlot->setInteraction(QCP::iRangeDrag , true);

}

void MainWindow::analogGraphUpdate(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4,
                                   QVector<double> time1,QVector<double> time2,QVector<double> time3,QVector<double> time4){
    //ui->analogPlot->graph(0)->setData(analogGraphTime[0] , analogDataPlot[0]);
    //std::cout << "back : " << time1.back() << "\n";
    ui->analogPlot->graph(0)->addData(time1 , channel1 , true);
    ui->analogPlot->graph(1)->addData(time2 , channel2 , true);
    ui->analogPlot->graph(2)->addData(time3 , channel3 , true);
    ui->analogPlot->graph(3)->addData(time4 , channel4 , true);
//    ui->analogPlot->rescaleAxes(true);
//    if(analogGraphTime[0].last() > 2){
//         ui->analogPlot->xAxis->setRange(analogGraphTime[0].last()-2,analogGraphTime[0].last());
//    }
//    else{
//        ui->analogPlot->xAxis->setRange(0,2);
//    }
//    ui->analogPlot->replot();

}

void MainWindow::digitalGraphUpdate(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4){

    ui->digitalPlot->graph(0)->setData(digitalGraphTime[0] , digitalDataPlot[0]);
    ui->digitalPlot->graph(1)->setData(digitalGraphTime[1] , digitalDataPlot[1]);
    ui->digitalPlot->graph(2)->setData(digitalGraphTime[2] , digitalDataPlot[2]);
    ui->digitalPlot->graph(3)->setData(digitalGraphTime[3] , digitalDataPlot[3]);
    ui->digitalPlot->rescaleAxes(true);
    if(digitalGraphTime[0].last() > 2){
         ui->digitalPlot->xAxis->setRange(digitalGraphTime[0].last()-2,digitalGraphTime[0].last());
    }
    else{
        ui->digitalPlot->xAxis->setRange(0,2);
    }
    ui->digitalPlot->replot();
}

void MainWindow::analogGraphClear()
{
//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();

//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();


//    ui->plot1->graph(0)->setData(GraphData::graphTime , GraphData::plot1Y[0]);
//    ui->plot1->graph(1)->setData(GraphData::graphTime , GraphData::plot1Y[1]);
//    ui->plot1->graph(2)->setData(GraphData::graphTime , GraphData::plot1Y[2]);
//    ui->plot1->graph(3)->setData(GraphData::graphTime , GraphData::plot1Y[3]);
//    ui->plot1->graph(4)->setData(GraphData::graphTime , GraphData::plot1Y[4]);
//    ui->plot1->rescaleAxes(true);
//    ui->plot1->xAxis->setRange(0,2);
//    ui->plot1->replot();
//    ui->plot2->graph(0)->setData(GraphData::graphTime , GraphData::plot2Y[0]);
//    ui->plot2->graph(1)->setData(GraphData::graphTime , GraphData::plot2Y[1]);
//    ui->plot2->graph(2)->setData(GraphData::graphTime , GraphData::plot2Y[2]);
//    ui->plot2->graph(3)->setData(GraphData::graphTime , GraphData::plot2Y[3]);
//    ui->plot2->rescaleAxes(true);
//    ui->plot2->xAxis->setRange(0,2);
//    ui->plot2->replot();
}

void MainWindow::digitalGraphClear()
{
//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();

//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();


//    ui->plot1->graph(0)->setData(GraphData::graphTime , GraphData::plot1Y[0]);
//    ui->plot1->graph(1)->setData(GraphData::graphTime , GraphData::plot1Y[1]);
//    ui->plot1->graph(2)->setData(GraphData::graphTime , GraphData::plot1Y[2]);
//    ui->plot1->graph(3)->setData(GraphData::graphTime , GraphData::plot1Y[3]);
//    ui->plot1->graph(4)->setData(GraphData::graphTime , GraphData::plot1Y[4]);
//    ui->plot1->rescaleAxes(true);
//    ui->plot1->xAxis->setRange(0,2);
//    ui->plot1->replot();
//    ui->plot2->graph(0)->setData(GraphData::graphTime , GraphData::plot2Y[0]);
//    ui->plot2->graph(1)->setData(GraphData::graphTime , GraphData::plot2Y[1]);
//    ui->plot2->graph(2)->setData(GraphData::graphTime , GraphData::plot2Y[2]);
//    ui->plot2->graph(3)->setData(GraphData::graphTime , GraphData::plot2Y[3]);
//    ui->plot2->rescaleAxes(true);
//    ui->plot2->xAxis->setRange(0,2);
//    ui->plot2->replot();
}

void MainWindow::analogGraphSave()
{
//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();

//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();


//    ui->plot1->graph(0)->setData(GraphData::graphTime , GraphData::plot1Y[0]);
//    ui->plot1->graph(1)->setData(GraphData::graphTime , GraphData::plot1Y[1]);
//    ui->plot1->graph(2)->setData(GraphData::graphTime , GraphData::plot1Y[2]);
//    ui->plot1->graph(3)->setData(GraphData::graphTime , GraphData::plot1Y[3]);
//    ui->plot1->graph(4)->setData(GraphData::graphTime , GraphData::plot1Y[4]);
//    ui->plot1->rescaleAxes(true);
//    ui->plot1->xAxis->setRange(0,2);
//    ui->plot1->replot();
//    ui->plot2->graph(0)->setData(GraphData::graphTime , GraphData::plot2Y[0]);
//    ui->plot2->graph(1)->setData(GraphData::graphTime , GraphData::plot2Y[1]);
//    ui->plot2->graph(2)->setData(GraphData::graphTime , GraphData::plot2Y[2]);
//    ui->plot2->graph(3)->setData(GraphData::graphTime , GraphData::plot2Y[3]);
//    ui->plot2->rescaleAxes(true);
//    ui->plot2->xAxis->setRange(0,2);
//    ui->plot2->replot();
}

void MainWindow::digitalGraphSave()
{
//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();

//    for(int i=0 ; i<5 ; i++){
//            GraphData::plot1Y[i].clear();
//        if(i != 4){
//                GraphData::plot2Y[i].clear();

//        }
//    }
//    GraphData::graphTime.clear();


//    ui->plot1->graph(0)->setData(GraphData::graphTime , GraphData::plot1Y[0]);
//    ui->plot1->graph(1)->setData(GraphData::graphTime , GraphData::plot1Y[1]);
//    ui->plot1->graph(2)->setData(GraphData::graphTime , GraphData::plot1Y[2]);
//    ui->plot1->graph(3)->setData(GraphData::graphTime , GraphData::plot1Y[3]);
//    ui->plot1->graph(4)->setData(GraphData::graphTime , GraphData::plot1Y[4]);
//    ui->plot1->rescaleAxes(true);
//    ui->plot1->xAxis->setRange(0,2);
//    ui->plot1->replot();
//    ui->plot2->graph(0)->setData(GraphData::graphTime , GraphData::plot2Y[0]);
//    ui->plot2->graph(1)->setData(GraphData::graphTime , GraphData::plot2Y[1]);
//    ui->plot2->graph(2)->setData(GraphData::graphTime , GraphData::plot2Y[2]);
//    ui->plot2->graph(3)->setData(GraphData::graphTime , GraphData::plot2Y[3]);
//    ui->plot2->rescaleAxes(true);
//    ui->plot2->xAxis->setRange(0,2);
//    ui->plot2->replot();
}

void MainWindow::updateGraphCallBack(){
    if (Communication::getDataMode() == analog){
        std::cout << "here";
        if(analogLastGraphTime > 2)
            ui->analogPlot->xAxis->setRange(analogLastGraphTime-2,analogLastGraphTime);
        else
            ui->analogPlot->xAxis->setRange(0,2);

        ui->analogPlot->replot(QCustomPlot::rpQueuedRefresh);

    }
    else if (Communication::getDataMode() == digital){

    }
}
