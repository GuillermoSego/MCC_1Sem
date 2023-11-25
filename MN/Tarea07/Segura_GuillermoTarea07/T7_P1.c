
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"


int main(int argc, char *argv[]){

    // Manejo de argumentos de la línea de comandos
    if(argc != 2) {
        printf("Uso: %s <nombre_archivo_matriz>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    // No tenemos certeza del tamaño de la matriz
    // Declaramos un apuntador hacia un bloque de memoria específico de la matriz A
    double *A;
    int rows, cols;

    // Leemos la matriz en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename ,&A, &rows, &cols) == 1) {
        free(A); // Liberamos memoria
        return 0;
    }

    // Comprobar si la matriz es cuadrada
    if (rows != cols) {
        printf("La matriz debe ser cuadrada para el método de la potencia.\n");
        free(A);
        return 1;
    }

    // Reservar memoria para almacenar los vectores propios y valores propios
    double *U = (double *)malloc(rows * rows * sizeof(double)); 
    double *l = (double *)malloc(rows * sizeof(double)); 

    // Pide al usuario ingresar el numero de n valores propios
    int number;
    printf("Introduce el numero de n valores propios(n): ");
    scanf("%d", &number);

    // Ejecutar el método de la potencia
    PowerMethod(A, U, l, rows);

    printf("Valores propios:\n");
    MatrixShow(number, 1, l);

    printf("Vectores propios:\n");
    MatrixShow(number, number, U);

    // Liberar la memoria reservada
    free(U);
    free(l);
    free(A);

    return 0;
}
