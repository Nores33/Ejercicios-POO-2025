#include "ventana_secundaria.h"
#include <QVBoxLayout>
#include <QPixmap>
#include <QBuffer>
#include <QImageReader>

ventana_secundaria::ventana_secundaria(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Imagen");
    resize(400, 300);

    imagenLabel = new QLabel("Cargando imagen...", this);
    imagenLabel->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imagenLabel);
    setLayout(layout);

    manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, this, &ventana_secundaria::imagenDescargada);
}

void ventana_secundaria::cargarImagenDesdeUrl(const QString &url)
{
    manager->get(QNetworkRequest(QUrl(url)));
}

void ventana_secundaria::imagenDescargada(QNetworkReply *reply)
{
    if (reply->error() != QNetworkReply::NoError) {
        imagenLabel->setText("Error al cargar imagen.");
        reply->deleteLater();
        return;
    }

    QPixmap pixmap;
    if (pixmap.loadFromData(reply->readAll())) {
        imagenLabel->setPixmap(pixmap);
        imagenLabel->adjustSize();
        adjustSize();
        emit imagenCargada();
    } else {
        imagenLabel->setText("No se pudo procesar la imagen.");
    }

    reply->deleteLater();
}
