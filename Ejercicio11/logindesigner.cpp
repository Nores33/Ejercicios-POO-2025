#include "logindesigner.h"
#include "ui_logindesigner.h"

LoginDesigner::LoginDesigner(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginDesigner)
{
    ui->setupUi(this);

    connect(ui->pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));
}

LoginDesigner::~LoginDesigner()
{
    delete ui;
}

void LoginDesigner::slot_validarUsuario()
{
    if(ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234") {
        this->close();
    }
    else {
        ui->leClave->clear();
    }
}
