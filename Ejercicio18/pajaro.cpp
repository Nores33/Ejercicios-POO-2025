#include "pajaro.h"

Pajaro::Pajaro(QObject *parent, int altura) : QObject(parent), QImage(30, 20, QImage::Format_ARGB32),
    posX(800), posY(altura) {
    fill(Qt::transparent);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(avanzar()));
    timer->start(30);
}

QRect Pajaro::getRect() const {
    return QRect(posX, posY, width(), height());
}

int Pajaro::getX() const {
    return posX;
}

int Pajaro::getY() const {
    return posY;
}

void Pajaro::avanzar() {
    posX -= 5;
    if (posX + width() < 0) {
        emit salirDePantalla(this);
    }
}

void Pajaro::mover() {
    // Método explícito si lo querés llamar aparte (no necesario en este esquema)
}

void Pajaro::paint(QPainter &painter) {
    QImage texture("../../imagenes/pajaro.png");
    painter.drawImage(getRect(), texture);
}
