/****************************************************************************
** Meta object code from reading C++ file 'wayside.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../train_sim/wayside.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wayside.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Wayside_t {
    const uint offsetsAndSize[38];
    char stringdata0[271];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Wayside_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Wayside_t qt_meta_stringdata_Wayside = {
    {
QT_MOC_LITERAL(0, 7), // "Wayside"
QT_MOC_LITERAL(8, 15), // "addedPassengers"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 5), // "added"
QT_MOC_LITERAL(31, 12), // "trainChanged"
QT_MOC_LITERAL(44, 14), // "vector<string>"
QT_MOC_LITERAL(59, 4), // "data"
QT_MOC_LITERAL(64, 12), // "toggleSwitch"
QT_MOC_LITERAL(77, 11), // "vector<int>"
QT_MOC_LITERAL(89, 2), // "sw"
QT_MOC_LITERAL(92, 14), // "toggleCrossing"
QT_MOC_LITERAL(107, 5), // "cross"
QT_MOC_LITERAL(113, 16), // "on_test1_clicked"
QT_MOC_LITERAL(130, 18), // "on_cont1_1_clicked"
QT_MOC_LITERAL(149, 31), // "on_toggleSwitch_editingFinished"
QT_MOC_LITERAL(181, 18), // "on_cont1_2_clicked"
QT_MOC_LITERAL(200, 18), // "on_cont1_3_clicked"
QT_MOC_LITERAL(219, 19), // "on_testYard_clicked"
QT_MOC_LITERAL(239, 31) // "on_toggleCrossing_returnPressed"

    },
    "Wayside\0addedPassengers\0\0added\0"
    "trainChanged\0vector<string>\0data\0"
    "toggleSwitch\0vector<int>\0sw\0toggleCrossing\0"
    "cross\0on_test1_clicked\0on_cont1_1_clicked\0"
    "on_toggleSwitch_editingFinished\0"
    "on_cont1_2_clicked\0on_cont1_3_clicked\0"
    "on_testYard_clicked\0on_toggleCrossing_returnPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Wayside[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   80,    2, 0x06,    1 /* Public */,
       4,    1,   83,    2, 0x06,    3 /* Public */,
       7,    1,   86,    2, 0x06,    5 /* Public */,
      10,    1,   89,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,   92,    2, 0x08,    9 /* Private */,
      13,    0,   93,    2, 0x08,   10 /* Private */,
      14,    0,   94,    2, 0x08,   11 /* Private */,
      15,    0,   95,    2, 0x08,   12 /* Private */,
      16,    0,   96,    2, 0x08,   13 /* Private */,
      17,    0,   97,    2, 0x08,   14 /* Private */,
      18,    0,   98,    2, 0x08,   15 /* Private */,

 // signals: parameters
    QMetaType::Int, QMetaType::Int,    3,
    0x80000000 | 5, 0x80000000 | 5,    6,
    0x80000000 | 8, 0x80000000 | 8,    9,
    QMetaType::Int, QMetaType::Int,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Wayside::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Wayside *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { int _r = _t->addedPassengers((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 1: { vector<string> _r = _t->trainChanged((*reinterpret_cast< vector<string>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<string>*>(_a[0]) = std::move(_r); }  break;
        case 2: { vector<int> _r = _t->toggleSwitch((*reinterpret_cast< vector<int>(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< vector<int>*>(_a[0]) = std::move(_r); }  break;
        case 3: { int _r = _t->toggleCrossing((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_test1_clicked(); break;
        case 5: _t->on_cont1_1_clicked(); break;
        case 6: _t->on_toggleSwitch_editingFinished(); break;
        case 7: _t->on_cont1_2_clicked(); break;
        case 8: _t->on_cont1_3_clicked(); break;
        case 9: _t->on_testYard_clicked(); break;
        case 10: _t->on_toggleCrossing_returnPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = int (Wayside::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Wayside::addedPassengers)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = vector<string> (Wayside::*)(vector<string> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Wayside::trainChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = vector<int> (Wayside::*)(vector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Wayside::toggleSwitch)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = int (Wayside::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Wayside::toggleCrossing)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Wayside::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Wayside.offsetsAndSize,
    qt_meta_data_Wayside,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Wayside_t
, QtPrivate::TypeAndForceComplete<Wayside, std::true_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<string>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Wayside::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Wayside::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Wayside.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Wayside::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
int Wayside::addedPassengers(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}

// SIGNAL 1
vector<string> Wayside::trainChanged(vector<string> _t1)
{
    vector<string> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
vector<int> Wayside::toggleSwitch(vector<int> _t1)
{
    vector<int> _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}

// SIGNAL 3
int Wayside::toggleCrossing(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
    return _t0;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
