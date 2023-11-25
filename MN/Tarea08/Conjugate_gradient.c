
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"

void Conjugate_gradient(double *A, double *B, double *x, int rows, int cols){
    double error_threshold = 0.0001;
    double alpha, beta, r_dot, r_next_dot;

    double *r = (double *)malloc(rows * sizeof(double));
    double *r_next = (double *)malloc(rows * sizeof(double));
    double *p = (double *)malloc(rows * sizeof(double));
    double *Ap = (double *)malloc(rows * sizeof(double));

    // r_0 = B - A*x_0
    double *Ax = (double *)malloc(rows * sizeof(double));
    MatrixProduct(A, x, Ax, rows, cols, 1);
    for(int i = 0; i < rows; i++) {
        r[i] = B[i] - Ax[i];
    }

    for(int i = 0; i < rows; i++){
        p[i] = r[i];  // p_0 = r_0
    }

    int max_iterations = rows; 
    for(int k = 0; k < max_iterations; k++){

        MatrixProduct(A, p, Ap, rows, cols, 1);

        r_dot = DotProd(r, r, rows);
        alpha = r_dot / DotProd(p, Ap, rows);

        for(int i = 0; i < rows; i++){
            x[i] += alpha * p[i];
            r_next[i] = r[i] - alpha * Ap[i];
        }

        r_next_dot = DotProd(r_next, r_next, rows);
        if(sqrt(r_next_dot) < error_threshold){
            break;
        }

        beta = r_next_dot / r_dot;
        for(int i = 0; i < rows; i++){
            p[i] = r_next[i] + beta * p[i];
            r[i] = r_next[i];
        }
    }

    free(r);
    free(r_next);
    free(p);
    free(Ap);
    free(Ax);
}


int main(int argc, char *argv[]){

    // Manejo de argumentos de la línea de comandos
    if(argc != 3) {
        printf("Uso: %s <nombre_archivo_matriz>\n", argv[0]);
        return 1;
    }

    const char* filename1 = argv[1];
    const char* filename2 = argv[2];

    // Declaramos un apuntador hacia un bloque de memoria específico de la matriz A y B
    double *A, *B;
    int rows, cols, r, c;

    // Leemos la matriz A en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename1 ,&A, &rows, &cols) == 1) {
        free(A); // Liberamos memoria
        return 0;
    }

    // Leemos la matriz B en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename2 ,&B, &r, &c) == 1) {
        free(B); // Liberamos memoria
        return 0;
    }

    // Declaramos la memoria para la solución
    double *X = malloc( rows * sizeof(double) );
    Initialize(X, rows);

    // Calculamos el gradiente conjugado
    Conjugate_gradient( A, B, X, rows, cols );

    // Mostramos la matriz
    printf("La solución del sistema X:\n");
    MatrixShow(rows, 1, X);


    return 0;
}