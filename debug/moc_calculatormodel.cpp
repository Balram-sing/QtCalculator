/****************************************************************************
** Meta object code from reading C++ file 'calculatormodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../calculatormodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calculatormodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CalculatorModel_t {
    QByteArrayData data[15];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CalculatorModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CalculatorModel_t qt_meta_stringdata_CalculatorModel = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CalculatorModel"
QT_MOC_LITERAL(1, 16, 16), // "setOperationType"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "pType"
QT_MOC_LITERAL(4, 40, 5), // "onDot"
QT_MOC_LITERAL(5, 46, 15), // "onKeyboardInput"
QT_MOC_LITERAL(6, 62, 6), // "pValue"
QT_MOC_LITERAL(7, 69, 13), // "onNumberInput"
QT_MOC_LITERAL(8, 83, 7), // "pNumber"
QT_MOC_LITERAL(9, 91, 4), // "onMR"
QT_MOC_LITERAL(10, 96, 4), // "onMS"
QT_MOC_LITERAL(11, 101, 18), // "onRemoveLastNumber"
QT_MOC_LITERAL(12, 120, 6), // "doMath"
QT_MOC_LITERAL(13, 127, 11), // "resetMemory"
QT_MOC_LITERAL(14, 139, 10) // "resetLogic"

    },
    "CalculatorModel\0setOperationType\0\0"
    "pType\0onDot\0onKeyboardInput\0pValue\0"
    "onNumberInput\0pNumber\0onMR\0onMS\0"
    "onRemoveLastNumber\0doMath\0resetMemory\0"
    "resetLogic"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CalculatorModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x02 /* Public */,
       4,    0,   67,    2, 0x02 /* Public */,
       5,    1,   68,    2, 0x02 /* Public */,
       7,    1,   71,    2, 0x02 /* Public */,
       9,    0,   74,    2, 0x02 /* Public */,
      10,    0,   75,    2, 0x02 /* Public */,
      11,    0,   76,    2, 0x02 /* Public */,
      12,    0,   77,    2, 0x02 /* Public */,
      13,    0,   78,    2, 0x02 /* Public */,
      14,    0,   79,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QString, QMetaType::QString,    3,
    QMetaType::QString,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::QString, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CalculatorModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CalculatorModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QString _r = _t->setOperationType((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 1: { QString _r = _t->onDot();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: { QString _r = _t->onKeyboardInput((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 3: { QString _r = _t->onNumberInput((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: { QString _r = _t->onMR();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->onMS(); break;
        case 6: { QString _r = _t->onRemoveLastNumber();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: { QString _r = _t->doMath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->resetMemory(); break;
        case 9: _t->resetLogic(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CalculatorModel::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_CalculatorModel.data,
    qt_meta_data_CalculatorModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CalculatorModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CalculatorModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CalculatorModel.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CalculatorModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
