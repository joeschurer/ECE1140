/****************************************************************************
** Meta object code from reading C++ file 'trackmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../train_sim/trackmodel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trackmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrackModel_t {
    const uint offsetsAndSize[66];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrackModel_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrackModel_t qt_meta_stringdata_TrackModel = {
    {
QT_MOC_LITERAL(0, 10), // "TrackModel"
QT_MOC_LITERAL(11, 8), // "newBlock"
QT_MOC_LITERAL(20, 11), // "vector<int>"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 4), // "data"
QT_MOC_LITERAL(38, 12), // "newTrainData"
QT_MOC_LITERAL(51, 14), // "vector<string>"
QT_MOC_LITERAL(66, 7), // "newData"
QT_MOC_LITERAL(74, 17), // "passengersChanged"
QT_MOC_LITERAL(92, 4), // "pass"
QT_MOC_LITERAL(97, 16), // "occupancyChanged"
QT_MOC_LITERAL(114, 12), // "vector<bool>"
QT_MOC_LITERAL(127, 3), // "occ"
QT_MOC_LITERAL(131, 10), // "beaconData"
QT_MOC_LITERAL(142, 6), // "string"
QT_MOC_LITERAL(149, 11), // "tempChanged"
QT_MOC_LITERAL(161, 4), // "temp"
QT_MOC_LITERAL(166, 10), // "trainMoved"
QT_MOC_LITERAL(177, 8), // "trainNum"
QT_MOC_LITERAL(186, 18), // "actualSpeedChanged"
QT_MOC_LITERAL(205, 4), // "item"
QT_MOC_LITERAL(210, 12), // "trainUpdated"
QT_MOC_LITERAL(223, 12), // "toggleSwitch"
QT_MOC_LITERAL(236, 2), // "sw"
QT_MOC_LITERAL(239, 14), // "toggleCrossing"
QT_MOC_LITERAL(254, 5), // "cross"
QT_MOC_LITERAL(260, 9), // "doorsOpen"
QT_MOC_LITERAL(270, 9), // "openDoors"
QT_MOC_LITERAL(280, 5), // "train"
QT_MOC_LITERAL(286, 29), // "on_breakCircuit_returnPressed"
QT_MOC_LITERAL(316, 27), // "on_breakTrack_returnPressed"
QT_MOC_LITERAL(344, 27), // "on_breakPower_returnPressed"
QT_MOC_LITERAL(372, 24) // "on_setTemp_returnPressed"

    },
    "TrackModel\0newBlock\0vector<int>\0\0data\0"
    "newTrainData\0vector<string>\0newData\0"
    "passengersChanged\0pass\0occupancyChanged\0"
    "vector<bool>\0occ\0beaconData\0string\0"
    "tempChanged\0temp\0trainMoved\0trainNum\0"
    "actualSpeedChanged\0item\0trainUpdated\0"
    "toggleSwitch\0sw\0toggleCrossing\0cross\0"
    "doorsOpen\0openDoors\0train\0"
    "on_breakCircuit_returnPressed\0"
    "on_breakTrack_returnPressed\0"
    "on_breakPower_returnPressed\0"
    "on_setTemp_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  116,    3, 0x06,    1 /* Public */,
       5,    1,  119,    3, 0x06,    3 /* Public */,
       8,    1,  122,    3, 0x06,    5 /* Public */,
      10,    1,  125,    3, 0x06,    7 /* Public */,
      13,    1,  128,    3, 0x06,    9 /* Public */,
      15,    1,  131,    3, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      17,    1,  134,    3, 0x0a,   13 /* Public */,
      19,    1,  137,    3, 0x0a,   15 /* Public */,
      21,    1,  140,    3, 0x0a,   17 /* Public */,
      22,    1,  143,    3, 0x0a,   19 /* Public */,
      24,    1,  146,    3, 0x0a,   21 /* Public */,
      26,    1,  149,    3, 0x0a,   23 /* Public */,
      27,    1,  152,    3, 0x0a,   25 /* Public */,
      29,    0,  155,    3, 0x08,   27 /* Private */,
      30,    0,  156,    3, 0x08,   28 /* Private */,
      31,    0,  157,    3, 0x08,   29 /* Private */,
      32,    0,  158,    3, 0x08,   30 /* Private */,

 // signals: parameters
    0x80000000 | 2, 0x80000000 | 2,    4,
    0x80000000 | 6, 0x80000000 | 6,    7,
    0x80000000 | 2, 0x80000000 | 2,    9,
    0x80000000 | 11, 0x80000000 | 11,   12,
    0x80000000 | 14, 0x80000000 | 14,    4,
    QMetaType::Double, QMetaType::Double,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, 0x80000000 | 6,   20,
    QMetaType::Void, 0x80000000 | 2,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, 0x80000000 | 2,   28,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void TrackModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrackModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { vector<int> _r = _t->newBlock((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 1: { vector<string> _r = _t->newTrainData((*reinterpret_cast< vector<string>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<string>*>(_a[0]) = std::move(_r); }  break;
        case 2: { vector<int> _r = _t->passengersChanged((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 3: { vector<bool> _r = _t->occupancyChanged((*reinterpret_cast< vector<bool>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<bool>*>(_a[0]) = std::move(_r); }  break;
        case 4: { string _r = _t->beaconData((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 5: { double _r = _t->tempChanged((*reinterpret_cast< double(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->trainMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->actualSpeedChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->trainUpdated((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 9: _t->toggleSwitch((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 10: _t->toggleCrossing((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->doorsOpen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->openDoors((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 13: _t->on_breakCircuit_returnPressed(); break;
        case 14: _t->on_breakTrack_returnPressed(); break;
        case 15: _t->on_breakPower_returnPressed(); break;
        case 16: _t->on_setTemp_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = vector<int> (TrackModel::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::newBlock)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = vector<string> (TrackModel::*)(vector<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::newTrainData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = vector<int> (TrackModel::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::passengersChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = vector<bool> (TrackModel::*)(vector<bool> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::occupancyChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = string (TrackModel::*)(string );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::beaconData)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = double (TrackModel::*)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrackModel::tempChanged)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject TrackModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrackModel.offsetsAndSize,
    qt_meta_data_TrackModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrackModel_t
, QtPrivate::TypeAndForceComplete<TrackModel, std::true_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrackModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrackModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrackModel.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrackModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
vector<int> TrackModel::newBlock(vector<int> _t1)
{
    vector<int> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
vector<string> TrackModel::newTrainData(vector<string> _t1)
{
    vector<string> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
vector<int> TrackModel::passengersChanged(vector<int> _t1)
{
    vector<int> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
vector<bool> TrackModel::occupancyChanged(vector<bool> _t1)
{
    vector<bool> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}

// SIGNAL 4
string TrackModel::beaconData(string _t1)
{
    string _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
    return _t0;
}

// SIGNAL 5
double TrackModel::tempChanged(double _t1)
{
    double _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
