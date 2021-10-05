#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qrunnable.h"
#include "qthreadpool.h"
#include "QVector"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_usb_connect_pushButton_clicked();

    void on_usb_disconnect_pushButton_clicked();

    void on_wifi_connect_pushButton_clicked();

    void on_wifi_disconnect_pushButton_clicked();

    void on_connection_check_pushButton_clicked();

    void on_diode_check_pushButton_clicked();

    void on_resistor_measure_pushButton_clicked();

    void on_capacitor_measure_pushButton_clicked();

    void on_current_measure_pushButton_clicked();

    void on_voltageout1_pushButton_clicked();

    void on_voltageout2_pushButton_clicked();

    void on_dac1_pushButton_clicked();

    void on_dac2_pushButton_clicked();

    void on_analog_start_pushButton_clicked();

    void on_analog_clear_pushButton_clicked();

    void on_analog_cursor_pushButton_clicked();

    void on_analog_save_pushButton_clicked();

    void on_digital_start_pushButton_clicked();

    void on_digital_clear_pushButton_clicked();

    void on_digital_cursor_pushButton_clicked();

    void on_digital_save_pushButton_clicked();

    void showingAnalog(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4);

    void showingDigital(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4);

    void showingConnection(uint16_t isConnected);

    void showingResistor(uint16_t resValue);

    void showingCapacitor(uint16_t capValue);

    void showingDiode(uint16_t diodeValue);

    void showingCurrent(uint16_t currentValue);

    void on_analog_channel1_checkBox_clicked(bool checked);

    void on_analog_channel2_checkBox_clicked(bool checked);

    void on_analog_channel3_checkBox_clicked(bool checked);

    void on_analog_channel4_checkBox_clicked(bool checked);

    void on_digital_channel1_checkBox_clicked(bool checked);

    void on_digital_channel2_checkBox_clicked(bool checked);

    void on_digital_channel3_checkBox_clicked(bool checked);

    void on_digital_channel4_checkBox_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    void graphInit();
    void analogGraphUpdate(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4,
                           QVector<double> time1,QVector<double> time2,QVector<double> time3,QVector<double> time4);
    void digitalGraphUpdate(QVector<double> channel1,QVector<double> channel2,QVector<double> channel3,QVector<double> channel4);
    void analogGraphSave();
    void digitalGraphSave();
    void analogGraphClear();
    void digitalGraphClear();
    void graphAddTimeData();
    void updateGraphCallBack();
    QVector<double> digitalDataPlot[4];
    double analogLastGraphTime = 0;
    QVector<double> digitalGraphTime[4];

};

#endif // MAINWINDOW_H
