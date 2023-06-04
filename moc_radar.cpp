/****************************************************************************
** Meta object code from reading C++ file 'radar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "radar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'radar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Tradar_t {
    QByteArrayData data[17];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tradar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tradar_t qt_meta_stringdata_Tradar = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Tradar"
QT_MOC_LITERAL(1, 7, 11), // "fun_zamknij"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "generuj_starty"
QT_MOC_LITERAL(4, 35, 18), // "std::vector<uint>&"
QT_MOC_LITERAL(5, 54, 3), // "mom"
QT_MOC_LITERAL(6, 58, 4), // "pocz"
QT_MOC_LITERAL(7, 63, 9), // "czas_leci"
QT_MOC_LITERAL(8, 73, 16), // "wylosuj_obj_poch"
QT_MOC_LITERAL(9, 90, 16), // "Tobiektlatajacy*"
QT_MOC_LITERAL(10, 107, 6), // "moment"
QT_MOC_LITERAL(11, 114, 21), // "przelicz_punkty_ramki"
QT_MOC_LITERAL(12, 136, 13), // "keyPressEvent"
QT_MOC_LITERAL(13, 150, 10), // "QKeyEvent*"
QT_MOC_LITERAL(14, 161, 1), // "e"
QT_MOC_LITERAL(15, 163, 10), // "closeEvent"
QT_MOC_LITERAL(16, 174, 12) // "QCloseEvent*"

    },
    "Tradar\0fun_zamknij\0\0generuj_starty\0"
    "std::vector<uint>&\0mom\0pocz\0czas_leci\0"
    "wylosuj_obj_poch\0Tobiektlatajacy*\0"
    "moment\0przelicz_punkty_ramki\0keyPressEvent\0"
    "QKeyEvent*\0e\0closeEvent\0QCloseEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tradar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    2,   50,    2, 0x08 /* Private */,
       7,    0,   55,    2, 0x08 /* Private */,
       8,    1,   56,    2, 0x08 /* Private */,
      11,    0,   59,    2, 0x08 /* Private */,
      12,    1,   60,    2, 0x08 /* Private */,
      15,    1,   63,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Int,    5,    6,
    QMetaType::Void,
    0x80000000 | 9, QMetaType::UInt,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 16,   14,

       0        // eod
};

void Tradar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tradar *_t = static_cast<Tradar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fun_zamknij(); break;
        case 1: _t->generuj_starty((*reinterpret_cast< std::vector<uint>(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->czas_leci(); break;
        case 3: { Tobiektlatajacy* _r = _t->wylosuj_obj_poch((*reinterpret_cast< uint(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Tobiektlatajacy**>(_a[0]) = std::move(_r); }  break;
        case 4: _t->przelicz_punkty_ramki(); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 6: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Tradar::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Tradar.data,
      qt_meta_data_Tradar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Tradar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tradar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Tradar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Tradar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
