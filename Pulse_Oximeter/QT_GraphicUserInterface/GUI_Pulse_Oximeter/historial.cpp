#include "historial.h"
#include "ui_historial.h"
#include <QMessageBox>

/*
 * Historial.cpp
 *
 *  Created on: 20 Nov. 2024]
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Implementación de la clase Historial que gestiona el almacenamiento,
 *      visualización y edición del historial de datos del sensor en la interfaz gráfica.
 *      Incluye operaciones de archivo y manejo de eventos de la UI.
 *
 *      ENG --> Description: Implementation of the Historial class managing the storage, display,
 *      and editing of sensor data history in the graphical interface.
 *      Includes file operations and UI event handling.
 *
 */

/***********************NOTA ANTES DE USAR/ NOTE BEFORE USING*********************************
 * ESP
 * @brief Cambiar en los métodos y slots la ruta donde se guardará el archivo con el historial de las mediciones.
 *        Métodos y slots afectados:
 *        - open_historial
 *        - on_botonGuardar_clicked
 *        - on_botonBorrar_clicked
 * ENG
 * @brief Change in the methods and slots the path where the file with the measurement history will be saved.
 *        Affected methods and slots:
 *        - open_historial
 *        - on_botonGuardar_clicked
 *        - on_botonBorrar_clicked
 **************************************************************************/


/* ESP
 * @brief Constructor de la clase Historial.
 *        Inicializa la interfaz y configura la ventana.
 *
 * @param parent Puntero al widget padre.
 * ENG
 * @brief Constructor of the Historial class.
 *        Initializes the interface and configures the window.
 *
 * @param parent Pointer to the parent widget.
 */

Historial::Historial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Historial)
{
    ui->setupUi(this);
    setWindowTitle("Historial");
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setCursor(Qt::ArrowCursor);
    ui->botonGuardar->setEnabled(false);
}




/* ESP
 * @brief Destructor de la clase Historial.
 *        Libera la memoria reservada para la interfaz.
 * ENG
 * @brief Destructor of the Historial class.
 *        Releases the memory allocated for the interface.
 */

Historial::~Historial()
{
    delete ui;
}




/* ESP
 * @brief Abre o crea un archivo para mostrar el historial de mediciones.
 *        Si el archivo existe, carga su contenido en el widget de texto.
 *        Si no existe, muestra un mensaje informando que está vacío.
 * ENG
 * @brief Opens or creates a file to display the measurement history.
 *        If the file exists, loads its content into the text widget.
 *        If it does not exist, shows a message informing it is empty.
 */

void Historial::open_historial(void)
{
    // ESP: Creo un objeto QFile que se asocia a un archivo enrutado y un objeto QTexStream que guarda la información contenida en el archivo del tipo QFile.
    // ENG: Creates a QFile object associated with a routed file and a QTextStream object that saves the information contained within the file of QFile type.
    archivo = new QFile("C:/Users/Facun/Documents/QT/GUI_Pulse_Oximeter/Output_files/historial_v2.txt");
    flujo = new QTextStream(archivo);

    // ESP: Abre el archivo en modo solo lectura.
    // ENG: Opens the file in read-only mode.
    if(archivo->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!flujo->atEnd())
        {
            QString linea = flujo->readLine();
            ui->textEdit->append(linea);
        }
        archivo->close(); // Cerrar el archivo cuando termines
    }
    else
        QMessageBox::information(this, "Historial", "El historial esta vacio");

    delete flujo;
    delete archivo;
}




//Slots
/* ESP
 * @brief Slot que se ejecuta al presionar el botón de menú.
 *        Cierra la ventana actual y regresa al menú principal.
 * ENG
 * @brief Slot executed when the menu button is pressed.
 *        Closes the current window and returns to the main menu.
 */

void Historial::on_botonMenu_clicked()
{
    menu = true;
    this->close();
}




/* ESP
 * @brief Slot que se ejecuta al presionar el botón de salir.
 *        Cierra la ventana actual y termina la aplicación.
 * ENG
 * @brief Slot executed when the exit button is pressed.
 *        Closes the current window and ends the application.
 */

void Historial::on_botonSalir_clicked()
{
    menu = false;
    this->close();
}




/* ESP
 * @brief Slot que permite la edición del historial al presionar el botón Editar.
 *        Cambia el estado del widget de texto para permitir la edición.
 * ENG
 * @brief Slot that allows editing of the history when the Edit button is pressed.
 *        Changes the text widget state to allow editing.
 */

void Historial::on_botonEditar_clicked()
{
    ui->botonGuardar->setEnabled(true);
    ui->textEdit->setReadOnly(false);
    ui->textEdit->setCursor(Qt::IBeamCursor);
    ui->textEdit->setStyleSheet("QTextEdit {border: 1px solid rgb(0,150,0)}");
}




/* ESP
 * @brief Slot que guarda el historial editado en el archivo.
 *        Deshabilita la edición y restaura el aspecto del widget de texto.
 * ENG
 * @brief Slot that saves the edited history into the file.
 *        Disables editing and restores the appearance of the text widget.
 */

void Historial::on_botonGuardar_clicked()
{
    ui->botonGuardar->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setCursor(Qt::ArrowCursor);
    ui->textEdit->setStyleSheet("QTextEdit {border: 1px solid grey}");

    archivo = new QFile("C:/Users/Facun/Documents/QT/GUI_Pulse_Oximeter/Output_files/historial_v2.txt");
    flujo = new QTextStream(archivo);

    if(archivo->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString newText = ui->textEdit->toPlainText();
        (*flujo) << newText;
        archivo->close();
    }
    else
        QMessageBox::warning(this, "Historial", "Error al editar el historial");

    delete flujo;
    delete archivo;
}




/* ESP
 * @brief Borra el archivo de historial y limpia la interfaz.
 * ENG
 * @brief Deletes the history file and clears the interface.
 */
void Historial::on_botonBorrar_clicked()
{
    archivo = new QFile("C:/Users/Facun/Documents/QT/GUI_Pulse_Oximeter/Output_files/historial_v2.txt");
    if(archivo->remove())
    {
        ui->textEdit->clear();
        QMessageBox::information(this, "Historial", "El historial se elimino correctamente ");
    }
    else
        QMessageBox::warning(this, "Historial", "Error al eliminar el historial");
}

