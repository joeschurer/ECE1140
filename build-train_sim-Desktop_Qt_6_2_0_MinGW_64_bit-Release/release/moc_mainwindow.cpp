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
    const uint offsetsAndSize[84];
    char stringdata0[634];
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
QT_MOC_LITERAL(100, 23), // "sendTrackModelCrossings"
QT_MOC_LITERAL(124, 20), // "sendTrackModelLights"
QT_MOC_LITERAL(145, 17), // "sendTrainDispatch"
QT_MOC_LITERAL(163, 24), // "std::vector<std::string>"
QT_MOC_LITERAL(188, 13), // "sendCTCHeater"
QT_MOC_LITERAL(202, 16), // "activateCrossing"
QT_MOC_LITERAL(219, 11), // "vector<int>"
QT_MOC_LITERAL(231, 14), // "sendThroughput"
QT_MOC_LITERAL(246, 9), // "sendFixed"
QT_MOC_LITERAL(256, 14), // "sendMaintenace"
QT_MOC_LITERAL(271, 12), // "vector<bool>"
QT_MOC_LITERAL(284, 14), // "upload_clicked"
QT_MOC_LITERAL(299, 8), // "sel_line"
QT_MOC_LITERAL(308, 9), // "sel_block"
QT_MOC_LITERAL(318, 11), // "sel_wayside"
QT_MOC_LITERAL(330, 8), // "ctc_test"
QT_MOC_LITERAL(339, 15), // "check_ctc_lines"
QT_MOC_LITERAL(355, 17), // "check_track_lines"
QT_MOC_LITERAL(373, 17), // "check_heater_line"
QT_MOC_LITERAL(391, 10), // "track_test"
QT_MOC_LITERAL(402, 12), // "track_heater"
QT_MOC_LITERAL(415, 22), // "check_maintenance_line"
QT_MOC_LITERAL(438, 23), // "on_uploadButton_clicked"
QT_MOC_LITERAL(462, 29), // "on_maintenance_submit_clicked"
QT_MOC_LITERAL(492, 29), // "on_maintenance_toggle_clicked"
QT_MOC_LITERAL(522, 10), // "receiveOcc"
QT_MOC_LITERAL(533, 3), // "occ"
QT_MOC_LITERAL(537, 13), // "receiveHeater"
QT_MOC_LITERAL(551, 11), // "recieveAuth"
QT_MOC_LITERAL(563, 10), // "TrainEntry"
QT_MOC_LITERAL(574, 17), // "getMaintenaceMode"
QT_MOC_LITERAL(592, 6), // "blocks"
QT_MOC_LITERAL(599, 12), // "changeSwitch"
QT_MOC_LITERAL(612, 3), // "pos"
QT_MOC_LITERAL(616, 17) // "receiveThroughput"

    },
    "MainWindow\0sendCTCOcc\0\0std::vector<bool>\0"
    "sendTrackModelAuth\0sendTrackModelSwitches\0"
    "std::vector<int>\0sendTrackModelCrossings\0"
    "sendTrackModelLights\0sendTrainDispatch\0"
    "std::vector<std::string>\0sendCTCHeater\0"
    "activateCrossing\0vector<int>\0"
    "sendThroughput\0sendFixed\0sendMaintenace\0"
    "vector<bool>\0upload_clicked\0sel_line\0"
    "sel_block\0sel_wayside\0ctc_test\0"
    "check_ctc_lines\0check_track_lines\0"
    "check_heater_line\0track_test\0track_heater\0"
    "check_maintenance_line\0on_uploadButton_clicked\0"
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
      31,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  200,    2, 0x06,    1 /* Public */,
       4,    1,  203,    2, 0x06,    3 /* Public */,
       5,    1,  206,    2, 0x06,    5 /* Public */,
       7,    1,  209,    2, 0x06,    7 /* Public */,
       8,    1,  212,    2, 0x06,    9 /* Public */,
       9,    1,  215,    2, 0x06,   11 /* Public */,
      11,    1,  218,    2, 0x06,   13 /* Public */,
      12,    1,  221,    2, 0x06,   15 /* Public */,
      14,    1,  224,    2, 0x06,   17 /* Public */,
      15,    1,  227,    2, 0x06,   19 /* Public */,
      16,    1,  230,    2, 0x06,   21 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      18,    0,  233,    2, 0x08,   23 /* Private */,
      19,    0,  234,    2, 0x08,   24 /* Private */,
      20,    0,  235,    2, 0x08,   25 /* Private */,
      21,    0,  236,    2, 0x08,   26 /* Private */,
      22,    0,  237,    2, 0x08,   27 /* Private */,
      23,    0,  238,    2, 0x08,   28 /* Private */,
      24,    0,  239,    2, 0x08,   29 /* Private */,
      25,    0,  240,    2, 0x08,   30 /* Private */,
      26,    0,  241,    2, 0x08,   31 /* Private */,
      27,    0,  242,    2, 0x08,   32 /* Private */,
      28,    0,  243,    2, 0x08,   33 /* Private */,
      29,    0,  244,    2, 0x08,   34 /* Private */,
      30,    0,  245,    2, 0x08,   35 /* Private */,
      31,    0,  246,    2, 0x08,   36 /* Private */,
      32,    1,  247,    2, 0x0a,   37 /* Public */,
      34,    1,  250,    2, 0x0a,   39 /* Public */,
      35,    1,  253,    2, 0x0a,   41 /* Public */,
      37,    1,  256,    2, 0x0a,   43 /* Public */,
      39,    1,  259,    2, 0x0a,   45 /* Public */,
      41,    1,  262,    2, 0x0a,   47 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 17,    2,

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
    QMetaType::Void, 0x80000000 | 3,   33,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, 0x80000000 | 3,   38,
    QMetaType::Void, 0x80000000 | 6,   40,
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
        case 3: _t->sendTrackModelCrossings((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 4: _t->sendTrackModelLights((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 5: _t->sendTrainDispatch((*reinterpret_cast< std::vector<std::string>(*)>(_a[1]))); break;
        case 6: _t->sendCTCHeater((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->activateCrossing((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 8: _t->sendThroughput((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->sendFixed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->sendMaintenace((*reinterpret_cast< vector<bool>(*)>(_a[1]))); break;
        case 11: _t->upload_clicked(); break;
        case 12: _t->sel_line(); break;
        case 13: _t->sel_block(); break;
        case 14: _t->sel_wayside(); break;
        case 15: _t->ctc_test(); break;
        case 16: _t->check_ctc_lines(); break;
        case 17: _t->check_track_lines(); break;
        case 18: _t->check_heater_line(); break;
        case 19: _t->track_test(); break;
        case 20: _t->track_heater(); break;
        case 21: _t->check_maintenance_line(); break;
        case 22: _t->on_uploadButton_clicked(); break;
        case 23: _t->on_maintenance_submit_clicked(); break;
        case 24: _t->on_maintenance_toggle_clicked(); break;
        case 25: _t->receiveOcc((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 26: _t->receiveHeater((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->recieveAuth((*reinterpret_cast< TrainEntry(*)>(_a[1]))); break;
        case 28: _t->getMaintenaceMode((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 29: _t->changeSwitch((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
        case 30: _t->receiveThroughput((*reinterpret_cast< int(*)>(_a[1]))); break;
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
            using _t = void (MainWindow::*)(std::vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrackModelCrossings)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrackModelLights)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(std::vector<std::string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendTrainDispatch)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendCTCHeater)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::activateCrossing)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendThroughput)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendFixed)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(vector<bool> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendMaintenace)) {
                *result = 10;
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
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<std::string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<bool>, std::false_type>
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
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
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
void MainWindow::sendTrackModelCrossings(std::vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sendTrackModelLights(std::vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::sendTrainDispatch(std::vector<std::string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::sendCTCHeater(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::activateCrossing(vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void MainWindow::sendThroughput(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void MainWindow::sendFixed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void MainWindow::sendMaintenace(vector<bool> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE