/****************************************************************************
** Meta object code from reading C++ file 'devicewindow.h'
**
** Created: Sat Oct 22 16:01:37 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "devicewindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'devicewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DeviceWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      29,   13,   13,   13, 0x08,
      46,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DeviceWindow[] = {
    "DeviceWindow\0\0windowClosed()\0"
    "on_buttonBoxOk()\0on_buttonBoxCancel()\0"
};

const QMetaObject DeviceWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DeviceWindow,
      qt_meta_data_DeviceWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DeviceWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DeviceWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DeviceWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceWindow))
        return static_cast<void*>(const_cast< DeviceWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int DeviceWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: windowClosed(); break;
        case 1: on_buttonBoxOk(); break;
        case 2: on_buttonBoxCancel(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DeviceWindow::windowClosed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
