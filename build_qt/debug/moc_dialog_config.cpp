/****************************************************************************
** Meta object code from reading C++ file 'dialog_config.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/lineccdview/headers/dialog_config.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog_config.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_config_t {
    QByteArrayData data[16];
    char stringdata0[425];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_config_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_config_t qt_meta_stringdata_Dialog_config = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Dialog_config"
QT_MOC_LITERAL(1, 14, 34), // "on_checkBox_HdTrigger_stateCh..."
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 4), // "arg1"
QT_MOC_LITERAL(4, 55, 28), // "on_pushButton_SetDAC_clicked"
QT_MOC_LITERAL(5, 84, 33), // "on_checkBox_Trigger2_stateCha..."
QT_MOC_LITERAL(6, 118, 28), // "on_checkBox_Trig_Con_clicked"
QT_MOC_LITERAL(7, 147, 36), // "on_checkBox_Trig_Single_state..."
QT_MOC_LITERAL(8, 184, 31), // "on_checkBox_Trig_Single_clicked"
QT_MOC_LITERAL(9, 216, 30), // "on_pushButton_Bandrate_clicked"
QT_MOC_LITERAL(10, 247, 29), // "on_pushButton_SetGain_clicked"
QT_MOC_LITERAL(11, 277, 31), // "on_pushButton_SetOffset_clicked"
QT_MOC_LITERAL(12, 309, 30), // "on_pushButton_SavePara_clicked"
QT_MOC_LITERAL(13, 340, 29), // "on_pushButton_Setting_clicked"
QT_MOC_LITERAL(14, 370, 24), // "on_checkBox_sync_clicked"
QT_MOC_LITERAL(15, 395, 29) // "on_checkBox_sync_stateChanged"

    },
    "Dialog_config\0on_checkBox_HdTrigger_stateChanged\0"
    "\0arg1\0on_pushButton_SetDAC_clicked\0"
    "on_checkBox_Trigger2_stateChanged\0"
    "on_checkBox_Trig_Con_clicked\0"
    "on_checkBox_Trig_Single_stateChanged\0"
    "on_checkBox_Trig_Single_clicked\0"
    "on_pushButton_Bandrate_clicked\0"
    "on_pushButton_SetGain_clicked\0"
    "on_pushButton_SetOffset_clicked\0"
    "on_pushButton_SavePara_clicked\0"
    "on_pushButton_Setting_clicked\0"
    "on_checkBox_sync_clicked\0"
    "on_checkBox_sync_stateChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog_config[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    1,   83,    2, 0x08 /* Private */,
       6,    0,   86,    2, 0x08 /* Private */,
       7,    1,   87,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void Dialog_config::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog_config *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_checkBox_HdTrigger_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_SetDAC_clicked(); break;
        case 2: _t->on_checkBox_Trigger2_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_checkBox_Trig_Con_clicked(); break;
        case 4: _t->on_checkBox_Trig_Single_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_checkBox_Trig_Single_clicked(); break;
        case 6: _t->on_pushButton_Bandrate_clicked(); break;
        case 7: _t->on_pushButton_SetGain_clicked(); break;
        case 8: _t->on_pushButton_SetOffset_clicked(); break;
        case 9: _t->on_pushButton_SavePara_clicked(); break;
        case 10: _t->on_pushButton_Setting_clicked(); break;
        case 11: _t->on_checkBox_sync_clicked(); break;
        case 12: _t->on_checkBox_sync_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog_config::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog_config.data,
    qt_meta_data_Dialog_config,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog_config::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog_config::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog_config.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog_config::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
