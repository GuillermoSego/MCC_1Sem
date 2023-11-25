
# include <stdio.h>
# include <stdlib.h> 
# include <math.h>
# include "matrix.h"

int main() {

    // Datos ejemplo libro Burden
    // double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    // double y[] = {1.3, 3.5, 4.2, 5.0, 7.0, 8.8, 10.1, 12.5, 13.0, 15.6}; 

    // Datos problema 2
    double x[] = {0.273, 0.473, 0.673, 0.873, 0.1073, 0.1273, 1.473};
    double m0 = 1.919e-2;
    double T0 = 273;
    double Su = 139;
    double lambdas[] = {0, 1e-5, 1e-7}; 

    int n = sizeof(x)/sizeof(x[0]); // Cantidad de datos
    // Cantidad de términos en el polinomio ajustado (grado + 1)
    int m = 3; 

    double y[n]; // Declaración y
    for (int i = 0; i < n; i++) {
        y[i] = sutherland(x[i], m0, T0, Su);
    }
    

    double lambda = 0.0000005; // Definimos lambda
    char* optionname[] = {"polinómica", "trigonométrica", "radial"};

    for (int i = 1; i < 4; i++)
    {

        // Construcción del sistema de interpolación
        double* A = malloc(m * m * sizeof(double)); // A = Phi^T * Phi + Alpha
        double* b = malloc(m * sizeof(double));
        
        // Construcción sistema A w = b 
        // A = Phi^T * Phi + Alpha
        // b = Phi^T y
        buildSystem(m, n, x, y, A, b, lambda, i); 

        // Resolución del sistema A*w = b
        double *w = malloc( m * sizeof(double) );
        Initialize(w, m);

        // Calculamos el gradiente conjugado
        Conjugate_gradient( A, b, w, m, m );

        // Mostramos la matriz
        printf("Los coeficientes del ajuste m = %d para opción %s son los siguientes:\n", m, optionname[i-1]);
        MatrixShow(m, 1, w);

        // Liberar memoria
        free(A);
        free(b);
        free(w);

    }
    

    return 0;
}