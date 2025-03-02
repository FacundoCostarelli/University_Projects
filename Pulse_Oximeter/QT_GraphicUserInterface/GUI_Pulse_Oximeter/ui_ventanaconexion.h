/********************************************************************************
** Form generated from reading UI file 'ventanaconexion.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANACONEXION_H
#define UI_VENTANACONEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaConexion
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConexion;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *VentanaConexion)
    {
        if (VentanaConexion->objectName().isEmpty())
            VentanaConexion->setObjectName(QString::fromUtf8("VentanaConexion"));
        VentanaConexion->resize(337, 145);
        QFont font;
        font.setFamilies({QString::fromUtf8("Manjari")});
        VentanaConexion->setFont(font);
        centralwidget = new QWidget(VentanaConexion);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(0, 105));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEditPort = new QLineEdit(groupBox);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout_2->addWidget(lineEditPort, 0, 1, 1, 2);

        pushButtonConexion = new QPushButton(groupBox);
        pushButtonConexion->setObjectName(QString::fromUtf8("pushButtonConexion"));

        gridLayout_2->addWidget(pushButtonConexion, 1, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        VentanaConexion->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(VentanaConexion);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        VentanaConexion->setStatusBar(statusbar);

        retranslateUi(VentanaConexion);

        QMetaObject::connectSlotsByName(VentanaConexion);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaConexion)
    {
        VentanaConexion->setWindowTitle(QCoreApplication::translate("VentanaConexion", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("VentanaConexion", "Seleccion de Puerto", nullptr));
        label->setText(QCoreApplication::translate("VentanaConexion", "Puerto", nullptr));
        pushButtonConexion->setText(QCoreApplication::translate("VentanaConexion", "Conectar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VentanaConexion: public Ui_VentanaConexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANACONEXION_H
