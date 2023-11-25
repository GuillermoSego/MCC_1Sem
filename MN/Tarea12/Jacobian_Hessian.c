
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include "derivation.h"
# include "matrix.h"


double func1(double x[]) {
    return 3 * x[0] - cos(x[1] * x[2]) - 0.5;
}

double func2(double x[]) {
    return x[0] * x[0] - 81 * (x[1] + 0.1) * (x[1] + 0.1) + sin(x[2]) + 1.06;
}

double func3(double x[]) {
    return exp(-x[0] * x[1]) + 20 * x[2] + (10 * M_PI - 3) / 3.0;
}

double (**systemFunctions)(double[]);

void F(double x[], double result[], int numFunctions) {
    for (int i = 0; i < numFunctions; i++) {
        result[i] = systemFunctions[i](x);
    }
}

// Calcula la primer derivada
double partialDerivative(int i, double x[], int xi, double h) {
    double temp, originalValue, derivative;
    originalValue = x[xi];

    // Aproximación de la derivada utilizando el método de cinco puntos
    x[xi] = originalValue - 2 * h;
    double f1 = systemFunctions[i](x);
    x[xi] = originalValue - h;
    double f2 = systemFunctions[i](x);
    x[xi] = originalValue + h;
    double f3 = systemFunctions[i](x);
    x[xi] = originalValue + 2 * h;
    double f4 = systemFunctions[i](x);

    // Restaura el valor original
    x[xi] = originalValue;

    derivative = (f1 - 8 * f2 + 8 * f3 - f4) / (12 * h);
    return derivative;
}

// Calcula la segunda derivada
double secondPartialDerivative(int funcIndex, double x[], int xi, int xj, double h) {
    double originalValueXi = x[xi];
    double originalValueXj = x[xj];
    double derivative;

    x[xi] = originalValueXi + h;
    x[xj] = originalValueXj + h;
    double f1 = systemFunctions[funcIndex](x);

    x[xi] = originalValueXi - h;
    x[xj] = originalValueXj + h;
    double f2 = systemFunctions[funcIndex](x);

    x[xi] = originalValueXi + h;
    x[xj] = originalValueXj - h;
    double f3 = systemFunctions[funcIndex](x);

    x[xi] = originalValueXi - h;
    x[xj] = originalValueXj - h;
    double f4 = systemFunctions[funcIndex](x);

    // Restaura los valores originales
    x[xi] = originalValueXi;
    x[xj] = originalValueXj;

    derivative = (f1 - f2 - f3 + f4) / (4 * h * h);
    return derivative;
}

// Calcula la matriz jacobiana
void Jacobian(double x[], double **jacobiano, double h, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            jacobiano[i][j] = partialDerivative(i, x, j, h);
        }
    }
}

// Calcula la matriz Hessiana para una función específica
void Hessian(double x[], double **hessiana, double h, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            hessiana[i][j] = secondPartialDerivative(i, x, i, j, h);
        }
    }
}

int main() {
    double x[] = {0.1, 0.1, -0.1}; // Valor inicial
    int N = sizeof(x)/sizeof(x[0]); // Tamaño del sistema
    double h = 1e-5;               // Tamaño del paso para la diferenciación

    // Definir el sistema de funciones
    systemFunctions = (double (**)(double[]))malloc(N * sizeof(double (*)(double[])));
    systemFunctions[0] = func1;
    systemFunctions[1] = func2;
    systemFunctions[2] = func3;

    // Memoria para las matrices resultado
    double **J = (double **)malloc(N * sizeof(double *));
    double **H = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        J[i] = (double *)malloc(N * sizeof(double));
        H[i] = (double *)malloc(N * sizeof(double));
    }

    Jacobian(x, J, h, N);
    Hessian(x, H, h, N);

    // Imprimir los resultados
    printf("Matriz Jacobiana:\n");
    double * Jshow = FlattenMatrix(J, N, N);
    MatrixShow(N, N, Jshow);

    printf("Matriz Hessiana:\n");
    double * Hshow = FlattenMatrix(H, N, N);
    MatrixShow(N, N, Hshow);

    // Liberar la memoria asignada
    for (int i = 0; i < N; i++) {
        free(J[i]);
        free(H[i]);
    }
    free(J);
    free(H);
    free(systemFunctions);

    return 0;
}