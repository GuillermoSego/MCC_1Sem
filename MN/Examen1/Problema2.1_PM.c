
/*
Metodo de potencias para eigenvalores
Guillermo Segura Gómez
*/

# include <stdio.h>
# include "matrix.h"
# include <stdlib.h>
# include <math.h>


int main() {
    
    int size = 200;
    // Inicializar la matriz A como un solo bloque de memoria
    double *A = malloc(size * size * sizeof(double));

    // Inicializar el vector B
    double *B = malloc(size * sizeof(double));
    
    // Iniclaizar la matriz
    Matrix_Initialize(A, B, size);

    /*
    
    Metodo de potencias 

    */

    // Reservar memoria para almacenar los vectores propios y valores propios
    double *U = (double *)malloc(size * size * sizeof(double)); 
    double *l = (double *)malloc(size * sizeof(double)); 

    // Ejecutar el método de la potencia
    PowerMethod(A, U, l, size);

    // Imprimir valores propios
    int numValues = 10;  // Número de valores propios a mostrar

    printf("+--------------------------------------+\n");
    printf("| Valores propios mayores | Valores propios menores |\n");
    printf("+--------------------------------------+\n");

    for(int i = 0; i < numValues; i++) {
        printf("| %7.2f                  | %7.2f                  |\n", l[i], l[size-numValues+i]);
    }

    printf("+--------------------------------------+\n");

    // Guardar valores propios en un archivo
    saveMatrixToFile( l, size, 1, "Valores_propios1.txt" );

    // Liberar la memoria
    free(A);
    free(U);
    free(l);
    free(B);

    return 0;
}
