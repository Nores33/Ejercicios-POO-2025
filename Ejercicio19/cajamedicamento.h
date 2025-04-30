#ifndef CAJAMEDICAMENTO_H
#define CAJAMEDICAMENTO_H

#include <QString>

class CajaMedicamento {
public:
    CajaMedicamento(float dosisTotales);
    CajaMedicamento(int id, float dosisTotales);

    CajaMedicamento operator+(const CajaMedicamento &otra) const;
    bool operator==(const CajaMedicamento &otra) const;
    QString toString() const;

    int getId() const;
    float getDosisTotales() const;

private:
    int id;
    float dosisTotales;
};

#endif // CAJAMEDICAMENTO_H
