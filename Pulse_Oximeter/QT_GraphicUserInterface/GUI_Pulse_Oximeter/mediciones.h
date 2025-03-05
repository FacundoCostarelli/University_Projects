/*
 * Mediciones.h
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Clase para gestionar la ventana de mediciones en tiempo real del sensor MAX30102 recibidas vía TCP.
 *      ENG --> Description: Class to manage the real-time measurement window for MAX30102 sensor data received via TCP.
 *
 */

/* ESP
 * @brief Este archivo define la clase Mediciones, que maneja la visualización y almacenamiento de datos de oxígeno y ritmo cardíaco
 *        recibidos desde el hardware a través de una conexión TCP. Incluye un parser para procesar tramas de datos.
 *
 *      **Macros**
 *
 *      HEADER:             Estado inicial del parser para detectar el inicio de una trama.
 *      OXIGENO:            Estado para procesar el valor de oxígeno en la trama.
 *      HEARTRATE:          Estado para procesar el valor de ritmo cardíaco en la trama.
 *      FIN_TRAMA:          Estado para detectar el fin de una trama.
 *
 *      **Clase Mediciones**
 *
 *      **Variables Privadas**
 *
 *      ui:                 Puntero a la interfaz gráfica generada por Qt.
 *      servidor:           Puntero al objeto QTcpServer para gestionar conexiones entrantes.
 *      cliente:            Puntero al objeto QTcpSocket para manejar la comunicación con el cliente.
 *      menu:               Bandera que indica si el menú está visible o no.
 *      m_oxigeno:          Almacena el último valor de oxígeno recibido del sensor.
 *      m_heartrate:        Almacena el último valor de ritmo cardíaco recibido del sensor.
 *
 *      **Slots Privados**
 *
 *      on_botonMenu_clicked():
 *                          Slot para alternar la visibilidad del menú lateral.
 *      on_botonSalir_clicked():
 *                          Slot para cerrar la ventana de mediciones.
 *      on_botonGuardar_clicked():
 *                          Slot para guardar los datos actuales en un archivo.
 *      data_medicion():    Slot para procesar los datos recibidos a través de TCP.
 *
 *      **Métodos Públicos**
 *
 *      Mediciones(QWidget *parent = nullptr):
 *                          Constructor. Inicializa la interfaz y configura conexiones.
 *      ~Mediciones():      Destructor. Libera recursos y cierra conexiones.
 *      setSocket(QTcpServer *, QTcpSocket *):
 *                          Configura los objetos de servidor y cliente TCP.
 *      getMenu():          Retorna el estado de visibilidad del menú.
 *      MdE_lectura_mediciones(int):
 *                          Máquina de estados para procesar tramas de datos (parser).
 *
 * @param Ninguno
 */

/* ENG
 * @brief This file defines the Mediciones class, which handles the display and storage of oxygen and heart rate data
 *        received from hardware via TCP. Includes a parser to process data frames.
 *
 *      **Macros**
 *
 *      HEADER:             Initial state of the parser to detect the start of a frame.
 *      OXIGENO:            State to process the oxygen value in the frame.
 *      HEARTRATE:          State to process the heart rate value in the frame.
 *      FIN_TRAMA:          State to detect the end of a frame.
 *
 *      **Class Mediciones**
 *
 *      **Private Variables**
 *
 *      ui:                 Pointer to the Qt-generated GUI interface.
 *      servidor:           Pointer to the QTcpServer object for managing incoming connections.
 *      cliente:            Pointer to the QTcpSocket object handling client communication.
 *      menu:               Flag indicating the visibility of the side menu.
 *      m_oxigeno:          Stores the latest oxygen value received from the sensor.
 *      m_heartrate:        Stores the latest heart rate value received from the sensor.
 *
 *      **Private Slots**
 *
 *      on_botonMenu_clicked():
 *                          Slot to toggle the visibility of the side menu.
 *      on_botonSalir_clicked():
 *                          Slot to close the measurement window.
 *      on_botonGuardar_clicked():
 *                          Slot to save current data to a file.
 *      data_medicion():    Slot to process data received via TCP.
 *
 *      **Public Methods**
 *
 *      Mediciones(QWidget *parent = nullptr):
 *                          Constructor. Initializes the GUI and configures connections.
 *      ~Mediciones():      Destructor. Releases resources and closes connections.
 *      setSocket(QTcpServer *, QTcpSocket *):
 *                          Configures TCP server and client objects.
 *      getMenu():          Returns the visibility state of the menu.
 *      MdE_lectura_mediciones(int):
 *                          State machine to process data frames (parser).
 *
 * @param None
 */

#ifndef MEDICIONES_H
#define MEDICIONES_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QByteArray>
#include <QFile>
#include "pacientes.h"

#define HEADER      0
#define OXIGENO     1
#define HEARTRATE   2
#define FIN_TRAMA   3

namespace Ui {
class Mediciones;
}

class Mediciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mediciones(QWidget *parent = nullptr);
    ~Mediciones();

    void setSocket(QTcpServer * , QTcpSocket *);
    inline bool getMenu(){return menu;}
    void MdE_lectura_mediciones(int);

private slots:
    void on_botonMenu_clicked();
    void on_botonSalir_clicked();
    void on_botonGuardar_clicked();
    void data_medicion();

private:
    Ui::Mediciones *ui;
    QTcpServer *servidor;
    QTcpSocket *cliente;
    bool menu;
    int m_oxigeno;
    int m_heartrate;
};

#endif // MEDICIONES_H
