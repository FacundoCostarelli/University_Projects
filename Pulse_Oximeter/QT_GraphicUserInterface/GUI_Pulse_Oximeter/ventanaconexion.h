/*
 * VentanaConexion.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Clase para gestionar la conexión TCP entre la interfaz gráfica y el dispositivo médico.
 *      ENG --> Description: Class to manage TCP connection between GUI and medical device.
 *
 */

/* ESP
 * @brief Este archivo define la clase VentanaConexion que maneja la configuración y establecimiento de la comunicación TCP.
 *        Implementa la lógica del servidor para recibir datos del sensor y actualizar la ventana principal.

 *      **Clase VentanaConexion**

 *      **Variables Privadas**
 *
 *      ui:                 Puntero a la interfaz gráfica generada por Qt.
 *      ventanappal:        Referencia a la ventana principal para actualizar su estado.
 *      servidor:           Objeto QTcpServer para gestionar conexiones entrantes.
 *      cliente:            Objeto QTcpSocket para manejar la comunicación con el dispositivo.

 *      **Slots Privados**
 *
 *      on_pushButtonConexion_clicked():
 *                          Slot para iniciar/detener el servidor TCP al hacer clic en el botón "Conectar".
 *      nuevoCliente():     Slot que se ejecuta cuando se detecta una nueva conexión entrante.

 *      **Métodos Públicos**
 *
 *      VentanaConexion(MainWindow &):
 *                          Constructor. Recibe referencia a MainWindow para coordinación entre ventanas.
 *      ~VentanaConexion(): Destructor. Libera recursos de red y memoria.

 * @param Ninguno
 */

/* ENG
 * @brief This file defines the VentanaConexion class handling TCP communication setup and management.
 *        Implements server logic to receive sensor data and update main window.

 *      **Class VentanaConexion**

 *      **Private Variables**
 *
 *      ui:                 Pointer to Qt-generated GUI interface.
 *      ventanappal:        Reference to main window for state updates.
 *      servidor:           QTcpServer object to manage incoming connections.
 *      cliente:            QTcpSocket object to handle device communication.

 *      **Private Slots**
 *
 *      on_pushButtonConexion_clicked():
 *                          Slot to start/stop TCP server when clicking "Connect" button.
 *      nuevoCliente():     Slot triggered when new incoming connection is detected.

 *      **Public Methods**
 *
 *      VentanaConexion(MainWindow &):
 *                          Constructor. Takes MainWindow reference for window coordination.
 *      ~VentanaConexion(): Destructor. Releases network resources and memory.

 * @param None
 */

#ifndef VENTANACONEXION_H
#define VENTANACONEXION_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>
#include "mainwindow.h"

namespace Ui {
class VentanaConexion;
}

class VentanaConexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaConexion(MainWindow &);
    ~VentanaConexion();

private slots:
    void on_pushButtonConexion_clicked();
    void nuevoCliente();

private:
    Ui::VentanaConexion *ui;
    MainWindow *ventanappal;
    QTcpServer *servidor;
    QTcpSocket *cliente;

};

#endif // VENTANACONEXION_H

