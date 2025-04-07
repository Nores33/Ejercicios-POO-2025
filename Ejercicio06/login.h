#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>

class QLineEdit;
class QLabel;
class QPushButton;
class Formulario;

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);

private slots:
    void verificarClave();

private:
    QLabel *lblUsuario;
    QLabel *lblClave;
    QLineEdit *editUsuario;
    QLineEdit *editClave;
    QPushButton *btnLogin;

    Formulario *formulario;
};

#endif // LOGIN_H
