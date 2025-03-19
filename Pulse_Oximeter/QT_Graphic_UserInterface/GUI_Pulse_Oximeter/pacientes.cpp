#include "pacientes.h"
#include "ui_pacientes.h"

/*
 * pacientes.cpp
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Implementación del diálogo para gestión de datos pacientes, incluyendo
 *      captura y validación de información clínica básica.
 *      ENG --> Description: Implementation of patient data management dialog, including capture
 *      and validation of basic clinical information.
 *
 */




/* ESP
 * @brief Constructor de la clase Pacientes.
 *        Inicializa la interfaz de usuario para la gestión de pacientes.
 *
 * @param parent Puntero al widget padre.
 */
/* ENG
 * @brief Constructor of the Pacientes class.
 *        Initializes the user interface for patient management.
 *
 * @param parent Pointer to the parent widget.
 */

Pacientes::Pacientes(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Pacientes)
{
    ui->setupUi(this);
    setWindowTitle("Paciente");
}




/* ESP
 * @brief Destructor de la clase Pacientes.
 *        Libera la memoria asignada para la interfaz de usuario.
 */
/* ENG
 * @brief Destructor of the Pacientes class.
 *        Releases memory allocated for the user interface.
 */

Pacientes::~Pacientes()
{
    delete ui;
}




/* ESP
 * @brief Slot para aceptar los datos ingresados.
 *        Guarda los datos del paciente en la estructura Usuario.
 */
/* ENG
 * @brief Slot to accept the entered data.
 *        Stores the patient's data in the Usuario structure.
 */

void Pacientes::on_buttonBox_accepted()
{
    // ESP: Guarda el nombre del paciente desde el lineEdit.
    // ENG: Save the patient's name from the lineEdit.
    user.nombre = ui->lineEditNombre->text();

    // ESP: Guarda el apellido del paciente en mayúsculas desde el lineEdit.
    // ENG: Save the patient's last name in uppercase from the lineEdit.
    user.apellido = ui->lineEditApellido->text().toUpper();

    // ESP: Guarda el DNI del paciente desde el lineEdit.
    // ENG: Save the patient's ID from the lineEdit.
    user.dni = ui->lineEditDNI->text().toInt();

    // ESP: Guarda el sexo del paciente según el botón seleccionado.
    // ENG: Save the patient's gender according to the selected button.
    if(ui->radioButtonM->isChecked())
        user.sexo = "Mujer";
    else if(ui->radioButtonH->isChecked())
        user.sexo = "Hombre";
}




/* ESP
 * @brief Devuelve los datos del paciente almacenados.
 *
 * @return Usuario con los datos del paciente.
 */
/* ENG
 * @brief Returns the stored patient data.
 *
 * @return Usuario with the patient's data.
 */

Usuario Pacientes::getUsuario(void)
{
    return user;
}
