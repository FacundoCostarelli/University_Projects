#include "ventanaconexion.h"
#include "ui_ventanaconexion.h"

VentanaConexion::VentanaConexion(MainWindow &ppal) :
    QMainWindow(nullptr),
    ui(new Ui::VentanaConexion)
{
    ui->setupUi(this);
    setWindowTitle("Conexion WiFi");
    this->setFixedSize(this->width(),this->height());

    servidor = NULL;
    cliente = NULL;
    ventanappal = &ppal;
}

VentanaConexion::~VentanaConexion()
{
    delete ui;
}

void VentanaConexion::on_pushButtonConexion_clicked()
{
    if(!servidor)
    {
        servidor = new QTcpServer(this);
        servidor->listen(QHostAddress::Any, ui->lineEditPort->text().toInt());

        connect(servidor, SIGNAL(newConnection()), this, SLOT(nuevoCliente()));

        ui->pushButtonConexion->setText("Conectando...");
        ui->pushButtonConexion->setStyleSheet("color: grey;");
        ui->pushButtonConexion->setEnabled(false);
    }
}

void VentanaConexion::nuevoCliente(void)
{
    if(!cliente)
    {
        cliente = new QTcpSocket;
        cliente = servidor->nextPendingConnection();

        ventanappal->setSocket(servidor, cliente);

        ventanappal->show();
        this->close();
    }
}
