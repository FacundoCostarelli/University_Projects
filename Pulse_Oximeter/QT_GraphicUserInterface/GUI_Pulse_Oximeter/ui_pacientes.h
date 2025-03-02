/********************************************************************************
** Form generated from reading UI file 'pacientes.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PACIENTES_H
#define UI_PACIENTES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_Pacientes
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QLabel *labelNombre;
    QLabel *labelApellido;
    QLabel *labelDNI;
    QLabel *labelSexo;
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *radioButtonH;
    QRadioButton *radioButtonM;
    QLineEdit *lineEditDNI;
    QLineEdit *lineEditApellido;
    QLineEdit *lineEditNombre;

    void setupUi(QDialog *Pacientes)
    {
        if (Pacientes->objectName().isEmpty())
            Pacientes->setObjectName(QString::fromUtf8("Pacientes"));
        Pacientes->resize(346, 220);
        QFont font;
        font.setFamilies({QString::fromUtf8("Manjari")});
        Pacientes->setFont(font);
        gridLayout = new QGridLayout(Pacientes);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 4, 2, 1, 1);

        labelNombre = new QLabel(Pacientes);
        labelNombre->setObjectName(QString::fromUtf8("labelNombre"));

        gridLayout->addWidget(labelNombre, 0, 0, 1, 1);

        labelApellido = new QLabel(Pacientes);
        labelApellido->setObjectName(QString::fromUtf8("labelApellido"));

        gridLayout->addWidget(labelApellido, 1, 0, 1, 1);

        labelDNI = new QLabel(Pacientes);
        labelDNI->setObjectName(QString::fromUtf8("labelDNI"));

        gridLayout->addWidget(labelDNI, 2, 0, 1, 1);

        labelSexo = new QLabel(Pacientes);
        labelSexo->setObjectName(QString::fromUtf8("labelSexo"));

        gridLayout->addWidget(labelSexo, 3, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Pacientes);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 6, 1, 1, 3);

        groupBox = new QGroupBox(Pacientes);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        radioButtonH = new QRadioButton(groupBox);
        radioButtonH->setObjectName(QString::fromUtf8("radioButtonH"));

        horizontalLayout->addWidget(radioButtonH);

        radioButtonM = new QRadioButton(groupBox);
        radioButtonM->setObjectName(QString::fromUtf8("radioButtonM"));

        horizontalLayout->addWidget(radioButtonM);


        gridLayout->addWidget(groupBox, 3, 1, 1, 3);

        lineEditDNI = new QLineEdit(Pacientes);
        lineEditDNI->setObjectName(QString::fromUtf8("lineEditDNI"));

        gridLayout->addWidget(lineEditDNI, 2, 1, 1, 3);

        lineEditApellido = new QLineEdit(Pacientes);
        lineEditApellido->setObjectName(QString::fromUtf8("lineEditApellido"));

        gridLayout->addWidget(lineEditApellido, 1, 1, 1, 3);

        lineEditNombre = new QLineEdit(Pacientes);
        lineEditNombre->setObjectName(QString::fromUtf8("lineEditNombre"));

        gridLayout->addWidget(lineEditNombre, 0, 1, 1, 3);


        retranslateUi(Pacientes);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Pacientes, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Pacientes, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Pacientes);
    } // setupUi

    void retranslateUi(QDialog *Pacientes)
    {
        Pacientes->setWindowTitle(QCoreApplication::translate("Pacientes", "Dialog", nullptr));
        labelNombre->setText(QCoreApplication::translate("Pacientes", "Nombre", nullptr));
        labelApellido->setText(QCoreApplication::translate("Pacientes", "Apellido", nullptr));
        labelDNI->setText(QCoreApplication::translate("Pacientes", "DNI", nullptr));
        labelSexo->setText(QCoreApplication::translate("Pacientes", "Sexo", nullptr));
        groupBox->setTitle(QString());
        radioButtonH->setText(QCoreApplication::translate("Pacientes", "Hombre", nullptr));
        radioButtonM->setText(QCoreApplication::translate("Pacientes", "Mujer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pacientes: public Ui_Pacientes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PACIENTES_H
