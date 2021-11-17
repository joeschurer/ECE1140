/****************************************************************************
** Meta object code from reading C++ file 'trackmodel.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/trackmodel.h"
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
    const uint offsetsAndSize[52];
    char stringdata0[302];
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
QT_MOC_LITERAL(114, 3), // "occ"
QT_MOC_LITERAL(118, 10), // "beaconData"
QT_MOC_LITERAL(129, 6), // "string"
QT_MOC_LITERAL(136, 7), // "timeout"
QT_MOC_LITERAL(144, 10), // "trainMoved"
QT_MOC_LITERAL(155, 8), // "trainNum"
QT_MOC_LITERAL(164, 18), // "actualSpeedChanged"
QT_MOC_LITERAL(183, 4), // "item"
QT_MOC_LITERAL(188, 12), // "trainUpdated"
QT_MOC_LITERAL(201, 12), // "toggleSwitch"
QT_MOC_LITERAL(214, 2), // "sw"
QT_MOC_LITERAL(217, 27), // "on_breakCircuit_textChanged"
QT_MOC_LITERAL(245, 4), // "arg1"
QT_MOC_LITERAL(250, 25), // "on_breakTrack_textChanged"
QT_MOC_LITERAL(276, 25) // "on_breakPower_textChanged"

    },
    "TrackModel\0newBlock\0vector<int>\0\0data\0"
    "newTrainData\0vector<string>\0newData\0"
    "passengersChanged\0pass\0occupancyChanged\0"
    "occ\0beaconData\0string\0timeout\0trainMoved\0"
    "trainNum\0actualSpeedChanged\0item\0"
    "trainUpdated\0toggleSwitch\0sw\0"
    "on_breakCircuit_textChanged\0arg1\0"
    "on_breakTrack_textChanged\0"
    "on_breakPower_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TrackModel[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   92,    3, 0x06,    1 /* Public */,
       5,    1,   95,    3, 0x06,    3 /* Public */,
       8,    1,   98,    3, 0x06,    5 /* Public */,
      10,    1,  101,    3, 0x06,    7 /* Public */,
      12,    1,  104,    3, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      14,    0,  107,    3, 0x0a,   11 /* Public */,
      15,    1,  108,    3, 0x0a,   12 /* Public */,
      17,    1,  111,    3, 0x0a,   14 /* Public */,
      19,    1,  114,    3, 0x0a,   16 /* Public */,
      20,    1,  117,    3, 0x0a,   18 /* Public */,
      22,    1,  120,    3, 0x08,   20 /* Private */,
      24,    1,  123,    3, 0x08,   22 /* Private */,
      25,    1,  126,    3, 0x08,   24 /* Private */,

 // signals: parameters
    0x80000000 | 2, 0x80000000 | 2,    4,
    0x80000000 | 6, 0x80000000 | 6,    7,
    0x80000000 | 2, 0x80000000 | 2,    9,
    0x80000000 | 2, 0x80000000 | 2,   11,
    0x80000000 | 13, 0x80000000 | 13,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void, 0x80000000 | 6,   18,
    QMetaType::Void, 0x80000000 | 2,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   23,

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
        case 3: { vector<int> _r = _t->occupancyChanged((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 4: { string _r = _t->beaconData((*reinterpret_cast< string(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< string*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->timeout(); break;
        case 6: _t->trainMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->actualSpeedChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->trainUpdated((*reinterpret_cast< vector<string>(*)>(_a[1]))); break;
        case 9: _t->toggleSwitch((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 10: _t->on_breakCircuit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_breakTrack_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->on_breakPower_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
            using _t = vector<int> (TrackModel::*)(vector<int> );
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
    }
}

const QMetaObject TrackModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_TrackModel.offsetsAndSize,
    qt_meta_data_TrackModel,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_TrackModel_t
, QtPrivate::TypeAndForceComplete<TrackModel, std::true_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>, QtPrivate::TypeAndForceComplete<string, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 13;
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
vector<int> TrackModel::occupancyChanged(vector<int> _t1)
{
    vector<int> _t0{};
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
