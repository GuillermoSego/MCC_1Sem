#include <stdio.h>

// Funcion para encontrar el GDC
int GDC( int a, int b ){

    // Para encontrar el GDC implementamos el algoritmo de euclides
    int maj, min, r;
    
    // Encontramos el valor mayor y el valor menor
    maj = a > b ? a : b;
    min = a < b ? a : b;

    // Iteramos sobre el residuo de la division
    while (maj % min != 0)
    {
        r = maj % min;
        maj = min;
        min = r;
    }

    return min;

}

int main(){

    // Tenemos que encontrar el MCD o GDC
    int a, b, resultado;

    a = 10, b = 4;

    printf("Introduce una fraccion en formato a/b:\n");
    scanf("%d/%d", &a, &b);

    // Llamamos ala funcion
    resultado = GDC(a, b);

    // Se imprime el resultado
    printf("La fraccion reducida es: %d/%d",a/resultado, b/resultado);

    return 0;
}