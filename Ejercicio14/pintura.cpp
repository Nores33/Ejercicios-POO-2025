#include "pintura.h"

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), brushColor(Qt::black), brushSize(5)
{
    setFixedSize(800, 600);
    canvas = QPixmap(size());
    canvas.fill(Qt::white);

    setFocusPolicy(Qt::StrongFocus);
    setFocus();
}

Pintura::~Pintura() {}

void Pintura::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, canvas);
}

void Pintura::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        QPainter painter(&canvas);
        painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        painter.drawLine(lastPoint, event->pos());
        lastPoint = event->pos();
        update();
    }
}

void Pintura::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_R:
        brushColor = Qt::red;
        break;
    case Qt::Key_G:
        brushColor = Qt::green;
        break;
    case Qt::Key_B:
        brushColor = Qt::blue;
        break;
    case Qt::Key_Escape:
        canvas.fill(Qt::white);
        update();
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Pintura::wheelEvent(QWheelEvent *event)
{
    if (event->angleDelta().y() > 0) {
        brushSize = qMin(brushSize + 1, 50); // Limitar tamaño máximo
    } else {
        brushSize = qMax(brushSize - 1, 1); // Limitar tamaño mínimo
    }
}
