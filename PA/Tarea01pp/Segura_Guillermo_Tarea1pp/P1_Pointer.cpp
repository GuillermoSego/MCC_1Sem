
# include <iostream>

int Sum(int* array, int n) {
    int result = 0;
    int* arrayPtr = array;

    for (int i = 0; i < n; i++) {
        result += *arrayPtr;
        arrayPtr++;
    }

    return result;
}

int main() {
    int arreglo[3] = {10, 20, 30};
    int size = sizeof(arreglo) / sizeof(arreglo[0]);

    int result = Sum(arreglo, size);

    std::cout << "La suma es: " << result << std::endl;

    return 0;
}
