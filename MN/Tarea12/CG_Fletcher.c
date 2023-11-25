
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

double g(double *x, int n) {
    return pow(func1(x), 2) + pow(func2(x), 2) + pow(func3(x), 2);
}

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

// Método de Fletcher-Reeves
void fletcherReeves(double *x, int n, double tol, int maxIter) {
    double g1, g2, g3, g0, g_new, alpha0, alpha1 = 0, alpha2, alpha3 = 1, z0, h1, h2, h3;
    double *z = malloc(n * sizeof(double));
    double *x_new = malloc(n * sizeof(double));
    double *F_val = malloc(3 * sizeof(double));
    double **JacobianMatrix = malloc(3 * sizeof(double *));
    for (int i = 0; i < 3; i++) {
        JacobianMatrix[i] = malloc(n * sizeof(double));
    }
    double *JacobianFlat = malloc(n * 3 * sizeof(double));
    int k;

    for (k = 1; k <= maxIter; k++) {
        F(x, F_val, n); // Calcula F(x)
        Jacobian(x, JacobianMatrix, tol, n); // Calcula la matriz Jacobiana

        // Aplana la matriz Jacobiana
        JacobianFlat = FlattenMatrix(JacobianMatrix, n, n);

        // Calcula el gradiente como 2 * Jacobian^T * F_val
        MatrixT(n, n, JacobianFlat, JacobianFlat); // Transpone la Jacobiana
        MatrixProduct(JacobianFlat, F_val, z, n, 3, 1); // Multiplica Jacobian^T * F_val
        Divide(z, 0.5, z, n); // Multiplica por 2


        z0 = Norm(z, n);
        if (z0 == 0) {
            printf("Gradiente cero en la iteración %d\n", k);
            break;
        };

        // Normalizar z
        Divide(z, z0, z, n);


        g1 = g(x, n);
        while (1) {
            for (int i = 0; i < n; i++) {
                x_new[i] = x[i] - alpha3 * z[i];
            }
            g3 = g(x_new, n);

            if (g3 < g1) {
                break;
            }

            alpha3 /= 2;
            if (alpha3 < tol) {
                printf("Sin probable mejora en la iteración %d\n", k);
                break;
            }
        }

        alpha2 = alpha3 / 2;
        for (int i = 0; i < n; i++) {
            x_new[i] = x[i] - alpha2 * z[i];
        }
        g2 = g(x_new, n);

        // Cálculos para interpolar la cuadrática
        h1 = (g2 - g1) / alpha2;
        h2 = (g3 - g2) / (alpha3 - alpha2);
        h3 = (h2 - h1) / alpha3;
        alpha0 = 0.5 * (alpha2 - h1 / h3);

        for (int i = 0; i < n; i++) {
            x_new[i] = x[i] - alpha0 * z[i];
        }
        g0 = g(x_new, n);

        // Escoger el mejor alpha
        double alpha = (g0 < g3) ? alpha0 : alpha3;
        for (int i = 0; i < n; i++) {
            x[i] -= alpha * z[i];
        }
        g_new = g(x, n);

        // Verificar la convergencia
        if (fabs(g_new - g1) < tol) {
            printf("Convergencia alcanzada en la iteración %d\n", k);
            break;
        }
    }

    if (k == maxIter) {
        printf("Número máximo de iteraciones excedido\n");
    }

    // Liberar memoria
    free(z);
    free(x_new);
    free(F_val);
    free(JacobianMatrix);
    free(JacobianFlat);
}

int main() {

    double x[] = {0.0, 0.0, 0.0}; // Aproximación inicial
    int N = sizeof(x)/sizeof(x[0]); // Tamaño sistema
    double tol = 1e-5;
    int maxIter = 1000;

    // Definir el sistema
    systemFunctions = (double (**)(double[]))malloc(N * sizeof(double (*)(double[])));
    systemFunctions[0] = func1;
    systemFunctions[1] = func2;
    systemFunctions[2] = func3;

    fletcherReeves(x, N, tol, maxIter);

    // Imprimir los resultados
    printf("Solución encontrada:\n");
    MatrixShow(N, 1, x);

    free(systemFunctions);

    return 0;
}

