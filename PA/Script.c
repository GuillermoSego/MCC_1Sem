#include <stdio.h>

// Define el tipo de función 'funcType' que toma dos enteros y devuelve un entero
typedef int (*funcType)(int, int);

// Una función que toma dos enteros y devuelve su suma
int suma(int a, int b) {
    return a + b;
}

// Una función que toma dos enteros y devuelve su resta
int resta(int a, int b) {
    return a - b;
}

// Una función que toma un apuntador a una función como argumento
void operacion(funcType func, int x, int y) {
    int resultado = func(x, y);  // Llama a la función a través del apuntador
    printf("Resultado: %d\n", resultado);
}

int main() {
    // Pasa la función 'suma' como argumento a 'operacion'
    operacion(suma, 5, 3);  // Output: Resultado: 8

    // Pasa la función 'resta' como argumento a 'operacion'
    operacion(resta, 5, 3);  // Output: Resultado: 2

    return 0;
}
