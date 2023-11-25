
# include <stdio.h>
# include <stdlib.h>
# include "matrix.h"

int main() {
    int n; // Número de puntos

    printf("Ingrese el número de puntos n+1: ");
    scanf("%d", &n);

    double *x = (double *)malloc(n * sizeof(double));
    double *f = (double *)malloc(n * sizeof(double));
    double **F = (double **)malloc(n * sizeof(double *));

    for (int i = 0; i < n; i++) {
        F[i] = (double *)malloc(n * sizeof(double));
    }

    printf("Ingrese los valores de x y f(x):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("f[%d] = ", i);
        scanf("%lf", &f[i]);
    }

    double valorX;
    printf("Ingrese el valor de x para interpolar: ");
    scanf("%lf", &valorX);

    // Calculamos la tabla de diferencias divididas
    calculaDiferenciasDivididas(n, x, f, F);

    // Realizamos la interpolación de Newton
    double resultado = interpolacionNewton(n, x, F, valorX);
    printf("El valor interpolado en x = %.2lf es: %.2lf\n", valorX, resultado);

    // Liberamos la memoria reservada
    free(x);
    free(f);
    for (int i = 0; i < n; i++) {
        free(F[i]);
    }
    free(F);

    return 0;
}
