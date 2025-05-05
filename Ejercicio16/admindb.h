#ifndef ADMINDB_H
#define ADMINDB_H

#include <QString>
#include <QSqlDatabase>

class AdminDB {
private:
    static AdminDB *instancia;
    QSqlDatabase db;
    AdminDB();

public:
    static AdminDB *getInstancia();
    void conectar();
    bool validarUsuario(const QString &username, const QString &password);
    void guardarUltimoUsuario(const QString &username);
    QString leerUltimoUsuario();
};

#endif // ADMINDB_H
