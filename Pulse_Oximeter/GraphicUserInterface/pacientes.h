#ifndef PACIENTES_H
#define PACIENTES_H

#include <QDialog>
#include <QDateTime>

struct Usuario
{
    QString nombre;
    QString apellido;
    int dni;
    QDateTime fecha;
    QString sexo;
};


namespace Ui {
class Pacientes;
}

class Pacientes : public QDialog
{
    Q_OBJECT

public:
    explicit Pacientes(QWidget *parent = nullptr);
    ~Pacientes();
    Usuario getUsuario(void);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Pacientes *ui;
    Usuario user;
};

#endif // PACIENTES_H
