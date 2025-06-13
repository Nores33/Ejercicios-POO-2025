#include "login.h"
#include "ui_login.h"
#include "adminapi.h"
#include "interfaz.h"
#include "registrar.h"
#include <QMessageBox>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    setWindowTitle("Login");

    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_LoginButton_clicked);
    connect(ui->signupButton, &QPushButton::clicked, this, &Login::on_SignUpButton_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    QString usuario = ui->usernameEdit->text();
    QString contrasena = ui->passwordEdit->text();

    if (usuario.isEmpty() || contrasena.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, ingresa usuario y contraseña.");
        return;
    }

    // Llama a AdminAPI para iniciar sesión
    replyActual = AdminAPI::getInstancia()->iniciarSesion(usuario, contrasena);
    connect(replyActual, &QNetworkReply::finished, this, &Login::onLoginReply);
}

void Login::onLoginReply()
{
    if (!replyActual)
        return;

    if (replyActual->error() == QNetworkReply::NoError) {
        QByteArray respuesta = replyActual->readAll();

        // Abrir la ventana principal (Interfaz)
        Interfaz *ventanaInterfaz = new Interfaz();
        ventanaInterfaz->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error de login", "Usuario o contraseña incorrectos.");
    }
    replyActual->deleteLater();
    replyActual = nullptr;
}

void Login::on_SignUpButton_clicked()
{
    Registrar *ventanaRegistrar = new Registrar();
    ventanaRegistrar->show();
    this->close();
}
