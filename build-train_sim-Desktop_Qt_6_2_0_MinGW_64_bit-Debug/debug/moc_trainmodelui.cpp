/****************************************************************************
** Meta object code from reading C++ file 'trainmodelui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/trainmodelui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainmodelui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrainModelUI_t {
    const uint offsetsAndSize[96];
    char stringdata0[702];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrainModelUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrainModelUI_t qt_meta_stringdata_TrainModelUI = {
    {
QT_MOC_LITERAL(0, 12), // "TrainModelUI"
QT_MOC_LITERAL(13, 11), // "currSpeedTC"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 12), // "speedLimitTC"
QT_MOC_LITERAL(39, 6), // "speedL"
QT_MOC_LITERAL(46, 16), // "commandedSpeedTC"
QT_MOC_LITERAL(63, 6), // "cSpeed"
QT_MOC_LITERAL(70, 10), // "distLeftTC"
QT_MOC_LITERAL(81, 4), // "dist"
QT_MOC_LITERAL(86, 11), // "eBrakeSetTC"
QT_MOC_LITERAL(98, 5), // "state"
QT_MOC_LITERAL(104, 12), // "failureState"
QT_MOC_LITERAL(117, 4), // "mode"
QT_MOC_LITERAL(122, 9), // "currSpeed"
QT_MOC_LITERAL(132, 17), // "currentPassengers"
QT_MOC_LITERAL(150, 10), // "passengers"
QT_MOC_LITERAL(161, 21), // "on_toggleDoor_clicked"
QT_MOC_LITERAL(183, 23), // "on_toggleLights_clicked"
QT_MOC_LITERAL(207, 28), // "on_inputPowerConfirm_clicked"
QT_MOC_LITERAL(236, 25), // "on_emergencyBrake_clicked"
QT_MOC_LITERAL(262, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(286, 26), // "on_toggleDoorRight_clicked"
QT_MOC_LITERAL(313, 25), // "on_toggleDoorLeft_clicked"
QT_MOC_LITERAL(339, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(363, 23), // "on_pushButton_4_clicked"
QT_MOC_LITERAL(387, 12), // "receivePower"
QT_MOC_LITERAL(400, 5), // "power"
QT_MOC_LITERAL(406, 20), // "DestinationDifferent"
QT_MOC_LITERAL(427, 11), // "std::string"
QT_MOC_LITERAL(439, 11), // "destination"
QT_MOC_LITERAL(451, 17), // "DistanceDifferent"
QT_MOC_LITERAL(469, 8), // "distance"
QT_MOC_LITERAL(478, 13), // "TimeDifferent"
QT_MOC_LITERAL(492, 4), // "time"
QT_MOC_LITERAL(497, 19), // "SpeedLimitDifferent"
QT_MOC_LITERAL(517, 5), // "speed"
QT_MOC_LITERAL(523, 23), // "CommandedSpeedDifferent"
QT_MOC_LITERAL(547, 21), // "CurrentSpeedDifferent"
QT_MOC_LITERAL(569, 23), // "EmergencyBrakeDifferent"
QT_MOC_LITERAL(593, 16), // "FailureDifferent"
QT_MOC_LITERAL(610, 24), // "boardingPassengersFromTM"
QT_MOC_LITERAL(635, 13), // "numPassengers"
QT_MOC_LITERAL(649, 17), // "trackSignalFromTM"
QT_MOC_LITERAL(667, 6), // "meters"
QT_MOC_LITERAL(674, 5), // "grade"
QT_MOC_LITERAL(680, 5), // "limit"
QT_MOC_LITERAL(686, 4), // "comm"
QT_MOC_LITERAL(691, 10) // "updateTime"

    },
    "TrainModelUI\0currSpeedTC\0\0speedLimitTC\0"
    "speedL\0commandedSpeedTC\0cSpeed\0"
    "distLeftTC\0dist\0eBrakeSetTC\0state\0"
    "failureState\0mode\0currSpeed\0"
    "currentPassengers\0passengers\0"
    "on_toggleDoor_clicked\0on_toggleLights_clicked\0"
    "on_inputPowerConfirm_clicked\0"
    "on_emergencyBrake_clicked\0"
    "on_pushButton_3_clicked\0"
    "on_toggleDoorRight_clicked\0"
    "on_toggleDoorLeft_clicked\0"
    "on_pushButton_2_clicked\0on_pushButton_4_clicked\0"
    "receivePower\0power\0DestinationDifferent\0"
    "std::string\0destination\0DistanceDifferent\0"
    "distance\0TimeDifferent\0time\0"
    "SpeedLimitDifferent\0speed\0"
    "CommandedSpeedDifferent\0CurrentSpeedDifferent\0"
    "EmergencyBrakeDifferent\0FailureDifferent\0"
    "boardingPassengersFromTM\0numPassengers\0"
    "trackSignalFromTM\0meters\0grade\0limit\0"
    "comm\0updateTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainModelUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      29,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  188,    2, 0x06,    1 /* Public */,
       3,    1,  191,    2, 0x06,    3 /* Public */,
       5,    1,  194,    2, 0x06,    5 /* Public */,
       7,    1,  197,    2, 0x06,    7 /* Public */,
       9,    1,  200,    2, 0x06,    9 /* Public */,
      11,    1,  203,    2, 0x06,   11 /* Public */,
      13,    1,  206,    2, 0x06,   13 /* Public */,
      14,    1,  209,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      16,    0,  212,    2, 0x08,   17 /* Private */,
      17,    0,  213,    2, 0x08,   18 /* Private */,
      18,    0,  214,    2, 0x08,   19 /* Private */,
      19,    0,  215,    2, 0x08,   20 /* Private */,
      20,    0,  216,    2, 0x08,   21 /* Private */,
      21,    0,  217,    2, 0x08,   22 /* Private */,
      22,    0,  218,    2, 0x08,   23 /* Private */,
      23,    0,  219,    2, 0x08,   24 /* Private */,
      24,    0,  220,    2, 0x08,   25 /* Private */,
      25,    1,  221,    2, 0x0a,   26 /* Public */,
      27,    1,  224,    2, 0x0a,   28 /* Public */,
      30,    1,  227,    2, 0x0a,   30 /* Public */,
      32,    1,  230,    2, 0x0a,   32 /* Public */,
      34,    1,  233,    2, 0x0a,   34 /* Public */,
      36,    1,  236,    2, 0x0a,   36 /* Public */,
      37,    1,  239,    2, 0x0a,   38 /* Public */,
      38,    1,  242,    2, 0x0a,   40 /* Public */,
      39,    1,  245,    2, 0x0a,   42 /* Public */,
      40,    1,  248,    2, 0x0a,   44 /* Public */,
      42,    4,  251,    2, 0x0a,   46 /* Public */,
      47,    0,  260,    2, 0x0a,   51 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,   15,

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
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, 0x80000000 | 28,   29,
    QMetaType::Void, 0x80000000 | 28,   31,
    QMetaType::Void, 0x80000000 | 28,   33,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,   26,
    QMetaType::Void, 0x80000000 | 28,   10,
    QMetaType::Void, 0x80000000 | 28,   10,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   43,   44,   45,   46,
    QMetaType::Void,

       0        // eod
};

void TrainModelUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrainModelUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->currSpeedTC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->speedLimitTC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->commandedSpeedTC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->distLeftTC((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->eBrakeSetTC((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->failureState((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->currSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->currentPassengers((*reinterpret_cast< int(*)>(_a[1]))); break;
        //case 8: _t->on_toggleDoor_clicked(); break;
        case 9: _t->on_toggleLights_clicked(); break;
        case 10: _t->on_inputPowerConfirm_clicked(); break;
        case 11: _t->on_emergencyBrake_clicked(); break;
        case 12: _t->on_pushButton_3_clicked(); break;
        case 13: _t->on_toggleDoorRight_clicked(); break;
        case 14: _t->on_toggleDoorLeft_clicked(); break;
        case 15: _t->on_pushButton_2_clicked(); break;
        case 16: _t->on_pushButton_4_clicked(); break;
//        case 17: _t->receivePower((*reinterpret_cast< int(*)>(_a[1]))); break;
//        case 18: _t->DestinationDifferent((*reinterpret_cast< std::string(*)>(_a[1]))); break;
//        case 19: _t->DistanceDifferent((*reinterpret_cast< std::string(*)>(_a[1]))); break;
//        case 20: _t->TimeDifferent((*reinterpret_cast< std::string(*)>(_a[1]))); break;
//        case 21: _t->SpeedLimitDifferent((*reinterpret_cast< int(*)>(_a[1]))); break;
//        case 22: _t->CommandedSpeedDifferent((*reinterpret_cast< int(*)>(_a[1]))); break;
//        case 23: _t->CurrentSpeedDifferent((*reinterpret_cast< int(*)>(_a[1]))); break;
//        case 24: _t->EmergencyBrakeDifferent((*reinterpret_cast< std::string(*)>(_a[1]))); break;
//        case 25: _t->FailureDifferent((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 26: _t->boardingPassengersFromTM((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->trackSignalFromTM((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
//        case 28: _t->updateTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::currSpeedTC)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::speedLimitTC)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::commandedSpeedTC)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::distLeftTC)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::eBrakeSetTC)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::failureState)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::currSpeed)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TrainModelUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainModelUI::currentPassengers)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject TrainModelUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_TrainModelUI.offsetsAndSize,
    qt_meta_data_TrainModelUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrainModelUI_t
, QtPrivate::TypeAndForceComplete<TrainModelUI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrainModelUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainModelUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrainModelUI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TrainModelUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 29)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 29;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 29)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 29;
    }
    return _id;
}

// SIGNAL 0
void TrainModelUI::currSpeedTC(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrainModelUI::speedLimitTC(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrainModelUI::commandedSpeedTC(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void TrainModelUI::distLeftTC(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void TrainModelUI::eBrakeSetTC(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TrainModelUI::failureState(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TrainModelUI::currSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TrainModelUI::currentPassengers(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
