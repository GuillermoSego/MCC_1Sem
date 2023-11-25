
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"

int main() {
    // Definimos los puntos de interpolación dados
    int n = 5;
    double x[] = {0, 0.5, 1.0, 1.5, 2.0};
    double f[5];
    for(int i = 0; i < n; i++) {
        f[i] = exp(x[i]);
    }

    // Puntos en los que queremos interpolar
    double z[] = {0.4, 0.8, 1.2, 1.6, 1.9};
    
    printf("|  z  |   f(z)   | I. Lagrange | error L. | I. Neville | error N. | I. DD  | error DD |\n");
    printf("|--------------------------------------------------------------------------------------------|\n");
    
    for(int i = 0; i < 5; i++) {
        double realValue = exp(z[i]);
        
        double lagrangeValue = polinomioLagrange(n-1, x, f, z[i]);
        double errorL = fabs(realValue - lagrangeValue);
        
        double nevilleValue = Neville(z[i], x, f, n-1);
        double errorN = fabs(realValue - nevilleValue);
        
        double **F = malloc(n * sizeof(double *));
        for (int j = 0; j < n; j++) {
            F[j] = malloc(n * sizeof(double));
        }
        calculaDiferenciasDivididas(n, x, f, F);
        double ddValue = interpolacionNewton(n, x, F, z[i]);
        double errorDD = fabs(realValue - ddValue);
        
        // Llenamos la tabla con los resultados
        printf("| %.1lf | %8.6lf | %11.6lf | %7.6lf | %10.6lf | %7.6lf | %6.6lf | %8.6lf |\n", z[i], realValue, 
        lagrangeValue, errorL, nevilleValue, errorN, ddValue, errorDD);


        for (int j = 0; j < n; j++) {
            free(F[j]);
        }
        free(F);
    }

    return 0;
}
