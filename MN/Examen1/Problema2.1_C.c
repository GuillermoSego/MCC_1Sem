
/*
Metodo de Cholesky para resolver Ax = b
Guillermo Segura Gómez
*/

# include <stdio.h>
# include "matrix.h"
# include <stdlib.h>
# include <math.h>


int main() {
    
    int size = 2000;
    // Inicializar la matriz A como un solo bloque de memoria
    double *A = malloc(size * size * sizeof(double));

    // Inicializar el vector B
    double *B = malloc(size * sizeof(double));
    
    // Iniclaizar la matriz
    Matrix_Initialize(A, B, size);

    /*
    
    Metodo de Cholesky
    
    */
    
    // Declaramos las matrices L y U para almacenar los resultados
    double *L = (double *) malloc(size * size * sizeof(double));
    // Las incializamos en 0
    Initialize(L, size * size);

    // Aplicamos la factorización LU
    // Manejo de estado devuelto por crout
    if (cholesky(A, L, size) == -1) {
        printf("Error durante la factorización\n");
        free(A);
        free(B);
        free(L);
        return -1;
    }

    // Declarar la memoria para la solución
    double *X = malloc( size * sizeof(double) );
    Initialize(X, size);

    solveCholesky(L, B, X, size);

    // Checar si tenemos solución
    double tolerance = 1e-3;  // Define umbral de tolerancia
    int control = isSolution(A, X, B, size, tolerance);

    if (control == 0 ) {
        printf("X es solución de AX = b.\n");
    } else {
        printf("X no es solución de AX = b.\n");
    }

    // Guardar valores propios en un archivo
    saveMatrixToFile( X, size, 1, "Solucion_Cholesky.txt" );

    // Liberar la memoria
    free(A);
    free(B);
    free(L);
    free(X);

    return 0;
}
