/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[478];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionExit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 26), // "on_actionConnect_triggered"
QT_MOC_LITERAL(4, 63, 29), // "on_actionDisconnect_triggered"
QT_MOC_LITERAL(5, 93, 26), // "on_actionRefresh_triggered"
QT_MOC_LITERAL(6, 120, 25), // "on_actionConfig_triggered"
QT_MOC_LITERAL(7, 146, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(8, 170, 25), // "on_actionenable_triggered"
QT_MOC_LITERAL(9, 196, 26), // "on_actiondisable_triggered"
QT_MOC_LITERAL(10, 223, 27), // "on_actionvelocity_triggered"
QT_MOC_LITERAL(11, 251, 27), // "on_actiondisplace_triggered"
QT_MOC_LITERAL(12, 279, 33), // "on_actionchannel_config_trigg..."
QT_MOC_LITERAL(13, 313, 25), // "on_actioncamera_triggered"
QT_MOC_LITERAL(14, 339, 25), // "on_pushButtonRead_clicked"
QT_MOC_LITERAL(15, 365, 26), // "on_pushButtonWrite_clicked"
QT_MOC_LITERAL(16, 392, 25), // "on_pushButtonSend_clicked"
QT_MOC_LITERAL(17, 418, 23), // "on_checkBoxAuto_clicked"
QT_MOC_LITERAL(18, 442, 7), // "checked"
QT_MOC_LITERAL(19, 450, 14), // "ReadSerialData"
QT_MOC_LITERAL(20, 465, 12) // "ChartDisplay"

    },
    "MainWindow\0on_actionExit_triggered\0\0"
    "on_actionConnect_triggered\0"
    "on_actionDisconnect_triggered\0"
    "on_actionRefresh_triggered\0"
    "on_actionConfig_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionenable_triggered\0"
    "on_actiondisable_triggered\0"
    "on_actionvelocity_triggered\0"
    "on_actiondisplace_triggered\0"
    "on_actionchannel_config_triggered\0"
    "on_actioncamera_triggered\0"
    "on_pushButtonRead_clicked\0"
    "on_pushButtonWrite_clicked\0"
    "on_pushButtonSend_clicked\0"
    "on_checkBoxAuto_clicked\0checked\0"
    "ReadSerialData\0ChartDisplay"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x0a /* Public */,
       3,    0,  105,    2, 0x0a /* Public */,
       4,    0,  106,    2, 0x0a /* Public */,
       5,    0,  107,    2, 0x0a /* Public */,
       6,    0,  108,    2, 0x0a /* Public */,
       7,    0,  109,    2, 0x0a /* Public */,
       8,    0,  110,    2, 0x0a /* Public */,
       9,    0,  111,    2, 0x0a /* Public */,
      10,    0,  112,    2, 0x0a /* Public */,
      11,    0,  113,    2, 0x0a /* Public */,
      12,    0,  114,    2, 0x0a /* Public */,
      13,    0,  115,    2, 0x0a /* Public */,
      14,    0,  116,    2, 0x0a /* Public */,
      15,    0,  117,    2, 0x0a /* Public */,
      16,    0,  118,    2, 0x0a /* Public */,
      17,    1,  119,    2, 0x0a /* Public */,
      19,    0,  122,    2, 0x0a /* Public */,
      20,    0,  123,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Bool,   18,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionExit_triggered(); break;
        case 1: _t->on_actionConnect_triggered(); break;
        case 2: _t->on_actionDisconnect_triggered(); break;
        case 3: _t->on_actionRefresh_triggered(); break;
        case 4: _t->on_actionConfig_triggered(); break;
        case 5: _t->on_actionSave_triggered(); break;
        case 6: _t->on_actionenable_triggered(); break;
        case 7: _t->on_actiondisable_triggered(); break;
        case 8: _t->on_actionvelocity_triggered(); break;
        case 9: _t->on_actiondisplace_triggered(); break;
        case 10: _t->on_actionchannel_config_triggered(); break;
        case 11: _t->on_actioncamera_triggered(); break;
        case 12: _t->on_pushButtonRead_clicked(); break;
        case 13: _t->on_pushButtonWrite_clicked(); break;
        case 14: _t->on_pushButtonSend_clicked(); break;
        case 15: _t->on_checkBoxAuto_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->ReadSerialData(); break;
        case 17: _t->ChartDisplay(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
