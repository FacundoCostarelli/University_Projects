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
