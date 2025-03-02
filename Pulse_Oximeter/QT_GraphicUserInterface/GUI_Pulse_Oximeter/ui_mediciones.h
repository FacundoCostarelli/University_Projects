/********************************************************************************
** Form generated from reading UI file 'mediciones.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDICIONES_H
#define UI_MEDICIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mediciones
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLCDNumber *lcdOxigeno;
    QLabel *label;
    QLCDNumber *lcdHeartrate;
    QPushButton *botonSalir;
    QSpacerItem *horizontalSpacer;
    QPushButton *botonGuardar;
    QPushButton *botonMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Mediciones)
    {
        if (Mediciones->objectName().isEmpty())
            Mediciones->setObjectName(QString::fromUtf8("Mediciones"));
        Mediciones->resize(554, 249);
        QFont font;
        font.setFamilies({QString::fromUtf8("Manjari")});
        Mediciones->setFont(font);
        centralwidget = new QWidget(Mediciones);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Manjari")});
        font1.setPointSize(30);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_2, 0, 1, 1, 1);

        lcdOxigeno = new QLCDNumber(groupBox_2);
        lcdOxigeno->setObjectName(QString::fromUtf8("lcdOxigeno"));

        gridLayout_3->addWidget(lcdOxigeno, 1, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Manjari")});
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        label->setFont(font2);
        label->setFrameShape(QFrame::NoFrame);
        label->setFrameShadow(QFrame::Plain);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        lcdHeartrate = new QLCDNumber(groupBox_2);
        lcdHeartrate->setObjectName(QString::fromUtf8("lcdHeartrate"));

        gridLayout_3->addWidget(lcdHeartrate, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 4);

        botonSalir = new QPushButton(centralwidget);
        botonSalir->setObjectName(QString::fromUtf8("botonSalir"));
        botonSalir->setMinimumSize(QSize(100, 50));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Manjari")});
        font3.setPointSize(15);
        botonSalir->setFont(font3);

        gridLayout->addWidget(botonSalir, 3, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 1, 1, 1);

        botonGuardar = new QPushButton(centralwidget);
        botonGuardar->setObjectName(QString::fromUtf8("botonGuardar"));
        botonGuardar->setMinimumSize(QSize(100, 50));
        botonGuardar->setFont(font3);

        gridLayout->addWidget(botonGuardar, 3, 0, 1, 1);

        botonMenu = new QPushButton(centralwidget);
        botonMenu->setObjectName(QString::fromUtf8("botonMenu"));
        botonMenu->setMinimumSize(QSize(100, 50));
        botonMenu->setFont(font3);

        gridLayout->addWidget(botonMenu, 3, 2, 1, 1);

        Mediciones->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Mediciones);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Mediciones->setStatusBar(statusbar);

        retranslateUi(Mediciones);

        QMetaObject::connectSlotsByName(Mediciones);
    } // setupUi

    void retranslateUi(QMainWindow *Mediciones)
    {
        Mediciones->setWindowTitle(QCoreApplication::translate("Mediciones", "MainWindow", nullptr));
        groupBox_2->setTitle(QString());
        label_2->setText(QCoreApplication::translate("Mediciones", "OXIGENO", nullptr));
        label->setText(QCoreApplication::translate("Mediciones", "HEART RATE", nullptr));
        botonSalir->setText(QCoreApplication::translate("Mediciones", "Salir", nullptr));
        botonGuardar->setText(QCoreApplication::translate("Mediciones", "Guardar", nullptr));
        botonMenu->setText(QCoreApplication::translate("Mediciones", "Atras", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mediciones: public Ui_Mediciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDICIONES_H
