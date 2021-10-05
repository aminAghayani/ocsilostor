/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Oscilostor/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[50];
    char stringdata0[1275];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 33), // "on_usb_connect_pushButton_cli..."
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 36), // "on_usb_disconnect_pushButton_..."
QT_MOC_LITERAL(4, 83, 34), // "on_wifi_connect_pushButton_cl..."
QT_MOC_LITERAL(5, 118, 37), // "on_wifi_disconnect_pushButton..."
QT_MOC_LITERAL(6, 156, 38), // "on_connection_check_pushButto..."
QT_MOC_LITERAL(7, 195, 33), // "on_diode_check_pushButton_cli..."
QT_MOC_LITERAL(8, 229, 38), // "on_resistor_measure_pushButto..."
QT_MOC_LITERAL(9, 268, 39), // "on_capacitor_measure_pushButt..."
QT_MOC_LITERAL(10, 308, 37), // "on_current_measure_pushButton..."
QT_MOC_LITERAL(11, 346, 33), // "on_voltageout1_pushButton_cli..."
QT_MOC_LITERAL(12, 380, 33), // "on_voltageout2_pushButton_cli..."
QT_MOC_LITERAL(13, 414, 26), // "on_dac1_pushButton_clicked"
QT_MOC_LITERAL(14, 441, 26), // "on_dac2_pushButton_clicked"
QT_MOC_LITERAL(15, 468, 34), // "on_analog_start_pushButton_cl..."
QT_MOC_LITERAL(16, 503, 34), // "on_analog_clear_pushButton_cl..."
QT_MOC_LITERAL(17, 538, 35), // "on_analog_cursor_pushButton_c..."
QT_MOC_LITERAL(18, 574, 33), // "on_analog_save_pushButton_cli..."
QT_MOC_LITERAL(19, 608, 35), // "on_digital_start_pushButton_c..."
QT_MOC_LITERAL(20, 644, 35), // "on_digital_clear_pushButton_c..."
QT_MOC_LITERAL(21, 680, 36), // "on_digital_cursor_pushButton_..."
QT_MOC_LITERAL(22, 717, 34), // "on_digital_save_pushButton_cl..."
QT_MOC_LITERAL(23, 752, 13), // "showingAnalog"
QT_MOC_LITERAL(24, 766, 15), // "QVector<double>"
QT_MOC_LITERAL(25, 782, 8), // "channel1"
QT_MOC_LITERAL(26, 791, 8), // "channel2"
QT_MOC_LITERAL(27, 800, 8), // "channel3"
QT_MOC_LITERAL(28, 809, 8), // "channel4"
QT_MOC_LITERAL(29, 818, 14), // "showingDigital"
QT_MOC_LITERAL(30, 833, 17), // "showingConnection"
QT_MOC_LITERAL(31, 851, 8), // "uint16_t"
QT_MOC_LITERAL(32, 860, 11), // "isConnected"
QT_MOC_LITERAL(33, 872, 15), // "showingResistor"
QT_MOC_LITERAL(34, 888, 8), // "resValue"
QT_MOC_LITERAL(35, 897, 16), // "showingCapacitor"
QT_MOC_LITERAL(36, 914, 8), // "capValue"
QT_MOC_LITERAL(37, 923, 12), // "showingDiode"
QT_MOC_LITERAL(38, 936, 10), // "diodeValue"
QT_MOC_LITERAL(39, 947, 14), // "showingCurrent"
QT_MOC_LITERAL(40, 962, 12), // "currentValue"
QT_MOC_LITERAL(41, 975, 35), // "on_analog_channel1_checkBox_c..."
QT_MOC_LITERAL(42, 1011, 7), // "checked"
QT_MOC_LITERAL(43, 1019, 35), // "on_analog_channel2_checkBox_c..."
QT_MOC_LITERAL(44, 1055, 35), // "on_analog_channel3_checkBox_c..."
QT_MOC_LITERAL(45, 1091, 35), // "on_analog_channel4_checkBox_c..."
QT_MOC_LITERAL(46, 1127, 36), // "on_digital_channel1_checkBox_..."
QT_MOC_LITERAL(47, 1164, 36), // "on_digital_channel2_checkBox_..."
QT_MOC_LITERAL(48, 1201, 36), // "on_digital_channel3_checkBox_..."
QT_MOC_LITERAL(49, 1238, 36) // "on_digital_channel4_checkBox_..."

    },
    "MainWindow\0on_usb_connect_pushButton_clicked\0"
    "\0on_usb_disconnect_pushButton_clicked\0"
    "on_wifi_connect_pushButton_clicked\0"
    "on_wifi_disconnect_pushButton_clicked\0"
    "on_connection_check_pushButton_clicked\0"
    "on_diode_check_pushButton_clicked\0"
    "on_resistor_measure_pushButton_clicked\0"
    "on_capacitor_measure_pushButton_clicked\0"
    "on_current_measure_pushButton_clicked\0"
    "on_voltageout1_pushButton_clicked\0"
    "on_voltageout2_pushButton_clicked\0"
    "on_dac1_pushButton_clicked\0"
    "on_dac2_pushButton_clicked\0"
    "on_analog_start_pushButton_clicked\0"
    "on_analog_clear_pushButton_clicked\0"
    "on_analog_cursor_pushButton_clicked\0"
    "on_analog_save_pushButton_clicked\0"
    "on_digital_start_pushButton_clicked\0"
    "on_digital_clear_pushButton_clicked\0"
    "on_digital_cursor_pushButton_clicked\0"
    "on_digital_save_pushButton_clicked\0"
    "showingAnalog\0QVector<double>\0channel1\0"
    "channel2\0channel3\0channel4\0showingDigital\0"
    "showingConnection\0uint16_t\0isConnected\0"
    "showingResistor\0resValue\0showingCapacitor\0"
    "capValue\0showingDiode\0diodeValue\0"
    "showingCurrent\0currentValue\0"
    "on_analog_channel1_checkBox_clicked\0"
    "checked\0on_analog_channel2_checkBox_clicked\0"
    "on_analog_channel3_checkBox_clicked\0"
    "on_analog_channel4_checkBox_clicked\0"
    "on_digital_channel1_checkBox_clicked\0"
    "on_digital_channel2_checkBox_clicked\0"
    "on_digital_channel3_checkBox_clicked\0"
    "on_digital_channel4_checkBox_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      36,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  194,    2, 0x08 /* Private */,
       3,    0,  195,    2, 0x08 /* Private */,
       4,    0,  196,    2, 0x08 /* Private */,
       5,    0,  197,    2, 0x08 /* Private */,
       6,    0,  198,    2, 0x08 /* Private */,
       7,    0,  199,    2, 0x08 /* Private */,
       8,    0,  200,    2, 0x08 /* Private */,
       9,    0,  201,    2, 0x08 /* Private */,
      10,    0,  202,    2, 0x08 /* Private */,
      11,    0,  203,    2, 0x08 /* Private */,
      12,    0,  204,    2, 0x08 /* Private */,
      13,    0,  205,    2, 0x08 /* Private */,
      14,    0,  206,    2, 0x08 /* Private */,
      15,    0,  207,    2, 0x08 /* Private */,
      16,    0,  208,    2, 0x08 /* Private */,
      17,    0,  209,    2, 0x08 /* Private */,
      18,    0,  210,    2, 0x08 /* Private */,
      19,    0,  211,    2, 0x08 /* Private */,
      20,    0,  212,    2, 0x08 /* Private */,
      21,    0,  213,    2, 0x08 /* Private */,
      22,    0,  214,    2, 0x08 /* Private */,
      23,    4,  215,    2, 0x08 /* Private */,
      29,    4,  224,    2, 0x08 /* Private */,
      30,    1,  233,    2, 0x08 /* Private */,
      33,    1,  236,    2, 0x08 /* Private */,
      35,    1,  239,    2, 0x08 /* Private */,
      37,    1,  242,    2, 0x08 /* Private */,
      39,    1,  245,    2, 0x08 /* Private */,
      41,    1,  248,    2, 0x08 /* Private */,
      43,    1,  251,    2, 0x08 /* Private */,
      44,    1,  254,    2, 0x08 /* Private */,
      45,    1,  257,    2, 0x08 /* Private */,
      46,    1,  260,    2, 0x08 /* Private */,
      47,    1,  263,    2, 0x08 /* Private */,
      48,    1,  266,    2, 0x08 /* Private */,
      49,    1,  269,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24,   25,   26,   27,   28,
    QMetaType::Void, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24, 0x80000000 | 24,   25,   26,   27,   28,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 31,   34,
    QMetaType::Void, 0x80000000 | 31,   36,
    QMetaType::Void, 0x80000000 | 31,   38,
    QMetaType::Void, 0x80000000 | 31,   40,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,
    QMetaType::Void, QMetaType::Bool,   42,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_usb_connect_pushButton_clicked(); break;
        case 1: _t->on_usb_disconnect_pushButton_clicked(); break;
        case 2: _t->on_wifi_connect_pushButton_clicked(); break;
        case 3: _t->on_wifi_disconnect_pushButton_clicked(); break;
        case 4: _t->on_connection_check_pushButton_clicked(); break;
        case 5: _t->on_diode_check_pushButton_clicked(); break;
        case 6: _t->on_resistor_measure_pushButton_clicked(); break;
        case 7: _t->on_capacitor_measure_pushButton_clicked(); break;
        case 8: _t->on_current_measure_pushButton_clicked(); break;
        case 9: _t->on_voltageout1_pushButton_clicked(); break;
        case 10: _t->on_voltageout2_pushButton_clicked(); break;
        case 11: _t->on_dac1_pushButton_clicked(); break;
        case 12: _t->on_dac2_pushButton_clicked(); break;
        case 13: _t->on_analog_start_pushButton_clicked(); break;
        case 14: _t->on_analog_clear_pushButton_clicked(); break;
        case 15: _t->on_analog_cursor_pushButton_clicked(); break;
        case 16: _t->on_analog_save_pushButton_clicked(); break;
        case 17: _t->on_digital_start_pushButton_clicked(); break;
        case 18: _t->on_digital_clear_pushButton_clicked(); break;
        case 19: _t->on_digital_cursor_pushButton_clicked(); break;
        case 20: _t->on_digital_save_pushButton_clicked(); break;
        case 21: _t->showingAnalog((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 22: _t->showingDigital((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 23: _t->showingConnection((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 24: _t->showingResistor((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 25: _t->showingCapacitor((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 26: _t->showingDiode((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 27: _t->showingCurrent((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 28: _t->on_analog_channel1_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 29: _t->on_analog_channel2_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 30: _t->on_analog_channel3_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 31: _t->on_analog_channel4_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 32: _t->on_digital_channel1_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 33: _t->on_digital_channel2_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 34: _t->on_digital_channel3_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 35: _t->on_digital_channel4_checkBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 21:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 22:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 36)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
