/****************************************************************************
** Meta object code from reading C++ file 'QBrowserWindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qBrowserWindow/QBrowserWindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QBrowserWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QBrowserWindow_t {
    QByteArrayData data[10];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QBrowserWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QBrowserWindow_t qt_meta_stringdata_QBrowserWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "QBrowserWindow"
QT_MOC_LITERAL(1, 15, 14), // "updateBtnState"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 9), // "isLoading"
QT_MOC_LITERAL(4, 41, 9), // "canGoBack"
QT_MOC_LITERAL(5, 51, 12), // "canGoForward"
QT_MOC_LITERAL(6, 64, 10), // "loadWebUrl"
QT_MOC_LITERAL(7, 75, 17), // "onWebViewGotFocus"
QT_MOC_LITERAL(8, 93, 14), // "onTitleChanged"
QT_MOC_LITERAL(9, 108, 5) // "title"

    },
    "QBrowserWindow\0updateBtnState\0\0isLoading\0"
    "canGoBack\0canGoForward\0loadWebUrl\0"
    "onWebViewGotFocus\0onTitleChanged\0title"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QBrowserWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   34,    2, 0x08 /* Private */,
       6,    0,   41,    2, 0x08 /* Private */,
       7,    0,   42,    2, 0x08 /* Private */,
       8,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void QBrowserWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QBrowserWindow *_t = static_cast<QBrowserWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBtnState((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 1: _t->loadWebUrl(); break;
        case 2: _t->onWebViewGotFocus(); break;
        case 3: _t->onTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QBrowserWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_QBrowserWindow.data,
      qt_meta_data_QBrowserWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QBrowserWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QBrowserWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QBrowserWindow.stringdata0))
        return static_cast<void*>(const_cast< QBrowserWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int QBrowserWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
