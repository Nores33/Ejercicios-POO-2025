#include <QJsonDocument>
#include <QJsonObject>
#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Login)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);

    setWindowTitle("Login");

    connect( ui->Cancel_Button, SIGNAL(pressed()), this, SLOT(slot_cancelar()));
    connect(ui->Login_Button, SIGNAL(pressed()), this, SLOT(slot_login()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_cancelar()
{
    QApplication::quit();
}

void Login::slot_login()
{
    if(ui->user->text() == "admin" && ui->password->text() == "1234") {
        if(!ventanaSecundaria){
            ventanaSecundaria = new ventana_secundaria;
            ventanaSecundaria->cargarImagenDesdeUrl("https://turismo.cordoba.gob.ar/wp-content/uploads/2021/07/dsdsd-scaled-e1677342686741-1110x624.jpg");
            connect(ventanaSecundaria, &ventana_secundaria::imagenCargada, [this]() {
                ventanaSecundaria->show();
                this->hide();
            });
        }
    }
}
