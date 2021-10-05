/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *measure;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout;
    QLabel *usb_label;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label;
    QLabel *usb_status;
    QHBoxLayout *horizontalLayout_15;
    QPushButton *usb_connect_pushButton;
    QPushButton *usb_disconnect_pushButton;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QLabel *wifi_status;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *wifi_connect_pushButton;
    QPushButton *wifi_disconnect_pushButton;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *resistor_measure_pushButton;
    QLabel *res_value;
    QComboBox *comboBox_Res;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *capacitor_measure_pushButton;
    QLabel *cap_value;
    QComboBox *comboBox_Cap;
    QHBoxLayout *horizontalLayout_8;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *diode_check_pushButton;
    QLabel *diode_value;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *connection_check_pushButton;
    QLabel *connection_state;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *current_measure_pushButton;
    QLabel *current_value;
    QWidget *analog;
    QHBoxLayout *horizontalLayout_25;
    QVBoxLayout *verticalLayout_28;
    QCustomPlot *analogPlot;
    QScrollBar *analog_scrollBar;
    QHBoxLayout *horizontalLayout_21;
    QCheckBox *analog_channel1_checkBox;
    QCheckBox *analog_channel2_checkBox;
    QCheckBox *analog_channel3_checkBox;
    QCheckBox *analog_channel4_checkBox;
    QHBoxLayout *horizontalLayout_24;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_38;
    QLabel *label_30;
    QLabel *label_21;
    QLabel *label_25;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *freq_channel1_value_analog;
    QLineEdit *factor_channel1_value;
    QLineEdit *shift_channel1_value;
    QComboBox *comboBox_math1;
    QVBoxLayout *verticalLayout_22;
    QLabel *label_39;
    QLabel *label_35;
    QLabel *label_22;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_23;
    QLineEdit *freq_channel2_value_analog;
    QLineEdit *factor_channel2_value;
    QLineEdit *shift_channel2_value;
    QComboBox *comboBox_math2;
    QVBoxLayout *verticalLayout_24;
    QLabel *label_40;
    QLabel *label_36;
    QLabel *label_23;
    QLabel *label_27;
    QVBoxLayout *verticalLayout_25;
    QLineEdit *freq_channel3_value_analog;
    QLineEdit *factor_channel3_value;
    QLineEdit *shift_channel3_value;
    QComboBox *comboBox_math3;
    QVBoxLayout *verticalLayout_26;
    QLabel *label_41;
    QLabel *label_37;
    QLabel *label_24;
    QLabel *label_28;
    QVBoxLayout *verticalLayout_27;
    QLineEdit *freq_channel4_value_analog;
    QLineEdit *factor_channel4_value;
    QLineEdit *shift_channel4_value;
    QComboBox *comboBox_math4;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *analog_start_pushButton;
    QPushButton *analog_clear_pushButton;
    QPushButton *analog_cursor_pushButton;
    QPushButton *analog_save_pushButton;
    QLineEdit *analog_save_value;
    QWidget *digital;
    QHBoxLayout *horizontalLayout_39;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *digitalPlot;
    QScrollBar *digital_scrollBar;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *digital_channel1_checkBox;
    QCheckBox *digital_channel2_checkBox;
    QCheckBox *digital_channel3_checkBox;
    QCheckBox *digital_channel4_checkBox;
    QHBoxLayout *horizontalLayout_38;
    QLabel *label_42;
    QLineEdit *freq_channel1_value_digital;
    QLabel *label_43;
    QLineEdit *freq_channel2_value_digital;
    QLabel *label_44;
    QLineEdit *freq_channel3_value_digital;
    QLabel *label_45;
    QLineEdit *freq_channel4_value_digital;
    QHBoxLayout *horizontalLayout_27;
    QPushButton *digital_start_pushButton;
    QPushButton *digital_clear_pushButton;
    QPushButton *digital_cursor_pushButton;
    QPushButton *digital_save_pushButton;
    QLineEdit *digital_save_value;
    QWidget *waveout;
    QVBoxLayout *verticalLayout_19;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_29;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_13;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_13;
    QLineEdit *voltageout1_value;
    QPushButton *voltageout1_pushButton;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_23;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_28;
    QLabel *label_16;
    QLineEdit *voltageout2_value;
    QPushButton *voltageout2_pushButton;
    QHBoxLayout *horizontalLayout_37;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_17;
    QHBoxLayout *horizontalLayout_30;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_29;
    QVBoxLayout *verticalLayout_17;
    QLineEdit *dac1pp_value;
    QLineEdit *dac1shift_value;
    QLineEdit *dac1freq_value;
    QComboBox *comboBox_dac1;
    QPushButton *dac1_pushButton;
    QFrame *frame_11;
    QHBoxLayout *horizontalLayout_35;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout_34;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QVBoxLayout *verticalLayout_16;
    QLineEdit *dac2pp_value;
    QLineEdit *dac2shift_value;
    QLineEdit *dac2freq_value;
    QComboBox *comboBox_dac2;
    QPushButton *dac2_pushButton;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1081, 599);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        MainWindow->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/resources/pictures/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setWindowOpacity(1);
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(172, 255, 235);"));
        MainWindow->setIconSize(QSize(20, 20));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(50);
        sizePolicy1.setVerticalStretch(50);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(12);
        tabWidget->setFont(font1);
        tabWidget->setStyleSheet(QStringLiteral(""));
        measure = new QWidget();
        measure->setObjectName(QStringLiteral("measure"));
        verticalLayout_10 = new QVBoxLayout(measure);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        frame = new QFrame(measure);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_16 = new QHBoxLayout(frame);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        usb_label = new QLabel(frame);
        usb_label->setObjectName(QStringLiteral("usb_label"));
        usb_label->setFont(font1);

        verticalLayout->addWidget(usb_label);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);

        horizontalLayout_14->addWidget(label);

        usb_status = new QLabel(frame);
        usb_status->setObjectName(QStringLiteral("usb_status"));
        usb_status->setFont(font1);
        usb_status->setStyleSheet(QStringLiteral("background-color: rgb(77, 170, 16);"));

        horizontalLayout_14->addWidget(usb_status);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        usb_connect_pushButton = new QPushButton(frame);
        usb_connect_pushButton->setObjectName(QStringLiteral("usb_connect_pushButton"));
        QFont font2;
        font2.setPointSize(15);
        usb_connect_pushButton->setFont(font2);
        usb_connect_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_15->addWidget(usb_connect_pushButton);

        usb_disconnect_pushButton = new QPushButton(frame);
        usb_disconnect_pushButton->setObjectName(QStringLiteral("usb_disconnect_pushButton"));
        usb_disconnect_pushButton->setFont(font2);
        usb_disconnect_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_15->addWidget(usb_disconnect_pushButton);


        verticalLayout->addLayout(horizontalLayout_15);


        horizontalLayout_16->addLayout(verticalLayout);


        horizontalLayout_5->addWidget(frame);

        frame_2 = new QFrame(measure);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_19 = new QHBoxLayout(frame_2);
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        verticalLayout_2->addWidget(label_2);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_18 = new QLabel(frame_2);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font1);

        horizontalLayout_17->addWidget(label_18);

        wifi_status = new QLabel(frame_2);
        wifi_status->setObjectName(QStringLiteral("wifi_status"));
        wifi_status->setFont(font1);
        wifi_status->setStyleSheet(QStringLiteral("background-color: rgb(255, 73, 76);"));

        horizontalLayout_17->addWidget(wifi_status);


        verticalLayout_2->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        wifi_connect_pushButton = new QPushButton(frame_2);
        wifi_connect_pushButton->setObjectName(QStringLiteral("wifi_connect_pushButton"));
        wifi_connect_pushButton->setFont(font2);
        wifi_connect_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_18->addWidget(wifi_connect_pushButton);

        wifi_disconnect_pushButton = new QPushButton(frame_2);
        wifi_disconnect_pushButton->setObjectName(QStringLiteral("wifi_disconnect_pushButton"));
        wifi_disconnect_pushButton->setFont(font2);
        wifi_disconnect_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_18->addWidget(wifi_disconnect_pushButton);


        verticalLayout_2->addLayout(horizontalLayout_18);


        horizontalLayout_19->addLayout(verticalLayout_2);


        horizontalLayout_5->addWidget(frame_2);


        verticalLayout_10->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame_3 = new QFrame(measure);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_3);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);
        label_5->setAutoFillBackground(false);

        verticalLayout_3->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        resistor_measure_pushButton = new QPushButton(frame_3);
        resistor_measure_pushButton->setObjectName(QStringLiteral("resistor_measure_pushButton"));
        resistor_measure_pushButton->setFont(font2);
        resistor_measure_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_3->addWidget(resistor_measure_pushButton);

        res_value = new QLabel(frame_3);
        res_value->setObjectName(QStringLiteral("res_value"));
        res_value->setFont(font2);
        res_value->setFrameShape(QFrame::Box);

        horizontalLayout_3->addWidget(res_value);


        verticalLayout_3->addLayout(horizontalLayout_3);

        comboBox_Res = new QComboBox(frame_3);
        comboBox_Res->setObjectName(QStringLiteral("comboBox_Res"));
        comboBox_Res->setFont(font);

        verticalLayout_3->addWidget(comboBox_Res);


        horizontalLayout_11->addLayout(verticalLayout_3);


        horizontalLayout_7->addWidget(frame_3);

        frame_4 = new QFrame(measure);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::Box);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_4);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        verticalLayout_4->addWidget(label_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        capacitor_measure_pushButton = new QPushButton(frame_4);
        capacitor_measure_pushButton->setObjectName(QStringLiteral("capacitor_measure_pushButton"));
        capacitor_measure_pushButton->setFont(font2);
        capacitor_measure_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_4->addWidget(capacitor_measure_pushButton);

        cap_value = new QLabel(frame_4);
        cap_value->setObjectName(QStringLiteral("cap_value"));
        cap_value->setFont(font2);
        cap_value->setFrameShape(QFrame::Box);

        horizontalLayout_4->addWidget(cap_value);


        verticalLayout_4->addLayout(horizontalLayout_4);

        comboBox_Cap = new QComboBox(frame_4);
        comboBox_Cap->setObjectName(QStringLiteral("comboBox_Cap"));
        comboBox_Cap->setFont(font);

        verticalLayout_4->addWidget(comboBox_Cap);


        horizontalLayout_12->addLayout(verticalLayout_4);


        horizontalLayout_7->addWidget(frame_4);


        verticalLayout_10->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        frame_5 = new QFrame(measure);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFont(font1);
        frame_5->setFrameShape(QFrame::Box);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(frame_5);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_8 = new QLabel(frame_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font1);
        label_8->setStyleSheet(QStringLiteral(""));

        verticalLayout_8->addWidget(label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        diode_check_pushButton = new QPushButton(frame_5);
        diode_check_pushButton->setObjectName(QStringLiteral("diode_check_pushButton"));
        diode_check_pushButton->setFont(font2);
        diode_check_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_2->addWidget(diode_check_pushButton);

        diode_value = new QLabel(frame_5);
        diode_value->setObjectName(QStringLiteral("diode_value"));
        diode_value->setFont(font2);
        diode_value->setFrameShape(QFrame::Box);

        horizontalLayout_2->addWidget(diode_value);


        verticalLayout_8->addLayout(horizontalLayout_2);


        horizontalLayout_8->addWidget(frame_5);

        frame_6 = new QFrame(measure);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        frame_6->setFrameShape(QFrame::Box);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_6);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_11 = new QLabel(frame_6);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);
        label_11->setFrameShadow(QFrame::Raised);

        verticalLayout_7->addWidget(label_11);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        connection_check_pushButton = new QPushButton(frame_6);
        connection_check_pushButton->setObjectName(QStringLiteral("connection_check_pushButton"));
        connection_check_pushButton->setFont(font2);
        connection_check_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));
        connection_check_pushButton->setIconSize(QSize(20, 20));

        horizontalLayout_32->addWidget(connection_check_pushButton);

        connection_state = new QLabel(frame_6);
        connection_state->setObjectName(QStringLiteral("connection_state"));
        connection_state->setFont(font2);
        connection_state->setFrameShape(QFrame::Box);

        horizontalLayout_32->addWidget(connection_state);


        verticalLayout_7->addLayout(horizontalLayout_32);


        horizontalLayout_8->addWidget(frame_6);


        verticalLayout_10->addLayout(horizontalLayout_8);

        frame_7 = new QFrame(measure);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setStyleSheet(QStringLiteral(""));
        frame_7->setFrameShape(QFrame::Box);
        frame_7->setFrameShadow(QFrame::Raised);
        frame_7->setLineWidth(1);
        frame_7->setMidLineWidth(0);
        verticalLayout_9 = new QVBoxLayout(frame_7);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_9 = new QLabel(frame_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setStyleSheet(QStringLiteral(""));
        label_9->setFrameShape(QFrame::NoFrame);

        horizontalLayout_9->addWidget(label_9);


        verticalLayout_9->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        current_measure_pushButton = new QPushButton(frame_7);
        current_measure_pushButton->setObjectName(QStringLiteral("current_measure_pushButton"));
        current_measure_pushButton->setFont(font2);
        current_measure_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_6->addWidget(current_measure_pushButton);

        current_value = new QLabel(frame_7);
        current_value->setObjectName(QStringLiteral("current_value"));
        current_value->setFont(font2);
        current_value->setFrameShape(QFrame::Box);

        horizontalLayout_6->addWidget(current_value);


        verticalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_10->addWidget(frame_7);

        tabWidget->addTab(measure, QString());
        analog = new QWidget();
        analog->setObjectName(QStringLiteral("analog"));
        horizontalLayout_25 = new QHBoxLayout(analog);
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        verticalLayout_28 = new QVBoxLayout();
        verticalLayout_28->setSpacing(6);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        analogPlot = new QCustomPlot(analog);
        analogPlot->setObjectName(QStringLiteral("analogPlot"));

        verticalLayout_28->addWidget(analogPlot);

        analog_scrollBar = new QScrollBar(analog);
        analog_scrollBar->setObjectName(QStringLiteral("analog_scrollBar"));
        analog_scrollBar->setOrientation(Qt::Horizontal);

        verticalLayout_28->addWidget(analog_scrollBar);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        analog_channel1_checkBox = new QCheckBox(analog);
        analog_channel1_checkBox->setObjectName(QStringLiteral("analog_channel1_checkBox"));
        QFont font3;
        font3.setPointSize(14);
        analog_channel1_checkBox->setFont(font3);
        analog_channel1_checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        analog_channel1_checkBox->setChecked(true);

        horizontalLayout_21->addWidget(analog_channel1_checkBox);

        analog_channel2_checkBox = new QCheckBox(analog);
        analog_channel2_checkBox->setObjectName(QStringLiteral("analog_channel2_checkBox"));
        analog_channel2_checkBox->setFont(font3);
        analog_channel2_checkBox->setStyleSheet(QStringLiteral("color: rgb(100, 80, 255);"));
        analog_channel2_checkBox->setChecked(true);

        horizontalLayout_21->addWidget(analog_channel2_checkBox);

        analog_channel3_checkBox = new QCheckBox(analog);
        analog_channel3_checkBox->setObjectName(QStringLiteral("analog_channel3_checkBox"));
        analog_channel3_checkBox->setFont(font3);
        analog_channel3_checkBox->setStyleSheet(QStringLiteral("color: rgb(85, 170, 0);"));
        analog_channel3_checkBox->setChecked(true);

        horizontalLayout_21->addWidget(analog_channel3_checkBox);

        analog_channel4_checkBox = new QCheckBox(analog);
        analog_channel4_checkBox->setObjectName(QStringLiteral("analog_channel4_checkBox"));
        analog_channel4_checkBox->setFont(font3);
        analog_channel4_checkBox->setStyleSheet(QStringLiteral("color: rgb(0, 0, 0);"));
        analog_channel4_checkBox->setChecked(true);

        horizontalLayout_21->addWidget(analog_channel4_checkBox);


        verticalLayout_28->addLayout(horizontalLayout_21);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_38 = new QLabel(analog);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setFont(font);
        label_38->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(label_38);

        label_30 = new QLabel(analog);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setFont(font);
        label_30->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(label_30);

        label_21 = new QLabel(analog);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);
        label_21->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(label_21);

        label_25 = new QLabel(analog);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setFont(font);
        label_25->setFrameShape(QFrame::Box);

        verticalLayout_5->addWidget(label_25);


        horizontalLayout_24->addLayout(verticalLayout_5);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        freq_channel1_value_analog = new QLineEdit(analog);
        freq_channel1_value_analog->setObjectName(QStringLiteral("freq_channel1_value_analog"));
        freq_channel1_value_analog->setFont(font);

        verticalLayout_11->addWidget(freq_channel1_value_analog);

        factor_channel1_value = new QLineEdit(analog);
        factor_channel1_value->setObjectName(QStringLiteral("factor_channel1_value"));
        factor_channel1_value->setFont(font);

        verticalLayout_11->addWidget(factor_channel1_value);

        shift_channel1_value = new QLineEdit(analog);
        shift_channel1_value->setObjectName(QStringLiteral("shift_channel1_value"));
        shift_channel1_value->setFont(font);

        verticalLayout_11->addWidget(shift_channel1_value);

        comboBox_math1 = new QComboBox(analog);
        comboBox_math1->setObjectName(QStringLiteral("comboBox_math1"));
        comboBox_math1->setFont(font);

        verticalLayout_11->addWidget(comboBox_math1);


        horizontalLayout_24->addLayout(verticalLayout_11);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setSpacing(6);
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        label_39 = new QLabel(analog);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setFont(font);
        label_39->setFrameShape(QFrame::Box);

        verticalLayout_22->addWidget(label_39);

        label_35 = new QLabel(analog);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setFont(font);
        label_35->setFrameShape(QFrame::Box);

        verticalLayout_22->addWidget(label_35);

        label_22 = new QLabel(analog);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setFont(font);
        label_22->setFrameShape(QFrame::Box);

        verticalLayout_22->addWidget(label_22);

        label_26 = new QLabel(analog);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setFont(font);
        label_26->setFrameShape(QFrame::Box);

        verticalLayout_22->addWidget(label_26);


        horizontalLayout_24->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setSpacing(6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        freq_channel2_value_analog = new QLineEdit(analog);
        freq_channel2_value_analog->setObjectName(QStringLiteral("freq_channel2_value_analog"));
        freq_channel2_value_analog->setFont(font);

        verticalLayout_23->addWidget(freq_channel2_value_analog);

        factor_channel2_value = new QLineEdit(analog);
        factor_channel2_value->setObjectName(QStringLiteral("factor_channel2_value"));
        factor_channel2_value->setFont(font);

        verticalLayout_23->addWidget(factor_channel2_value);

        shift_channel2_value = new QLineEdit(analog);
        shift_channel2_value->setObjectName(QStringLiteral("shift_channel2_value"));
        shift_channel2_value->setFont(font);

        verticalLayout_23->addWidget(shift_channel2_value);

        comboBox_math2 = new QComboBox(analog);
        comboBox_math2->setObjectName(QStringLiteral("comboBox_math2"));
        comboBox_math2->setFont(font);

        verticalLayout_23->addWidget(comboBox_math2);


        horizontalLayout_24->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setSpacing(6);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        label_40 = new QLabel(analog);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setFont(font);
        label_40->setFrameShape(QFrame::Box);

        verticalLayout_24->addWidget(label_40);

        label_36 = new QLabel(analog);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setFont(font);
        label_36->setFrameShape(QFrame::Box);

        verticalLayout_24->addWidget(label_36);

        label_23 = new QLabel(analog);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setFont(font);
        label_23->setFrameShape(QFrame::Box);

        verticalLayout_24->addWidget(label_23);

        label_27 = new QLabel(analog);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setFont(font);
        label_27->setFrameShape(QFrame::Box);

        verticalLayout_24->addWidget(label_27);


        horizontalLayout_24->addLayout(verticalLayout_24);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setSpacing(6);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        freq_channel3_value_analog = new QLineEdit(analog);
        freq_channel3_value_analog->setObjectName(QStringLiteral("freq_channel3_value_analog"));
        freq_channel3_value_analog->setFont(font);

        verticalLayout_25->addWidget(freq_channel3_value_analog);

        factor_channel3_value = new QLineEdit(analog);
        factor_channel3_value->setObjectName(QStringLiteral("factor_channel3_value"));
        factor_channel3_value->setFont(font);

        verticalLayout_25->addWidget(factor_channel3_value);

        shift_channel3_value = new QLineEdit(analog);
        shift_channel3_value->setObjectName(QStringLiteral("shift_channel3_value"));
        shift_channel3_value->setFont(font);

        verticalLayout_25->addWidget(shift_channel3_value);

        comboBox_math3 = new QComboBox(analog);
        comboBox_math3->setObjectName(QStringLiteral("comboBox_math3"));
        comboBox_math3->setFont(font);

        verticalLayout_25->addWidget(comboBox_math3);


        horizontalLayout_24->addLayout(verticalLayout_25);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setSpacing(6);
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        label_41 = new QLabel(analog);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setFont(font);
        label_41->setFrameShape(QFrame::Box);

        verticalLayout_26->addWidget(label_41);

        label_37 = new QLabel(analog);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setFont(font);
        label_37->setFrameShape(QFrame::Box);

        verticalLayout_26->addWidget(label_37);

        label_24 = new QLabel(analog);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setFont(font);
        label_24->setFrameShape(QFrame::Box);

        verticalLayout_26->addWidget(label_24);

        label_28 = new QLabel(analog);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);
        label_28->setFrameShape(QFrame::Box);

        verticalLayout_26->addWidget(label_28);


        horizontalLayout_24->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setSpacing(6);
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        freq_channel4_value_analog = new QLineEdit(analog);
        freq_channel4_value_analog->setObjectName(QStringLiteral("freq_channel4_value_analog"));
        freq_channel4_value_analog->setFont(font);

        verticalLayout_27->addWidget(freq_channel4_value_analog);

        factor_channel4_value = new QLineEdit(analog);
        factor_channel4_value->setObjectName(QStringLiteral("factor_channel4_value"));
        factor_channel4_value->setFont(font);

        verticalLayout_27->addWidget(factor_channel4_value);

        shift_channel4_value = new QLineEdit(analog);
        shift_channel4_value->setObjectName(QStringLiteral("shift_channel4_value"));
        shift_channel4_value->setFont(font);

        verticalLayout_27->addWidget(shift_channel4_value);

        comboBox_math4 = new QComboBox(analog);
        comboBox_math4->setObjectName(QStringLiteral("comboBox_math4"));
        comboBox_math4->setFont(font);

        verticalLayout_27->addWidget(comboBox_math4);


        horizontalLayout_24->addLayout(verticalLayout_27);


        verticalLayout_28->addLayout(horizontalLayout_24);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        analog_start_pushButton = new QPushButton(analog);
        analog_start_pushButton->setObjectName(QStringLiteral("analog_start_pushButton"));
        QFont font4;
        font4.setPointSize(16);
        analog_start_pushButton->setFont(font4);
        analog_start_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));
        analog_start_pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_20->addWidget(analog_start_pushButton);

        analog_clear_pushButton = new QPushButton(analog);
        analog_clear_pushButton->setObjectName(QStringLiteral("analog_clear_pushButton"));
        analog_clear_pushButton->setFont(font4);
        analog_clear_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_20->addWidget(analog_clear_pushButton);

        analog_cursor_pushButton = new QPushButton(analog);
        analog_cursor_pushButton->setObjectName(QStringLiteral("analog_cursor_pushButton"));
        analog_cursor_pushButton->setFont(font4);
        analog_cursor_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_20->addWidget(analog_cursor_pushButton);

        analog_save_pushButton = new QPushButton(analog);
        analog_save_pushButton->setObjectName(QStringLiteral("analog_save_pushButton"));
        analog_save_pushButton->setFont(font4);
        analog_save_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));
        analog_save_pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_20->addWidget(analog_save_pushButton);

        analog_save_value = new QLineEdit(analog);
        analog_save_value->setObjectName(QStringLiteral("analog_save_value"));
        analog_save_value->setFont(font);

        horizontalLayout_20->addWidget(analog_save_value);


        verticalLayout_28->addLayout(horizontalLayout_20);


        horizontalLayout_25->addLayout(verticalLayout_28);

        tabWidget->addTab(analog, QString());
        digital = new QWidget();
        digital->setObjectName(QStringLiteral("digital"));
        horizontalLayout_39 = new QHBoxLayout(digital);
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        digitalPlot = new QCustomPlot(digital);
        digitalPlot->setObjectName(QStringLiteral("digitalPlot"));

        verticalLayout_6->addWidget(digitalPlot);

        digital_scrollBar = new QScrollBar(digital);
        digital_scrollBar->setObjectName(QStringLiteral("digital_scrollBar"));
        digital_scrollBar->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(digital_scrollBar);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        digital_channel1_checkBox = new QCheckBox(digital);
        digital_channel1_checkBox->setObjectName(QStringLiteral("digital_channel1_checkBox"));
        digital_channel1_checkBox->setFont(font3);
        digital_channel1_checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        digital_channel1_checkBox->setChecked(true);

        horizontalLayout_22->addWidget(digital_channel1_checkBox);

        digital_channel2_checkBox = new QCheckBox(digital);
        digital_channel2_checkBox->setObjectName(QStringLiteral("digital_channel2_checkBox"));
        digital_channel2_checkBox->setFont(font3);
        digital_channel2_checkBox->setStyleSheet(QStringLiteral("color: rgb(100, 80, 255);"));
        digital_channel2_checkBox->setChecked(true);

        horizontalLayout_22->addWidget(digital_channel2_checkBox);

        digital_channel3_checkBox = new QCheckBox(digital);
        digital_channel3_checkBox->setObjectName(QStringLiteral("digital_channel3_checkBox"));
        digital_channel3_checkBox->setFont(font3);
        digital_channel3_checkBox->setStyleSheet(QStringLiteral("color: rgb(85, 170, 0);"));
        digital_channel3_checkBox->setChecked(true);

        horizontalLayout_22->addWidget(digital_channel3_checkBox);

        digital_channel4_checkBox = new QCheckBox(digital);
        digital_channel4_checkBox->setObjectName(QStringLiteral("digital_channel4_checkBox"));
        digital_channel4_checkBox->setFont(font3);
        digital_channel4_checkBox->setStyleSheet(QLatin1String("color: rgb(0, 0, 0\n"
");"));
        digital_channel4_checkBox->setChecked(true);

        horizontalLayout_22->addWidget(digital_channel4_checkBox);


        verticalLayout_6->addLayout(horizontalLayout_22);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        label_42 = new QLabel(digital);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setFont(font);
        label_42->setFrameShape(QFrame::Box);

        horizontalLayout_38->addWidget(label_42);

        freq_channel1_value_digital = new QLineEdit(digital);
        freq_channel1_value_digital->setObjectName(QStringLiteral("freq_channel1_value_digital"));
        freq_channel1_value_digital->setFont(font);

        horizontalLayout_38->addWidget(freq_channel1_value_digital);

        label_43 = new QLabel(digital);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setFont(font);
        label_43->setFrameShape(QFrame::Box);

        horizontalLayout_38->addWidget(label_43);

        freq_channel2_value_digital = new QLineEdit(digital);
        freq_channel2_value_digital->setObjectName(QStringLiteral("freq_channel2_value_digital"));
        freq_channel2_value_digital->setFont(font);

        horizontalLayout_38->addWidget(freq_channel2_value_digital);

        label_44 = new QLabel(digital);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setFont(font);
        label_44->setFrameShape(QFrame::Box);

        horizontalLayout_38->addWidget(label_44);

        freq_channel3_value_digital = new QLineEdit(digital);
        freq_channel3_value_digital->setObjectName(QStringLiteral("freq_channel3_value_digital"));
        freq_channel3_value_digital->setFont(font);

        horizontalLayout_38->addWidget(freq_channel3_value_digital);

        label_45 = new QLabel(digital);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setFont(font);
        label_45->setFrameShape(QFrame::Box);

        horizontalLayout_38->addWidget(label_45);

        freq_channel4_value_digital = new QLineEdit(digital);
        freq_channel4_value_digital->setObjectName(QStringLiteral("freq_channel4_value_digital"));
        freq_channel4_value_digital->setFont(font);

        horizontalLayout_38->addWidget(freq_channel4_value_digital);


        verticalLayout_6->addLayout(horizontalLayout_38);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        digital_start_pushButton = new QPushButton(digital);
        digital_start_pushButton->setObjectName(QStringLiteral("digital_start_pushButton"));
        digital_start_pushButton->setFont(font4);
        digital_start_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));
        digital_start_pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_27->addWidget(digital_start_pushButton);

        digital_clear_pushButton = new QPushButton(digital);
        digital_clear_pushButton->setObjectName(QStringLiteral("digital_clear_pushButton"));
        digital_clear_pushButton->setFont(font4);
        digital_clear_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_27->addWidget(digital_clear_pushButton);

        digital_cursor_pushButton = new QPushButton(digital);
        digital_cursor_pushButton->setObjectName(QStringLiteral("digital_cursor_pushButton"));
        digital_cursor_pushButton->setFont(font4);
        digital_cursor_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        horizontalLayout_27->addWidget(digital_cursor_pushButton);

        digital_save_pushButton = new QPushButton(digital);
        digital_save_pushButton->setObjectName(QStringLiteral("digital_save_pushButton"));
        digital_save_pushButton->setFont(font4);
        digital_save_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));
        digital_save_pushButton->setIconSize(QSize(50, 50));

        horizontalLayout_27->addWidget(digital_save_pushButton);

        digital_save_value = new QLineEdit(digital);
        digital_save_value->setObjectName(QStringLiteral("digital_save_value"));
        digital_save_value->setFont(font);

        horizontalLayout_27->addWidget(digital_save_value);


        verticalLayout_6->addLayout(horizontalLayout_27);


        horizontalLayout_39->addLayout(verticalLayout_6);

        tabWidget->addTab(digital, QString());
        waveout = new QWidget();
        waveout->setObjectName(QStringLiteral("waveout"));
        verticalLayout_19 = new QVBoxLayout(waveout);
        verticalLayout_19->setSpacing(6);
        verticalLayout_19->setContentsMargins(11, 11, 11, 11);
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setSpacing(6);
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        frame_8 = new QFrame(waveout);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFont(font1);
        frame_8->setFrameShape(QFrame::Box);
        frame_8->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_8);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_12 = new QLabel(frame_8);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral(""));

        verticalLayout_12->addWidget(label_12);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_13 = new QLabel(frame_8);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font2);
        label_13->setFrameShape(QFrame::Box);

        horizontalLayout_10->addWidget(label_13);

        voltageout1_value = new QLineEdit(frame_8);
        voltageout1_value->setObjectName(QStringLiteral("voltageout1_value"));
        voltageout1_value->setFont(font1);

        horizontalLayout_10->addWidget(voltageout1_value);


        verticalLayout_12->addLayout(horizontalLayout_10);

        voltageout1_pushButton = new QPushButton(frame_8);
        voltageout1_pushButton->setObjectName(QStringLiteral("voltageout1_pushButton"));
        voltageout1_pushButton->setFont(font2);
        voltageout1_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        verticalLayout_12->addWidget(voltageout1_pushButton);


        horizontalLayout_13->addLayout(verticalLayout_12);


        horizontalLayout_29->addWidget(frame_8);

        frame_10 = new QFrame(waveout);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setFont(font1);
        frame_10->setFrameShape(QFrame::Box);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_23 = new QHBoxLayout(frame_10);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        label_15 = new QLabel(frame_10);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font1);
        label_15->setStyleSheet(QStringLiteral(""));

        verticalLayout_14->addWidget(label_15);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        label_16 = new QLabel(frame_10);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font2);
        label_16->setFrameShape(QFrame::Box);

        horizontalLayout_28->addWidget(label_16);

        voltageout2_value = new QLineEdit(frame_10);
        voltageout2_value->setObjectName(QStringLiteral("voltageout2_value"));
        voltageout2_value->setFont(font1);

        horizontalLayout_28->addWidget(voltageout2_value);


        verticalLayout_14->addLayout(horizontalLayout_28);

        voltageout2_pushButton = new QPushButton(frame_10);
        voltageout2_pushButton->setObjectName(QStringLiteral("voltageout2_pushButton"));
        voltageout2_pushButton->setFont(font2);
        voltageout2_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        verticalLayout_14->addWidget(voltageout2_pushButton);


        horizontalLayout_23->addLayout(verticalLayout_14);


        horizontalLayout_29->addWidget(frame_10);


        verticalLayout_18->addLayout(horizontalLayout_29);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        frame_9 = new QFrame(waveout);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        frame_9->setFrameShape(QFrame::Box);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_31 = new QHBoxLayout(frame_9);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setSpacing(6);
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_17 = new QLabel(frame_9);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font1);
        label_17->setStyleSheet(QStringLiteral(""));

        verticalLayout_21->addWidget(label_17);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_19 = new QLabel(frame_9);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font2);
        label_19->setFrameShape(QFrame::Box);

        verticalLayout_15->addWidget(label_19);

        label_20 = new QLabel(frame_9);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font2);
        label_20->setFrameShape(QFrame::Box);

        verticalLayout_15->addWidget(label_20);

        label_29 = new QLabel(frame_9);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font2);
        label_29->setFrameShape(QFrame::Box);

        verticalLayout_15->addWidget(label_29);


        horizontalLayout_30->addLayout(verticalLayout_15);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        dac1pp_value = new QLineEdit(frame_9);
        dac1pp_value->setObjectName(QStringLiteral("dac1pp_value"));
        dac1pp_value->setFont(font1);

        verticalLayout_17->addWidget(dac1pp_value);

        dac1shift_value = new QLineEdit(frame_9);
        dac1shift_value->setObjectName(QStringLiteral("dac1shift_value"));
        dac1shift_value->setFont(font1);

        verticalLayout_17->addWidget(dac1shift_value);

        dac1freq_value = new QLineEdit(frame_9);
        dac1freq_value->setObjectName(QStringLiteral("dac1freq_value"));
        dac1freq_value->setFont(font1);

        verticalLayout_17->addWidget(dac1freq_value);


        horizontalLayout_30->addLayout(verticalLayout_17);


        verticalLayout_21->addLayout(horizontalLayout_30);

        comboBox_dac1 = new QComboBox(frame_9);
        comboBox_dac1->setObjectName(QStringLiteral("comboBox_dac1"));
        comboBox_dac1->setFont(font);

        verticalLayout_21->addWidget(comboBox_dac1);

        dac1_pushButton = new QPushButton(frame_9);
        dac1_pushButton->setObjectName(QStringLiteral("dac1_pushButton"));
        dac1_pushButton->setFont(font2);
        dac1_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        verticalLayout_21->addWidget(dac1_pushButton);


        horizontalLayout_31->addLayout(verticalLayout_21);


        horizontalLayout_37->addWidget(frame_9);

        frame_11 = new QFrame(waveout);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setFrameShape(QFrame::Box);
        frame_11->setFrameShadow(QFrame::Raised);
        horizontalLayout_35 = new QHBoxLayout(frame_11);
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setSpacing(6);
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        label_31 = new QLabel(frame_11);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setFont(font1);
        label_31->setStyleSheet(QStringLiteral(""));

        verticalLayout_20->addWidget(label_31);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        label_32 = new QLabel(frame_11);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setFont(font2);
        label_32->setFrameShape(QFrame::Box);

        verticalLayout_13->addWidget(label_32);

        label_33 = new QLabel(frame_11);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setFont(font2);
        label_33->setFrameShape(QFrame::Box);

        verticalLayout_13->addWidget(label_33);

        label_34 = new QLabel(frame_11);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setFont(font2);
        label_34->setFrameShape(QFrame::Box);

        verticalLayout_13->addWidget(label_34);


        horizontalLayout_34->addLayout(verticalLayout_13);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        dac2pp_value = new QLineEdit(frame_11);
        dac2pp_value->setObjectName(QStringLiteral("dac2pp_value"));
        dac2pp_value->setFont(font1);

        verticalLayout_16->addWidget(dac2pp_value);

        dac2shift_value = new QLineEdit(frame_11);
        dac2shift_value->setObjectName(QStringLiteral("dac2shift_value"));
        dac2shift_value->setFont(font1);

        verticalLayout_16->addWidget(dac2shift_value);

        dac2freq_value = new QLineEdit(frame_11);
        dac2freq_value->setObjectName(QStringLiteral("dac2freq_value"));
        dac2freq_value->setFont(font1);

        verticalLayout_16->addWidget(dac2freq_value);


        horizontalLayout_34->addLayout(verticalLayout_16);


        verticalLayout_20->addLayout(horizontalLayout_34);

        comboBox_dac2 = new QComboBox(frame_11);
        comboBox_dac2->setObjectName(QStringLiteral("comboBox_dac2"));
        comboBox_dac2->setFont(font);

        verticalLayout_20->addWidget(comboBox_dac2);

        dac2_pushButton = new QPushButton(frame_11);
        dac2_pushButton->setObjectName(QStringLiteral("dac2_pushButton"));
        dac2_pushButton->setFont(font2);
        dac2_pushButton->setStyleSheet(QStringLiteral("background-color: rgb(0, 212, 35);"));

        verticalLayout_20->addWidget(dac2_pushButton);


        horizontalLayout_35->addLayout(verticalLayout_20);


        horizontalLayout_37->addWidget(frame_11);


        verticalLayout_18->addLayout(horizontalLayout_37);


        verticalLayout_19->addLayout(verticalLayout_18);

        tabWidget->addTab(waveout, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QFont font5;
        font5.setPointSize(18);
        statusBar->setFont(font5);
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(resistor_measure_pushButton, capacitor_measure_pushButton);
        QWidget::setTabOrder(capacitor_measure_pushButton, wifi_connect_pushButton);
        QWidget::setTabOrder(wifi_connect_pushButton, current_measure_pushButton);
        QWidget::setTabOrder(current_measure_pushButton, diode_check_pushButton);
        QWidget::setTabOrder(diode_check_pushButton, connection_check_pushButton);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Oscilostor", nullptr));
        usb_label->setText(QApplication::translate("MainWindow", "usb connection", nullptr));
        label->setText(QApplication::translate("MainWindow", "Status : ", nullptr));
        usb_status->setText(QApplication::translate("MainWindow", "Connected", nullptr));
        usb_connect_pushButton->setText(QApplication::translate("MainWindow", "Connect to usb", nullptr));
        usb_disconnect_pushButton->setText(QApplication::translate("MainWindow", "Disconnect usb", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "wifi connection", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Status : ", nullptr));
        wifi_status->setText(QApplication::translate("MainWindow", "Not Connected", nullptr));
        wifi_connect_pushButton->setText(QApplication::translate("MainWindow", "Connect to wifi", nullptr));
        wifi_disconnect_pushButton->setText(QApplication::translate("MainWindow", "Disconnect wifi", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Resistor Measure", nullptr));
        resistor_measure_pushButton->setText(QApplication::translate("MainWindow", "Measure", nullptr));
        res_value->setText(QApplication::translate("MainWindow", "Value", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Capacitor Measure", nullptr));
        capacitor_measure_pushButton->setText(QApplication::translate("MainWindow", "Measure", nullptr));
        cap_value->setText(QApplication::translate("MainWindow", "Value", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "Diode Check", nullptr));
        diode_check_pushButton->setText(QApplication::translate("MainWindow", "Check", nullptr));
        diode_value->setText(QApplication::translate("MainWindow", "Value", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Connection Check", nullptr));
        connection_check_pushButton->setText(QApplication::translate("MainWindow", "Check", nullptr));
        connection_state->setText(QApplication::translate("MainWindow", "state", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "Current Measure", nullptr));
        current_measure_pushButton->setText(QApplication::translate("MainWindow", "Measure", nullptr));
        current_value->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(measure), QApplication::translate("MainWindow", "Measure", nullptr));
        analog_channel1_checkBox->setText(QApplication::translate("MainWindow", "channel 1", nullptr));
        analog_channel2_checkBox->setText(QApplication::translate("MainWindow", "channel 2", nullptr));
        analog_channel3_checkBox->setText(QApplication::translate("MainWindow", "channel 3", nullptr));
        analog_channel4_checkBox->setText(QApplication::translate("MainWindow", "channel 4", nullptr));
        label_38->setText(QApplication::translate("MainWindow", "freq channel 1", nullptr));
        label_30->setText(QApplication::translate("MainWindow", "factor channel 1", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "shift channel 1", nullptr));
        label_25->setText(QApplication::translate("MainWindow", "math channel 1", nullptr));
        label_39->setText(QApplication::translate("MainWindow", "freq channel 2", nullptr));
        label_35->setText(QApplication::translate("MainWindow", "factor channel 2", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "shift channel 2", nullptr));
        label_26->setText(QApplication::translate("MainWindow", "math channel 2", nullptr));
        label_40->setText(QApplication::translate("MainWindow", "freq channel 3", nullptr));
        label_36->setText(QApplication::translate("MainWindow", "factor channel 3", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "shift channel 3", nullptr));
        label_27->setText(QApplication::translate("MainWindow", "math channel 3", nullptr));
        label_41->setText(QApplication::translate("MainWindow", "freq channel 4", nullptr));
        label_37->setText(QApplication::translate("MainWindow", "factor channel 4", nullptr));
        label_24->setText(QApplication::translate("MainWindow", "shift channel 4", nullptr));
        label_28->setText(QApplication::translate("MainWindow", "math channel 4", nullptr));
        analog_start_pushButton->setText(QApplication::translate("MainWindow", "start", nullptr));
        analog_clear_pushButton->setText(QApplication::translate("MainWindow", "clear", nullptr));
        analog_cursor_pushButton->setText(QApplication::translate("MainWindow", "cursor", nullptr));
        analog_save_pushButton->setText(QApplication::translate("MainWindow", "save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(analog), QApplication::translate("MainWindow", "Analog", nullptr));
        digital_channel1_checkBox->setText(QApplication::translate("MainWindow", "channel 1", nullptr));
        digital_channel2_checkBox->setText(QApplication::translate("MainWindow", "channel 2", nullptr));
        digital_channel3_checkBox->setText(QApplication::translate("MainWindow", "channel 3", nullptr));
        digital_channel4_checkBox->setText(QApplication::translate("MainWindow", "channel 4", nullptr));
        label_42->setText(QApplication::translate("MainWindow", "freq channel 1", nullptr));
        label_43->setText(QApplication::translate("MainWindow", "freq channel 2", nullptr));
        label_44->setText(QApplication::translate("MainWindow", "freq channel 3", nullptr));
        label_45->setText(QApplication::translate("MainWindow", "freq channel 4", nullptr));
        digital_start_pushButton->setText(QApplication::translate("MainWindow", "start", nullptr));
        digital_clear_pushButton->setText(QApplication::translate("MainWindow", "clear", nullptr));
        digital_cursor_pushButton->setText(QApplication::translate("MainWindow", "cursor", nullptr));
        digital_save_pushButton->setText(QApplication::translate("MainWindow", "save", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(digital), QApplication::translate("MainWindow", "Digital", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "DC Voltage Out 1", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "voltage ", nullptr));
        voltageout1_pushButton->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "DC Voltage Out 2", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "voltage ", nullptr));
        voltageout2_pushButton->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "Dac Out 1", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "PP voltage ", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "shift voltage ", nullptr));
        label_29->setText(QApplication::translate("MainWindow", "frequency ", nullptr));
        dac1_pushButton->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        label_31->setText(QApplication::translate("MainWindow", "Dac Out 2", nullptr));
        label_32->setText(QApplication::translate("MainWindow", "PP voltage ", nullptr));
        label_33->setText(QApplication::translate("MainWindow", "shift voltage ", nullptr));
        label_34->setText(QApplication::translate("MainWindow", "frequency ", nullptr));
        dac2_pushButton->setText(QApplication::translate("MainWindow", "Generate", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(waveout), QApplication::translate("MainWindow", "Wave Out", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
