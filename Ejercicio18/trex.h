#ifndef TREX_H
#define TREX_H

#include <QImage>
#include <QRect>
#include <QPainter>

class TRex : public QImage {
public:
    TRex();

    QRect getRect() const;
    void saltar();
    void agacharse();
    void levantarse();
    void adelantarse();
    void frenarse();
    void actualizarMovimiento();

    void paint(QPainter &painter);

private:
    int posX;
    int posY;
    int velocidadY;
    bool enElAire;
    bool agachado;

    QImage texturaNormal;    // Textura normal del TRex
    QImage texturaAgachado;  // Textura del TRex agachado
    QSize tamanoActual;      // Tamaño actual del TRex
};

#endif // TREX_H
