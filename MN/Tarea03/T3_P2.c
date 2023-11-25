
#include <stdio.h>
#include <stdlib.h>

// Función para resolver un sistema de ecuaciones Ux = b
// donde U es una matriz triangular superior
void resuelveSistema(int n, double **U, double *b, double *x) {

    // Recorremos cada ecuación en orden inverso para encontrar la incógnita correspondiente
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;

        // Calculamos la suma de U[i][j] * x[j] para j > i
        for (int j = n - 1; j > i; j--) {
            sum += U[i][j] * x[j];
        }

        // Despejamos x[i] de la ecuación
        x[i] = (b[i] - sum) / U[i][i];
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

    // Creamos la matriz U y el vector b
    double **U = (double **)malloc(n * sizeof(double *));
    double *b = (double *)malloc(n * sizeof(double));
    double *x = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        U[i] = (double *)malloc(n * sizeof(double));
    }

    // Inicializamos la matriz U (triangular superior) y el vector b
    U[0][0] = 1; U[0][1] = 2; U[0][2] = 1;
    U[1][0] = 0; U[1][1] = 1; U[1][2] = 2;
    U[2][0] = 0; U[2][1] = 0; U[2][2] = 1;

    b[0] = 3;
    b[1] = 3;
    b[2] = 1;

    // Imprimimos la matriz U y el vector b
    printf("Matriz U:\n");
    imprimeMatriz(n, U);
    printf("Vector b:\n");
    imprimeVector(n, b);

    // Resolvemos el sistema de ecuaciones
    resuelveSistema(n, U, b, x);

    // Imprimimos el resultado
    printf("Solución x:\n");
    imprimeVector(n, x);

    // Liberamos la memoria reservada
    for (int i = 0; i < n; i++) {
        free(U[i]);
    }
    free(U);
    free(b);
    free(x);

    return 0;
}
