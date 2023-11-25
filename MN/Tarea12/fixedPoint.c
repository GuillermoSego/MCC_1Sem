
# include <stdio.h>
# include <math.h>
# include "matrix.h"

// Ejemplo burden
void G(double x[], double result[]) {
    result[0] = (cos(x[1] * x[2]) + 0.5) / 3.0; // x1
    result[1] = -0.1 + sqrt((x[0] * x[0] + sin(x[2]) + 1.06) / 81.0); // x2
    result[2] = -(exp(-x[0] * x[1]) + (10 * M_PI - 3) / 3.0) / 20.0; // x3
}

// Método de iteración de punto fijo
void fixedPointIteration(double x[], double tol, int maxIter, int N) {
    double xNext[N], error;
    int iter = 0;

    do {
        // Aplicar la función G
        G(x, xNext);

        // Calcular el error como la norma de la diferencia entre iteraciones
        for (int i = 0; i < N; i++) {
            xNext[i] -= x[i];
        }
        error = Norm(xNext, N);

        // Preparar la siguiente iteración
        for (int i = 0; i < N; i++) {
            x[i] += xNext[i];
        }

        iter++;
    } while (error > tol && iter < maxIter);

    // Imprimir el resultado
    if (iter < maxIter) {
        printf("Solución encontrada después de %d iteraciones:\n", iter);
        for (int i = 0; i < N; i++) {
            printf("x[%d] = %f\n", i, x[i]);
        }
    } else {
        printf("No se encontró una solución en %d iteraciones.\n", maxIter);
    }
}

int main() {
    double x[] = {0.1, 0.1, -0.1}; // Valores iniciales
    int N = sizeof(x)/sizeof(x[0]); // Tamaño sistema
    double tol = 1e-5; // Tolerancia
    int maxIter = 1000; // Número máximo de iteraciones

    fixedPointIteration(x, tol, maxIter, N);

    return 0;
}
