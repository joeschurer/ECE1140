/****************************************************************************
** Meta object code from reading C++ file 'HomepageWindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../CtcOffice/HomepageWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'HomepageWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HomepageWindow_t {
    const uint offsetsAndSize[60];
    char stringdata0[671];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_HomepageWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_HomepageWindow_t qt_meta_stringdata_HomepageWindow = {
    {
QT_MOC_LITERAL(0, 14), // "HomepageWindow"
QT_MOC_LITERAL(15, 16), // "sendClosedBlocks"
QT_MOC_LITERAL(32, 0), // ""
QT_MOC_LITERAL(33, 12), // "vector<bool>"
QT_MOC_LITERAL(46, 18), // "sendSwitchPosition"
QT_MOC_LITERAL(65, 11), // "vector<int>"
QT_MOC_LITERAL(77, 16), // "sendDispatchInfo"
QT_MOC_LITERAL(94, 10), // "TrainEntry"
QT_MOC_LITERAL(105, 16), // "receiveOccupancy"
QT_MOC_LITERAL(122, 9), // "occupancy"
QT_MOC_LITERAL(132, 9), // "timerSlot"
QT_MOC_LITERAL(142, 31), // "on_uploadScheduleButton_clicked"
QT_MOC_LITERAL(174, 16), // "updateTrainTable"
QT_MOC_LITERAL(191, 24), // "std::list<ScheduleEntry>"
QT_MOC_LITERAL(216, 8), // "schedule"
QT_MOC_LITERAL(225, 50), // "std::unordered_map<int,std::v..."
QT_MOC_LITERAL(276, 19), // "updateTrainComboBox"
QT_MOC_LITERAL(296, 21), // "on_plusButton_clicked"
QT_MOC_LITERAL(318, 32), // "on_addTrackSectionButton_clicked"
QT_MOC_LITERAL(351, 39), // "on_maintenanceModeCheckBox_st..."
QT_MOC_LITERAL(391, 4), // "arg1"
QT_MOC_LITERAL(396, 30), // "on_testInterfaceButton_clicked"
QT_MOC_LITERAL(427, 25), // "on_homepageButton_clicked"
QT_MOC_LITERAL(453, 29), // "on_manageTrainsButton_clicked"
QT_MOC_LITERAL(483, 29), // "on_manageTracksButton_clicked"
QT_MOC_LITERAL(513, 37), // "on_submitTestTrackInputButton..."
QT_MOC_LITERAL(551, 37), // "on_submitTestTrainInputButton..."
QT_MOC_LITERAL(589, 26), // "on_addSwitchButton_clicked"
QT_MOC_LITERAL(616, 25), // "on_dispatchButton_clicked"
QT_MOC_LITERAL(642, 28) // "on_submitBlockButton_clicked"

    },
    "HomepageWindow\0sendClosedBlocks\0\0"
    "vector<bool>\0sendSwitchPosition\0"
    "vector<int>\0sendDispatchInfo\0TrainEntry\0"
    "receiveOccupancy\0occupancy\0timerSlot\0"
    "on_uploadScheduleButton_clicked\0"
    "updateTrainTable\0std::list<ScheduleEntry>\0"
    "schedule\0std::unordered_map<int,std::vector<ScheduleEntry>>\0"
    "updateTrainComboBox\0on_plusButton_clicked\0"
    "on_addTrackSectionButton_clicked\0"
    "on_maintenanceModeCheckBox_stateChanged\0"
    "arg1\0on_testInterfaceButton_clicked\0"
    "on_homepageButton_clicked\0"
    "on_manageTrainsButton_clicked\0"
    "on_manageTracksButton_clicked\0"
    "on_submitTestTrackInputButton_clicked\0"
    "on_submitTestTrainInputButton_clicked\0"
    "on_addSwitchButton_clicked\0"
    "on_dispatchButton_clicked\0"
    "on_submitBlockButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HomepageWindow[] = {

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
       6,    1,  146,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,  149,    2, 0x0a,    7 /* Public */,
      10,    0,  152,    2, 0x0a,    9 /* Public */,
      11,    0,  153,    2, 0x08,   10 /* Private */,
      12,    1,  154,    2, 0x08,   11 /* Private */,
      12,    1,  157,    2, 0x08,   13 /* Private */,
      16,    0,  160,    2, 0x08,   15 /* Private */,
      17,    0,  161,    2, 0x08,   16 /* Private */,
      18,    0,  162,    2, 0x08,   17 /* Private */,
      19,    1,  163,    2, 0x08,   18 /* Private */,
      21,    0,  166,    2, 0x08,   20 /* Private */,
      22,    0,  167,    2, 0x08,   21 /* Private */,
      23,    0,  168,    2, 0x08,   22 /* Private */,
      24,    0,  169,    2, 0x08,   23 /* Private */,
      25,    0,  170,    2, 0x08,   24 /* Private */,
      26,    0,  171,    2, 0x08,   25 /* Private */,
      27,    0,  172,    2, 0x08,   26 /* Private */,
      28,    0,  173,    2, 0x08,   27 /* Private */,
      29,    0,  174,    2, 0x08,   28 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 15,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
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

void HomepageWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HomepageWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendClosedBlocks((*reinterpret_cast< vector<bool>(*)>(_a[1]))); break;
        case 1: _t->sendSwitchPosition((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 2: _t->sendDispatchInfo((*reinterpret_cast< TrainEntry(*)>(_a[1]))); break;
        case 3: _t->receiveOccupancy((*reinterpret_cast< vector<bool>(*)>(_a[1]))); break;
        case 4: _t->timerSlot(); break;
        case 5: _t->on_uploadScheduleButton_clicked(); break;
        case 6: _t->updateTrainTable((*reinterpret_cast< std::list<ScheduleEntry>(*)>(_a[1]))); break;
        case 7: _t->updateTrainTable((*reinterpret_cast< std::unordered_map<int,std::vector<ScheduleEntry>>(*)>(_a[1]))); break;
        case 8: _t->updateTrainComboBox(); break;
        case 9: _t->on_plusButton_clicked(); break;
        case 10: _t->on_addTrackSectionButton_clicked(); break;
        case 11: _t->on_maintenanceModeCheckBox_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_testInterfaceButton_clicked(); break;
        case 13: _t->on_homepageButton_clicked(); break;
        case 14: _t->on_manageTrainsButton_clicked(); break;
        case 15: _t->on_manageTracksButton_clicked(); break;
        case 16: _t->on_submitTestTrackInputButton_clicked(); break;
        case 17: _t->on_submitTestTrainInputButton_clicked(); break;
        case 18: _t->on_addSwitchButton_clicked(); break;
        case 19: _t->on_dispatchButton_clicked(); break;
        case 20: _t->on_submitBlockButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HomepageWindow::*)(vector<bool> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomepageWindow::sendClosedBlocks)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HomepageWindow::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomepageWindow::sendSwitchPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HomepageWindow::*)(TrainEntry );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HomepageWindow::sendDispatchInfo)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject HomepageWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_HomepageWindow.offsetsAndSize,
    qt_meta_data_HomepageWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_HomepageWindow_t
, QtPrivate::TypeAndForceComplete<HomepageWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<TrainEntry, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<bool>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::list<ScheduleEntry>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::unordered_map<int,std::vector<ScheduleEntry>>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *HomepageWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HomepageWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HomepageWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int HomepageWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HomepageWindow::sendClosedBlocks(vector<bool> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void HomepageWindow::sendSwitchPosition(vector<int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void HomepageWindow::sendDispatchInfo(TrainEntry _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
