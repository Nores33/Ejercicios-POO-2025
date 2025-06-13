#ifndef ADMINAPI_H
#define ADMINAPI_H

#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>

class AdminAPI {
private:
    static AdminAPI *instancia;
    QNetworkAccessManager networkManager;
    const QString urlBase = "http://localhost:8000";
    QString token;
    AdminAPI();

public:
    static AdminAPI *getInstancia();

    // Inicio de sesión y registro
    QNetworkReply* iniciarSesion(
        const QString &usuario,
        const QString &contrasena);

    QNetworkReply* registrarUsuario(
        const QString &nombre,
        const QString &apellido,
        const QString &usuario,
        const QString &contrasena,
        const QString &correo);

    QNetworkReply* cambiarContrasena(
        const QString &usuario,
        const QString &contrasenaActual,
        const QString &nuevaContrasena);
};

#endif // ADMINAPI_H
