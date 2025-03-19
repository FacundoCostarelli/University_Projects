/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pushButtonSalir;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *botonHistorial;
    QLabel *label;
    QPushButton *botonMediciones;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 401);
        QFont font;
        font.setFamilies({QString::fromUtf8("Manjari")});
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButtonSalir = new QPushButton(centralwidget);
        pushButtonSalir->setObjectName(QString::fromUtf8("pushButtonSalir"));
        pushButtonSalir->setMinimumSize(QSize(300, 50));
        pushButtonSalir->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Manjari")});
        font1.setPointSize(15);
        pushButtonSalir->setFont(font1);

        gridLayout->addWidget(pushButtonSalir, 3, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 3, 2, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 280));
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 3, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 5, 1, 1);

        botonHistorial = new QPushButton(groupBox);
        botonHistorial->setObjectName(QString::fromUtf8("botonHistorial"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(botonHistorial->sizePolicy().hasHeightForWidth());
        botonHistorial->setSizePolicy(sizePolicy);
        botonHistorial->setMinimumSize(QSize(150, 100));
        botonHistorial->setBaseSize(QSize(0, 0));
        botonHistorial->setFont(font1);

        gridLayout_2->addWidget(botonHistorial, 3, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Manjari")});
        font2.setPointSize(50);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        label->setFont(font2);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 6);

        botonMediciones = new QPushButton(groupBox);
        botonMediciones->setObjectName(QString::fromUtf8("botonMediciones"));
        botonMediciones->setMinimumSize(QSize(150, 100));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Manjari")});
        font3.setPointSize(15);
        font3.setKerning(true);
        botonMediciones->setFont(font3);
        botonMediciones->setLayoutDirection(Qt::LeftToRight);

        gridLayout_2->addWidget(botonMediciones, 3, 4, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 2, 3);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButtonSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        groupBox->setTitle(QString());
        botonHistorial->setText(QCoreApplication::translate("MainWindow", "Historial", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "PULSIOX\303\215METRO", nullptr));
        botonMediciones->setText(QCoreApplication::translate("MainWindow", "Medir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
