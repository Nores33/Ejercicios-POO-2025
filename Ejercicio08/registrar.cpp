#include "registrar.h"
#include "ui_registrar.h"
#include "adminapi.h"
#include "login.h"
#include <QMessageBox>

Registrar::Registrar(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::registrar)
{
    ui->setupUi(this);

    setWindowTitle("Registro de Usuario");

    connect(ui->signupButton, &QPushButton::clicked, this, &Registrar::on_signupButton_clicked);
    connect(ui->cancelButton, &QPushButton::clicked, this, &Registrar::on_cancelButton_clicked);
}

Registrar::~Registrar()
{
    delete ui;
}

void Registrar::on_signupButton_clicked()
{
    QString nombre = ui->nameEdit->text();
    QString apellido = ui->surnameEdit->text();
    QString usuario = ui->usernameEdit->text();
    QString contrasena = ui->passwordEdit->text();
    QString correo = ui->mailEdit->text();

    if (nombre.isEmpty() || apellido.isEmpty() || usuario.isEmpty() || contrasena.isEmpty() || correo.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Por favor, completa todos los campos.");
        return;
    }

    ui->signupButton->setEnabled(false); // Deshabilita el botón para evitar múltiples envíos

    replyActual = AdminAPI::getInstancia()->registrarUsuario(nombre, apellido, usuario, contrasena, correo);
    connect(replyActual, &QNetworkReply::finished, this, &Registrar::onRegisterReply);
}

void Registrar::onRegisterReply()
{
    ui->signupButton->setEnabled(true); // Rehabilita el botón

    if (!replyActual)
        return;

    replyActual->deleteLater(); // Libera el reply antes de cerrar la ventana
    QNetworkReply *reply = replyActual;
    replyActual = nullptr;

    if (reply->error() == QNetworkReply::NoError) {
        QMessageBox::information(this, "Registro exitoso", "¡Usuario registrado correctamente!");
        Login *ventanaLogin = new Login();
        ventanaLogin->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Error de registro", "No se pudo registrar el usuario.");
    }
}

void Registrar::on_cancelButton_clicked()
{
    Login *ventanaLogin = new Login();
    ventanaLogin->show();
    this->close();
}
