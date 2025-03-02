#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <QMainWindow>
#include <QFile>
#include <QTextStream>

namespace Ui {
class Historial;
}

class Historial : public QMainWindow
{
    Q_OBJECT

public:
    explicit Historial(QWidget *parent = nullptr);
    ~Historial();

    inline bool getMenu(){return menu;}
    void open_historial(void);

private slots:
    void on_botonMenu_clicked();
    void on_botonSalir_clicked();
    void on_botonEditar_clicked();
    void on_botonGuardar_clicked();
    void on_botonBorrar_clicked();

private:
    Ui::Historial *ui;
    QFile *archivo;
    QTextStream *flujo;
    bool menu;
};

#endif // HISTORIAL_H
