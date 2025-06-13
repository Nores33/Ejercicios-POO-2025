#include "adminapi.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>

AdminAPI* AdminAPI::instancia = nullptr;

AdminAPI::AdminAPI() {}

AdminAPI* AdminAPI::getInstancia() {
    if (!instancia) {
        instancia = new AdminAPI();
    }
    return instancia;
}

QNetworkReply* AdminAPI::iniciarSesion(const QString &usuario, const QString &contrasena) {
    QUrl url(urlBase + "/auth/login");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("username", usuario);
    params.addQueryItem("password", contrasena);

    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::registrarUsuario(const QString &nombre, const QString &apellido, const QString &usuario,
                                          const QString &contrasena, const QString &correo) {
    QUrl url(urlBase + "/auth/registro");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("nombre", nombre);
    params.addQueryItem("apellido", apellido);
    params.addQueryItem("usuario", usuario);
    params.addQueryItem("clave", contrasena);
    params.addQueryItem("mail", correo);

    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}

QNetworkReply* AdminAPI::cambiarContrasena(const QString &usuario, const QString &contrasenaActual, const QString &nuevaContrasena) {
    QUrl url(urlBase + "/auth/cambiar-clave");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QUrlQuery params;
    params.addQueryItem("usuario", usuario);
    params.addQueryItem("clave_actual", contrasenaActual);
    params.addQueryItem("nueva_clave", nuevaContrasena);

    return networkManager.post(request, params.query(QUrl::FullyEncoded).toUtf8());
}


