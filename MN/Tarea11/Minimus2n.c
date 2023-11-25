
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
    double lambdas[] = {0.0, 0.00001, 0.0000001};
    double evaluationTable[4][3]; 

    int n = sizeof(x)/sizeof(x[0]); // Cantidad de datos
    
    // Declaración y
    double y[n];
    for (int i = 0; i < n; i++) {
        y[i] = sutherland(x[i], m0, T0, Su);
    }

    // El valor option determina que tipo de función se utiliza.
    // 1. Polinomial
    // 2. Trigonométrico
    // 3. Radial
    // int option = 1; 
    int option;
    printf("Introduce el tipo de ajuste:\n1. Polinomial\n2. Trigonométrico\n3. Radial\n");
    scanf("%d", &option);

    // Para cada grado m, calcular los coeficientes para cada lambda y almacenar las evaluaciones
    for (int mIndex = 0; mIndex < 4; mIndex++) {
        int m = mIndex + 2; // m = 2, 3, 4, 5

        for (int lambdaIndex = 0; lambdaIndex < sizeof(lambdas)/sizeof(lambdas[0]); lambdaIndex++) {
            double lambda = lambdas[lambdaIndex];

            double* A = malloc(m * m * sizeof(double));
            double* b = malloc(m * sizeof(double));
            double* w = malloc(m * sizeof(double));

            // Construimos y resolvemos el sistema para cada lambda
            buildSystem(m, n, x, y, A, b, lambda, option); 
            Initialize(w, m);
            Conjugate_gradient(A, b, w, m, m);

            // Evaluamos el polinomio en el punto 1.2 y almacenamos el resultado
            evaluationTable[mIndex][lambdaIndex] = EvaluatePol(w, m-1, 1.2);

            // Liberamos memoria
            free(A);
            free(b);
            free(w);
        }
    }

    // Imprimir la tabla de evaluaciones
    printf("Tabla de Evaluaciones para T = 1.2\n");
    printf("m \\ lambda\t");
    for (int lambdaIndex = 0; lambdaIndex < sizeof(lambdas)/sizeof(lambdas[0]); lambdaIndex++) {
        printf("%e\t", lambdas[lambdaIndex]);
    }
    printf("\n");

    for (int mIndex = 0; mIndex < 4; mIndex++) {
        printf("%d\t\t", mIndex + 2);
        for (int lambdaIndex = 0; lambdaIndex < sizeof(lambdas)/sizeof(lambdas[0]); lambdaIndex++) {
            printf("%lf\t", evaluationTable[mIndex][lambdaIndex]);
        }
        printf("\n");
    }

    // Imprimir el valor real de la función de Sutherland para T = 1.2
    double realValue = sutherland(1.2, m0, T0, Su);
    printf("\nEl valor real de la función de Sutherland para T = 1.2 es: %lf\n", realValue);

    return 0;
}