/****************************************************************************
** Meta object code from reading C++ file 'poweramp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PowerAmp/poweramp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'poweramp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PowerAmp_t {
    QByteArrayData data[12];
    char stringdata[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PowerAmp_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PowerAmp_t qt_meta_stringdata_PowerAmp = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PowerAmp"
QT_MOC_LITERAL(1, 9, 5), // "error"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "errorString"
QT_MOC_LITERAL(4, 28, 15), // "actionCompleted"
QT_MOC_LITERAL(5, 44, 8), // "resetAll"
QT_MOC_LITERAL(6, 53, 8), // "startAll"
QT_MOC_LITERAL(7, 62, 4), // "VOLT"
QT_MOC_LITERAL(8, 67, 4), // "volt"
QT_MOC_LITERAL(9, 72, 11), // "handleError"
QT_MOC_LITERAL(10, 84, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(11, 113, 11) // "serialError"

    },
    "PowerAmp\0error\0\0errorString\0actionCompleted\0"
    "resetAll\0startAll\0VOLT\0volt\0handleError\0"
    "QSerialPort::SerialPortError\0serialError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PowerAmp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

void PowerAmp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PowerAmp *_t = static_cast<PowerAmp *>(_o);
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->actionCompleted(); break;
        case 2: { bool _r = _t->resetAll();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->startAll((*reinterpret_cast< VOLT(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (PowerAmp::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PowerAmp::error)) {
                *result = 0;
            }
        }
        {
            typedef void (PowerAmp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&PowerAmp::actionCompleted)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject PowerAmp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PowerAmp.data,
      qt_meta_data_PowerAmp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *PowerAmp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PowerAmp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_PowerAmp.stringdata))
        return static_cast<void*>(const_cast< PowerAmp*>(this));
    return QObject::qt_metacast(_clname);
}

int PowerAmp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PowerAmp::error(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PowerAmp::actionCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
