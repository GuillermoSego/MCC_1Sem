
#include <stdio.h>
#include <stdlib.h>

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

    // Inicializamos la matriz A y el vector b para el caso d)
    double A_values[5][5] = {
        {9.00000, 7.00000, 2.00000, 3.00000, 2.00000},
        {0.00000, 9.22222, 8.77778, 9.66667, 8.77778},
        {0.00000, 0.00000, 2.93976, -5.93976, 1.93976},
        {0.00000, 0.00000, 0.00000, -5.22951, 1.59016},
        {0.00000, 0.00000, 0.00000, 0.00000, 5.69749}
    };
    double b_values[5] = {51.0000, 127.3333, -5.2410, -12.9672, 28.4875};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A_values[i][j];
        }
        b[i] = b_values[i];
    }

    // Resolvemos el sistema Ux = b (como la matriz ya es triangular superior)
    resuelveSistema(n, A, b, x);

    // Imprimimos el resultado
    printf("Solución x:\n");
    for (int i = 0; i < n; i++) {
        printf("%.4f ", x[i]);
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
