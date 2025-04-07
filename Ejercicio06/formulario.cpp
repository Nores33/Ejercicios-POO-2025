#include "formulario.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>

Formulario::Formulario(QWidget *parent) : QWidget(parent)
{
    setFixedSize(250, 200);
    setWindowTitle( "Formulario" );

    lblLegajo = new QLabel("Legajo:");
    lblNombre = new QLabel("Nombre:");
    lblApellido = new QLabel("Apellido:");

    editLegajo = new QLineEdit;
    editNombre = new QLineEdit;
    editApellido = new QLineEdit;

    btnGuardar = new QPushButton("Guardar");

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(lblLegajo, 0, 0);
    layout->addWidget(editLegajo, 0, 1);
    layout->addWidget(lblNombre, 1, 0);
    layout->addWidget(editNombre, 1, 1);
    layout->addWidget(lblApellido, 2, 0);
    layout->addWidget(editApellido, 2, 1);
    layout->addWidget(btnGuardar, 3, 1);

    setLayout(layout);
}
