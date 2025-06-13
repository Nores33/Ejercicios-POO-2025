#include "ventana.h"
#include "ui_ventana.h"
#include <QPainter>
#include <QLinearGradient>
#include <QImage>

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    ui->botonDentista->colorear(Boton::Rojo);
    ui->botonDentista->setObjectName("Mi dentista");

    ui->botonVisitas->colorear(Boton::Magenta);
    ui->botonVisitas->setObjectName("Visitas");

    ui->botonHigiene->colorear(Boton::Violeta);
    ui->botonHigiene->setObjectName("Técnicas de higiene");

    ui->botonBoca->colorear(Boton::Azul);
    ui->botonBoca->setObjectName("Mi boca");

    ui->botonCepillar->colorear(Boton::Verde);
    ui->botonCepillar->setObjectName("Hora de cepillarse");
}

void Ventana::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QImage fondo(size(), QImage::Format_RGB32);

    QPainter imagePainter(&fondo);

    // Crear un gradiente diagonal dentro de la imagen
    QLinearGradient gradiente(0, 0, width(), height());
    gradiente.setColorAt(0.0, QColor(255, 255, 0));   // Amarillo
    gradiente.setColorAt(1.0, QColor(0, 0, 255));     // Azul

    imagePainter.fillRect(rect(), gradiente);
    painter.drawImage(0, 0, fondo);
}
