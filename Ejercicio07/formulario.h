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

private slots:
    void validarCaptcha(); // slot para validar el captcha
    void cerrarAplicacion(); // slot para cerrar

private:
    QLabel *lblLegajo;
    QLabel *lblNombre;
    QLabel *lblApellido;
    QLineEdit *editLegajo;
    QLineEdit *editNombre;
    QLineEdit *editApellido;
    QPushButton *btnGuardar;

    // CAPTCHA
    QLabel *lblCaptcha;
    QLineEdit *editCaptcha;
    QPushButton *btnAlta;
    int numeroCaptcha;
};

#endif // FORMULARIO_H

