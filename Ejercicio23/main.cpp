#include <iostream>
using namespace std;

class CuentaBancaria {
private:
    int saldo;
public:
    CuentaBancaria(int saldoInicial) : saldo(saldoInicial) {}

    void depositar(int cantidad) {
        saldo += cantidad;
    }

    void mostrar() const {
        cout << "Saldo: " << saldo << endl;
    }

    friend bool compararSaldo(const CuentaBancaria& c1, const CuentaBancaria& c2);
};

bool compararSaldo(const CuentaBancaria& c1, const CuentaBancaria& c2) {
    return c1.saldo > c2.saldo;
}

int main()
{
    CuentaBancaria cuenta1(1000);
    CuentaBancaria cuenta2(500);

    cuenta1.depositar(200); // cuenta1 ahora tiene 1200
    cuenta2.depositar(800); // cuenta2 ahora tiene 1300

    cout << "Cuenta 1: ";
    cuenta1.mostrar();
    cout << "Cuenta 2: ";
    cuenta2.mostrar();

    if (compararSaldo(cuenta1, cuenta2)) {
        cout << "La cuenta 1 tiene mayor saldo que la cuenta 2." << endl;
    } else {
        cout << "La cuenta 1 NO tiene mayor saldo que la cuenta 2." << endl;
    }

    return 0;
}
