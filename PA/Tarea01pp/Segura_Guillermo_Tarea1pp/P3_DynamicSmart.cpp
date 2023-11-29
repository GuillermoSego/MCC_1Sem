
# include <iostream>
# include <ctime>
# include <memory>  // Para std::unique_ptr

int main() {
    int size;
    std::cout << "Ingrese el tamaño del arreglo: ";
    std::cin >> size;

    // Para asegurar que el size sea un número valido
    if (size <= 0) {
        std::cout << "El tamaño debe ser un número positivo." << std::endl;
        return 1;
    }

    // Asignación dinámica de memoria para el arreglo usando std::unique_ptr
    std::unique_ptr<double[]> array(new double[size]);

    // Inicializar la semilla de números aleatorios
    std::srand(std::time(0));

    // Llenar el arreglo con números aleatorios
    for (int i = 0; i < size; ++i) {
        array[i] = static_cast<double>(rand()) / RAND_MAX;
        std::cout << "array[" << i << "] = " << array[i] << std::endl; // Imprimir
    }

    // No es necesario liberar la memoria (explícitamente) :o

    return 0;
}
