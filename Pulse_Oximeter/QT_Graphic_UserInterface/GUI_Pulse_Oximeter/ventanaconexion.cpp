#include "ventanaconexion.h"
#include "ui_ventanaconexion.h"

/*
 * ventanaconexión.cpp
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Implementación de la ventana de configuración inicial para conexión WiFi
 *      y establecimiento de servidor TCP/IP.
 *      ENG --> Description: Implementation of the initial setup window for WiFi connection and TCP/IP
 *      server establishment
 *
 */




/* ESP
 * @brief Constructor de la clase VentanaConexion.
 *        Inicializa la ventana de conexión WiFi.
 *
 * @param ppal Referencia a la ventana principal.
 */

VentanaConexion::VentanaConexion(MainWindow &ppal) :
    QMainWindow(nullptr),
    ui(new Ui::VentanaConexion)
{
    ui->setupUi(this);
    setWindowTitle("Conexion WiFi");
    this->setFixedSize(this->width(),this->height());

    // ESP: Inicializa los punteros a servidor y cliente como NULL.
    // ENG: Initializes server and client pointers to NULL.
    servidor = NULL;
    cliente = NULL;

    // ESP: Guarda la referencia a la ventana principal.
    // ENG: Stores the reference to the main window.
    ventanappal = &ppal;
}




/* ESP
 * @brief Destructor de la clase VentanaConexion.
 *        Libera los recursos asociados.
 */
/* ENG
 * @brief Destructor of the VentanaConexion class.
 *        Releases associated resources.
 */

VentanaConexion::~VentanaConexion()
{
    delete ui;
}




/* ESP
 * @brief Slot para manejar el clic en el botón de conexión.
 *        Inicia la escucha del servidor en la dirección y puerto especificados.
 */
/* ENG
 * @brief Slot to handle the click on the connection button.
 *        Starts the server listening on the specified address and port.
 */

void VentanaConexion::on_pushButtonConexion_clicked()
{
    if(!servidor)
    {
        // ESP: Crea el objeto QTcpServer y empieza a escuchar.
        // ENG: Creates the QTcpServer object and starts listening.
        servidor = new QTcpServer(this);
        servidor->listen(QHostAddress::Any, ui->lineEditPort->text().toInt());

        // ESP: Conecta la señal de nueva conexión con el slot correspondiente.
        // ENG: Connects the new connection signal to the corresponding slot.
        connect(servidor, SIGNAL(newConnection()), this, SLOT(nuevoCliente()));

        // ESP: Cambia el texto y apariencia del botón para indicar que está conectando.
        // ENG: Changes the button text and appearance to indicate connecting.
        ui->pushButtonConexion->setText("Conectando...");
        ui->pushButtonConexion->setStyleSheet("color: grey;");
        ui->pushButtonConexion->setEnabled(false);
    }
}




/* ESP
 * @brief Slot para manejar la llegada de un nuevo cliente.
 *        Acepta la conexión entrante y muestra la ventana principal.
 */
/* ENG
 * @brief Slot to handle the arrival of a new client.
 *        Accepts the incoming connection and shows the main window.
 */

void VentanaConexion::nuevoCliente(void)
{
    if(!cliente)
    {
        // ESP: Acepta la conexión pendiente y almacena el socket del cliente.
        // ENG: Accepts the pending connection and stores the client socket.
        cliente = new QTcpSocket;
        cliente = servidor->nextPendingConnection();

        // ESP: Configura la ventana principal con los sockets de servidor y cliente.
        // ENG: Sets up the main window with the server and client sockets.
        ventanappal->setSocket(servidor, cliente);

        // ESP: Muestra la ventana principal y cierra la ventana de conexión.
        // ENG: Shows the main window and closes the connection window.
        ventanappal->show();
        this->close();
    }
}
