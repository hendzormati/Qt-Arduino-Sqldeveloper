/****************************************************************************
** Meta object code from reading C++ file 'modifmdp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../smesa/AhminyFinal/Ahminy/modifmdp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'modifmdp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_modifmdp_t {
    QByteArrayData data[23];
    char stringdata0[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_modifmdp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_modifmdp_t qt_meta_stringdata_modifmdp = {
    {
QT_MOC_LITERAL(0, 0, 8), // "modifmdp"
QT_MOC_LITERAL(1, 9, 12), // "sendcodemail"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 8), // "onStatus"
QT_MOC_LITERAL(4, 32, 9), // "Status::e"
QT_MOC_LITERAL(5, 42, 6), // "status"
QT_MOC_LITERAL(6, 49, 12), // "errorMessage"
QT_MOC_LITERAL(7, 62, 28), // "on_verifemailp_returnPressed"
QT_MOC_LITERAL(8, 91, 31), // "on_confirmercodep_returnPressed"
QT_MOC_LITERAL(9, 123, 27), // "on_nouveaumdp_returnPressed"
QT_MOC_LITERAL(10, 151, 19), // "setPasswordStrength"
QT_MOC_LITERAL(11, 171, 8), // "password"
QT_MOC_LITERAL(12, 180, 7), // "QLabel*"
QT_MOC_LITERAL(13, 188, 13), // "strengthLabel"
QT_MOC_LITERAL(14, 202, 13), // "QProgressBar*"
QT_MOC_LITERAL(15, 216, 11), // "strengthBar"
QT_MOC_LITERAL(16, 228, 24), // "on_nouveaumdp_textEdited"
QT_MOC_LITERAL(17, 253, 4), // "arg1"
QT_MOC_LITERAL(18, 258, 21), // "on_quittermdp_clicked"
QT_MOC_LITERAL(19, 280, 19), // "on_renvoyer_clicked"
QT_MOC_LITERAL(20, 300, 19), // "on_showpswd_pressed"
QT_MOC_LITERAL(21, 320, 20), // "on_showpswd_released"
QT_MOC_LITERAL(22, 341, 26) // "on_quittermodifmdp_clicked"

    },
    "modifmdp\0sendcodemail\0\0onStatus\0"
    "Status::e\0status\0errorMessage\0"
    "on_verifemailp_returnPressed\0"
    "on_confirmercodep_returnPressed\0"
    "on_nouveaumdp_returnPressed\0"
    "setPasswordStrength\0password\0QLabel*\0"
    "strengthLabel\0QProgressBar*\0strengthBar\0"
    "on_nouveaumdp_textEdited\0arg1\0"
    "on_quittermdp_clicked\0on_renvoyer_clicked\0"
    "on_showpswd_pressed\0on_showpswd_released\0"
    "on_quittermodifmdp_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_modifmdp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x08 /* Private */,
       3,    2,   75,    2, 0x08 /* Private */,
       7,    0,   80,    2, 0x08 /* Private */,
       8,    0,   81,    2, 0x08 /* Private */,
       9,    0,   82,    2, 0x08 /* Private */,
      10,    3,   83,    2, 0x08 /* Private */,
      16,    1,   90,    2, 0x08 /* Private */,
      18,    0,   93,    2, 0x08 /* Private */,
      19,    0,   94,    2, 0x08 /* Private */,
      20,    0,   95,    2, 0x08 /* Private */,
      21,    0,   96,    2, 0x08 /* Private */,
      22,    0,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString,    5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 12, 0x80000000 | 14,   11,   13,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void modifmdp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        modifmdp *_t = static_cast<modifmdp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendcodemail(); break;
        case 1: _t->onStatus((*reinterpret_cast< Status::e(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_verifemailp_returnPressed(); break;
        case 3: _t->on_confirmercodep_returnPressed(); break;
        case 4: _t->on_nouveaumdp_returnPressed(); break;
        case 5: _t->setPasswordStrength((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QLabel*(*)>(_a[2])),(*reinterpret_cast< QProgressBar*(*)>(_a[3]))); break;
        case 6: _t->on_nouveaumdp_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_quittermdp_clicked(); break;
        case 8: _t->on_renvoyer_clicked(); break;
        case 9: _t->on_showpswd_pressed(); break;
        case 10: _t->on_showpswd_released(); break;
        case 11: _t->on_quittermodifmdp_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLabel* >(); break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QProgressBar* >(); break;
            }
            break;
        }
    }
}

const QMetaObject modifmdp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_modifmdp.data,
      qt_meta_data_modifmdp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *modifmdp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *modifmdp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_modifmdp.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int modifmdp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
