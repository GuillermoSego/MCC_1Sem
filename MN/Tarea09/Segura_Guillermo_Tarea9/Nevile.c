
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"


int main() {
    // Número de puntos (n+1)
    int n;
    printf("Ingrese el número de puntos n+1: ");
    scanf("%d", &n);
    n--;  // Como el usuario ingresa n+1, reducimos en 1 para usar 0-indexación

    // Arrays para almacenar los puntos x y y
    double x_values[n+1], y_values[n+1];

    // Capturamos los puntos
    for (int i = 0; i <= n; i++) {
        printf("Ingrese x[%d] y y[%d]: ", i, i);
        scanf("%lf %lf", &x_values[i], &y_values[i]);
    }

    // Punto x donde queremos interpolar
    double x;
    printf("Ingrese el valor de x para interpolar: ");
    scanf("%lf", &x);

    // Calculamos el valor interpolado usando Neville
    double y_interpolado = Neville(x, x_values, y_values, n);

    // Imprimimos el resultado
    printf("El valor interpolado en x = %.2f es: %.2f\n", x, y_interpolado);

    return 0;
}
