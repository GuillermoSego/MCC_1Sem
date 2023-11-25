# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Esta rutina formula el sistema de ecuaciones a partir de los parámetros del problema
void formulate_system(double Q, double K, double Phi_0, double Phi_n, int n, double L, double *A, double *B) {
    double Delta_x = L / n;

    // Inicializar matriz A y vector B
    for (int i = 0; i < n - 1; i++) {
        // Elementos diagonales
        A[i * (n - 1) + i] = 2.0;

        // Elementos fuera de la diagonal
        if (i > 0) {
            A[i * (n - 1) + i - 1] = -1.0;
        }
        if (i < n - 2) {
            A[i * (n - 1) + i + 1] = -1.0;
        }

        // Llenar el vector B
        B[i] = -Q * Delta_x * Delta_x / K;
    }

    // Ajustar el vector B para las condiciones de frontera
    B[0] += Phi_0;
    B[n - 2] += Phi_n;
}

// Esta rutina realiza la factorización LDL^T
int cholesky_ldlt(double *A, double *L, double *D, int n) {
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int k = 0; k < j; k++) {
            sum += L[j * n + k] * L[j * n + k] * D[k];
        }

        D[j] = A[j * n + j] - sum;  // Elemento diagonal de D

        if (D[j] <= 0) {
            return -1;  // La matriz no es definida positiva
        }

        L[j * n + j] = 1;  // La diagonal de L es 1

        for (int i = j + 1; i < n; i++) {
            sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i * n + k] * L[j * n + k] * D[k];
            }
            L[i * n + j] = (A[i * n + j] - sum) / D[j];
        }
    }
    return 0;
}

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double v[])
{
    int i, j, k=0;
    for(i=0 ; i<m ; i++){
        for (j=0 ; j<n ; j ++){
            printf("%lf ", v[k]);
            k ++;
        }
        printf("\n");
    }
}

// Función para resolver un sistema Ax = b dado L y D en la descomposición Cholesky A = LDL^T
void solveCholesky(double L[], double D[], double b[], double x[], int n) {
    // Resolvemos Ly = b para y
    double y[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i * n + j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i * n + i];
    }

    // Resolvemos Dz = y para z
    double z[n];
    for (int i = 0; i < n; i++) {
        z[i] = y[i] / D[i];
    }

    // Resolvemos L^Tx = z para x
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += L[j * n + i] * x[j]; 
        }
        x[i] = (z[i] - sum) / L[i * n + i];
    }
}

int main() {

    // Parámetros del problema
    double Q = 1000, K = 1, Phi_0 = 0, Phi_n = 100;
    int n = 4;
    double L = 10;

    // Crear espacio para la matriz A y el vector B
    double *A = malloc((n - 1) * (n - 1) * sizeof(double));
    double *B = malloc((n - 1) * sizeof(double));

    // Formular el sistema
    formulate_system(Q, K, Phi_0, Phi_n, n, L, A, B);

    // Crear espacio para la matriz L
    double *L_mat = malloc((n - 1) * (n - 1) * sizeof(double));
    double *D = calloc((n - 1), sizeof(double)); // Almacen de resultados

    // Aplicamos Cholesky
    if (cholesky_ldlt(A, L_mat, D, n-1) == -1) {
        printf("La matriz no es definida positiva.\n");
        return -1;
    }

    // Imprimir matriz A y vector B
    printf("Matriz A:\n");
    MatrixShow(n-1, n-1, A);

    printf("Matriz L:\n");
    MatrixShow(n-1, n-1, L_mat);

    printf("Vector D:\n");
    MatrixShow(n-1, 1, D);


    // Reservamos memoria para la solución
    double x[n-1]; 

    // Resolvemos la matriz
    solveCholesky(L_mat, D, B, x, n-1);

    // Imprimimos la matriz solucion
    printf("Vector x:\n");
    MatrixShow(n-1, 1, x);

    // Guardamos los resultados en un archivo
    FILE *file = fopen("n4.txt", "w"); // Abrimos el archivo para escritura


    // Escribir los resultados en el archivo
    for (int i = 0; i < n-1; i++) {
        fprintf(file, "%lf\n", x[i]);
    }

    // Cerrar archivo
    fclose(file);

    // Liberar memoria
    free(A);
    free(B);
    free(L_mat);
    free(D);

    return 0;
}
