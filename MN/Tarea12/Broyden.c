
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
#include <string.h>
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

// Calcula la matriz jacobiana
void Jacobian(double x[], double **jacobiano, double h, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            jacobiano[i][j] = partialDerivative(i, x, j, h);
        }
    }
}


// Función para actualizar la matriz A utilizando Broyden
void UpdateBroyden(double *A, double *s, double *y, double *v, int n) {
    double *z = (double *)malloc(n * sizeof(double));
    double p, u[n];

    // Paso 6: z = -A * y
    Divide(y, -1, y, n);
    MatrixProduct(A, y, z, n, n, 1);

    // Paso 7: p = -s^T * z
    p = 0;
    for (int i = 0; i < n; i++) {
        p -= s[i] * z[i];
    }

    // Paso 8: u^T = s^T * A
    for (int i = 0; i < n; i++) {
        u[i] = 0;
        for (int j = 0; j < n; j++) {
            u[i] += s[j] * A[j * n + i];
        }
    }

    // Paso 9: A = A + (1/p) * (s + z) * u^T
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i * n + j] += (1/p) * (s[i] + z[i]) * u[j];
        }
    }

    free(z);
}

// Método de Broyden
void BroydenMethod(double x[], double tol, int maxIter, int n) {
    double *deltaX = (double *)malloc(n * sizeof(double));
    double **A = (double **)malloc(n * sizeof(double *));
    double *v = (double *)malloc(n * sizeof(double)); 
    double *w = (double *)malloc(n * sizeof(double)); 
    double *y = (double *)malloc(n * sizeof(double));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Paso 1: Determinar A_0 = J(x) y v = F(x)
    Jacobian(x, A, tol, n); //
    F(x, v, n);

    // Paso 2: A = A_0^-1 (Usar eliminación gaussiana)
    gaussJordanInversa(n, A, A);

    // v = FlattenMatrix(A, n, n);
    // MatrixShow(n, n, v);
    // exit(1);

    // Aplanamos la matriz
    double* Ainv = FlattenMatrix(A, n, n);

    int iter;
    for (iter = 1; iter <= maxIter; iter++) {
        // Paso 3: s = -A * v
        // Conjugate_gradient(Ainv, v, deltaX, n, n);
        Divide(v, -1, v, n);
        MatrixProduct(Ainv, v, deltaX, n, n, 1);

        // MatrixShow(n, 1, deltaX);
        // exit(1);

        // Paso 4: x = x + s
        for (int i = 0; i < n; i++) {
            x[i] += deltaX[i];
        }

        // Paso 5: w = v; v = F(x); y = v - w
        memcpy(w, v, n * sizeof(double));
        F(x, v, n);
        for (int i = 0; i < n; i++) {
            y[i] = v[i] - w[i];
        }

        // Actualizar A usando Broyden
        UpdateBroyden(Ainv, deltaX, y, v, n);

        // Verificar la convergencia
        if (Norm(deltaX, n) < tol) {
            printf("Convergencia alcanzada en %d iteraciones.\n", iter);
            break;
        }
    }

    if (iter > maxIter) {
        printf("Número máximo de iteraciones excedido.\n");
    }

    free(A);
    free(deltaX);
    free(v);
    free(w);
    free(y);
}

int main() {
    double x[] = {0.1, 0.1, -0.1}; // Valor inicial
    int N = sizeof(x)/sizeof(x[0]); // Tamaño sistema
    double tol = 1e-5;              // Tolerancia para la convergencia
    int maxIter = 1000;              // Número máximo de iteraciones

    // Definir el sistema
    systemFunctions = (double (**)(double[]))malloc(N * sizeof(double (*)(double[])));
    systemFunctions[0] = func1;
    systemFunctions[1] = func2;
    systemFunctions[2] = func3;

    BroydenMethod(x, tol, maxIter, N);

    // Imprimir los resultados
    printf("Solución encontrada:\n");
    MatrixShow(N, 1, x);

    return 0;
}
