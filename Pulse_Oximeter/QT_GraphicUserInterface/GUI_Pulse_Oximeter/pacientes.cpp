#include "pacientes.h"
#include "ui_pacientes.h"

Pacientes::Pacientes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Pacientes)
{
    ui->setupUi(this);
    setWindowTitle("Paciente");
}

Pacientes::~Pacientes()
{
    delete ui;
}


void Pacientes::on_buttonBox_accepted()
{
    user.nombre = ui->lineEditNombre->text();
    user.apellido = ui->lineEditApellido->text().toUpper();
    user.dni = ui->lineEditDNI->text().toInt();

    if(ui->radioButtonM->isChecked())
        user.sexo = "Mujer";
    else if(ui->radioButtonH->isChecked())
        user.sexo = "Hombre";
}

Usuario Pacientes::getUsuario(void)
{
    return user;
}
