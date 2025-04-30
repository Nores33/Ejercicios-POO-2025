#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QList>
#include "cajamedicamento.h"

class AdminDB {
private:
    static AdminDB *instancia; // Puntero estático a la instancia única
    AdminDB(); // Constructor privado

    QSqlDatabase db;

public:
    static AdminDB *getInstancia(); // Método estático para obtener la instancia única

    void conectar();
    bool insertarCaja(float dosis);
    QList<CajaMedicamento> obtenerTodas();
};

#endif // ADMINDB_H
