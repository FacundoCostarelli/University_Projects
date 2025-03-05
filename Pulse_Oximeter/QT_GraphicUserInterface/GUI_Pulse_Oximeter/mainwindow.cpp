#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QTimer>

/*
 * mainwindow.cpp
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Implementación de la ventana principal que gestiona la navegación
 *      entre funcionalidades, configuración de red y adaptación de interfaz gráfica al dispositivo.
 *      ENG --> Description: Implementation of the main window handling feature navigation,
 *         network configuration, and GUI adaptation to the device.
 *
 */




/* ESP
 * @brief Constructor de la clase MainWindow.
 *        Inicializa la interfaz gráfica y ajusta el tamaño de la ventana.
 *
 * @param parent Puntero al widget padre.
 *
 * ENG
 * @brief Constructor of the MainWindow class.
 *        Initializes the graphical interface and adjusts the window size.
 *
 * @param parent Pointer to the parent widget.
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        // ESP: Obtiene el tamaño de la pantalla y lo aplica a la ventana.
        // ENG: Gets the screen size and applies it to the window.
        QRect screenGeometry = screen->geometry();
        this->resize(screenGeometry.width(), screenGeometry.height());
    }
}




/* ESP
 * @brief Destructor de la clase MainWindow.
 *        Libera la memoria utilizada por la interfaz gráfica.
 *
 * ENG
 * @brief Destructor of the MainWindow class.
 *        Frees the memory used by the graphical interface.
 */

MainWindow::~MainWindow()
{
    delete ui;
}




/* ESP
 * @brief Método para configurar los sockets de servidor y cliente.
 *
 * @param s Puntero al objeto QTcpServer.
 * @param c Puntero al objeto QTcpSocket.
 *
 * ENG
 * @brief Method to set server and client sockets.
 *
 * @param s Pointer to the QTcpServer object.
 * @param c Pointer to the QTcpSocket object.
 */

void MainWindow::setSocket(QTcpServer *s , QTcpSocket *c)
{
    servidor = s;
    cliente = c;
}




/* ESP
 * @brief Slot para manejar la acción de salir de la aplicación.
 *        Cierra las conexiones de red y la ventana.
 *
 * ENG
 * @brief Slot to handle the application exit action.
 *        Closes network connections and the window.
 */

void MainWindow::on_pushButtonSalir_clicked()
{
    cliente->close();
    cliente = NULL;

    servidor->close();
    delete servidor;
    servidor = NULL;

    this->close();
}




/* ESP
 * @brief Slot para abrir la ventana de mediciones.
 *        Desconecta el socket y crea la nueva ventana.
 *
 * ENG
 * @brief Slot to open the measurement window.
 *        Disconnects the socket and creates the new window.
 */

void MainWindow::on_botonMediciones_clicked()
{
    window_medir = new Mediciones;

    disconnect(cliente, &QTcpSocket::readyRead, nullptr, nullptr);    //Desconecto el puerto

    window_medir->setSocket(servidor, cliente);

    //Abro la ventana y seteo para que cuando se cierre pueda volver al menu o cerrar la aplicacion
    window_medir->setAttribute(Qt::WA_DeleteOnClose);
    window_medir->resize(this->width(), this->height());
    window_medir->show();
    connect(window_medir, &Mediciones::destroyed, this, &MainWindow::open_close_menu);

    this->hide();
}




/* ESP
 * @brief Slot para abrir la ventana de historial.
 *        Crea la nueva ventana y la muestra.
 *
 * ENG
 * @brief Slot to open the history window.
 *        Creates the new window and shows it.
 */

void MainWindow::on_botonHistorial_clicked()
{
    window_historial = new Historial;

    window_historial->setAttribute(Qt::WA_DeleteOnClose);
    window_historial->resize(this->width(), this->height());
    window_historial->show();
    window_historial->open_historial();
    connect(window_historial, &Historial::destroyed, this, &MainWindow::open_close_historial);

    this->hide();
}




/* ESP
 * @brief Método para manejar el cierre de la ventana de mediciones.
 *
 * ENG
 * @brief Method to handle the closing of the measurement window.
 */

void MainWindow::open_close_menu()
{
    if(window_medir->getMenu()==true)
        this->show();
    else
        on_pushButtonSalir_clicked();
}




/* ESP
 * @brief Método para manejar el cierre de la ventana de historial.
 *
 * ENG
 * @brief Method to handle the closing of the history window.
 */

void MainWindow::open_close_historial()
{
    if(window_historial->getMenu()==true)
        this->show();
    else
        on_pushButtonSalir_clicked();
}
