#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>
#include <QScreen>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear la etiqueta (QLabel)
    QLabel *label = new QLabel;
    label->setWindowTitle("Imagen");
    label->setAlignment(Qt::AlignCenter);

    // Cargar la imagen
    QPixmap imagen("../../pcb.jpg");
    if (imagen.isNull()) {
        qWarning("No se pudo cargar la imagen");
        return -1;
    }

    // Obtener tamaño de pantalla principal
    QSize pantallaSize = QGuiApplication::primaryScreen()->availableSize();

    // Escalar la imagen al tamaño de la pantalla, manteniendo proporciones
    QPixmap escalada = imagen.scaled(pantallaSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Pegar la imagen escalada en el QLabel
    label->setPixmap(escalada);

    // Mostrar en pantalla completa
    label->showMaximized();

    // Cerrar aplicación después de 3 segundos
    QTimer::singleShot(3000, &app, &QApplication::quit);

    return app.exec();
}
