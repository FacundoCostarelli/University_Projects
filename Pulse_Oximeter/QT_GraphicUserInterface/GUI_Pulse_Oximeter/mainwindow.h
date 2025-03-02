#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "mediciones.h"
#include "historial.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setSocket(QTcpServer * , QTcpSocket *);

private slots:
    void on_pushButtonSalir_clicked();
    void on_botonHistorial_clicked();
    void on_botonMediciones_clicked();

    void open_close_menu();
    void open_close_historial();

private:
    Ui::MainWindow *ui;
    QTcpServer *servidor;
    QTcpSocket *cliente;
    Mediciones *window_medir;
    Historial *window_historial;

};
#endif // MAINWINDOW_H
