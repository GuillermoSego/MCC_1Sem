
#include <stdio.h>
#include <stdlib.h>

// Rutina para leer una matriz con un header
int ReadMatrix(const char *filename, double **A, int *rows, int *cols) {

    FILE *file;
    int i, j;

    // Abrimos el archivo en modo lectura
    file = fopen(filename, "r");

    // Comprobamos si el archivo se abrió con éxito
    if (file == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // Leemos el número de filas y columnas
    fscanf(file, "%d %d", rows, cols);

    // Asignamos memoria para la matriz A
    *A = malloc((*rows) * (*cols) * sizeof(double));
    if (*A == NULL) {
        printf("Fallo en la asignación de memoria\n");
        return 2;
    }

    // Leemos el archivo y asignar los valores a la matriz A
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *cols; j++) {
            fscanf(file, "%lf", &(*A)[i * (*cols) + j]); 
        }
    }

    // Cerramos el archivo
    fclose(file);

    return 0;
}

// Función para realizar la factorización LU usando el método de Crout
int crout(double A[], double L[], double U[], int n) {
    // Inicializamos la diagonal de U a 1
    for (int j = 0; j < n; j++) {
        U[j * n + j] = 1;
    }

    // Iteramos a través de cada columna j
    for (int j = 0; j < n; j++) {
        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[i * n + k] * U[k * n + j];
            }
            L[i * n + j] = A[i * n + j] - sum;
        }

        for (int i = j; i < n; i++) {
            double sum = 0;
            for (int k = 0; k < j; k++) {
                sum += L[j * n + k] * U[k * n + i];
            }
            if (L[j * n + j] == 0) {
                return -1;  // Devolvemos -1 si hay un error
            }
            U[j * n + i] = (A[j * n + i] - sum) / L[j * n + j];
        }
    }
    return 0;  // Todo bien
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

int main(int argc, char *argv[]) {

    // Manejo de argumentos de la linea de comandos
    if(argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    // No tenemos certeza del tamaño de la matriz
    // Declaramos un apuntador hacia un bloque de memoria especifico de la matriz A
    double *A;
    int rows, cols;
    
    // Leemos la matriz en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename ,&A, &rows, &cols) == 1) {
        free(A); // Liberamos memoria
        return 0;
    } 

    // Declaramos las matrices L y U para almacenar los resultados
    double *L = (double *) malloc(rows * cols * sizeof(double));
    double *U = (double *) malloc(rows * cols * sizeof(double));
    // Las incializamos en 0
    for (int i = 0; i < rows * cols; i++) {
        L[i] = 0;
        U[i] = 0;
    }

    int n = rows;

    // Aplicamos la factorización LU
    // Manejo de estado devuelto por crout
    if (crout(A, L, U, n) == -1) {
        printf("Error durante la factorización\n");
        free(A);
        free(L);
        free(U);
        return -1;
    }

    // Imprimimos la matriz L
    printf("Matriz L:\n");
    MatrixShow(n,n, L);

    // Imprimimos la matriz U
    printf("\nMatriz U:\n");
    MatrixShow(n,n, U);

    free(A);
    free(L);
    free(U);

    return 0;
}
