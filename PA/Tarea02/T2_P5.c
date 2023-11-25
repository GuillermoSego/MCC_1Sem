# include <stdio.h>

// Función para convertir un número en base 10 a una base N
void ConvertToBaseN(int num, int base) {
    int stack = 0;  // Actúa como una pila para almacenar dígitos
    int size = 0;  // Guarda el tamaño actual de la pila

    /* Usamos una pila para ir guardando los dígitos del número en la base deseada.
    Cada dígito es el residuo de la división del número entre la base. */
    while (num > 0) {
        // Obtenemos el residuo de la división
        int remainder = num % base;  
        stack = stack * 10 + remainder;  
        size++; 

        // Dividimos el número entre la base
        num /= base; 
    }

    int i = 0; 
    do {

        // Sacamos el último dígito almacenado en la pila
        int digit = stack % 10; 

        // Usamos un if implícito para determinar cómo imprimir el dígito
        printf("%c", digit < 10 ? '0' + digit : 'A' + digit - 10);

        // Quitamos el último dígito de la pila
        stack /= 10;  
        i++;  
    } while (i < size);  
}

int main() {
    int num, base;  // Declaración de variables

    // Solicitamos el número y la base al usuario
    printf("Introduce un numero decimal: ");
    scanf("%d", &num);

    printf("Introduce la base a la que deseas convertir (2-16): ");
    scanf("%d", &base);

    // Verificamos que la base esté en el rango permitido
    if (base < 2 || base > 16) {
        printf("Base fuera del rango permitido.\n");
        return 1;  // Terminamos el programa con un código de error
    }

    // Llamamos a la función para realizar la conversión
    printf("El numero en base %d es: ", base);
    ConvertToBaseN(num, base);
    printf("\n");  // Añadimos un salto de línea al final

    return 0;  // Finalizamos el programa exitosamente
}
