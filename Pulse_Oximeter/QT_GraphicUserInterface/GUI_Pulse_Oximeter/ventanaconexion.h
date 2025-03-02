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

