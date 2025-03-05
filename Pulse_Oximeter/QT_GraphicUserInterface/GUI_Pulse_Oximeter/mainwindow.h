/*
 * MainWindow.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Clase principal de la interfaz gráfica que gestiona la conexión TCP, ventanas de mediciones e historial.
 *      ENG --> Description: Main GUI class handling TCP connection, measurement, and history windows.
 *
 */

/* ESP
 * @brief Este archivo define la clase MainWindow, que representa la ventana principal de la aplicación.
 *        Gestiona la conexión TCP con el hardware, la interacción con las ventanas de mediciones en tiempo real
 *        y el historial de datos, además de controlar los elementos de la interfaz gráfica.
 *
 *      **Clase MainWindow**
 *
 *      **Variables Privadas**
 *
 *      ui:                 Puntero a la interfaz gráfica generada por Qt.
 *      servidor:           Puntero al objeto QTcpServer para gestionar conexiones entrantes.
 *      cliente:            Puntero al objeto QTcpSocket para manejar la comunicación con el cliente.
 *      window_medir:       Puntero a la ventana de mediciones en tiempo real (clase Mediciones).
 *      window_historial:   Puntero a la ventana de historial de datos (clase Historial).
 *
 *      **Slots Privados**
 *
 *      on_pushButtonSalir_clicked():
 *                          Slot para cerrar la aplicación al hacer clic en el botón "Salir".
 *      on_botonHistorial_clicked():
 *                          Slot para abrir/cerrar la ventana de historial de datos.
 *      on_botonMediciones_clicked():
 *                          Slot para abrir/cerrar la ventana de mediciones en tiempo real.
 *      open_close_menu():  Slot para alternar la visibilidad del menú principal.
 *      open_close_historial():
 *                          Slot para alternar la visibilidad de la ventana de historial.
 *
 *      **Métodos Públicos**
 *
 *      MainWindow(QWidget *parent = nullptr):
 *                          Constructor. Inicializa la interfaz y componentes.
 *      ~MainWindow():      Destructor. Libera recursos y cierra conexiones.
 *      setSocket(QTcpServer *, QTcpSocket *):
 *                          Configura los objetos de servidor y cliente TCP.
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file defines the MainWindow class, representing the application's main window.
 *        It handles TCP communication with hardware, interaction with real-time measurement
 *        and data history windows, and controls GUI elements.
 *
 *      **Class MainWindow**
 *
 *      **Private Variables**
 *
 *      ui:                 Pointer to the Qt-generated GUI interface.
 *      servidor:           Pointer to the QTcpServer object for managing incoming connections.
 *      cliente:            Pointer to the QTcpSocket object handling client communication.
 *      window_medir:       Pointer to the real-time measurements window (Mediciones class).
 *      window_historial:   Pointer to the data history window (Historial class).
 *
 *      **Private Slots**
 *
 *      on_pushButtonSalir_clicked():
 *                          Slot to close the application when clicking the "Exit" button.
 *      on_botonHistorial_clicked():
 *                          Slot to open/close the data history window.
 *      on_botonMediciones_clicked():
 *                          Slot to open/close the real-time measurements window.
 *      open_close_menu():  Slot to toggle the visibility of the main menu.
 *      open_close_historial():
 *                          Slot to toggle the visibility of the history window.
 *
 *      **Public Methods**
 *
 *      MainWindow(QWidget *parent = nullptr):
 *                          Constructor. Initializes the GUI and components.
 *      ~MainWindow():      Destructor. Releases resources and closes connections.
 *      setSocket(QTcpServer *, QTcpSocket *):
 *                          Configures TCP server and client objects.
 *
 * @param None
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "mediciones.h"
#include "historial.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSocket(QTcpServer * , QTcpSocket *);

private slots:
    void on_pushButtonSalir_clicked();
    void on_botonHistorial_clicked();
    void on_botonMediciones_clicked();

    void open_close_menu();
    void open_close_historial();

private:
    Ui::MainWindow *ui;
    QTcpServer *servidor;
    QTcpSocket *cliente;
    Mediciones *window_medir;
    Historial *window_historial;

};
#endif // MAINWINDOW_H
