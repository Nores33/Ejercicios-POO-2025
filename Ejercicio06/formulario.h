#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;

class Formulario : public QWidget
{
    Q_OBJECT

public:
    explicit Formulario(QWidget *parent = nullptr);

private:
    QLabel *lblLegajo;
    QLabel *lblNombre;
    QLabel *lblApellido;
    QLineEdit *editLegajo;
    QLineEdit *editNombre;
    QLineEdit *editApellido;
    QPushButton *btnGuardar;
};

#endif // FORMULARIO_H
