/****************************************************************************
** Meta object code from reading C++ file 'mailingp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Ahminy/mailingp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mailingp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mailingp_t {
    QByteArrayData data[15];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mailingp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mailingp_t qt_meta_stringdata_mailingp = {
    {
QT_MOC_LITERAL(0, 0, 8), // "mailingp"
QT_MOC_LITERAL(1, 9, 29), // "on_closeafficherperso_clicked"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 9), // "sendemail"
QT_MOC_LITERAL(4, 50, 8), // "mailSent"
QT_MOC_LITERAL(5, 59, 11), // "clearFields"
QT_MOC_LITERAL(6, 71, 6), // "browse"
QT_MOC_LITERAL(7, 78, 18), // "on_envoyer_clicked"
QT_MOC_LITERAL(8, 97, 16), // "on_clear_clicked"
QT_MOC_LITERAL(9, 114, 22), // "on_mailE_returnPressed"
QT_MOC_LITERAL(10, 137, 20), // "on_browseBtn_clicked"
QT_MOC_LITERAL(11, 158, 23), // "on_closemailing_clicked"
QT_MOC_LITERAL(12, 182, 22), // "on_paswd_returnPressed"
QT_MOC_LITERAL(13, 205, 19), // "on_showpswd_pressed"
QT_MOC_LITERAL(14, 225, 20) // "on_showpswd_released"

    },
    "mailingp\0on_closeafficherperso_clicked\0"
    "\0sendemail\0mailSent\0clearFields\0browse\0"
    "on_envoyer_clicked\0on_clear_clicked\0"
    "on_mailE_returnPressed\0on_browseBtn_clicked\0"
    "on_closemailing_clicked\0on_paswd_returnPressed\0"
    "on_showpswd_pressed\0on_showpswd_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mailingp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    1,   81,    2, 0x08 /* Private */,
       5,    0,   84,    2, 0x08 /* Private */,
       6,    0,   85,    2, 0x08 /* Private */,
       7,    0,   86,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
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

void mailingp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        mailingp *_t = static_cast<mailingp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_closeafficherperso_clicked(); break;
        case 1: _t->sendemail(); break;
        case 2: _t->mailSent((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->clearFields(); break;
        case 4: _t->browse(); break;
        case 5: _t->on_envoyer_clicked(); break;
        case 6: _t->on_clear_clicked(); break;
        case 7: _t->on_mailE_returnPressed(); break;
        case 8: _t->on_browseBtn_clicked(); break;
        case 9: _t->on_closemailing_clicked(); break;
        case 10: _t->on_paswd_returnPressed(); break;
        case 11: _t->on_showpswd_pressed(); break;
        case 12: _t->on_showpswd_released(); break;
        default: ;
        }
    }
}

const QMetaObject mailingp::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_mailingp.data,
      qt_meta_data_mailingp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *mailingp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mailingp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mailingp.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int mailingp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
