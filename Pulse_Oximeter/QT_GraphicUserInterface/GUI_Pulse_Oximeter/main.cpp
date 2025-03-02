#include <QApplication>
#include <QSerialPort>
#include "mainwindow.h"
#include "ventanaconexion.h"

/************************NOTA ANTES DE USAR***************************
Cambiar en los metodos y slots:
    - open_historial (en historial.cpp)
    - on_botonGuardar_clicked (en historial.cpp)
    - on_botonBorrar_clicked (en historial.cpp)
    - on_botonGuardar_clicked (en mediciones.cpp)
La ruta donde quiero guardar el archivo con el historial de mediciones
**********************************************************************/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    VentanaConexion v(w);
    v.show();

    return a.exec();
}
