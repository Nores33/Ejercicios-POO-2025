#ifndef SENSOR_H
#define SENSOR_H

#include <QWidget>
#include <random>

class Sensor : public QWidget
{
    Q_OBJECT

    int valorActual;

public:
    Sensor(QWidget *parent = nullptr);
    ~Sensor();

    // Inline implícito (definido dentro de la clase)
    int getValorBruto() const { return valorActual; }

    // Declaración offline (definido fuera de la clase)
    int getValorBrutoOffline() const;

    // Inline explícito
    inline double getValorNormalizado() const { return valorActual / 1023.0; }

    // Declaración offline (definido fuera de la clase, sin inline)
    double getValorNormalizadoOffline() const;
};

#endif // SENSOR_H
