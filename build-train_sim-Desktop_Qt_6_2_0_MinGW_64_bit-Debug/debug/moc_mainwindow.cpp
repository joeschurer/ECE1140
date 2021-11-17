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
    const uint offsetsAndSize[58];
    char stringdata0[412];
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
QT_MOC_LITERAL(100, 14), // "upload_clicked"
QT_MOC_LITERAL(115, 8), // "sel_line"
QT_MOC_LITERAL(124, 9), // "sel_block"
QT_MOC_LITERAL(134, 11), // "sel_wayside"
QT_MOC_LITERAL(146, 8), // "ctc_test"
QT_MOC_LITERAL(155, 15), // "check_ctc_lines"
QT_MOC_LITERAL(171, 17), // "check_track_lines"
QT_MOC_LITERAL(189, 17), // "check_heater_line"
QT_MOC_LITERAL(207, 10), // "track_test"
QT_MOC_LITERAL(218, 12), // "track_heater"
QT_MOC_LITERAL(231, 22), // "check_maintenance_line"
QT_MOC_LITERAL(254, 23), // "on_uploadButton_clicked"
QT_MOC_LITERAL(278, 29), // "on_maintenance_submit_clicked"
QT_MOC_LITERAL(308, 29), // "on_maintenance_toggle_clicked"
QT_MOC_LITERAL(338, 10), // "receiveOcc"
QT_MOC_LITERAL(349, 3), // "occ"
QT_MOC_LITERAL(353, 11), // "recieveAuth"
QT_MOC_LITERAL(365, 4), // "auth"
QT_MOC_LITERAL(370, 17), // "getMaintenaceMode"
QT_MOC_LITERAL(388, 6), // "blocks"
QT_MOC_LITERAL(395, 12), // "changeSwitch"
QT_MOC_LITERAL(408, 3) // "pos"

    },
    "MainWindow\0sendCTCOcc\0\0std::vector<bool>\0"
    "sendTrackModelAuth\0sendTrackModelSwitches\0"
    "std::vector<int>\0upload_clicked\0"
    "sel_line\0sel_block\0sel_wayside\0ctc_test\0"
    "check_ctc_lines\0check_track_lines\0"
    "check_heater_line\0track_test\0track_heater\0"
    "check_maintenance_line\0on_uploadButton_clicked\0"
    "on_maintenance_submit_clicked\0"
    "on_maintenance_toggle_clicked\0receiveOcc\0"
    "occ\0recieveAuth\0auth\0getMaintenaceMode\0"
    "blocks\0changeSwitch\0pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  140,    2, 0x06,    1 /* Public */,
       4,    1,  143,    2, 0x06,    3 /* Public */,
       5,    1,  146,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,  149,    2, 0x08,    7 /* Private */,
       8,    0,  150,    2, 0x08,    8 /* Private */,
       9,    0,  151,    2, 0x08,    9 /* Private */,
      10,    0,  152,    2, 0x08,   10 /* Private */,
      11,    0,  153,    2, 0x08,   11 /* Private */,
      12,    0,  154,    2, 0x08,   12 /* Private */,
      13,    0,  155,    2, 0x08,   13 /* Private */,
      14,    0,  156,    2, 0x08,   14 /* Private */,
      15,    0,  157,    2, 0x08,   15 /* Private */,
      16,    0,  158,    2, 0x08,   16 /* Private */,
      17,    0,  159,    2, 0x08,   17 /* Private */,
      18,    0,  160,    2, 0x08,   18 /* Private */,
      19,    0,  161,    2, 0x08,   19 /* Private */,
      20,    0,  162,    2, 0x08,   20 /* Private */,
      21,    1,  163,    2, 0x0a,   21 /* Public */,
      23,    1,  166,    2, 0x0a,   23 /* Public */,
      25,    1,  169,    2, 0x0a,   25 /* Public */,
      27,    1,  172,    2, 0x0a,   27 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 6,    2,

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
    QMetaType::Void, 0x80000000 | 3,   22,
    QMetaType::Void, 0x80000000 | 3,   24,
    QMetaType::Void, 0x80000000 | 3,   26,
    QMetaType::Void, 0x80000000 | 6,   28,

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
        case 3: _t->upload_clicked(); break;
        case 4: _t->sel_line(); break;
        case 5: _t->sel_block(); break;
        case 6: _t->sel_wayside(); break;
        case 7: _t->ctc_test(); break;
        case 8: _t->check_ctc_lines(); break;
        case 9: _t->check_track_lines(); break;
        case 10: _t->check_heater_line(); break;
        case 11: _t->track_test(); break;
        case 12: _t->track_heater(); break;
        case 13: _t->check_maintenance_line(); break;
        case 14: _t->on_uploadButton_clicked(); break;
        case 15: _t->on_maintenance_submit_clicked(); break;
        case 16: _t->on_maintenance_toggle_clicked(); break;
        case 17: _t->receiveOcc((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 18: _t->recieveAuth((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 19: _t->getMaintenaceMode((*reinterpret_cast< std::vector<bool>(*)>(_a[1]))); break;
        case 20: _t->changeSwitch((*reinterpret_cast< std::vector<int>(*)>(_a[1]))); break;
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
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<int>, std::false_type>


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
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
