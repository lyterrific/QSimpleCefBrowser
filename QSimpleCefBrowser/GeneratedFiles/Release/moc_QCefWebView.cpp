/****************************************************************************
** Meta object code from reading C++ file 'QCefWebView.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../qBrowserWindow/QCefWebView.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QCefWebView.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QCefWebView_t {
    QByteArrayData data[21];
    char stringdata0[212];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QCefWebView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QCefWebView_t qt_meta_stringdata_QCefWebView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QCefWebView"
QT_MOC_LITERAL(1, 12, 12), // "titleChanged"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "title"
QT_MOC_LITERAL(4, 32, 10), // "urlChanged"
QT_MOC_LITERAL(5, 43, 3), // "url"
QT_MOC_LITERAL(6, 47, 16), // "loadStateChanged"
QT_MOC_LITERAL(7, 64, 9), // "isLoading"
QT_MOC_LITERAL(8, 74, 9), // "canGoBack"
QT_MOC_LITERAL(9, 84, 12), // "canGoForward"
QT_MOC_LITERAL(10, 97, 15), // "webViewGotFocus"
QT_MOC_LITERAL(11, 113, 11), // "loadStarted"
QT_MOC_LITERAL(12, 125, 12), // "loadFinished"
QT_MOC_LITERAL(13, 138, 11), // "loadSuccess"
QT_MOC_LITERAL(14, 150, 7), // "loadUrl"
QT_MOC_LITERAL(15, 158, 4), // "back"
QT_MOC_LITERAL(16, 163, 7), // "forward"
QT_MOC_LITERAL(17, 171, 7), // "refresh"
QT_MOC_LITERAL(18, 179, 4), // "stop"
QT_MOC_LITERAL(19, 184, 16), // "onBrowserCreated"
QT_MOC_LITERAL(20, 201, 10) // "SetLoading"

    },
    "QCefWebView\0titleChanged\0\0title\0"
    "urlChanged\0url\0loadStateChanged\0"
    "isLoading\0canGoBack\0canGoForward\0"
    "webViewGotFocus\0loadStarted\0loadFinished\0"
    "loadSuccess\0loadUrl\0back\0forward\0"
    "refresh\0stop\0onBrowserCreated\0SetLoading"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QCefWebView[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       6,    3,   85,    2, 0x06 /* Public */,
      10,    0,   92,    2, 0x06 /* Public */,
      11,    0,   93,    2, 0x06 /* Public */,
      12,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   97,    2, 0x0a /* Public */,
      15,    0,  100,    2, 0x0a /* Public */,
      16,    0,  101,    2, 0x0a /* Public */,
      17,    0,  102,    2, 0x0a /* Public */,
      18,    0,  103,    2, 0x0a /* Public */,
      19,    0,  104,    2, 0x08 /* Private */,
      20,    1,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool, QMetaType::Bool,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    7,

       0        // eod
};

void QCefWebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QCefWebView *_t = static_cast<QCefWebView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->titleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->urlChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->loadStateChanged((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->webViewGotFocus(); break;
        case 4: _t->loadStarted(); break;
        case 5: _t->loadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->loadUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->back(); break;
        case 8: _t->forward(); break;
        case 9: _t->refresh(); break;
        case 10: _t->stop(); break;
        case 11: _t->onBrowserCreated(); break;
        case 12: _t->SetLoading((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QCefWebView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::titleChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (QCefWebView::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::urlChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (QCefWebView::*_t)(bool , bool , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::loadStateChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (QCefWebView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::webViewGotFocus)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (QCefWebView::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::loadStarted)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (QCefWebView::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QCefWebView::loadFinished)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject QCefWebView::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_QCefWebView.data,
      qt_meta_data_QCefWebView,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QCefWebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QCefWebView::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QCefWebView.stringdata0))
        return static_cast<void*>(const_cast< QCefWebView*>(this));
    return QWidget::qt_metacast(_clname);
}

int QCefWebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void QCefWebView::titleChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QCefWebView::urlChanged(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QCefWebView::loadStateChanged(bool _t1, bool _t2, bool _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QCefWebView::webViewGotFocus()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void QCefWebView::loadStarted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void QCefWebView::loadFinished(bool _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
