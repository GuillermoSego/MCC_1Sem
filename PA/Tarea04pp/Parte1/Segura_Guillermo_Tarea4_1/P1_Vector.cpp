
# include <iostream>
# include <vector>

// Función para imprimir un vector
void printVector(const std::vector<int>& v) {
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

    // Declarar un vector
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printVector(vec);

    // Agregar elementos al final del vector
    vec.push_back(6);
    vec.push_back(7);
    std::cout << "Elementos agregados: " << std::endl;;
    printVector(vec);

    // Eliminar elementos del vector
    vec.erase(vec.begin() + 1, vec.begin() + 3);
    std::cout << "Elementos eliminados: " << std::endl;;
    printVector(vec);

    // Encontrar elementos del vector
    auto it = std::find(vec.begin(), vec.end(), 4);
    if (it != vec.end()) {
        std::cout << "Valor encontrado: " << *it << std::endl;
    } else {
        std::cout << "Valor no encontrado" << std::endl;
    }

    return 0;
}
