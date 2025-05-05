#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <QCryptographicHash>

// Inicialización del puntero estático
AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");
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
        query.exec("CREATE TABLE IF NOT EXISTS usuarios ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "username TEXT NOT NULL UNIQUE,"
                   "password TEXT NOT NULL)");

        query.exec("CREATE TABLE IF NOT EXISTS configuracion ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "ultimo_usuario TEXT)");
    }
}

bool AdminDB::validarUsuario(const QString &username, const QString &password) {
    QSqlQuery query;
    query.prepare("SELECT password_md5 FROM usuarios WHERE username = :username");
    query.bindValue(":username", username);

    if (query.exec() && query.next()) {
        QString storedPassword = query.value(0).toString();
        QString hashedPassword = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Md5).toHex());
        return storedPassword == hashedPassword;
    }
    return false;
}

void AdminDB::guardarUltimoUsuario(const QString &username) {
    QSqlQuery query;
    query.prepare("INSERT OR REPLACE INTO configuracion (id, ultimo_usuario) VALUES (1, :username)");
    query.bindValue(":username", username);
    query.exec();
}

QString AdminDB::leerUltimoUsuario() {
    QSqlQuery query("SELECT ultimo_usuario FROM configuracion WHERE id = 1");
    if (query.exec() && query.next()) {
        return query.value(0).toString();
    }
    return QString();
}
