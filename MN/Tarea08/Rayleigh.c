# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"

void RayleighQuotientMethod(double *A, double *v0, double *v1, int n, double epsilon, int maxIterations, double *eigenvalue) {
    
    // Inicialización de la variable sigma
    double sigma = 0;

    // Alocación dinámica de memoria para matrices temporales
    double *B = (double *)malloc(n * n * sizeof(double));
    double *Av0 = (double *)malloc(n * sizeof(double));

    // Iteración principal
    for (int k = 0; k < maxIterations; k++) {

        // B = A - sigma * I
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                B[i*n + j] = A[i*n + j];
                if (i == j) {
                    B[i*n + i] -= sigma;
                }
            }
        }

        // Resolución del sistema usando eliminación Gaussiana
        eliminacionGaussiana(n, B, v0);
        resuelveSistema(n, B, v0, v1);

        // Normalización de v1
        double norm_v1 = sqrt(DotProd(v1, v1, n));
        Divide(v1, norm_v1, v1, n);

        // Actualización de v0 y cálculo de sigma
        for (int i = 0; i < n; i++) {
            v0[i] = v1[i];
        }
        MatrixProduct(A, v0, Av0, n, n, 1);
        sigma = DotProd(v0, Av0, n) / DotProd(v0, v0, n);

        // Verificación de convergencia
        SubtractVector(v1, v0, n);
        if (sqrt(DotProd(v1, v1, n)) < epsilon) {
            break;
        }
    }

    // Actualización del eigenvalor resultante
    *eigenvalue = sigma;

    // Liberación de memoria
    free(B);
    free(Av0);
}

int main(int argc, char *argv[]){

    // Verificación de argumentos de entrada
    if(argc != 2) {
        printf("Uso: %s <nombre_archivo_matriz>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    double *A;
    int rows, cols;

    // Lectura de la matriz desde el archivo
    if (ReadMatrix(filename, &A, &rows, &cols) == 1) {
        free(A);
        return 0;
    }

    // Verificación de que la matriz sea cuadrada
    if(rows != cols) {
        printf("La matriz no es cuadrada.\n");
        free(A);
        return 1;
    }

    // Inicialización del vector de entrada v0
    double v0[rows];
    for(int i = 0; i < rows; i++) {
        v0[i] = 1.0;
    }

    double v1[rows];
    double eigenvalue;

    // Aplicación del método cociente de Rayleigh
    RayleighQuotientMethod(A, v0, v1, rows, 1e-9, 1000, &eigenvalue);

    // Impresión de resultados
    printf("Eigenvalor aproximado: %lf\n", eigenvalue);
    printf("El vector propio aproximado: \n");
    MatrixShow(rows, 1, v0);

    // Liberación de memoria
    free(A);
    return 0;
}
