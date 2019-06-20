/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HelloFaruq/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      38,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      21,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   12,   11,   11, 0x0a,
      81,   12,   11,   11, 0x0a,
     112,   11,   11,   11, 0x0a,
     128,   11,   11,   11, 0x0a,
     143,   11,   11,   11, 0x0a,
     159,   11,   11,   11, 0x08,
     193,  188,   11,   11, 0x08,
     240,   11,   11,   11, 0x08,
     264,   11,   11,   11, 0x08,
     288,   11,   11,   11, 0x08,
     305,   11,   11,   11, 0x08,
     325,   11,   11,   11, 0x08,
     355,  188,   11,   11, 0x08,
     390,   11,   11,   11, 0x08,
     409,  188,   11,   11, 0x08,
     443,   11,   11,   11, 0x08,
     465,   11,   11,   11, 0x08,
     498,   11,   11,   11, 0x08,
     531,   11,   11,   11, 0x08,
     557,  188,   11,   11, 0x08,
     592,   11,   11,   11, 0x08,
     624,   11,   11,   11, 0x08,
     673,  665,   11,   11, 0x08,
     698,  665,   11,   11, 0x08,
     719,  665,   11,   11, 0x08,
     751,  665,   11,   11, 0x08,
     783,  665,   11,   11, 0x08,
     821,   11,   11,   11, 0x08,
     839,   11,   11,   11, 0x08,
     857,  188,   11,   11, 0x08,
     885,  188,   11,   11, 0x08,
     913,  188,   11,   11, 0x08,
     941,  188,   11,   11, 0x08,
     971,  188,   11,   11, 0x08,
    1001,  188,   11,   11, 0x08,
    1031,  188,   11,   11, 0x08,
    1067,  188,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0fileName\0parametersChanged(QString)\0"
    "readParametersFromFile(QString&)\0"
    "writeParametersToFile(QString)\0"
    "displayOutput()\0displayError()\0"
    "updateConsole()\0on_ReferenceButton_clicked()\0"
    "arg1\0on_ReferenceStructurePath_textChanged(QString)\0"
    "on_SelectPpbs_clicked()\0on_SelectPqrs_clicked()\0"
    "on_Run_clicked()\0on_Output_clicked()\0"
    "on_ViewPointsButton_clicked()\0"
    "on_OutputPath_textChanged(QString)\0"
    "on_Input_clicked()\0on_InputPath_textChanged(QString)\0"
    "on_DisplayX_clicked()\0"
    "on_DisplayXValue_returnPressed()\0"
    "on_DisplayYValue_returnPressed()\0"
    "on_apbsInButton_clicked()\0"
    "on_apbsInText_textChanged(QString)\0"
    "on_ColumnsValue_returnPressed()\0"
    "on_ImageCreatorQuality_2_returnPressed()\0"
    "checked\0on_pdb2pqr_toggled(bool)\0"
    "on_vmd_toggled(bool)\0"
    "on_doImageCreator_toggled(bool)\0"
    "on_doMovieCreator_toggled(bool)\0"
    "on_doCreateTrainingsSet_toggled(bool)\0"
    "on_Stop_pressed()\0mutCompFinished()\0"
    "on_xRot_textEdited(QString)\0"
    "on_yRot_textEdited(QString)\0"
    "on_zRot_textEdited(QString)\0"
    "on_xTrans_textEdited(QString)\0"
    "on_yTrans_textEdited(QString)\0"
    "on_zTrans_textEdited(QString)\0"
    "on_ColumnsValue_textEdited(QString)\0"
    "on_FontSizeValue_textEdited(QString)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->parametersChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->readParametersFromFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->writeParametersToFile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->displayOutput(); break;
        case 4: _t->displayError(); break;
        case 5: _t->updateConsole(); break;
        case 6: _t->on_ReferenceButton_clicked(); break;
        case 7: _t->on_ReferenceStructurePath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_SelectPpbs_clicked(); break;
        case 9: _t->on_SelectPqrs_clicked(); break;
        case 10: _t->on_Run_clicked(); break;
        case 11: _t->on_Output_clicked(); break;
        case 12: _t->on_ViewPointsButton_clicked(); break;
        case 13: _t->on_OutputPath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->on_Input_clicked(); break;
        case 15: _t->on_InputPath_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_DisplayX_clicked(); break;
        case 17: _t->on_DisplayXValue_returnPressed(); break;
        case 18: _t->on_DisplayYValue_returnPressed(); break;
        case 19: _t->on_apbsInButton_clicked(); break;
        case 20: _t->on_apbsInText_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_ColumnsValue_returnPressed(); break;
        case 22: _t->on_ImageCreatorQuality_2_returnPressed(); break;
        case 23: _t->on_pdb2pqr_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->on_vmd_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 25: _t->on_doImageCreator_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->on_doMovieCreator_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 27: _t->on_doCreateTrainingsSet_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 28: _t->on_Stop_pressed(); break;
        case 29: _t->mutCompFinished(); break;
        case 30: _t->on_xRot_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->on_yRot_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 32: _t->on_zRot_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->on_xTrans_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->on_yTrans_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->on_zTrans_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 36: _t->on_ColumnsValue_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->on_FontSizeValue_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 38)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 38;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::parametersChanged(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
