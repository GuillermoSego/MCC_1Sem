
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

int main() {
    int n;  // Grado del polinomio

    // Pedimos al usuario el grado del polinomio
    printf("Introduce el grado n del polinomio: ");
    scanf("%d", &n);

    // Creamos los arrays para los puntos de prueba
    double *x_values = malloc((n+1) * sizeof(double));
    double *y_values = malloc((n+1) * sizeof(double));

    // Pedimos al usuario los puntos de prueba
    for (int i = 0; i <= n; i++) {
        printf("Introduce x[%d]: ", i);
        scanf("%lf", &x_values[i]);
        printf("Introduce y[%d]: ", i);
        scanf("%lf", &y_values[i]);
    }

    double x;  // Punto en el que se evaluará el polinomio
    printf("Introduce el valor de x para evaluar el polinomio: ");
    scanf("%lf", &x);

    // Calculamos el valor del polinomio en x
    double valor = polinomioLagrange(n, x_values, y_values, x);

    // Imprimimos el resultado
    printf("El valor del polinomio de Lagrange en x=%.2lf es: %.2lf\n", x, valor);

    // Liberamos la memoria reservada
    free(x_values);
    free(y_values);

    return 0;
}
