#include "ventana.h"
#include "ui_ventana.h"
#include <QMessageBox>
#include <QDebug>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    setWindowTitle("Gestion de medicamentos - OSTEP");

    // Conectar botones a sus slots
    connect(ui->btnAgregar, SIGNAL(clicked()), this, SLOT(onAgregarClicked()));
    connect(ui->btnSumar, SIGNAL(clicked()), this, SLOT(onSumarClicked()));
    connect(ui->btnComparar, SIGNAL(clicked()), this, SLOT(onCompararClicked()));

    // Conectar a la base de datos
    AdminDB::getInstancia()->conectar();

    // Actualizar la lista de cajas al iniciar
    actualizarListaCajas();
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::onAgregarClicked()
{
    float dosis = ui->spinDosis->value();
    if (AdminDB::getInstancia()->insertarCaja(dosis)) {
        actualizarListaCajas();
    } else {
        QMessageBox::warning(this, "Error", "No se puede agregar la caja. Se excede el límite de 1000 dosis.");
    }
}

void Ventana::onSumarClicked()
{
    QList<QListWidgetItem *> seleccionadas = ui->listaCajas->selectedItems();
    if (seleccionadas.size() != 2) {
        QMessageBox::warning(this, "Error", "Debe seleccionar exactamente dos cajas para sumar.");
        return;
    }

    int id1 = seleccionadas[0]->data(Qt::UserRole).toInt();
    int id2 = seleccionadas[1]->data(Qt::UserRole).toInt();

    QList<CajaMedicamento> cajas = AdminDB::getInstancia()->obtenerTodas();
    CajaMedicamento *caja1 = nullptr;
    CajaMedicamento *caja2 = nullptr;

    for (CajaMedicamento &caja : cajas) {
        if (caja.getId() == id1) caja1 = &caja;
        if (caja.getId() == id2) caja2 = &caja;
    }

    if (caja1 && caja2) {
        CajaMedicamento suma = *caja1 + *caja2;
        if (suma.getDosisTotales() > 1000) {
            QMessageBox::warning(this, "Error", "La suma de las cajas excede el límite de 1000 dosis.");
        } else {
            AdminDB::getInstancia()->insertarCaja(suma.getDosisTotales());
            actualizarListaCajas();
        }
    }
}

void Ventana::onCompararClicked()
{
    QList<QListWidgetItem *> seleccionadas = ui->listaCajas->selectedItems();
    if (seleccionadas.size() != 2) {
        QMessageBox::warning(this, "Error", "Debe seleccionar exactamente dos cajas para comparar.");
        return;
    }

    int id1 = seleccionadas[0]->data(Qt::UserRole).toInt();
    int id2 = seleccionadas[1]->data(Qt::UserRole).toInt();

    QList<CajaMedicamento> cajas = AdminDB::getInstancia()->obtenerTodas();
    CajaMedicamento *caja1 = nullptr;
    CajaMedicamento *caja2 = nullptr;

    for (CajaMedicamento &caja : cajas) {
        if (caja.getId() == id1) caja1 = &caja;
        if (caja.getId() == id2) caja2 = &caja;
    }

    if (caja1 && caja2) {
        if (*caja1 == *caja2) {
            qDebug() << "Las cajas tienen la misma cantidad de dosis.";
        } else {
            qDebug() << "Las cajas tienen cantidades de dosis diferentes.";
        }
    }
}

void Ventana::actualizarListaCajas()
{
    ui->listaCajas->clear();
    QList<CajaMedicamento> cajas = AdminDB::getInstancia()->obtenerTodas();
    for (const CajaMedicamento &caja : cajas) {
        QListWidgetItem *item = new QListWidgetItem(caja.toString());
        item->setData(Qt::UserRole, caja.getId());
        ui->listaCajas->addItem(item);
    }
}
