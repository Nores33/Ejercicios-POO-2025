#include "cajamedicamento.h"

CajaMedicamento::CajaMedicamento(float dosisTotales)
    : id(-1), dosisTotales(dosisTotales) {}

CajaMedicamento::CajaMedicamento(int id, float dosisTotales)
    : id(id), dosisTotales(dosisTotales) {}

CajaMedicamento CajaMedicamento::operator+(const CajaMedicamento &otra) const {
    return CajaMedicamento(-1, this->dosisTotales + otra.dosisTotales);
}

bool CajaMedicamento::operator==(const CajaMedicamento &otra) const {
    return this->dosisTotales == otra.dosisTotales;
}

QString CajaMedicamento::toString() const {
    return QString("CajaMedicamento [ID: %1, Dosis: %2]").arg(id).arg(dosisTotales);
}

int CajaMedicamento::getId() const {
    return id;
}

float CajaMedicamento::getDosisTotales() const {
    return dosisTotales;
}
