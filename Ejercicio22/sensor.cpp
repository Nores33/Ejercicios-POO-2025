#include "sensor.h"
#include <random>

Sensor::Sensor(QWidget *parent)
    : QWidget(parent)
{
    // Inicializa valorActual con un valor aleatorio entre 0 y 1023
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1023);
    valorActual = dis(gen);
}

Sensor::~Sensor() {}

int Sensor::getValorBrutoOffline() const {
    return valorActual;
}

double Sensor::getValorNormalizadoOffline() const {
    return valorActual / 1023.0;
}
