#ifndef PAJARO_H
#define PAJARO_H

#include <QImage>
#include <QRect>
#include <QTimer>
#include <QPainter>

class Pajaro : public QObject, public QImage {
    Q_OBJECT

public:
    explicit Pajaro(QObject *parent = nullptr, int altura = 150);

    QRect getRect() const;
    int getX() const;
    int getY() const;
    void mover();

    void paint(QPainter &painter);

signals:
    void salirDePantalla(Pajaro *pajaro);

private slots:
    void avanzar();

private:
    int posX;
    int posY;
    QTimer *timer;
};

#endif // PAJARO_H
