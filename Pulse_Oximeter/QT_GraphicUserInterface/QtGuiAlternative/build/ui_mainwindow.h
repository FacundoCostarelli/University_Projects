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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEditPort;
    QPushButton *conectar;
    QLabel *label_2;
    QPlainTextEdit *plainTextRecibir;
    QLabel *label_result_Spo2;
    QLabel *label_result_Hr;
    QLabel *label;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(400, 301);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEditPort = new QLineEdit(centralWidget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));
        lineEditPort->setGeometry(QRect(80, 20, 241, 20));
        conectar = new QPushButton(centralWidget);
        conectar->setObjectName(QString::fromUtf8("conectar"));
        conectar->setGeometry(QRect(170, 50, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 20, 31, 16));
        plainTextRecibir = new QPlainTextEdit(centralWidget);
        plainTextRecibir->setObjectName(QString::fromUtf8("plainTextRecibir"));
        plainTextRecibir->setGeometry(QRect(250, 90, 131, 161));


        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40,140,71,16));
        label_3->setText("HEART BEAT");

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40,100,49,16));
        label->setText("SPO2");

        label_result_Spo2 = new QLabel(centralWidget);
        label_result_Spo2->setObjectName(QString::fromUtf8("result_SPO2"));
        label_result_Spo2->setGeometry(QRect(120, 100, 113, 24));
        label_result_Spo2->setText("0");

        label_result_Hr = new QLabel(centralWidget);
        label_result_Hr->setObjectName(QString::fromUtf8("result_Heart_Beat"));
        label_result_Hr->setGeometry(QRect(120, 140, 113, 24));
        label_result_Hr->setText("0");

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Servidor", nullptr));
        conectar->setText(QCoreApplication::translate("MainWindow", "Conectar", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
