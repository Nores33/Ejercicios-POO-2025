#ifndef VENTANA_SECUNDARIA_H
#define VENTANA_SECUNDARIA_H

#include <QWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ventana_secundaria : public QWidget
{
    Q_OBJECT
public:
    explicit ventana_secundaria(QWidget *parent = nullptr);

    void cargarImagenDesdeUrl(const QString &url);

signals:
    void imagenCargada(); // señal para avisar cuando esté lista

private slots:
    void imagenDescargada(QNetworkReply *reply);

private:
    QLabel *imagenLabel;
    QNetworkAccessManager *manager;
};

#endif // VENTANA_SECUNDARIA_H
