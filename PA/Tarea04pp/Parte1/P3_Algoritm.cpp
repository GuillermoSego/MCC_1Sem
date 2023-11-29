
# include <iostream>
# include <vector>
# include <random>
# include <algorithm>

int main() {

    // Inicializar el generador de números aleatorios
    std::random_device rd;

    // std::mt19937 es un generador de números pseudoaleatorios
    // Se alimenta con una 'semilla' procedente de std::random_device
    std::mt19937 gen(rd());

    // Definimos una distribución de números. Aquí estamos usando números enteros
    // en el rango de 1 a 100
    std::uniform_int_distribution<> distrib(1, 100);

    // Crear un vector para almacenar números enteros
    std::vector<int> vec;

    // Llenar el vector con 10 números aleatorios
    for (int i = 0; i < 10; ++i) {
        vec.push_back(distrib(gen)); // Añadir un número aleatorio al vector
    }

    // Ordenar el vector
    // std::sort reordena los elementos en el rango [begin, end)
    std::sort(vec.begin(), vec.end());

    // Imprimir el vector ordenado.
    std::cout << "Vector ordenado: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Encontrar el elemento más pequeño en el vector
    // std::min_element devuelve un iterador al elemento más pequeño
    auto min_it = std::min_element(vec.begin(), vec.end());

    // Encontrar el elemento más grande en el vector
    // std::max_element devuelve un iterador al elemento más grande
    auto max_it = std::max_element(vec.begin(), vec.end());

    // Imprimir el valor más pequeño y más grande
    std::cout << "El menor elemento es: " << *min_it << std::endl;
    std::cout << "El mayor elemento es: " << *max_it << std::endl;

    // Barajar el vector. std::shuffle reorganiza los elementos en un orden aleatorio
    // Para este método usamos un generado de números aleatorios como tercer argumentp
    std::shuffle(vec.begin(), vec.end(), gen);

    // Imprimir el vector después de barajarlo
    std::cout << "Vector barajado: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
