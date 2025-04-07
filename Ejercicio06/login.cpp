#include "login.h"
#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QKeyEvent>

Login::Login(QWidget *parent) : QWidget(parent)
{
    setFixedSize(250, 150);
    setWindowTitle( "Login" );

    lblUsuario = new QLabel("Usuario:");
    lblClave = new QLabel("Clave:");

    editUsuario = new QLineEdit;
    editClave = new QLineEdit;
    editClave->setEchoMode(QLineEdit::Password); // Asteriscos

    btnLogin = new QPushButton("Ingresar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblUsuario, 0, 0);
    layout->addWidget(editUsuario, 0, 1);
    layout->addWidget(lblClave, 1, 0);
    layout->addWidget(editClave, 1, 1);
    layout->addWidget(btnLogin, 2, 1);

    setLayout(layout);

    formulario = new Formulario;

    connect(editClave, &QLineEdit::returnPressed, btnLogin, &QPushButton::click);
    connect(btnLogin, &QPushButton::clicked, this, &Login::verificarClave);
}

void Login::verificarClave()
{
    QString usuario = editUsuario->text();
    QString clave = editClave->text();

    if (usuario == "admin" && clave == "1111") {
        formulario->show();
        this->close();  // cerrar login
    } else {
        editClave->clear();
    }
}
