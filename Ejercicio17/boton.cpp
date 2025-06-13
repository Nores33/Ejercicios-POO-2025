#include "boton.h"
#include <QPainter>
#include <QMouseEvent>

Boton::Boton(QWidget *parent) : QWidget(parent) {
    colorActual = Qt::gray;
    setMinimumHeight(50);
}

void Boton::colorear(Color color) {
    switch (color) {
    case Rojo:
        colorActual = QColor(255, 50, 50);
        break;
    case Magenta:
        colorActual = QColor(255, 0, 200);
        break;
    case Violeta:
        colorActual = QColor(150, 0, 255);
        break;
    case Azul:
        colorActual = QColor(0, 160, 255);
        break;
    case Verde:
        colorActual = QColor(0, 220, 120);
        break;
    }
    update(); // Redibuja el widget
}

void Boton::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.fillRect(rect(), colorActual);
    painter.setPen(Qt::white);

    QFont fuente("Comic Sans MS", 14);
    painter.setFont(fuente);

    painter.drawText(rect().adjusted(10, 0, -10, 0), Qt::AlignVCenter | Qt::AlignLeft, this->objectName());
}

void Boton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton)
        emit signal_clic();
}
