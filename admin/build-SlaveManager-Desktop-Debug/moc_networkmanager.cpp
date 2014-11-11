/****************************************************************************
** Meta object code from reading C++ file 'networkmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../SlaveManager/networkmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'networkmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_NetworkManager_t {
    QByteArrayData data[14];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_NetworkManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_NetworkManager_t qt_meta_stringdata_NetworkManager = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 20),
QT_MOC_LITERAL(2, 36, 0),
QT_MOC_LITERAL(3, 37, 14),
QT_MOC_LITERAL(4, 52, 15),
QT_MOC_LITERAL(5, 68, 12),
QT_MOC_LITERAL(6, 81, 28),
QT_MOC_LITERAL(7, 110, 7),
QT_MOC_LITERAL(8, 118, 5),
QT_MOC_LITERAL(9, 124, 1),
QT_MOC_LITERAL(10, 126, 12),
QT_MOC_LITERAL(11, 139, 7),
QT_MOC_LITERAL(12, 147, 6),
QT_MOC_LITERAL(13, 154, 5)
    },
    "NetworkManager\0connectionSuccessful\0"
    "\0connectionLost\0loginSuccessful\0"
    "errorOccured\0QAbstractSocket::SocketError\0"
    "receive\0index\0t\0connexion_OK\0lecture\0"
    "closed\0error\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NetworkManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,
       3,    0,   60,    2, 0x05,
       4,    0,   61,    2, 0x05,
       5,    1,   62,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       7,    2,   65,    2, 0x0a,
      10,    0,   70,    2, 0x08,
      11,    0,   71,    2, 0x08,
      12,    0,   72,    2, 0x08,
      13,    1,   73,    2, 0x08,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void NetworkManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        NetworkManager *_t = static_cast<NetworkManager *>(_o);
        switch (_id) {
        case 0: _t->connectionSuccessful(); break;
        case 1: _t->connectionLost(); break;
        case 2: _t->loginSuccessful(); break;
        case 3: _t->errorOccured((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 4: _t->receive((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->connexion_OK(); break;
        case 6: _t->lecture(); break;
        case 7: _t->closed(); break;
        case 8: _t->error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (NetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkManager::connectionSuccessful)) {
                *result = 0;
            }
        }
        {
            typedef void (NetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkManager::connectionLost)) {
                *result = 1;
            }
        }
        {
            typedef void (NetworkManager::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkManager::loginSuccessful)) {
                *result = 2;
            }
        }
        {
            typedef void (NetworkManager::*_t)(QAbstractSocket::SocketError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&NetworkManager::errorOccured)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject NetworkManager::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_NetworkManager.data,
      qt_meta_data_NetworkManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *NetworkManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NetworkManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NetworkManager.stringdata))
        return static_cast<void*>(const_cast< NetworkManager*>(this));
    return QObject::qt_metacast(_clname);
}

int NetworkManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void NetworkManager::connectionSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void NetworkManager::connectionLost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void NetworkManager::loginSuccessful()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void NetworkManager::errorOccured(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
