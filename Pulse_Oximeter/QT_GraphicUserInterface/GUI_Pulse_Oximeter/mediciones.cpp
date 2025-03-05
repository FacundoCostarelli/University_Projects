#include "mediciones.h"
#include "ui_mediciones.h"
#include <QMessageBox>
#include <QRegularExpression>

/*
 * mediciones.cpp
 *
 *  Created on: 20 Nov. 2024
 *      Author: Ezequiel Lagatche
 *		ESP --> Descripción: Implementación de la ventana de mediciones en tiempo real con visualización
 *      de datos sensoriales y almacenamiento seguro en historial clínico.
 *      ENG --> Description: Implementation of the real-time measurement window with sensor data visualization
 *      and secure clinical history storage.
 *
 */




/***********************NOTA ANTES DE USAR/NOTE BEFORE USING*********************************
 * ESP:
 * Cambiar en el slot:
 *  - on_botonGuardar_clicked
 * La ruta donde quiero guardar el archivo con el historial de las mediciones
 * ENG:
 * Change in the slot:
 *  - on_botonGuardar_clicked
 *  The route where i want to sabe the file with the measures history
 **************************************************************************/




/* ESP
 * @brief Constructor de la clase Mediciones.
 *        Inicializa la interfaz gráfica para la visualización de las mediciones.
 *
 * @param parent Puntero al widget padre.
 */
/* ENG
 * @brief Constructor of the Mediciones class.
 *        Initializes the graphical interface for measurement visualization.
 *
 * @param parent Pointer to the parent widget.
 */

Mediciones::Mediciones(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mediciones)
{
    ui->setupUi(this);
    setWindowTitle("Mediciones");

    // ESP: Configuración de los displays LCD.
    // ENG: LCD displays configuration.
    ui->lcdHeartrate->setDigitCount(4);
    ui->lcdHeartrate->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdOxigeno->setDigitCount(4);
    ui->lcdOxigeno->setSegmentStyle(QLCDNumber::Flat);

    // ESP: Estilos de los displays para ritmo cardíaco y oxígeno.
    // ENG: Styles for heart rate and oxygen displays.
    ui->lcdHeartrate->setStyleSheet(
        "QLCDNumber {"
        "   color: red;"                // ESP: Cambiar color del numero. ENG: Change number color.
        "   border: 2px solid red;"     // Cambiar color del borde. ENG: Change edge color.
        "}"
    );
    ui->lcdOxigeno->setStyleSheet(
        "QLCDNumber {"
        "   color: blue;"                // Cambiar color del numero
        "   border: 2px solid blue;"     // Cambiar color del borde
        "}"
    );
    ui->label->setStyleSheet("QLabel {color: red;}");
    ui->label_2->setStyleSheet("QLabel {color: blue;}");
}




/* ESP
 * @brief Destructor de la clase Mediciones.
 *        Libera la memoria reservada para la interfaz.
 */
/* ENG
 * @brief Destructor of the Mediciones class.
 *        Releases memory allocated for the interface.
 */

Mediciones::~Mediciones()
{
    delete ui;
}




/* ESP
 * @brief Configura el puerto de comunicaciones para recibir datos de mediciones.
 *
 * @param s Puntero al servidor TCP.
 * @param c Puntero al socket TCP.
 */
/* ENG
 * @brief Configures the communication port to receive measurement data.
 *
 * @param s Pointer to the TCP server.
 * @param c Pointer to the TCP socket.
 */

void Mediciones::setSocket(QTcpServer *s , QTcpSocket *c)
{
    servidor = s;
    cliente = c;

    connect(cliente, SIGNAL(readyRead()), this, SLOT(data_medicion()));
}




/* ESP
 * @brief Máquina de estados para procesar los datos recibidos.
 *
 * @param dato Valor recibido.
 */
/* ENG
 * @brief State machine to process received data.
 *
 * @param dato Received value.
 */

void Mediciones::MdE_lectura_mediciones(int dato)
{
    static uint8_t estado = HEADER;

    switch(estado)
    {
    case HEADER:
        if(dato == 0)
            estado = HEARTRATE;

        if(dato == 1)
            estado = OXIGENO;

        break;

    case HEARTRATE:
        m_heartrate = dato;
        estado = HEADER;
        break;

    case OXIGENO:
        m_oxigeno = dato;
        estado = HEADER;
        break;

    default:
        estado = HEADER;
        break;
    }
}




/* ESP
 * @brief Lee los datos del socket y actualiza los displays.
 */
/* ENG
 * @brief Reads data from the socket and updates the displays.
 */

void Mediciones::data_medicion()
{
    QByteArray data = cliente->read(cliente->bytesAvailable());
    if(!data.isEmpty())
    {
        QString strData = QString::fromUtf8(data);  // Convierte los bytes a cadena
        bool ok;
        int value = strData.toInt(&ok);  // Convierte la cadena a un entero

        if(ok)
        {
            MdE_lectura_mediciones(value);
            ui->lcdOxigeno->display(m_oxigeno);
            ui->lcdHeartrate->display(m_heartrate);
        }
    }
}




/* ESP
 * @brief Cierra la ventana y regresa al menú principal.
 */
/* ENG
 * @brief Closes the window and returns to the main menu.
 */

void Mediciones::on_botonMenu_clicked()
{
    disconnect(cliente, &QTcpSocket::readyRead, nullptr, nullptr);    //Desconecto el puerto

    menu = true;
    this->close();
}




/* ESP
 * @brief Cierra la aplicación.
 */
/* ENG
 * @brief Closes the application.
 */

void Mediciones::on_botonSalir_clicked()
{
    menu = false;
    this->close();
}




/* ESP
 * @brief Guarda las mediciones actuales con los datos del paciente en un archivo de texto.
 */
/* ENG
 * @brief Saves current measurements with patient data into a text file.
 */

void Mediciones::on_botonGuardar_clicked()
{
    int aux_o2 = m_oxigeno;
    int aux_hr = m_heartrate;
    Pacientes paciente;

    if(paciente.exec() == Pacientes::Accepted)
    {
        Usuario newUser = paciente.getUsuario();

        QFile archivo("C:/Users/Facun/Documents/QT/GUI_Pulse_Oximeter/Output_files/historial_v2.txt");
        if (!archivo.open(QIODevice::Append | QIODevice::Text))
        {
            QMessageBox::warning(this, "Pacientes", "Error al guardar la informacion");
            return;
        }

        QTextStream flujo(&archivo);

        newUser.fecha = QDateTime::currentDateTime();
        flujo << newUser.fecha.toString("dd/MM/yyyy  hh:mm:ss").leftJustified(20, ' ')
              << QString("\tPaciente: %1, %2").arg(newUser.apellido, newUser.nombre).leftJustified(50, ' ')
              << QString("\tDNI: %1").arg(newUser.dni).leftJustified(15, ' ')
              << QString("\tSexo: %1").arg(newUser.sexo).leftJustified(20, ' ')
              << QString("\tNivel de oxigeno: %1").arg(QString::number(aux_o2)).leftJustified(25, ' ')
              << QString("\tHeart rate: %1").arg(QString::number(aux_hr)).leftJustified(25, ' ');
        archivo.seek(archivo.size());
        flujo << "\n";


        archivo.close();
        QMessageBox::information(this, "Pacientes", "Paciente agregado correctamente");
    }
}
