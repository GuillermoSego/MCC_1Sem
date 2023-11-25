
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"

// Función para realizar la factorización QR
void QR_Factorization(double *A, double *Q, double *R, int n) {
    // Creamos matrices temporales
    double u[n][n];
    double e[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            u[i][j] = A[j + i*n];
        }

        for (int k = 0; k < i; k++) {
            double proj[n];
            for (int j = 0; j < n; j++) {
                proj[j] = e[k][j] * DotProd(u[i], e[k], n);
            }
            SubtractVector(u[i], proj, n);
        }

        // Normalizamos el vector u[i] para obtener e[i]
        double norm = sqrt(DotProd(u[i], u[i], n));
        for (int j = 0; j < n; j++) {
            e[i][j] = u[i][j] / norm;
        }
    }

    // Obtenemos Q y R
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Q[j + i*n] = e[i][j];
            if (i <= j) {
                R[i + j*n] = DotProd(e[i], u[j], n);
            } else {
                R[i + j*n] = 0.0;
            }
        }
    }
}

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
        printf("La matriz debe ser cuadrada para la factorización QR.\n");
        free(A);
        return 1;
    }

    double *Q = (double *)malloc(rows * rows * sizeof(double)); 
    double *R = (double *)malloc(rows * rows * sizeof(double)); 

    QR_Factorization(A, Q, R, rows);

    printf("Matriz Q:\n");
    MatrixShow(rows, rows, Q);

    printf("\nMatriz R:\n");
    MatrixShow(rows, rows, R);

    free(Q);
    free(R);

    return 0;
}