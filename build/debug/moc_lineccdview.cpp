/****************************************************************************
** Meta object code from reading C++ file 'lineccdview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/lineccdview/headers/lineccdview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lineccdview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyThreadSerial_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyThreadSerial_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyThreadSerial_t qt_meta_stringdata_MyThreadSerial = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyThreadSerial"
QT_MOC_LITERAL(1, 15, 11), // "ThreadMyCom"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "MyThreadSerial\0ThreadMyCom\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyThreadSerial[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,

       0        // eod
};

void MyThreadSerial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyThreadSerial *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ThreadMyCom((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyThreadSerial::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyThreadSerial::ThreadMyCom)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyThreadSerial::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_MyThreadSerial.data,
    qt_meta_data_MyThreadSerial,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyThreadSerial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyThreadSerial::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyThreadSerial.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int MyThreadSerial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void MyThreadSerial::ThreadMyCom(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_lineccdview_t {
    QByteArrayData data[37];
    char stringdata0[835];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lineccdview_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lineccdview_t qt_meta_stringdata_lineccdview = {
    {
QT_MOC_LITERAL(0, 0, 11), // "lineccdview"
QT_MOC_LITERAL(1, 12, 13), // "ThreadCCDdata"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 43, 27), // "on_pushButton_Close_clicked"
QT_MOC_LITERAL(5, 71, 9), // "readMyCom"
QT_MOC_LITERAL(6, 81, 3), // "str"
QT_MOC_LITERAL(7, 85, 11), // "timerUpDate"
QT_MOC_LITERAL(8, 97, 12), // "timerUpDate2"
QT_MOC_LITERAL(9, 110, 12), // "timerUpDate3"
QT_MOC_LITERAL(10, 123, 26), // "on_pushButton_Open_clicked"
QT_MOC_LITERAL(11, 150, 26), // "on_pushButton_Send_clicked"
QT_MOC_LITERAL(12, 177, 25), // "on_pushButton_Cou_clicked"
QT_MOC_LITERAL(13, 203, 28), // "on_pushButton_SetInt_clicked"
QT_MOC_LITERAL(14, 232, 26), // "on_pushButton_Save_clicked"
QT_MOC_LITERAL(15, 259, 27), // "on_pushButton_Pause_clicked"
QT_MOC_LITERAL(16, 287, 28), // "on_pushButton_SetAvg_clicked"
QT_MOC_LITERAL(17, 316, 5), // "ToStr"
QT_MOC_LITERAL(18, 322, 6), // "number"
QT_MOC_LITERAL(19, 329, 4), // "size"
QT_MOC_LITERAL(20, 334, 24), // "on_pushButton_fW_clicked"
QT_MOC_LITERAL(21, 359, 24), // "on_pushButton_fR_clicked"
QT_MOC_LITERAL(22, 384, 23), // "on_textEdit_textChanged"
QT_MOC_LITERAL(23, 408, 27), // "on_pushButton_Clean_clicked"
QT_MOC_LITERAL(24, 436, 36), // "on_comboBox_unit_currentIndex..."
QT_MOC_LITERAL(25, 473, 4), // "arg1"
QT_MOC_LITERAL(26, 478, 31), // "on_pushButton_SetSmooth_clicked"
QT_MOC_LITERAL(27, 510, 32), // "on_pushButton_EarseFlash_clicked"
QT_MOC_LITERAL(28, 543, 29), // "on_pushButton_GetDark_clicked"
QT_MOC_LITERAL(29, 573, 35), // "on_checkBox_removeDark_stateC..."
QT_MOC_LITERAL(30, 609, 29), // "on_radioButton_pixels_clicked"
QT_MOC_LITERAL(31, 639, 33), // "on_radioButton_wavelength_cli..."
QT_MOC_LITERAL(32, 673, 28), // "on_radioButton_raman_clicked"
QT_MOC_LITERAL(33, 702, 33), // "on_radioButton_wavenumber_cli..."
QT_MOC_LITERAL(34, 736, 33), // "on_pushButton_SetInterval_cli..."
QT_MOC_LITERAL(35, 770, 28), // "on_pushButton_filter_clicked"
QT_MOC_LITERAL(36, 799, 35) // "on_pushButton_Bandrate_read_c..."

    },
    "lineccdview\0ThreadCCDdata\0\0QVector<double>\0"
    "on_pushButton_Close_clicked\0readMyCom\0"
    "str\0timerUpDate\0timerUpDate2\0timerUpDate3\0"
    "on_pushButton_Open_clicked\0"
    "on_pushButton_Send_clicked\0"
    "on_pushButton_Cou_clicked\0"
    "on_pushButton_SetInt_clicked\0"
    "on_pushButton_Save_clicked\0"
    "on_pushButton_Pause_clicked\0"
    "on_pushButton_SetAvg_clicked\0ToStr\0"
    "number\0size\0on_pushButton_fW_clicked\0"
    "on_pushButton_fR_clicked\0"
    "on_textEdit_textChanged\0"
    "on_pushButton_Clean_clicked\0"
    "on_comboBox_unit_currentIndexChanged\0"
    "arg1\0on_pushButton_SetSmooth_clicked\0"
    "on_pushButton_EarseFlash_clicked\0"
    "on_pushButton_GetDark_clicked\0"
    "on_checkBox_removeDark_stateChanged\0"
    "on_radioButton_pixels_clicked\0"
    "on_radioButton_wavelength_clicked\0"
    "on_radioButton_raman_clicked\0"
    "on_radioButton_wavenumber_clicked\0"
    "on_pushButton_SetInterval_clicked\0"
    "on_pushButton_filter_clicked\0"
    "on_pushButton_Bandrate_read_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lineccdview[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  164,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  167,    2, 0x08 /* Private */,
       5,    1,  168,    2, 0x08 /* Private */,
       7,    0,  171,    2, 0x08 /* Private */,
       8,    0,  172,    2, 0x08 /* Private */,
       9,    0,  173,    2, 0x08 /* Private */,
      10,    0,  174,    2, 0x08 /* Private */,
      11,    0,  175,    2, 0x08 /* Private */,
      12,    0,  176,    2, 0x08 /* Private */,
      13,    0,  177,    2, 0x08 /* Private */,
      14,    0,  178,    2, 0x08 /* Private */,
      15,    0,  179,    2, 0x08 /* Private */,
      16,    0,  180,    2, 0x08 /* Private */,
      17,    2,  181,    2, 0x08 /* Private */,
      20,    0,  186,    2, 0x08 /* Private */,
      21,    0,  187,    2, 0x08 /* Private */,
      22,    0,  188,    2, 0x08 /* Private */,
      23,    0,  189,    2, 0x08 /* Private */,
      24,    1,  190,    2, 0x08 /* Private */,
      26,    0,  193,    2, 0x08 /* Private */,
      27,    0,  194,    2, 0x08 /* Private */,
      28,    0,  195,    2, 0x08 /* Private */,
      29,    1,  196,    2, 0x08 /* Private */,
      30,    0,  199,    2, 0x08 /* Private */,
      31,    0,  200,    2, 0x08 /* Private */,
      32,    0,  201,    2, 0x08 /* Private */,
      33,    0,  202,    2, 0x08 /* Private */,
      34,    0,  203,    2, 0x08 /* Private */,
      35,    0,  204,    2, 0x08 /* Private */,
      36,    0,  205,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    6,
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
    QMetaType::QString, QMetaType::Int, QMetaType::Int,   18,   19,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lineccdview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lineccdview *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ThreadCCDdata((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_Close_clicked(); break;
        case 2: _t->readMyCom((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->timerUpDate(); break;
        case 4: _t->timerUpDate2(); break;
        case 5: _t->timerUpDate3(); break;
        case 6: _t->on_pushButton_Open_clicked(); break;
        case 7: _t->on_pushButton_Send_clicked(); break;
        case 8: _t->on_pushButton_Cou_clicked(); break;
        case 9: _t->on_pushButton_SetInt_clicked(); break;
        case 10: _t->on_pushButton_Save_clicked(); break;
        case 11: _t->on_pushButton_Pause_clicked(); break;
        case 12: _t->on_pushButton_SetAvg_clicked(); break;
        case 13: { QString _r = _t->ToStr((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->on_pushButton_fW_clicked(); break;
        case 15: _t->on_pushButton_fR_clicked(); break;
        case 16: _t->on_textEdit_textChanged(); break;
        case 17: _t->on_pushButton_Clean_clicked(); break;
        case 18: _t->on_comboBox_unit_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_pushButton_SetSmooth_clicked(); break;
        case 20: _t->on_pushButton_EarseFlash_clicked(); break;
        case 21: _t->on_pushButton_GetDark_clicked(); break;
        case 22: _t->on_checkBox_removeDark_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_radioButton_pixels_clicked(); break;
        case 24: _t->on_radioButton_wavelength_clicked(); break;
        case 25: _t->on_radioButton_raman_clicked(); break;
        case 26: _t->on_radioButton_wavenumber_clicked(); break;
        case 27: _t->on_pushButton_SetInterval_clicked(); break;
        case 28: _t->on_pushButton_filter_clicked(); break;
        case 29: _t->on_pushButton_Bandrate_read_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lineccdview::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lineccdview::ThreadCCDdata)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject lineccdview::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_lineccdview.data,
    qt_meta_data_lineccdview,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lineccdview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lineccdview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lineccdview.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int lineccdview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    }
    return _id;
}

// SIGNAL 0
void lineccdview::ThreadCCDdata(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
