
# include <iostream>
# include <vector>
# include <iterator>
# include <algorithm>

int main() {

    std::cout << "Ingrese una serie de enteros. Para terminar ingrese un valor no numérico." << std::endl;

    // Leer enteros desde la entrada estándar usando 
    // Se lee hasta EOF o hasta un valor no válido para el tipo de dato
    std::istream_iterator<int> inputStart(std::cin), inputEnd;

    // Crear un vector y copiar los enteros leídos en él usando std::copy
    std::vector<int> nums;
    std::copy(inputStart, inputEnd, std::back_inserter(nums));

    // Comprobar si se han ingresado números.
    if (nums.empty()) {
        std::cout << "No se ingresaron números. Terminando el programa." << std::endl;
        return 0;
    }

    std::cout << "Ordenando los números ingresados..." << std::endl;

    // sort reordena los elementos en el rango [begin, end)
    std::sort(nums.begin(), nums.end());

    // Escribir los enteros ordenados a la salida estándar usando std::ostream_iterator
    std::cout << "Números ordenados: ";
    std::ostream_iterator<int> output(std::cout, " ");
    std::copy(nums.begin(), nums.end(), output);
    std::cout << std::endl;

    return 0;
}
