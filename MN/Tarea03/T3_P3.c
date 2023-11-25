
#include <stdio.h>
#include <stdlib.h>

// Función para realizar la eliminación gaussiana y transformar A en una matriz U
void eliminacionGaussiana(int n, double **A, double *b) {
    for (int k = 0; k < n - 1; k++) {  // Iteramos sobre las columnas
        for (int i = k + 1; i < n; i++) {  // Iteramos sobre las filas debajo de la diagonal
            double lik = A[i][k] / A[k][k];
            
            // Actualizamos la fila i
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= lik * A[k][j];
            }
            
            // Actualizamos b[i]
            b[i] -= lik * b[k];
        }
    }
}

// Función para resolver un sistema Ux = b donde U es una matriz triangular superior
void resuelveSistema(int n, double **U, double *b, double *x) {
    // Implementación de la sustitución hacia atrás
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = n - 1; j > i; j--) {
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
}

// Función para imprimir una matriz
void imprimeMatriz(int n, double **matriz) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para imprimir un vector
void imprimeVector(int n, double *vector) {
    for (int i = 0; i < n; i++) {
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main() {
    int n = 3;  // Número de ecuaciones y variables

    // Reservamos memoria para las matrices y vectores
    double **A = (double **)malloc(n * sizeof(double *));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Inicializamos la matriz A y el vector b
    A[0][0] = 2; A[0][1] = 1; A[0][2] = -1;
    A[1][0] = -3; A[1][1] = -1; A[1][2] = 2;
    A[2][0] = -2; A[2][1] = 1; A[2][2] = 2;

    b[0] = 8;
    b[1] = -11;
    b[2] = -3;

    // Realizamos la eliminación gaussiana
    eliminacionGaussiana(n, A, b);

    // Resolvemos el sistema Ux = b
    resuelveSistema(n, A, b, x);

    // Imprimimos el resultado
    printf("Solución x:\n");
    imprimeVector(n, x);

    // Liberamos la memoria reservada
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);

    return 0;
}
