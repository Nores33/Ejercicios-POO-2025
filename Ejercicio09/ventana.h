#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>                // Incluye la clase base QWidget para crear la ventana
#include <QUrl>                   // Incluye la clase QUrl para manejar URLs
#include <QNetworkAccessManager>  // Permite gestionar solicitudes de red
#include <QNetworkRequest>        // Permite crear solicitudes HTTP
#include <QNetworkReply>          // Permite manejar las respuestas de red

// Definición de la clase ventana, que hereda de QWidget
class ventana : public QWidget
{
    Q_OBJECT // Macro necesaria para usar señales y slots en Qt

public:
    ventana(); // Constructor de la clase ventana

private:
    QNetworkAccessManager manager; // Objeto para gestionar las descargas de red
    QImage image;                  // Imagen descargada que se mostrará en la ventana

protected:
    void paintEvent(QPaintEvent * ); // Método protegido que se llama cuando la ventana necesita repintarse

private slots:
    void slot_descargaFinalizada(QNetworkReply * reply); // Slot privado que se ejecuta cuando termina la descarga
};

#endif // VENTANA_H
