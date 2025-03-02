#include "mediciones.h"
#include "ui_mediciones.h"
#include <QMessageBox>
#include <QRegularExpression>

/***********************NOTA ANTES DE USAR*********************************
 Cambiar en el slot:
    - on_botonGuardar_clicked
 La ruta donde quiero guardar el archivo con el historial de las mediciones
 **************************************************************************/

Mediciones::Mediciones(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Mediciones)
{
    ui->setupUi(this);
    setWindowTitle("Mediciones");
    ui->lcdHeartrate->setDigitCount(4);
    ui->lcdHeartrate->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdOxigeno->setDigitCount(4);
    ui->lcdOxigeno->setSegmentStyle(QLCDNumber::Flat);
    ui->lcdHeartrate->setStyleSheet(
        "QLCDNumber {"
        "   color: red;"                // Cambiar color del numero
        "   border: 2px solid red;"     // Cambiar color del borde
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

Mediciones::~Mediciones()
{
    delete ui;
}

//Metodos
//Configuro el puerto para leer la medicion
void Mediciones::setSocket(QTcpServer *s , QTcpSocket *c)
{
    servidor = s;
    cliente = c;

    connect(cliente, SIGNAL(readyRead()), this, SLOT(data_medicion()));
}

//MdE para la recepcion de datos
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


//Slots
//Mostrar la info que leo del sensor en el lcd
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

//Vuelvo al menu
void Mediciones::on_botonMenu_clicked()
{
    disconnect(cliente, &QTcpSocket::readyRead, nullptr, nullptr);    //Desconecto el puerto

    menu = true;
    this->close();
}

//Cierro la aplicacion
void Mediciones::on_botonSalir_clicked()
{
    menu = false;
    this->close();
}

void Mediciones::on_botonGuardar_clicked()
{
    int aux_o2 = m_oxigeno;
    int aux_hr = m_heartrate;
    Pacientes paciente;

    if(paciente.exec() == Pacientes::Accepted)
    {
        //Guardo el usuario en un archivo
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


        archivo.close(); // Cerrar el archivo cuando termines

        QMessageBox::information(this, "Pacientes", "Paciente agregado correctamente");
    }
}
