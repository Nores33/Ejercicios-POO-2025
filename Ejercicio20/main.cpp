#include <iostream>
#include <vector>

using namespace std;

// Clase base Instrumento
class Instrumento {
protected:
    string marca;

public:
    Instrumento() : marca("Yamaha") {}
    virtual ~Instrumento() {}

    virtual void sonar() = 0; // función virtual pura
    virtual void verlo() {
        cout << "Marca: " << marca << endl;
    }

    void setMarca(const string& nuevaMarca) {
        marca = nuevaMarca;
    }

    string getMarca() const {
        return marca;
    }
};

// Clase Guitarra
class Guitarra : public Instrumento {
private:
    int cuerdas;

public:
    Guitarra() : cuerdas(6) {}

    void sonar() override {
        cout << "Guitarra suena..." << endl;
    }

    int getCuerdas() const {
        return cuerdas;
    }

    void setCuerdas(int c) {
        cuerdas = c;
    }
};

// Clase Bateria
class Bateria : public Instrumento {
private:
    int tambores;

public:
    Bateria() : tambores(5) {}

    void sonar() override {
        cout << "Batería suena..." << endl;
    }

    int getTambores() const {
        return tambores;
    }

    void setTambores(int t) {
        tambores = t;
    }
};

// Clase Electrico
class Electrico {
protected:
    int voltaje;

public:
    Electrico() : voltaje(220) {}
    virtual ~Electrico() {
        cout << "Desenchufado" << endl;
    }

    int getVoltaje() const {
        return voltaje;
    }

    void setVoltaje(int v) {
        voltaje = v;
    }
};

// Clase Teclado con herencia múltiple
class Teclado : public Instrumento, public Electrico {
private:
    int teclas;

public:
    Teclado() : teclas(61) {}

    void sonar() override {
        cout << "Teclado suena..." << endl;
    }

    int getTeclas() const {
        return teclas;
    }

    void setTeclas(int t) {
        teclas = t;
    }
};

int main() {
    vector<Instrumento*> instrumentos;

    // Crear e insertar objetos
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Teclado());

    cout << "--- Marcas de los instrumentos ---" << endl;
    for (Instrumento* inst : instrumentos) {
        inst->verlo();
    }

    cout << "\n--- Sonido de los instrumentos ---" << endl;
    for (Instrumento* inst : instrumentos) {
        inst->sonar();
    }


    for (Instrumento* inst : instrumentos) {
        delete inst;
    }

    return 0;
}
