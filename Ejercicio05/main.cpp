#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QWidget * ventana = new QWidget;
    ventana->setWindowTitle( "Imagen" );
    ventana->resize( 800, 600 );

    QLabel *label = new QLabel;

    QPixmap imagen("../imagen.jpg");

    return app.exec();
}
