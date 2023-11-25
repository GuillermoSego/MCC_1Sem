
#include <stdio.h>
#include <stdlib.h>

// Función para resolver un sistema de ecuaciones Lx = b
// donde L es una matriz triangular inferior
void resuelveSistema(int n, double **L, double *b, double *x) {

    // Recorremos cada ecuación para encontrar la incógnita correspondiente
    for (int i = 0; i < n; i++) {
        double sum = 0.0;

        // Calculamos la suma de L[i][j] * x[j] para j < i
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * x[j];
        }

        // Despejamos x[i] de la ecuación
        x[i] = (b[i] - sum) / L[i][i];
    }
}

// Función para imprimir una matriz
void imprimeMatriz(int n, double **matriz) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Imprimimos cada elemento de la matriz seguido de un espacio
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para imprimir un vector
void imprimeVector(int n, double *vector) {
    for (int i = 0; i < n; i++) {
        // Imprimimos cada elemento del vector seguido de un espacio
        printf("%.2f ", vector[i]);
    }
    printf("\n");
}

int main() {
    int n = 3;  // Número de ecuaciones y variables

    // Creamos la matriz L y el vector b
    double **L = (double **)malloc(n * sizeof(double *));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        L[i] = (double *)malloc(n * sizeof(double));
    }

    // Inicializamos la matriz L (triangular inferior) y el vector b
    L[0][0] = 1; L[0][1] = 0; L[0][2] = 0;
    L[1][0] = 2; L[1][1] = 1; L[1][2] = 0;
    L[2][0] = 1; L[2][1] = 2; L[2][2] = 1;

    b[0] = 1;
    b[1] = 3;
    b[2] = 3;

    // Imprimimos la matriz L y el vector b
    printf("Matriz L:\n");
    imprimeMatriz(n, L);
    printf("Vector b:\n");
    imprimeVector(n, b);

    // Resolvemos el sistema de ecuaciones
    resuelveSistema(n, L, b, x);

    // Imprimimos el resultado
    printf("Solución x:\n");
    imprimeVector(n, x);

    // Liberamos la memoria reservada
    for (int i = 0; i < n; i++) {
        free(L[i]);
    }
    free(L);
    free(b);
    free(x);

    return 0;
}
