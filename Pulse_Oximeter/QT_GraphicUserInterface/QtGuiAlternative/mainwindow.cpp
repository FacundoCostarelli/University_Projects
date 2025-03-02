#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = NULL;
    cliente = NULL;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_conectar_clicked()
{
    if( !socket )
    {
        socket = new QTcpServer(this);
        
        
        socket->listen(QHostAddress::Any, ui->lineEditPort->text().toInt());
        
        connect(socket, SIGNAL(newConnection()), this, SLOT(nuevoCliente()));
              

        ui->conectar->setText("Conectado");
        ui->conectar->setStyleSheet("background-color: rgb(0,255,0);");
    }
    else
    {
        if(cliente)
        {
            cliente->close();
            cliente = NULL;
        }

        socket->close();
        delete socket;
        socket = NULL;

        ui->conectar->setText("Desconectado");
        ui->conectar->setStyleSheet("background-color: rgb(255,0,0);");
    }
}



void MainWindow::nuevoCliente(void)
{
    if(!cliente)
    {
        cliente = new QTcpSocket;
        cliente = socket->nextPendingConnection();
        
        connect(cliente, SIGNAL(disconnected()), this, SLOT(disconnected()));
        connect(cliente, SIGNAL(readyRead()), this, SLOT(readyRead()));
        ui->plainTextRecibir->appendPlainText("cliente conectado");
    }
}




void MainWindow::readyRead()
{
    QByteArray data = cliente->read(cliente->bytesAvailable());
    static int tipo_valor_recibido = -1;

    if (!data.isEmpty()) {
        QString strData = QString::fromUtf8(data);  // Convierte los bytes a cadena
        bool ok;
        int value = strData.toInt(&ok);  // Convierte la cadena a un entero

        if (ok) {

            //TODO falta esto
            if(value == 0 || value == 1){//si se recibio el tipo de valor (si es de HeartBeat o SPO2)
                tipo_valor_recibido = value; // lo guardo
            }else { // sino se recibio un valor
                switch(tipo_valor_recibido){
                    case 1:
                        ui->label_result_Spo2->setText(QString::number(value));
                        break;
                    case 0:
                         ui->label_result_Hr->setText(QString::number(value));
                        break;
                    default: ui->plainTextRecibir->appendPlainText("Error: Datos recibidos incorrectamente");
                }
            }
            ui->plainTextRecibir->appendPlainText(QString::number(value));  // Muestra el número como texto
        } else {
            ui->plainTextRecibir->appendPlainText("Error: Datos no numéricos recibidos");
        }
    }
}

void MainWindow::disconnected()
{
    cliente->close();
    cliente = NULL;
}
