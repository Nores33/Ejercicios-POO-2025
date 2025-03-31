#include <iostream>
#include <vector>
#include <string>

std::string eliminarEspacios(const std::string& str) {
    std::string resultado;
    for (char c : str) {
        if (c != ' ') {
            resultado += c;
        }
    }
    return resultado;
}

int main() {
    std::vector<std::string> expresiones = {
        "pan comido",
        "hablando de roma...",
        "estar al horno",
        "el que avisa no traiciona",
        "tirar la toalla"
    };

    // Ordenar sin considerar los espacios
    for (int i = 0; i < expresiones.size(); ++i) {
        for (int j = i + 1; j < expresiones.size(); ++j) {
            if (eliminarEspacios(expresiones[i]) > eliminarEspacios(expresiones[j])) {
                std::swap(expresiones[i], expresiones[j]);
            }
        }
    }

    for (int i = 0; i < expresiones.size(); ++i) {
        std::cout << expresiones[i] << std::endl;
    }

    return 0;
}
