/*

Biblioteca para manejo de matrices

*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>


// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double *v)
{
    
     
    int i, j, k=0;
    
    for(i=0 ; i<m ; i++){
        
        for (j=0 ; j<n ; j ++){
            
            printf("%lf \t", v[k]);
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

// Esta rutina implementa el Método de Jacobi para resolver sistemas lineales de ecuaciones Ax = b.
double* jacobiMethod(double *A, double *b, int n, int maxIter, double tol) {
    double *x = (double*) malloc(n * sizeof(double));  // Vector de solución
    double *oldX = (double*) malloc(n * sizeof(double));  // Vector para almacenar la solución de la iteración anterior
    int iter = 0;    // Contador de iteraciones

    // Inicializar el vector de soluciones x con ceros
    for(int i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    while(iter < maxIter) {
        // Copiar el vector x a oldX
        for(int i = 0; i < n; i++) {
            oldX[i] = x[i];
        }

        // Actualizar cada valor de x según la formula de Jacobi
        for(int i = 0; i < n; i++) {
            double sigma = 0.0;
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    sigma += A[i * n + j] * oldX[j];
                }
            }
            x[i] = (b[i] - sigma) / A[i * n + i];
        }

        // Calcular la norma de la diferencia entre x y oldX
        double diffNorm = 0.0;
        for(int i = 0; i < n; i++) {
            diffNorm += pow(x[i] - oldX[i], 2);
        }
        diffNorm = sqrt(diffNorm);

        // Chequear la convergencia
        if(diffNorm < tol) {
            break;
        }
        
        iter++;
    }

    // Liberar memoria de oldX ya que x será retornado
    free(oldX);

    // Si se alcanzan las iteraciones máximas, mostrar un mensaje
    if(iter == maxIter) {
        printf("Jacobi method did not converge within %d iterations\n", maxIter);
    }
    
    return x;
}

// Esta rutina implementa el Método de Gauss-Seidel para resolver sistemas lineales de ecuaciones Ax = b.
double* gaussSeidelMethod(double *A, double *b, int n, int maxIter, double tol) {
    int i, j, iter = 0;
    double sigma, diff, diffNorm;

    double *x = (double*) malloc(n * sizeof(double));  // Vector de solución

    // Inicializar el vector de soluciones x con ceros
    for(i = 0; i < n; i++) {
        x[i] = 0.0;
    }

    while(iter < maxIter) {
        diffNorm = 0.0; // Se usa para chequear la convergencia

        // Actualizar cada valor de x según la fórmula de Gauss-Seidel
        for(i = 0; i < n; i++) {
            sigma = 0.0;

            for(j = 0; j < n; j++) {
                if(i != j) {
                    sigma += A[i * n + j] * x[j];
                }
            }

            diff = (b[i] - sigma) / A[i * n + i] - x[i]; // Diferencia entre nuevo y antiguo valor de x[i]
            x[i] += diff; // Actualizar x[i]
            
            diffNorm += pow(diff, 2); // Agregar al cuadrado de la norma de la diferencia
        }

        diffNorm = sqrt(diffNorm); // Finalizar cálculo de la norma de la diferencia

        // Chequear la convergencia
        if(diffNorm < tol) {
            break;
        }
        
        iter++;
    }

    // Si se alcanzan las iteraciones máximas, mostrar un mensaje
    if(iter == maxIter) {
        printf("Gauss-Seidel method did not converge within %d iterations\n", maxIter);
    }

    return x;
}
