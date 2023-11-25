
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

int main(int argc, char *argv[]){

    // Manejo de argumentos de la línea de comandos
    if(argc != 3) {
        printf("Uso: %s <nombre_archivo_matriz> <nombre_archivo_vector>\n", argv[0]);
        return 1;
    }

    const char* filename1 = argv[1];
    const char* filename2 = argv[2];

    // No tenemos certeza del tamaño de la matriz
    // Declaramos un apuntador hacia un bloque de memoria específico de la matriz A
    double *A;
    int rows, cols;

    // Leemos la matriz en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename1 ,&A, &rows, &cols) == 1) {
        free(A); // Liberamos memoria
        return 0;
    } 

    // Leemos B
    double *B;
    int rowsB, colsB;  // Para no sobreescribir las dimensiones originales de A

    if (ReadMatrix(filename2 ,&B, &rowsB, &colsB) == 1) {
        free(B); // Liberamos memoria
        return 0;
    } 

    int maxIter = 1000; // Número máximo de iteraciones
    double tol = 1e-10; // Tolerancia para la convergencia

    double *x = gaussSeidelMethod(A, B, rows, maxIter, tol);

    // Imprimir la solución
    printf("La solución x es: \n");
    MatrixShow(1, rowsB, x);

    // Liberamos la memoria
    free(A);
    free(B);
    free(x);

    return 0;
}