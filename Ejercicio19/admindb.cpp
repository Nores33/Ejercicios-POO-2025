#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

// Inicialización del puntero estático
AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("medicamentos.db");
}

AdminDB *AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB();
    }
    return instancia;
}

void AdminDB::conectar() {
    if (!db.open()) {
        qDebug() << "Error al conectar con la base de datos:" << db.lastError().text();
    } else {
        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS cajas_medicamentos ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "dosis_totales REAL NOT NULL)");
    }
}

bool AdminDB::insertarCaja(float dosis) {
    if (dosis > 1000) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO cajas_medicamentos (dosis_totales) VALUES (:dosis)");
    query.bindValue(":dosis", dosis);
    return query.exec();
}

QList<CajaMedicamento> AdminDB::obtenerTodas() {
    QList<CajaMedicamento> lista;
    QSqlQuery query("SELECT id, dosis_totales FROM cajas_medicamentos");
    while (query.next()) {
        int id = query.value(0).toInt();
        float dosis = query.value(1).toFloat();
        lista.append(CajaMedicamento(id, dosis));
    }
    return lista;
}
