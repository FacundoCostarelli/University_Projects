#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QScreen>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Menu");
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen) {
        //Obtener el tamaño de la pantalla y aplicarlo a la ventana
        QRect screenGeometry = screen->geometry();
        this->resize(screenGeometry.width(), screenGeometry.height());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Metodos
void MainWindow::setSocket(QTcpServer *s , QTcpSocket *c)
{
    servidor = s;
    cliente = c;
}

//Slots
void MainWindow::on_pushButtonSalir_clicked()
{
    cliente->close();
    cliente = NULL;

    servidor->close();
    delete servidor;
    servidor = NULL;

    this->close();
}

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

void MainWindow::open_close_menu()
{
    if(window_medir->getMenu()==true)
        this->show();
    else
        on_pushButtonSalir_clicked();
}

void MainWindow::open_close_historial()
{
    if(window_historial->getMenu()==true)
        this->show();
    else
        on_pushButtonSalir_clicked();
}
