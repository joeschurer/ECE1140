/****************************************************************************
** Meta object code from reading C++ file 'trainfactory.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/trainfactory.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trainfactory.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TrainFactory_t {
    const uint offsetsAndSize[32];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_TrainFactory_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_TrainFactory_t qt_meta_stringdata_TrainFactory = {
    {
QT_MOC_LITERAL(0, 12), // "TrainFactory"
QT_MOC_LITERAL(13, 16), // "commandedSpeedTC"
QT_MOC_LITERAL(30, 0), // ""
QT_MOC_LITERAL(31, 2), // "id"
QT_MOC_LITERAL(34, 6), // "cSpeed"
QT_MOC_LITERAL(41, 12), // "passOffTrain"
QT_MOC_LITERAL(54, 11), // "vector<int>"
QT_MOC_LITERAL(66, 10), // "beaconToTC"
QT_MOC_LITERAL(77, 14), // "vector<string>"
QT_MOC_LITERAL(92, 13), // "dispatchTrain"
QT_MOC_LITERAL(106, 13), // "receiveSignal"
QT_MOC_LITERAL(120, 18), // "boardingPassengers"
QT_MOC_LITERAL(139, 13), // "receiveBeacon"
QT_MOC_LITERAL(153, 17), // "temperatureChange"
QT_MOC_LITERAL(171, 18), // "receiveStationInfo"
QT_MOC_LITERAL(190, 6) // "string"

    },
    "TrainFactory\0commandedSpeedTC\0\0id\0"
    "cSpeed\0passOffTrain\0vector<int>\0"
    "beaconToTC\0vector<string>\0dispatchTrain\0"
    "receiveSignal\0boardingPassengers\0"
    "receiveBeacon\0temperatureChange\0"
    "receiveStationInfo\0string"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrainFactory[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       5,    1,   73,    2, 0x06,    4 /* Public */,
       7,    1,   76,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    1,   79,    2, 0x0a,    8 /* Public */,
      10,    1,   82,    2, 0x0a,   10 /* Public */,
      11,    1,   85,    2, 0x0a,   12 /* Public */,
      12,    1,   88,    2, 0x0a,   14 /* Public */,
      13,    1,   91,    2, 0x0a,   16 /* Public */,
      14,    3,   94,    2, 0x0a,   18 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void, QMetaType::Double,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 15, 0x80000000 | 15,    2,    2,    2,

       0        // eod
};

void TrainFactory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TrainFactory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->commandedSpeedTC((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->passOffTrain((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 2: _t->beaconToTC((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 3: _t->dispatchTrain((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 4: _t->receiveSignal((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 5: _t->boardingPassengers((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 6: _t->receiveBeacon((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 7: _t->temperatureChange((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->receiveStationInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< string(*)>(_a[2])),(*reinterpret_cast< string(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TrainFactory::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainFactory::commandedSpeedTC)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TrainFactory::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainFactory::passOffTrain)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TrainFactory::*)(vector<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TrainFactory::beaconToTC)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject TrainFactory::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrainFactory.offsetsAndSize,
    qt_meta_data_TrainFactory,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrainFactory_t
, QtPrivate::TypeAndForceComplete<TrainFactory, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>


>,
    nullptr
} };


const QMetaObject *TrainFactory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TrainFactory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TrainFactory.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TrainFactory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void TrainFactory::commandedSpeedTC(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TrainFactory::passOffTrain(vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void TrainFactory::beaconToTC(vector<string> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
