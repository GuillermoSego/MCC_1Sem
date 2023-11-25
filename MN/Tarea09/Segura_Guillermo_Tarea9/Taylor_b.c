#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "matrix.h"

// Función para calcular el factorial de un número
double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// Función que calcula la aproximación mediante la serie de Taylor
double Taylor(double* derivadas, double x0, double z, int n) {
    double resultado = 0.0;

    // Recorremos las derivadas para calcular el término i de la serie
    for (int i = 0; i < n; i++) {
        resultado += (derivadas[i] * pow((z - x0), i)) / factorial(i);
    }

    return resultado;
}

int main() {
    double x0 = 0.0;  // Valor en el que está centrada la serie
    double z_values[] = {0.5, 1, 1.5, 2.0};  // Valores para los cuales se evaluará la serie
    int n_values[] = {1, 3, 5, 10};  // Grados de la serie a evaluar
    int num_z_values = sizeof(z_values) / sizeof(z_values[0]);
    int num_n_values = sizeof(n_values) / sizeof(n_values[0]);

    // Imprimimos las cabeceras de la tabla
    printf("| %-8s | %-8s | %-15s | %-15s | %-15s |\n", "z", "n", "P_n(z)", "f(z)", "Error Absoluto");
    printf("|----------|----------|-----------------|-----------------|-----------------|\n");

    // Recorremos los valores de z
    for (int i = 0; i < num_z_values; i++) {
        // Recorremos los grados de la serie
        for (int j = 0; j < num_n_values; j++) {
            int n = n_values[j];
            double* nprimes = malloc(n * sizeof(double));

            // Calculamos las derivadas (en este caso son todas iguales a e^x0)
            for (int k = 0; k < n; k++) {
                nprimes[k] = pow(M_E, x0);  
            }

            // Calculamos la aproximación con la serie de Taylor
            double valorAproximado = Taylor(nprimes, x0, z_values[i], n);
            double valorReal = exp(z_values[i]);
            double errorAbsoluto = fabs(valorReal - valorAproximado);

            // Imprimimos los resultados en la tabla
            printf("| %-8.2lf | %-8d | %-15.5lf | %-15.5lf | %-15.5lf |\n", z_values[i], n, valorAproximado, valorReal, errorAbsoluto);

            // Liberamos la memoria reservada para las derivadas
            free(nprimes);
        }
    }

    return 0;
}
