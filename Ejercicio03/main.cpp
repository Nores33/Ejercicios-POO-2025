#include <iostream>
#include <vector>
#include <cstring>

#define MAX_RAM (200 * 1024 * 1024) // 200 MB en bytes

class Producto {
private:
    int id;
    double precio;
    char descripcion[256]; // Simula un objeto con tamaño significativo

public:
    Producto(int id, double precio, const char* desc) : id(id), precio(precio) {
        strncpy(descripcion, desc, sizeof(descripcion) - 1);
        descripcion[sizeof(descripcion) - 1] = '\0';
    }
};

int main() {
    std::vector<Producto> productos;
    size_t memoriaUsada = 0;
    size_t tamObjeto = sizeof(Producto);

    while (memoriaUsada + tamObjeto <= MAX_RAM) {
        productos.emplace_back(productos.size(), productos.size() * 1.5, "Ejemplo de producto");
        memoriaUsada += tamObjeto;
    }

    std::cout << "Objetos almacenados: " << productos.size() << std::endl;
    return 0;
}
