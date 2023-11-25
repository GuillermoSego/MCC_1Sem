
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "EDO.h"

// Función dada
double f(double t, double y) {
    return y - pow(t, 2) + 1;
}

int main() {
    double a = 0; // Punto inicial
    double b = 2; // Punto final
    int N = 10; // Número de pasos
    double alpha = 0.5; // Condición inicial y(0) = alpha

    double w[N+1]; // +1 para incluir el punto inicial

    Euler(a, b, N, alpha, f, w);

    return 0;
}
