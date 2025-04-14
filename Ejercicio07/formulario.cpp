#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QRandomGenerator>
#include <QVBoxLayout>
#include <QHBoxLayout>

Formulario::Formulario(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 200);
    setWindowTitle("Formulario");

    lblLegajo = new QLabel("Legajo:");
    lblNombre = new QLabel("Nombre:");
    lblApellido = new QLabel("Apellido:");

    editLegajo = new QLineEdit;
    editNombre = new QLineEdit;
    editApellido = new QLineEdit;


    // CAPTCHA
    numeroCaptcha = QRandomGenerator::global()->bounded(1, 10001); // 1 a 10000 inclusive
    lblCaptcha = new QLabel(QString("CAPTCHA: %1").arg(numeroCaptcha));
    editCaptcha = new QLineEdit;
    btnAlta = new QPushButton("Alta");
    btnAlta->setEnabled(false);

    connect(editCaptcha, &QLineEdit::textChanged, this, &Formulario::validarCaptcha);
    connect(btnAlta, &QPushButton::clicked, this, &Formulario::cerrarAplicacion);

    // Layout principal
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblLegajo, 0, 0);
    layout->addWidget(editLegajo, 0, 1);
    layout->addWidget(lblNombre, 1, 0);
    layout->addWidget(editNombre, 1, 1);
    layout->addWidget(lblApellido, 2, 0);
    layout->addWidget(editApellido, 2, 1);
    layout->addWidget(lblCaptcha, 4, 0);
    layout->addWidget(editCaptcha, 5, 0);
    layout->addWidget(btnAlta, 5, 1);

    setLayout(layout);
}

void Formulario::validarCaptcha()
{
    bool ok;
    int valorIngresado = editCaptcha->text().toInt(&ok);
    btnAlta->setEnabled(ok && valorIngresado == numeroCaptcha);
}

void Formulario::cerrarAplicacion()
{
    close(); // o qApp->quit(); si querés cerrar toda la aplicación
}

