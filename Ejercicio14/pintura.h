#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QPixmap>

class Pintura : public QWidget
{
    Q_OBJECT

public:
    explicit Pintura(QWidget *parent = nullptr);
    ~Pintura();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;

private:
    QPixmap canvas;
    QPoint lastPoint;
    QColor brushColor;
    int brushSize;
};

#endif // PINTURA_H
