/*

Biblioteca para manejo de interpolación

*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>


// Funcion para realizar un arreglo con cierta separacion
void linspace(double x[], double init, double end, int n) {
    double delta = (end - init) / (n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = init + delta * i;
    }
}

// Rutina para guardar una matriz en un archivo
void saveMatrixToFile(double *A, int n, int m, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            fprintf(file, "%7.2f ", A[i * m + j]);  // %7.2f para dar formato y que se vea ordenado
        }
        fprintf(file, "\n");  // Nueva línea al final de cada fila
    }

    fclose(file);
}

// Función para calcular el polinomio de Lagrange
double polinomioLagrange(int n, double *x_values, double *y_values, double x) {
    double resultado = 0.0;

    // Recorremos cada punto de prueba
    for (int i = 0; i <= n; i++) {
        double producto = y_values[i];

        // Calculamos el producto L_i(x)
        for (int j = 0; j <= n; j++) {
            if (i != j) {
                producto *= (x - x_values[j]) / (x_values[i] - x_values[j]);
            }
        }

        // Sumamos el producto al resultado
        resultado += producto;
    }

    return resultado;
}

// Función para calcular la interpolación de Neville
double Neville(double x, double x_values[], double y_values[], int n) {
    // Creamos una matriz para almacenar los valores intermedios
    double **Q = (double **)malloc((n+1) * sizeof(double *));
    for (int i = 0; i <= n; i++) {
        Q[i] = (double *)malloc((n+1) * sizeof(double));
    }

    // Inicializamos la primera columna de Q con los y_values
    for (int i = 0; i <= n; i++) {
        Q[i][0] = y_values[i];
    }

    // Aplicamos la formula recursiva de Neville
    for (int j = 1; j <= n; j++) {
        for (int i = j; i <= n; i++) {
            Q[i][j] = ((x - x_values[i-j]) * Q[i][j-1] - (x - x_values[i]) * Q[i-1][j-1]) / (x_values[i] - x_values[i-j]);
        }
    }

    // El valor interpolado está en la esquina superior derecha de la matriz Q
    double result = Q[n][n];

    // Liberamos la memoria reservada para Q
    for (int i = 0; i <= n; i++) {
        free(Q[i]);
    }
    free(Q);

    return result;
}


// Función para calcular la tabla de diferencias divididas
void calculaDiferenciasDivididas(int n, double x[], double f[], double **F) {
    // Los valores de la primera columna de F son simplemente los valores de f
    for (int i = 0; i < n; i++) {
        F[i][0] = f[i];
    }

    // Rellenamos la tabla de diferencias divididas
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            F[i][j] = (F[i+1][j-1] - F[i][j-1]) / (x[i+j] - x[i]);
        }
    }
}

// Función para realizar la interpolación de Newton
double interpolacionNewton(int n, double x[], double **F, double valorX) {
    double resultado = F[0][0];
    double terminoPolinomio = 1.0;

    for (int j = 1; j < n; j++) {
        terminoPolinomio *= (valorX - x[j-1]);
        resultado += (terminoPolinomio * F[0][j]);
    }

    return resultado;
}