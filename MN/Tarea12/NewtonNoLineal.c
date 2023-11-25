
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


void NewtonMethod(double x[], double tol, int maxIter, int N) {
    double Fval[N], deltaX[N];
    double h = 1e-5;  // Paso para el cálculo de derivadas
    int iter = 0;

    // Crear Jval como una matriz dinámica
    double **Jval = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        Jval[i] = malloc(N * sizeof(double));
    }

    for (iter = 0; iter < maxIter; iter++) {
        F(x, Fval, N); // Evaluar la función
        Jacobian(x, Jval, h, N); // Calcular el Jacobiano

        // Convertir el Jacobiano y Fval para usar en el método del Gradiente Conjugado
        double *J_flat = FlattenMatrix(Jval, N, N);
        NegateVector(Fval, N); // Convertir a -Fval

        // Resuelve el sistema lineal J * deltaX = -F usando Gradiente Conjugado
        Conjugate_gradient(J_flat, Fval, deltaX, N, N);

        // Actualizar x = x + deltaX
        for (int i = 0; i < N; i++) {
            x[i] += deltaX[i];
        }

        // Verificar la convergencia
        if (Norm(deltaX, N) < tol) {
            break;
        }

        free(J_flat); // Liberar la memoria de la matriz aplanada
    }

    // Liberar la memoria de Jval
    for (int i = 0; i < N; i++) {
        free(Jval[i]);
    }
    free(Jval);

    // Comprobar si se alcanzó la convergencia
    if (iter == maxIter) {
        printf("No se alcanzó la convergencia después de %d iteraciones.\n", maxIter);
    } else {
        printf("Convergencia alcanzada en %d iteraciones.\n", iter);
    }
}


int main() {
    double x[] = {0.1, 0.1, -0.1}; // Valor inicial
    int N = sizeof(x)/sizeof(x[0]); // Tamaño sistema
    double tol = 1e-5;              // Tolerancia para la convergencia
    int maxIter = 100;              // Número máximo de iteraciones

    systemFunctions = (double (**)(double[]))malloc(N * sizeof(double (*)(double[])));
    systemFunctions[0] = func1;
    systemFunctions[1] = func2;
    systemFunctions[2] = func3;

    NewtonMethod(x, tol, maxIter, N);

    // Imprimir los resultados
    printf("Solución encontrada:\n");
    MatrixShow(N, 1, x);

    return 0;
}
