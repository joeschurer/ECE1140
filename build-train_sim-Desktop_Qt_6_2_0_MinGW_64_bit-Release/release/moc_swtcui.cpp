/****************************************************************************
** Meta object code from reading C++ file 'swtcui.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/swtcui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'swtcui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SWTCUI_t {
    const uint offsetsAndSize[78];
    char stringdata0[572];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_SWTCUI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_SWTCUI_t qt_meta_stringdata_SWTCUI = {
    {
QT_MOC_LITERAL(0, 6), // "SWTCUI"
QT_MOC_LITERAL(7, 17), // "SetSpeedDifferent"
QT_MOC_LITERAL(25, 0), // ""
QT_MOC_LITERAL(26, 5), // "speed"
QT_MOC_LITERAL(32, 15), // "LightsDifferent"
QT_MOC_LITERAL(48, 5), // "state"
QT_MOC_LITERAL(54, 18), // "LeftDoorsDifferent"
QT_MOC_LITERAL(73, 19), // "RightDoorsDifferent"
QT_MOC_LITERAL(93, 13), // "TempDifferent"
QT_MOC_LITERAL(107, 4), // "temp"
QT_MOC_LITERAL(112, 23), // "EmergencyBrakeDifferent"
QT_MOC_LITERAL(136, 22), // "AutomaticModeDifferent"
QT_MOC_LITERAL(159, 15), // "PowerCalculated"
QT_MOC_LITERAL(175, 5), // "power"
QT_MOC_LITERAL(181, 18), // "DestinationChanged"
QT_MOC_LITERAL(200, 11), // "std::string"
QT_MOC_LITERAL(212, 11), // "destination"
QT_MOC_LITERAL(224, 15), // "DistanceChanged"
QT_MOC_LITERAL(240, 8), // "distance"
QT_MOC_LITERAL(249, 11), // "TimeChanged"
QT_MOC_LITERAL(261, 4), // "time"
QT_MOC_LITERAL(266, 17), // "SpeedLimitChanged"
QT_MOC_LITERAL(284, 21), // "CommandedSpeedChanged"
QT_MOC_LITERAL(306, 19), // "CurrentSpeedChanged"
QT_MOC_LITERAL(326, 21), // "EmergencyBrakeChanged"
QT_MOC_LITERAL(348, 14), // "FailureChanged"
QT_MOC_LITERAL(363, 11), // "KpKiChanged"
QT_MOC_LITERAL(375, 2), // "Kp"
QT_MOC_LITERAL(378, 2), // "Ki"
QT_MOC_LITERAL(381, 16), // "PlusSpeedPressed"
QT_MOC_LITERAL(398, 17), // "MinusSpeedPressed"
QT_MOC_LITERAL(416, 15), // "PlusTempPressed"
QT_MOC_LITERAL(432, 16), // "MinusTempPressed"
QT_MOC_LITERAL(449, 24), // "OperateRightDoorsPressed"
QT_MOC_LITERAL(474, 23), // "OperateLeftDoorsPressed"
QT_MOC_LITERAL(498, 19), // "LightsButtonPressed"
QT_MOC_LITERAL(518, 26), // "AutomaticModeButtonPressed"
QT_MOC_LITERAL(545, 12), // "BrakePressed"
QT_MOC_LITERAL(558, 13) // "EBrakePressed"

    },
    "SWTCUI\0SetSpeedDifferent\0\0speed\0"
    "LightsDifferent\0state\0LeftDoorsDifferent\0"
    "RightDoorsDifferent\0TempDifferent\0"
    "temp\0EmergencyBrakeDifferent\0"
    "AutomaticModeDifferent\0PowerCalculated\0"
    "power\0DestinationChanged\0std::string\0"
    "destination\0DistanceChanged\0distance\0"
    "TimeChanged\0time\0SpeedLimitChanged\0"
    "CommandedSpeedChanged\0CurrentSpeedChanged\0"
    "EmergencyBrakeChanged\0FailureChanged\0"
    "KpKiChanged\0Kp\0Ki\0PlusSpeedPressed\0"
    "MinusSpeedPressed\0PlusTempPressed\0"
    "MinusTempPressed\0OperateRightDoorsPressed\0"
    "OperateLeftDoorsPressed\0LightsButtonPressed\0"
    "AutomaticModeButtonPressed\0BrakePressed\0"
    "EBrakePressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SWTCUI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  176,    2, 0x06,    1 /* Public */,
       4,    1,  179,    2, 0x06,    3 /* Public */,
       6,    1,  182,    2, 0x06,    5 /* Public */,
       7,    1,  185,    2, 0x06,    7 /* Public */,
       8,    1,  188,    2, 0x06,    9 /* Public */,
      10,    1,  191,    2, 0x06,   11 /* Public */,
      11,    1,  194,    2, 0x06,   13 /* Public */,
      12,    1,  197,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,  200,    2, 0x0a,   17 /* Public */,
      17,    1,  203,    2, 0x0a,   19 /* Public */,
      19,    1,  206,    2, 0x0a,   21 /* Public */,
      21,    1,  209,    2, 0x0a,   23 /* Public */,
      22,    1,  212,    2, 0x0a,   25 /* Public */,
      23,    1,  215,    2, 0x0a,   27 /* Public */,
      24,    1,  218,    2, 0x0a,   29 /* Public */,
      25,    1,  221,    2, 0x0a,   31 /* Public */,
      26,    2,  224,    2, 0x0a,   33 /* Public */,
      29,    0,  229,    2, 0x08,   36 /* Private */,
      30,    0,  230,    2, 0x08,   37 /* Private */,
      31,    0,  231,    2, 0x08,   38 /* Private */,
      32,    0,  232,    2, 0x08,   39 /* Private */,
      33,    0,  233,    2, 0x08,   40 /* Private */,
      34,    0,  234,    2, 0x08,   41 /* Private */,
      35,    0,  235,    2, 0x08,   42 /* Private */,
      36,    0,  236,    2, 0x08,   43 /* Private */,
      37,    0,  237,    2, 0x08,   44 /* Private */,
      38,    0,  238,    2, 0x08,   45 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void, QMetaType::Int,   13,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   18,
    QMetaType::Void, 0x80000000 | 15,   20,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 15,    5,
    QMetaType::Void, 0x80000000 | 15,    5,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   27,   28,
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

       0        // eod
};

void SWTCUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SWTCUI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SetSpeedDifferent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->LightsDifferent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->LeftDoorsDifferent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->RightDoorsDifferent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->TempDifferent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->EmergencyBrakeDifferent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->AutomaticModeDifferent((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->PowerCalculated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->DestinationChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 9: _t->DistanceChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: _t->TimeChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 11: _t->SpeedLimitChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->CommandedSpeedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->CurrentSpeedChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->EmergencyBrakeChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 15: _t->FailureChanged((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 16: _t->KpKiChanged((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 17: _t->PlusSpeedPressed(); break;
        case 18: _t->MinusSpeedPressed(); break;
        case 19: _t->PlusTempPressed(); break;
        case 20: _t->MinusTempPressed(); break;
        case 21: _t->OperateRightDoorsPressed(); break;
        case 22: _t->OperateLeftDoorsPressed(); break;
        case 23: _t->LightsButtonPressed(); break;
        case 24: _t->AutomaticModeButtonPressed(); break;
        case 25: _t->BrakePressed(); break;
        case 26: _t->EBrakePressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SWTCUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::SetSpeedDifferent)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::LightsDifferent)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::LeftDoorsDifferent)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::RightDoorsDifferent)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::TempDifferent)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::EmergencyBrakeDifferent)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::AutomaticModeDifferent)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SWTCUI::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SWTCUI::PowerCalculated)) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject SWTCUI::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_SWTCUI.offsetsAndSize,
    qt_meta_data_SWTCUI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_SWTCUI_t
, QtPrivate::TypeAndForceComplete<SWTCUI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::string, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *SWTCUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SWTCUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SWTCUI.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SWTCUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void SWTCUI::SetSpeedDifferent(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SWTCUI::LightsDifferent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SWTCUI::LeftDoorsDifferent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SWTCUI::RightDoorsDifferent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SWTCUI::TempDifferent(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SWTCUI::EmergencyBrakeDifferent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SWTCUI::AutomaticModeDifferent(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SWTCUI::PowerCalculated(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
