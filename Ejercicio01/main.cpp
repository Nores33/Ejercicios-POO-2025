#include <iostream>
#include <vector>

class Poste{
private:
    int altura; // m
    float diametro; // cm

public:
    Poste(int a, float d){
        altura = a;
        diametro = d;
    }

    int GetAltura(){
        return altura;
    }

    float GetDiametro(){
        return diametro;
    }
};

int main()  {
    std::vector<Poste> postes;

    postes.emplace_back(5, 10.5);
    postes.emplace_back(3, 8.2);
    postes.emplace_back(7, 12.0);
    postes.emplace_back(4, 9.8);
    postes.emplace_back(6, 11.3);

    // Mostrar postes antes de ordenar
    for (int i = 0; i < postes.size(); i++){
        std::cout << "Poste " << i+1 << ": Altura = " << postes[i].GetAltura() << " m, Diametro = " << postes[i].GetDiametro() << " cm" << std::endl;
    }

    std::cout << "\nOrdenamos por altura los postes...\n";

    // Ordenar postes por altura
    for (int i = 0; i < postes.size(); i++){
        for (int j = 0; j < postes.size()-1; j++){
            if (postes[j].GetAltura() > postes[j+1].GetAltura()){
                Poste aux = postes[j];
                postes[j] = postes[j+1];
                postes[j+1] = aux;
            }
        }
    }

    // Mostrar postes despues de ordenar
    for (int i = 0; i < postes.size(); i++){
        std::cout << "Poste " << i+1 << ": Altura = " << postes[i].GetAltura() << " m, Diametro = " << postes[i].GetDiametro() << " cm" << std::endl;
    }

    return 0;
}
