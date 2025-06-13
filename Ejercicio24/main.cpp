#include <QCoreApplication>
#include <QString>
#include <QDebug>

class Persona {
private:
    QString nombre;
    static int contador;
public:
    Persona(const QString& nombre);
    void mostrar() const;
    static int totalPersonas();
};

int Persona::contador = 0;

Persona::Persona(const QString& nombre) : nombre(nombre) {
    ++contador;
}

void Persona::mostrar() const {
    qDebug() << "Nombre:" << nombre;
}

int Persona::totalPersonas() {
    return contador;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Persona p1("Ana");
    Persona p2("Luis");
    Persona p3("Sofía");

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    qDebug() << "Total de personas creadas:" << Persona::totalPersonas();

    return 0;
}
