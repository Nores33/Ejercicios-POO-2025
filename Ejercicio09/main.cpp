#include <QApplication>
#include "ventana.h"

int main(int argc, char **argv)
{
    QApplication app( argc, argv );

    //La razon por la que no funcionaba el ejercicio del profesor era que mainWindow era un QWidget y no una "Ventana"
    ventana mainWindow;
    mainWindow.setWindowTitle("Ventana");
    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}
