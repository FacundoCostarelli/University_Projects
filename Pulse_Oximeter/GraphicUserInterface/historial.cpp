#include "historial.h"
#include "ui_historial.h"
#include <QMessageBox>

/***********************NOTA ANTES DE USAR*********************************
 Cambiar en los metodos y slots:
    - open_historial
    - on_botonGuardar_clicked
    - on_botonBorrar_clicked
 La ruta donde quiero guardar el archivo con el historial de las mediciones
 **************************************************************************/

Historial::Historial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Historial)
{
    ui->setupUi(this);
    setWindowTitle("Historial");
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setCursor(Qt::ArrowCursor);
    ui->botonGuardar->setEnabled(false);
}

Historial::~Historial()
{
    delete ui;
}

void Historial::open_historial(void)
{
    //Abro o creo un archivo donde tengo guardada la informacion
    archivo = new QFile("/home/elagache/Documentos/UNIVERSIDAD/INFO_II/TPO/Interfaz_TPO_v2.2/historial_v2.txt");
    flujo = new QTextStream(archivo);

    // Abrir el archivo en modo de solo lectura
    if(archivo->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        while (!flujo->atEnd())
        {
            QString linea = flujo->readLine();
            ui->textEdit->append(linea);
        }
        archivo->close(); // Cerrar el archivo cuando termines
    }
    else
        QMessageBox::information(this, "Historial", "El historial esta vacio");

    delete flujo;
    delete archivo;
}

//Slots
void Historial::on_botonMenu_clicked()
{
    menu = true;
    this->close();
}

void Historial::on_botonSalir_clicked()
{
    menu = false;
    this->close();
}

void Historial::on_botonEditar_clicked()
{
    ui->botonGuardar->setEnabled(true);
    ui->textEdit->setReadOnly(false);
    ui->textEdit->setCursor(Qt::IBeamCursor);
    ui->textEdit->setStyleSheet("QTextEdit {border: 1px solid rgb(0,150,0)}");
}

void Historial::on_botonGuardar_clicked()
{
    ui->botonGuardar->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->textEdit->setCursor(Qt::ArrowCursor);
    ui->textEdit->setStyleSheet("QTextEdit {border: 1px solid grey}");

    archivo = new QFile("/home/elagache/Documentos/UNIVERSIDAD/INFO_II/TPO/Interfaz_TPO_v2.2/historial_v2.txt");
    flujo = new QTextStream(archivo);

    if(archivo->open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QString newText = ui->textEdit->toPlainText();
        (*flujo) << newText;
        archivo->close();
    }
    else
        QMessageBox::warning(this, "Historial", "Error al editar el historial");

    delete flujo;
    delete archivo;
}

void Historial::on_botonBorrar_clicked()
{
    archivo = new QFile("/home/elagache/Documentos/UNIVERSIDAD/INFO_II/TPO/Interfaz_TPO_v2.2/historial_v2.txt");
    if(archivo->remove())
    {
        ui->textEdit->clear();
        QMessageBox::information(this, "Historial", "El historial se elimino correctamente ");
    }
    else
        QMessageBox::warning(this, "Historial", "Error al eliminar el historial");
}

