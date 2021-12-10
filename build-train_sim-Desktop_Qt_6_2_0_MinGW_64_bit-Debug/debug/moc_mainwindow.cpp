/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[76];
    char stringdata0[566];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 10), // "sendCTCOcc"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 17), // "std::vector<bool>"
QT_MOC_LITERAL(41, 18), // "sendTrackModelAuth"
QT_MOC_LITERAL(60, 22), // "sendTrackModelSwitches"
QT_MOC_LITERAL(83, 16), // "std::vector<int>"
QT_MOC_LITERAL(100, 17), // "sendTrainDispatch"
QT_MOC_LITERAL(118, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(143, 13), // "sendCTCHeater"
QT_MOC_LITERAL(157, 16), // "activateCrossing"
QT_MOC_LITERAL(174, 11), // "vector<int>"
QT_MOC_LITERAL(186, 14), // "sendThroughput"
QT_MOC_LITERAL(201, 14), // "sendMaintenace"
QT_MOC_LITERAL(216, 14), // "upload_clicked"
QT_MOC_LITERAL(231, 8), // "sel_line"
QT_MOC_LITERAL(240, 9), // "sel_block"
QT_MOC_LITERAL(250, 11), // "sel_wayside"
QT_MOC_LITERAL(262, 8), // "ctc_test"
QT_MOC_LITERAL(271, 15), // "check_ctc_lines"
QT_MOC_LITERAL(287, 17), // "check_track_lines"
QT_MOC_LITERAL(305, 17), // "check_heater_line"
QT_MOC_LITERAL(323, 10), // "track_test"
QT_MOC_LITERAL(334, 12), // "track_heater"
QT_MOC_LITERAL(347, 22), // "check_maintenance_line"
QT_MOC_LITERAL(370, 23), // "on_uploadButton_clicked"
QT_MOC_LITERAL(394, 29), // "on_maintenance_submit_clicked"
QT_MOC_LITERAL(424, 29), // "on_maintenance_toggle_clicked"
QT_MOC_LITERAL(454, 10), // "receiveOcc"
QT_MOC_LITERAL(465, 3), // "occ"
QT_MOC_LITERAL(469, 13), // "receiveHeater"
QT_MOC_LITERAL(483, 11), // "recieveAuth"
QT_MOC_LITERAL(495, 10), // "TrainEntry"
QT_MOC_LITERAL(506, 17), // "getMaintenaceMode"
QT_MOC_LITERAL(524, 6), // "blocks"
QT_MOC_LITERAL(531, 12), // "changeSwitch"
QT_MOC_LITERAL(544, 3), // "pos"
QT_MOC_LITERAL(548, 17) // "receiveThroughput"

    },
    "MainWindow\0sendCTCOcc\0\0std::vector<bool>\0"
    "sendTrackModelAuth\0sendTrackModelSwitches\0"
    "std::vector<int>\0sendTrainDispatch\0"
    "std::vector<std::string>\0sendCTCHeater\0"
    "activateCrossing\0vector<int>\0"
    "sendThroughput\0sendMaintenace\0"
    "upload_clicked\0sel_line\0sel_block\0"
    "sel_wayside\0ctc_test\0check_ctc_lines\0"
    "check_track_lines\0check_heater_line\0"
    "track_test\0track_heater\0check_maintenance_line\0"
    "on_uploadButton_clicked\0"
    "on_maintenance_submit_clicked\0"
    "on_maintenance_toggle_clicked\0receiveOcc\0"
    "occ\0receiveHeater\0recieveAuth\0TrainEntry\0"
    "getMaintenaceMode\0blocks\0changeSwitch\0"
    "pos\0receiveThroughput"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      28,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  182,    2, 0x06,    1 /* Public */,
       4,    1,  185,    2, 0x06,    3 /* Public */,
       5,    1,  188,    2, 0x06,    5 /* Public */,
       7,    1,  191,    2, 0x06,    7 /* Public */,
       9,    1,  194,    2, 0x06,    9 /* Public */,
      10,    1,  197,    2, 0x06,   11 /* Public */,
      12,    1,  200,    2, 0x06,   13 /* Public */,
      13,    1,  203,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  206,    2, 0x08,   17 /* Private */,
      15,    0,  207,    2, 0x08,   18 /* Private */,
      16,    0,  208,    2, 0x08,   19 /* Private */,
      17,    0,  209,    2, 0x08,   20 /* Private */,
      18,    0,  210,    2, 0x08,   21 /* Private */,
      19,    0,  211,    2, 0x08,   22 /* Private */,
      20,    0,  212,    2, 0x08,   23 /* Private */,
      21,    0,  213,    2, 0x08,   24 /* Private */,
      22,    0,  214,    2, 0x08,   25 /* Private */,
      23,    0,  215,    2, 0x08,   26 /* Private */,
      24,    0,  216,    2, 0x08,   27 /* Private */,
      25,    0,  217,    2, 0x08,   28 /* Private */,
      26,    0,  218,    2, 0x08,   29 /* Private */,
      27,    0,  219,    2, 0x08,   30 /* Private */,
      28,    1,  220,    2, 0x0a,   31 /* Public */,
      30,    1,  223,    2, 0x0a,   33 /* Public */,
      31,    1,  226,    2, 0x0a,   35 /* Public */,
      33,    1,  229,    2, 0x0a,   37 /* Public */,
      35,    1,  232,    2, 0x0a,   39 /* Public */,
      37,    1,  235,    2, 0x0a,   41 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 11,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

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
    QMetaType::Void, 0x80000000 | 3,   29,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 32,    2,
    QMetaType::Void, 0x80000000 | 3,   34,
    QMetaType::Void, 0x80000000 | 6,   36,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendCTCOcc((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 1: _t->sendTrackModelAuth((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 2: _t->sendTrackModelSwitches((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 3: _t->sendTrainDispatch((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 4: _t->sendCTCHeater((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->activateCrossing((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 6: _t->sendThroughput((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sendMaintenace((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->upload_clicked(); break;
        case 9: _t->sel_line(); break;
        case 10: _t->sel_block(); break;
        case 11: _t->sel_wayside(); break;
        case 12: _t->ctc_test(); break;
        case 13: _t->check_ctc_lines(); break;
        case 14: _t->check_track_lines(); break;
        case 15: _t->check_heater_line(); break;
        case 16: _t->track_test(); break;
        case 17: _t->track_heater(); break;
        case 18: _t->check_maintenance_line(); break;
        case 19: _t->on_uploadButton_clicked(); break;
        case 20: _t->on_maintenance_submit_clicked(); break;
        case 21: _t->on_maintenance_toggle_clicked(); break;
        case 22: _t->receiveOcc((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 23: _t->receiveHeater((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->recieveAuth((*reinterpret_cast< TrainEntry(*)>(_a[1]))); break;
        case 25: _t->getMaintenaceMode((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 26: _t->changeSwitch((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 27: _t->receiveThroughput((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(std::vector<bool> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendCTCOcc)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::vector<bool> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrackModelAuth)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrackModelSwitches)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::vector<std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrainDispatch)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendCTCHeater)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::activateCrossing)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendThroughput)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendMaintenace)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TrainEntry, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
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
        if (_id < 28)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 28;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 28)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 28;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sendCTCOcc(std::vector<bool> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sendTrackModelAuth(std::vector<bool> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainWindow::sendTrackModelSwitches(std::vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sendTrainDispatch(std::vector<std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sendCTCHeater(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::activateCrossing(vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::sendThroughput(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::sendMaintenace(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
