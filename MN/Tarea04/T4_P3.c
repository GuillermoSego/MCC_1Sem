
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

// Función para realizar la factorización de Cholesky (A = L * L^T)
int cholesky(double A[], double L[], int n) {
    // Iteramos a través de cada fila y columna para llenar L
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;

            // Si estamos en la misma fila y columna (diagonal)
            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += L[j * n + k] * L[j * n + k];
                }

                // La raíz cuadrada podría fallar si la matriz no es definida positiva
                double diagonalElement = A[i * n + i] - sum;
                if (diagonalElement <= 0) {
                    return -1; // Devolvemos -1 si hay un error (matriz no es definida positiva)
                }
                L[i * n + j] = sqrt(diagonalElement);
            } else {
                // Si estamos en diferentes filas y columnas
                for (int k = 0; k < j; k++) {
                    sum += (L[i * n + k] * L[j * n + k]);
                }
                L[i * n + j] = (A[i * n + j] - sum) / L[j * n + j];
            }
        }
    }
    return 0; // Todo bien
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

// Función para resolver un sistema Ax = b dado L en la descomposición Cholesky A = LL^T
void solveCholesky(double L[], double b[], double x[], int n) {
    // Resolvemos Ly = b para y
    double y[n];
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i * n + j] * y[j];
        }
        y[i] = (b[i] - sum) / L[i * n + i];
    }

    // Resolvemos L^Tx = y para x
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += L[j * n + i] * x[j]; // Notar que estamos accediendo a L^T
        }
        x[i] = (y[i] - sum) / L[i * n + i];
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
    // Las incializamos en 0
    for (int i = 0; i < rows * cols; i++) {
        L[i] = 0;
    }

    int n = rows;

    // Aplicamos la factorización LU
    // Manejo de estado devuelto por crout
    if (cholesky(A, L, n) == -1) {
        printf("Error durante la factorización\n");
        free(A);
        free(L);
        return -1;
    }

    // Imprimimos la matriz L
    printf("Matriz L:\n");
    MatrixShow(n,n, L);

    const char* fileb = {"b.txt"};

    double *B;
    int r, c;
    
    // Leemos la matriz en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(fileb ,&B, &r, &c) == 1) {
        free(B); // Liberamos memoria
        return 0;
    } 

    double x[n];  // Vector para almacenar la solución

    solveCholesky(L, B, x, n);

    // Imprimimos la matriz solucion
    printf("Matriz x:\n");
    MatrixShow(n,1, x);

    free(A);
    free(L);
    free(B);

    return 0;
}