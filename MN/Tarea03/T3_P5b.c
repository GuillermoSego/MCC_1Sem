
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Función para intercambiar dos filas en una matriz
void intercambiaFilas(double **A, double *b, int fila1, int fila2, int n) {
    for (int j = 0; j < n; j++) {
        double temp = A[fila1][j];
        A[fila1][j] = A[fila2][j];
        A[fila2][j] = temp;
    }
    double temp = b[fila1];
    b[fila1] = b[fila2];
    b[fila2] = temp;
}

// Función para encontrar el valor máximo y la fila correspondiente en una columna de una matriz
int encuentraMax(double **A, int columna, int n) {
    double maxValor = fabs(A[columna][columna]);
    int filaMax = columna;
    for (int i = columna + 1; i < n; i++) {
        if (fabs(A[i][columna]) > maxValor) {
            maxValor = fabs(A[i][columna]);
            filaMax = i;
        }
    }
    return filaMax;
}

// Función para realizar la eliminación gaussiana con pivoteo parcial
void eliminacionGaussianaPivoteo(int n, double **A, double *b) {
    for (int k = 0; k < n - 1; k++) {
        int filaMax = encuentraMax(A, k, n);
        if (filaMax != k) {
            intercambiaFilas(A, b, filaMax, k, n);
        }
        for (int i = k + 1; i < n; i++) {
            double lik = A[i][k] / A[k][k];
            for (int j = k + 1; j < n; j++) {
                A[i][j] -= lik * A[k][j];
            }
            b[i] -= lik * b[k];
        }
    }
}

// Función para resolver el sistema Ux = b donde U es una matriz triangular superior
void resuelveSistema(int n, double **U, double *b, double *x) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = n - 1; j > i; j--) {
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
}

int main() {
    int n = 5;  // Número de ecuaciones y variables

    // Reservamos memoria para las matrices y vectores
    double **A = (double **)malloc(n * sizeof(double *));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));
    
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Inicializamos la matriz A y el vector b para el caso b)
    double A_values[5][5] = {
        {2, 20, 18, 20, 18},
        {6, 16, 18, 2, 16},
        {18, 14, 4, 6, 4},
        {16, 16, 2, 16, 16},
        {6, 10, 4, 2, 8}
    };
    double b_values[5] = {532, 360, 204, 396, 172};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A_values[i][j];
        }
        b[i] = b_values[i];
    }

    // Realizamos la eliminación gaussiana con pivoteo parcial
    eliminacionGaussianaPivoteo(n, A, b);

    // Resolvemos el sistema Ux = b
    resuelveSistema(n, A, b, x);

    // Imprimimos el resultado
    printf("Solución x:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", x[i]);
    }
    printf("\n");

    // Liberamos la memoria reservada
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);

    return 0;
}
