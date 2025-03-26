/*
 * Pacientes.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Diálogo para capturar datos de pacientes y estructura de almacenamiento de información médica.
 *      ENG --> Description: Dialog for capturing patient data and medical information storage structure.
 *
 */

/* ESP
 * @brief Este archivo define la estructura de datos de pacientes y la clase para gestionar su entrada mediante un diálogo.
 *        Incluye validación básica de datos y persistencia temporal de la información.
 *
 *      **Estructura Usuario**
 *
 *      nombre:             Almacena el nombre del paciente (QString).
 *      apellido:           Almacena el apellido del paciente (QString).
 *      dni:                Almacena el Documento Nacional de Identidad (entero).
 *      fecha:              Almacena fecha y hora de registro (QDateTime).
 *      sexo:               Almacena género del paciente (QString).
 *
 *      **Clase Pacientes**
 *
 *      **Variables Privadas**
 *
 *      ui:                 Puntero a la interfaz gráfica generada por Qt.
 *      user:               Instancia de la estructura Usuario para almacenar datos capturados.
 *
 *      **Slots Privados**
 *
 *      on_buttonBox_accepted():
 *                          Slot ejecutado al aceptar el diálogo. Captura los datos ingresados en la estructura user.
 *
 *      **Métodos Públicos**
 *
 *      Pacientes(QWidget *parent = nullptr):
 *                          Constructor. Inicializa la interfaz del diálogo.
 *      ~Pacientes():       Destructor. Libera recursos de la interfaz.
 *      getUsuario(void):   Retorna la estructura Usuario con los datos capturados.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file defines the patient data structure and dialog class for data input.
 *        Includes basic data validation and temporary information persistence.
 *
 *      **Struct Usuario**
 *
 *      nombre:             Stores patient's first name (QString).
 *      apellido:           Stores patient's last name (QString).
 *      dni:                Stores national identification number (integer).
 *      fecha:              Stores registration date and time (QDateTime).
 *      sexo:               Stores patient's gender (QString).
 *
 *      **Class Pacientes**
 *
 *      **Private Variables**
 *
 *      ui:                 Pointer to the Qt-generated GUI interface.
 *      user:               Instance of Usuario structure to store captured data.
 *
 *      **Private Slots**
 *
 *      on_buttonBox_accepted():
 *                          Slot triggered when dialog is accepted. Captures input data into user structure.
 *
 *      **Public Methods**
 *
 *      Pacientes(QWidget *parent = nullptr):
 *                          Constructor. Initializes dialog interface.
 *      ~Pacientes():       Destructor. Releases interface resources.
 *      getUsuario(void):   Returns Usuario structure with captured data.
 *
 * @param None
 */

#ifndef PACIENTES_H
#define PACIENTES_H

#include <QDialog>
#include <QDateTime>

struct Usuario
{
    QString nombre;
    QString apellido;
    int dni;
    QDateTime fecha;
    QString sexo;
};


namespace Ui {
class Pacientes;
}

class Pacientes : public QDialog
{
    Q_OBJECT

public:
    explicit Pacientes(QWidget *parent = nullptr);
    ~Pacientes();
    Usuario getUsuario(void);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Pacientes *ui;
    Usuario user;
};

#endif // PACIENTES_H
