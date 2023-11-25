
#include "Solve_Matrix.h"
#include <stdio.h>
#include <stdlib.h>

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
