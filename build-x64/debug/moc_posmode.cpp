/****************************************************************************
** Meta object code from reading C++ file 'posmode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/motorcontrol/headers/posmode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'posmode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DataCaptureThread_t {
    QByteArrayData data[7];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DataCaptureThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DataCaptureThread_t qt_meta_stringdata_DataCaptureThread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "DataCaptureThread"
QT_MOC_LITERAL(1, 18, 13), // "capturethread"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 16), // "QVector<quint16>"
QT_MOC_LITERAL(4, 50, 4), // "data"
QT_MOC_LITERAL(5, 55, 14), // "receiveccddata"
QT_MOC_LITERAL(6, 70, 15) // "QVector<double>"

    },
    "DataCaptureThread\0capturethread\0\0"
    "QVector<quint16>\0data\0receiveccddata\0"
    "QVector<double>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DataCaptureThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       5,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    4,

       0        // eod
};

void DataCaptureThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DataCaptureThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->capturethread((*reinterpret_cast< QVector<quint16>(*)>(_a[1]))); break;
        case 1: _t->receiveccddata((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint16> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DataCaptureThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_DataCaptureThread.data,
    qt_meta_data_DataCaptureThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DataCaptureThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DataCaptureThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DataCaptureThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int DataCaptureThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_posmode_t {
    QByteArrayData data[14];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_posmode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_posmode_t qt_meta_stringdata_posmode = {
    {
QT_MOC_LITERAL(0, 0, 7), // "posmode"
QT_MOC_LITERAL(1, 8, 12), // "readycapture"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 16), // "QVector<quint16>"
QT_MOC_LITERAL(4, 39, 4), // "data"
QT_MOC_LITERAL(5, 44, 11), // "stopcapture"
QT_MOC_LITERAL(6, 56, 29), // "on_pushButtonbackzero_clicked"
QT_MOC_LITERAL(7, 86, 30), // "on_pushButtonstartstep_clicked"
QT_MOC_LITERAL(8, 117, 28), // "on_pushButtonendstep_clicked"
QT_MOC_LITERAL(9, 146, 29), // "on_pushButtonstartp2p_clicked"
QT_MOC_LITERAL(10, 176, 27), // "on_pushButtonendp2p_clicked"
QT_MOC_LITERAL(11, 204, 9), // "timedelay"
QT_MOC_LITERAL(12, 214, 10), // "postopulse"
QT_MOC_LITERAL(13, 225, 3) // "pos"

    },
    "posmode\0readycapture\0\0QVector<quint16>\0"
    "data\0stopcapture\0on_pushButtonbackzero_clicked\0"
    "on_pushButtonstartstep_clicked\0"
    "on_pushButtonendstep_clicked\0"
    "on_pushButtonstartp2p_clicked\0"
    "on_pushButtonendp2p_clicked\0timedelay\0"
    "postopulse\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_posmode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    1,   69,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int, QMetaType::Double,   13,

       0        // eod
};

void posmode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<posmode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readycapture((*reinterpret_cast< QVector<quint16>(*)>(_a[1]))); break;
        case 1: _t->stopcapture(); break;
        case 2: _t->on_pushButtonbackzero_clicked(); break;
        case 3: _t->on_pushButtonstartstep_clicked(); break;
        case 4: _t->on_pushButtonendstep_clicked(); break;
        case 5: _t->on_pushButtonstartp2p_clicked(); break;
        case 6: _t->on_pushButtonendp2p_clicked(); break;
        case 7: _t->timedelay(); break;
        case 8: { int _r = _t->postopulse((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<quint16> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (posmode::*)(QVector<quint16> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&posmode::readycapture)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (posmode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&posmode::stopcapture)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject posmode::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_posmode.data,
    qt_meta_data_posmode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *posmode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *posmode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_posmode.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int posmode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void posmode::readycapture(QVector<quint16> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void posmode::stopcapture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
