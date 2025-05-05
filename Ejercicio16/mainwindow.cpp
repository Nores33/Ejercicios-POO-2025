#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Login");

    connect(ui->login_button, SIGNAL(clicked()), this, SLOT(onLoginClicked()));
    connect(ui->cancel_button, SIGNAL(clicked()), this, SLOT(onCancelClicked()));

    AdminDB::getInstancia()->conectar();
    QString ultimoUsuario = AdminDB::getInstancia()->leerUltimoUsuario();
    ui->user->setText(ultimoUsuario);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLoginClicked()
{
    // Problema con la aplicacion: solo contempla usuarios ya registrados, pero no hay ninguno, por lo que nunca va a entrar
    // Solucion: ver como registrar usuarios (agregarlos manualmente o agregar un metodo para registrarse si no existe)
    QString username = ui->user->text();
    QString password = ui->user->text();

    AdminDB *db = AdminDB::getInstancia();
    if (db->validarUsuario(username, password)) {
        db->guardarUltimoUsuario(username);
        QMessageBox::information(this, "Login", "Inicio de sesión exitoso.");
    } else {
        QMessageBox::warning(this, "Login", "Usuario o contraseña incorrectos.");
    }
}

void MainWindow::onCancelClicked()
{
    close();
}
