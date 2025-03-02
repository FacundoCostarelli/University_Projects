/********************************************************************************
** Form generated from reading UI file 'historial.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORIAL_H
#define UI_HISTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Historial
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *botonMenu;
    QPushButton *botonGuardar;
    QPushButton *botonBorrar;
    QPushButton *botonSalir;
    QPushButton *botonEditar;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Historial)
    {
        if (Historial->objectName().isEmpty())
            Historial->setObjectName(QString::fromUtf8("Historial"));
        Historial->resize(639, 345);
        QFont font;
        font.setFamilies({QString::fromUtf8("Manjari")});
        Historial->setFont(font);
        centralwidget = new QWidget(Historial);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 3, 1, 1);

        botonMenu = new QPushButton(centralwidget);
        botonMenu->setObjectName(QString::fromUtf8("botonMenu"));
        botonMenu->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(botonMenu, 2, 4, 1, 1);

        botonGuardar = new QPushButton(centralwidget);
        botonGuardar->setObjectName(QString::fromUtf8("botonGuardar"));
        botonGuardar->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(botonGuardar, 2, 1, 1, 1);

        botonBorrar = new QPushButton(centralwidget);
        botonBorrar->setObjectName(QString::fromUtf8("botonBorrar"));
        botonBorrar->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(botonBorrar, 2, 2, 1, 1);

        botonSalir = new QPushButton(centralwidget);
        botonSalir->setObjectName(QString::fromUtf8("botonSalir"));
        botonSalir->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(botonSalir, 2, 5, 1, 1);

        botonEditar = new QPushButton(centralwidget);
        botonEditar->setObjectName(QString::fromUtf8("botonEditar"));
        botonEditar->setMinimumSize(QSize(100, 50));

        gridLayout->addWidget(botonEditar, 2, 0, 1, 1);

        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setFrameShape(QFrame::StyledPanel);

        gridLayout->addWidget(textEdit, 0, 0, 1, 6);

        Historial->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Historial);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 639, 22));
        Historial->setMenuBar(menubar);
        statusbar = new QStatusBar(Historial);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Historial->setStatusBar(statusbar);

        retranslateUi(Historial);

        QMetaObject::connectSlotsByName(Historial);
    } // setupUi

    void retranslateUi(QMainWindow *Historial)
    {
        Historial->setWindowTitle(QCoreApplication::translate("Historial", "MainWindow", nullptr));
        botonMenu->setText(QCoreApplication::translate("Historial", "Atras", nullptr));
        botonGuardar->setText(QCoreApplication::translate("Historial", "Guardar", nullptr));
        botonBorrar->setText(QCoreApplication::translate("Historial", "Borrar", nullptr));
        botonSalir->setText(QCoreApplication::translate("Historial", "Salir", nullptr));
        botonEditar->setText(QCoreApplication::translate("Historial", "Editar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Historial: public Ui_Historial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORIAL_H
