#include "ventana.h" // Incluye el archivo de cabecera de la clase ventana

#include <QPainter> // Incluye la clase QPainter para dibujar en la ventana

ventana::ventana()
{
    // Conecta la señal 'finished' del QNetworkAccessManager con el slot que maneja la descarga finalizada
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    // Crea una solicitud de red para descargar la imagen desde la URL especificada
    QNetworkRequest req(QUrl("https://www.ubp.edu.ar/wp-content/uploads/2021/08/UBP.png"));
    // Inicia la descarga de la imagen usando el manager
    manager.get(req);
}

void ventana::paintEvent(QPaintEvent *)
{
    QPainter painter(this); // Crea un objeto QPainter para dibujar en la ventana actual
    // Dibuja la imagen escalada al tamaño de la ventana
    painter.drawImage(0, 0, this->image.scaled(this->width(), this->height()));
}

void ventana::slot_descargaFinalizada(QNetworkReply *reply)
{
    // Convierte los datos descargados en una imagen y la guarda en el atributo 'image'
    this->image = QImage::fromData(reply->readAll());
    // Solicita que la ventana se repinte para mostrar la imagen descargada
    this->repaint();
}
