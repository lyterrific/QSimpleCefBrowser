/****************************************************************************
** Meta object code from reading C++ file 'CefBrowserHandlerImp.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cef3/CefBrowserHandlerImp.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CefBrowserHandlerImp.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CefBrowserHandlerImp_t {
    QByteArrayData data[12];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CefBrowserHandlerImp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CefBrowserHandlerImp_t qt_meta_stringdata_CefBrowserHandlerImp = {
    {
QT_MOC_LITERAL(0, 0, 20), // "CefBrowserHandlerImp"
QT_MOC_LITERAL(1, 21, 14), // "browserCreated"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "urlChanged"
QT_MOC_LITERAL(4, 48, 3), // "url"
QT_MOC_LITERAL(5, 52, 12), // "titleChanged"
QT_MOC_LITERAL(6, 65, 5), // "title"
QT_MOC_LITERAL(7, 71, 19), // "loadingStateChanged"
QT_MOC_LITERAL(8, 91, 9), // "isLoading"
QT_MOC_LITERAL(9, 101, 9), // "canGoBack"
QT_MOC_LITERAL(10, 111, 12), // "canGoForward"
QT_MOC_LITERAL(11, 124, 15) // "webViewGotFocus"

    },
    "CefBrowserHandlerImp\0browserCreated\0"
    "\0urlChanged\0url\0titleChanged\0title\0"
    "loadingStateChanged\0isLoading\0canGoBack\0"
    "canGoForward\0webViewGotFocus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CefBrowserHandlerImp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,
       5,    1,   43,    2, 0x06 /* Public */,
       7,    3,   46,    2, 0x06 /* Public */,
      11,    0,   53,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    8,    9,   10,
    QMetaType::Void,

       0        // eod
};

void CefBrowserHandlerImp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CefBrowserHandlerImp *_t = static_cast<CefBrowserHandlerImp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->browserCreated(); break;
        case 1: _t->urlChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->loadingStateChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 4: _t->webViewGotFocus(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CefBrowserHandlerImp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CefBrowserHandlerImp::browserCreated)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (CefBrowserHandlerImp::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CefBrowserHandlerImp::urlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (CefBrowserHandlerImp::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CefBrowserHandlerImp::titleChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (CefBrowserHandlerImp::*_t)(bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CefBrowserHandlerImp::loadingStateChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (CefBrowserHandlerImp::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CefBrowserHandlerImp::webViewGotFocus)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject CefBrowserHandlerImp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CefBrowserHandlerImp.data,
      qt_meta_data_CefBrowserHandlerImp,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CefBrowserHandlerImp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CefBrowserHandlerImp::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CefBrowserHandlerImp.stringdata0))
        return static_cast<void*>(const_cast< CefBrowserHandlerImp*>(this));
    if (!strcmp(_clname, "CefClient"))
        return static_cast< CefClient*>(const_cast< CefBrowserHandlerImp*>(this));
    if (!strcmp(_clname, "CefDisplayHandler"))
        return static_cast< CefDisplayHandler*>(const_cast< CefBrowserHandlerImp*>(this));
    if (!strcmp(_clname, "CefLifeSpanHandler"))
        return static_cast< CefLifeSpanHandler*>(const_cast< CefBrowserHandlerImp*>(this));
    if (!strcmp(_clname, "CefFocusHandler"))
        return static_cast< CefFocusHandler*>(const_cast< CefBrowserHandlerImp*>(this));
    if (!strcmp(_clname, "CefLoadHandler"))
        return static_cast< CefLoadHandler*>(const_cast< CefBrowserHandlerImp*>(this));
    return QObject::qt_metacast(_clname);
}

int CefBrowserHandlerImp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CefBrowserHandlerImp::browserCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CefBrowserHandlerImp::urlChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CefBrowserHandlerImp::titleChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CefBrowserHandlerImp::loadingStateChanged(bool _t1, bool _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CefBrowserHandlerImp::webViewGotFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
