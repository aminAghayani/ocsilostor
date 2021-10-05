/****************************************************************************
** Meta object code from reading C++ file 'computedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Oscilostor/computedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'computedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ComputeData_t {
    QByteArrayData data[22];
    char stringdata0[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComputeData_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComputeData_t qt_meta_stringdata_ComputeData = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ComputeData"
QT_MOC_LITERAL(1, 12, 14), // "showDataAnalog"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 44, 8), // "channel1"
QT_MOC_LITERAL(5, 53, 8), // "channel2"
QT_MOC_LITERAL(6, 62, 8), // "channel3"
QT_MOC_LITERAL(7, 71, 8), // "channel4"
QT_MOC_LITERAL(8, 80, 15), // "showDataDigital"
QT_MOC_LITERAL(9, 96, 18), // "showDataConnection"
QT_MOC_LITERAL(10, 115, 8), // "uint16_t"
QT_MOC_LITERAL(11, 124, 11), // "isConnected"
QT_MOC_LITERAL(12, 136, 16), // "showDataResistor"
QT_MOC_LITERAL(13, 153, 8), // "resValue"
QT_MOC_LITERAL(14, 162, 17), // "showDataCapacitor"
QT_MOC_LITERAL(15, 180, 8), // "capValue"
QT_MOC_LITERAL(16, 189, 13), // "showDataDiode"
QT_MOC_LITERAL(17, 203, 10), // "diodeValue"
QT_MOC_LITERAL(18, 214, 15), // "showDataCurrent"
QT_MOC_LITERAL(19, 230, 12), // "currentValue"
QT_MOC_LITERAL(20, 243, 11), // "computeData"
QT_MOC_LITERAL(21, 255, 4) // "data"

    },
    "ComputeData\0showDataAnalog\0\0QVector<double>\0"
    "channel1\0channel2\0channel3\0channel4\0"
    "showDataDigital\0showDataConnection\0"
    "uint16_t\0isConnected\0showDataResistor\0"
    "resValue\0showDataCapacitor\0capValue\0"
    "showDataDiode\0diodeValue\0showDataCurrent\0"
    "currentValue\0computeData\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComputeData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   54,    2, 0x06 /* Public */,
       8,    4,   63,    2, 0x06 /* Public */,
       9,    1,   72,    2, 0x06 /* Public */,
      12,    1,   75,    2, 0x06 /* Public */,
      14,    1,   78,    2, 0x06 /* Public */,
      16,    1,   81,    2, 0x06 /* Public */,
      18,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3, 0x80000000 | 3,    4,    5,    6,    7,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 10,   13,
    QMetaType::Void, 0x80000000 | 10,   15,
    QMetaType::Void, 0x80000000 | 10,   17,
    QMetaType::Void, 0x80000000 | 10,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   21,

       0        // eod
};

void ComputeData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ComputeData *_t = static_cast<ComputeData *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->showDataAnalog((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 1: _t->showDataDigital((*reinterpret_cast< QVector<double>(*)>(_a[1])),(*reinterpret_cast< QVector<double>(*)>(_a[2])),(*reinterpret_cast< QVector<double>(*)>(_a[3])),(*reinterpret_cast< QVector<double>(*)>(_a[4]))); break;
        case 2: _t->showDataConnection((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 3: _t->showDataResistor((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 4: _t->showDataCapacitor((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 5: _t->showDataDiode((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 6: _t->showDataCurrent((*reinterpret_cast< uint16_t(*)>(_a[1]))); break;
        case 7: _t->computeData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 3:
            case 2:
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ComputeData::*)(QVector<double> , QVector<double> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataAnalog)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(QVector<double> , QVector<double> , QVector<double> , QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataDigital)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataConnection)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataResistor)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataCapacitor)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataDiode)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ComputeData::*)(uint16_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ComputeData::showDataCurrent)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ComputeData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ComputeData.data,
      qt_meta_data_ComputeData,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ComputeData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComputeData::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComputeData.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ComputeData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ComputeData::showDataAnalog(QVector<double> _t1, QVector<double> _t2, QVector<double> _t3, QVector<double> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ComputeData::showDataDigital(QVector<double> _t1, QVector<double> _t2, QVector<double> _t3, QVector<double> _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ComputeData::showDataConnection(uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ComputeData::showDataResistor(uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ComputeData::showDataCapacitor(uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ComputeData::showDataDiode(uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ComputeData::showDataCurrent(uint16_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_ComputeDataThread_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ComputeDataThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ComputeDataThread_t qt_meta_stringdata_ComputeDataThread = {
    {
QT_MOC_LITERAL(0, 0, 17) // "ComputeDataThread"

    },
    "ComputeDataThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ComputeDataThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void ComputeDataThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ComputeDataThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ComputeDataThread.data,
      qt_meta_data_ComputeDataThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ComputeDataThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ComputeDataThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ComputeDataThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ComputeDataThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
