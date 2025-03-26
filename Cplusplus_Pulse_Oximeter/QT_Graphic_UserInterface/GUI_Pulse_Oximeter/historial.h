/*
 * Historial.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Declaraciones para la clase Historial que gestiona el historial de datos del sensor en la interfaz gráfica.
 *      ENG --> Description: Declarations for the Historial class managing the sensor data history in the graphical interface.
 *
 */

/* ESP
 * @brief Este archivo contiene las declaraciones de la clase Historial, encargada de gestionar la visualización y edición del historial de datos del sensor.
 *        Incluye métodos para abrir, guardar, borrar y editar el archivo de historial, así como slots para manejar eventos de la interfaz.
 *
 *      **Clase Historial**
 *
 *      **Variables Privadas**
 *
 *      ui:                 Puntero a la interfaz de usuario generada por Qt.
 *      archivo:            Puntero al objeto QFile que maneja el archivo de historial.
 *      flujo:             Puntero al objeto QTextStream para leer/escribir en el archivo.
 *      menu:               Bandera que indica el estado del menú (abierto/cerrado).
 *
 *      **Slots Privados**
 *
 *      on_botonMenu_clicked():
 *                          Slot para manejar el clic del botón "Menu". Regresa a la ventana principal.
 *      on_botonSalir_clicked():
 *                          Slot para manejar el clic del botón "Salir". Cierra la aplicación.
 *      on_botonEditar_clicked():
 *                          Slot para manejar el clic del botón "Editar". Habilita la edición del historial.
 *      on_botonGuardar_clicked():
 *                          Slot para manejar el clic del botón "Guardar". Guarda los cambios en el archivo.
 *      on_botonBorrar_clicked():
 *                          Slot para manejar el clic del botón "Borrar". Elimina el contenido del historial.
 *
 *      **Métodos Públicos**
 *
 *      Historial(QWidget *parent = nullptr):
 *                          Constructor de la clase. Inicializa la interfaz y componentes.
 *      ~Historial():
 *                          Destructor. Libera los recursos de la interfaz y cierra el archivo.
 *      bool getMenu():
 *                          Método inline que devuelve el estado actual del menú.
 *      void open_historial(void):
 *                          Abre el archivo de historial y carga su contenido en la interfaz.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file contains the declarations for the Historial class, responsible for managing the display and editing of sensor data history.
 *        Includes methods to open, save, delete, and edit the history file, as well as slots to handle interface events.
 *
 *      **Class Historial**
 *
 *      **Private Variables**
 *
 *      ui:                 Pointer to the Qt-generated user interface.
 *      archivo:            Pointer to the QFile object managing the history file.
 *      flujo:             Pointer to the QTextStream object for reading/writing to the file.
 *      menu:               Flag indicating the menu state (open/closed).
 *
 *      **Private Slots**
 *
 *      on_botonMenu_clicked():
 *                          Slot to handle the "Menu" button click. Returns to the main window.
 *      on_botonSalir_clicked():
 *                          Slot to handle the "Exit" button click. Closes the application.
 *      on_botonEditar_clicked():
 *                          Slot to handle the "Edit" button click. Enables history editing.
 *      on_botonGuardar_clicked():
 *                          Slot to handle the "Save" button click. Saves changes to the file.
 *      on_botonBorrar_clicked():
 *                          Slot to handle the "Delete" button click. Clears the history content.
 *
 *      **Public Methods**
 *
 *      Historial(QWidget *parent = nullptr):
 *                          Class constructor. Initializes the interface and components.
 *      ~Historial():
 *                          Destructor. Releases interface resources and closes the file.
 *      bool getMenu():
 *                          Inline method returning the current menu state.
 *      void open_historial(void):
 *                          Opens the history file and loads its content into the interface.
 *
 * @param None
 */

#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Historial;
}

class Historial : public QMainWindow
{
    Q_OBJECT

public:
    explicit Historial(QWidget *parent = nullptr);
    ~Historial();

    inline bool getMenu(){return menu;}
    void open_historial(void);

private slots:
    void on_botonMenu_clicked();
    void on_botonSalir_clicked();
    void on_botonEditar_clicked();
    void on_botonGuardar_clicked();
    void on_botonBorrar_clicked();

private:
    Ui::Historial *ui;
    QFile *archivo;
    QTextStream *flujo;
    bool menu;
};

#endif // HISTORIAL_H
