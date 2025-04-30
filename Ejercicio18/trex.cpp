#include "trex.h"

TRex::TRex() : QImage(40, 40, QImage::Format_ARGB32),
    posX(100), 
    posY(200), 
    velocidadY(0), 
    enElAire(false), 
    agachado(false), 
    texturaNormal("../../imagenes/trex.png"),
    texturaAgachado("../../imagenes/trex_agachado.png"),
    tamanoActual(40, 40) 
{
    fill(Qt::transparent);
}

QRect TRex::getRect() const {
    return QRect(posX, posY, tamanoActual.width(), tamanoActual.height());
}

void TRex::saltar() {
    if (!enElAire) {
        velocidadY = -15;
        enElAire = true;
    }
}

void TRex::agacharse() {
    if (!agachado) {
        agachado = true;
        tamanoActual = QSize(50, 30); // Reducir el tamaño al agacharse
        posY += 10; // Ajustar la posición Y al agacharse
    }
}

void TRex::levantarse() {
    if (agachado) {
        agachado = false;
        tamanoActual = QSize(40, 40); // Restaurar el tamaño original
    }
}

void TRex::adelantarse() {
    posX += 10;
}

void TRex::frenarse() {
    posX -= 10;
}

void TRex::actualizarMovimiento() {
    posY += velocidadY;
    velocidadY += 1; // gravedad

    // Ajustar la posición dependiendo de si está agachado o no
    int alturaBase = agachado ? 225 : 215; // Más bajo si está agachado

    if (posY >= alturaBase) {
        posY = alturaBase;
        velocidadY = 0;
        enElAire = false;
    }
}

void TRex::paint(QPainter &painter) {
    if (agachado) {
        painter.drawImage(getRect(), texturaAgachado); // Dibujar textura agachado
    } else {
        painter.drawImage(getRect(), texturaNormal); // Dibujar textura normal
    }
}
