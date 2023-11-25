
#include <stdio.h>

int main() {
    int numero;

    // Solicitar al usuario un número
    printf("Introduce un número: ");
    scanf("%d", &numero);

    // Uso de la estructura de selección if...else
    if (numero > 0) {
        printf("El número es positivo.\n");
    } else if (numero < 0) {
        printf("El número es negativo.\n");
    } else {
        printf("El número es cero.\n");
    }

    return 0;
}
