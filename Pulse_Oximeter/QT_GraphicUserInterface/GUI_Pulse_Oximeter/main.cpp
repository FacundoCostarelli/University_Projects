#include <QApplication>
#include <QSerialPort>
#include "mainwindow.h"
#include "ventanaconexion.h"

/*
 * main.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Punto de entrada principal y configuración inicial de la aplicación.
 *      Gestiona la creación de ventanas y la ejecución del bucle de eventos.
 *      ENG --> Description: Main entry point and initial application setup.
 *      Handles window creation and event loop execution.
 *
 */




/************************NOTA ANTES DE USAR/NOTE BEFORE USING***************************
 * ESP
 * Cambiar en los métodos y slots:
 *    - open_historial (en historial.cpp)
 *    - on_botonGuardar_clicked (en historial.cpp)
 *    - on_botonBorrar_clicked (en historial.cpp)
 *    - on_botonGuardar_clicked (en mediciones.cpp)
 * La ruta donde quiero guardar el archivo con el historial de mediciones
 *
 * ENG
 * Change in the methods and slots:
 *    - open_historial (in historial.cpp)
 *    - on_botonGuardar_clicked (in historial.cpp)
 *    - on_botonBorrar_clicked (in historial.cpp)
 *    - on_botonGuardar_clicked (in mediciones.cpp)
 * The path where the file with the measurement history is to be saved
 **********************************************************************/




/* ESP
 * @brief Función principal de la aplicación.
 *        Inicializa la aplicación y las ventanas principales.
 *
 * @param argc Número de argumentos de la línea de comandos.
 * @param argv Array de cadenas con los argumentos de la línea de comandos.
 * @return Código de salida de la aplicación.
 *
 * ENG
 * @brief Main function of the application.
 *        Initializes the application and the main windows.
 *
 * @param argc Number of command-line arguments.
 * @param argv Array of strings with command-line arguments.
 * @return Application exit code.
 */

int main(int argc, char *argv[])
{
    // ESP: Crea la aplicación Qt con los argumentos proporcionados
    // ENG: Creates the Qt application with the provided arguments
    QApplication a(argc, argv);

    // ESP: Crea la ventana principal de la aplicación
    // ENG: Creates the main window of the application
    MainWindow w;

    // ESP: Crea la ventana de conexión asociada a la ventana principal
    // ENG: Creates the connection window associated with the main window
    VentanaConexion v(w);

    // ESP: Muestra la ventana de conexión al iniciar la aplicación
    // ENG: Displays the connection window when starting the application
    v.show();

    // ESP: Ejecuta el bucle de eventos de la aplicación
    // ENG: Executes the application's event loop
    return a.exec();
}
