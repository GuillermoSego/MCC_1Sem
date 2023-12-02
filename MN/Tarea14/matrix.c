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

// Esta rutina calcula la matriz transpuesta de un vector y la guarda en otro
void MatrixT(int n, int m, double v[], double Vec[] )
{
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      Vec[j * n + i] = v[i * m + j];
    }
  }
}

// Esta rutina calcula el producto punto entre dos vectores
double DotProd(double x[], double y[], int n)
{
    
    double* xPtr = x;
    double* yPtr = y;
    
    double sum = 0;
    int i=0;
    
    do {
        sum += *( xPtr++ ) * *(yPtr ++ );
        i ++;
    } while (i<n);
    
    return sum;
}

// Esta rutina hace el producto entre dos matrices
void MatrixProduct(double m1[], double m2[], double Matrix[], int M, int N, int O)
{

  // Apuntadores a las matrices
  double* m1Ptr = m1;
  double* m2Ptr = m2;
    
  // Arreglo new, va guardar los elementos de la columna de la segunda matriz
  double new[N];
  double* nPtr = new;
    
  int i = 0, j = 0, k = 0;
    
  // Declaramos la matriz producto
  double* MPtr = Matrix;
    
  /*
    
  Para hacer la multiplicacion de matrices necesitamos tres ciclos, en el 
  primero, recorremos los elementos de la matriz 1. En el segundo recorremos
  las filas de la matriz 2. Y en el tercero las columnas. Vamos guardando las
  columnas de la matriz 2 en un arreglo llamado new y hacemos el producto 
  punto con los elementos de la fila de la matriz 1.
    
  */
    
  do {
        
      do {
            
          // Apuntamos en la direccion correcta
          nPtr = new;
          m2Ptr = m2;
          j = 0;
           
          do {
               
              // Guardamos la columna en el arreglo new
              *nPtr = *(m2Ptr + i + j*O);
              nPtr ++;
               
              j ++;
               
          } while (j<N);
            
          // Apuntamos en la direccion correcta
          nPtr = new;
            
          /*
            
          Hacemos el producto punto entre la fila de la matriz 1 y la columna 
          de la matriz 2
            
          */
          *MPtr = DotProd(m1Ptr, nPtr, N);
          MPtr ++;
            
          i ++;
            
      } while(i<O);
    
      i = 0;
      k ++;
        
      // Sumamos para estar en la siguiente fila
      m1Ptr = m1Ptr + N;
    
  } while(k<M);

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

// Este programa calcula el valor maxino de un arreglo
double maximus(double v[], int s)
{
    
    // Apuntamos
    double* vPtr = v;
    
    // Donde guardamos el minimo
    double m;
    
    int i = 0;
    
    // Guardamos el primer valor del arreglo en m
    m = *vPtr;
    
    do {
        
        // Comparamos
        if (*vPtr >= m) {
            
            m = *vPtr;
            
        }
        
        vPtr ++;
        i ++;
        
    } while(i< s);
    
    return m;
    
}

// Esta rutina inicializa a cero un arreglo
void Initialize(double in[], int n)
{

  double* inPtr = in;
  int i = 0;

  do {

    *inPtr = 0;
    inPtr ++;

    i ++;

  } while(i<n);

}

// Esta rutina calcula la suma de dos matrices m x n
void MatrixSum(double* m1, double* m2, double* mout, int m, int n) {

    for (int i = 0; i < m; ++i) {

        for (int j = 0; j < n; ++j) {

            mout[i * n + j] = m1[i * n + j] + m2[i * n + j];

        }
    }
}


// Este programa suma todos los elementos de un vector, y los pone en otro vec
void Sum(double in[], double out[], int n)
{

  Initialize(out, n);

  double sum = 0;
  // Apuntamos
  double* inPtr = in;
  double* outPtr = out;
  int i = 0, j = 0;

  do{

    do {

      sum += *inPtr;
      inPtr ++;

      i ++;

    } while(i<n);

    *outPtr += sum; 
    outPtr ++;
    sum = 0;
    i = 0;
    j ++;

  } while(j<n);

}

// Este programa divide un arreglo por un escalar
void Divide(double matrix[], double scalar, double out[], int s)
{

  double* mPtr = matrix;
  double* outPtr = out;
  int i = 0;

  do {

    *outPtr = *mPtr/scalar;
    outPtr ++;
    mPtr ++;

    i ++;

  } while( i < s );

}

// Esta rutina inicializa un arreglo de unos
void Ones(double t[], int n)
{

  double* tPtr = t;

  int i = 0;

  do {

    *tPtr = 1;
    tPtr ++;

    i++;

  } while(i<n);


}

// Rutina para restar v2 de v1 (v1 = v1 - v2)
void SubtractVector(double *v1, double *v2, int n) {
    for (int i = 0; i < n; i++) {
        v1[i] -= v2[i];
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

// Función para inicializar matrices
double** createMatrix(int n, int m) {
    double **Matrix = (double **)malloc(n * sizeof(double *));
    if (Matrix == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        Matrix[i] = (double *)malloc(m * sizeof(double));
        if (Matrix[i] == NULL) {
            fprintf(stderr, "Error al asignar memoria en la fila %d\n", i);
            // Limpieza parcial en caso de error
            for (int j = 0; j < i; j++) {
                free(Matrix[j]);
            }
            free(Matrix);
            exit(1);
        }
    }

    return Matrix;
}

// Función para liberar la memoria de una matriz
void freeMatrix(double **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Libera cada fila de la matriz
    }
    free(matrix); // Libera el puntero a los punteros de las filas
}


double *FlattenMatrix(double **matrix, int rows, int cols) {
    double *flat = (double *)malloc(rows * cols * sizeof(double));
    if (flat == NULL) {
        // Manejo de error en caso de que malloc falle
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            flat[i * cols + j] = matrix[i][j];
        }
    }
    return flat;
}

// Funcion para realizar un arreglo con cierta separacion
void linspace(double x[], double init, double end, int n) {
    double delta = (end - init) / (n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = init + delta * i;
    }
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

void solveLowerTriangular(double L[], double b[], double y[], int n) {
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i * n + j] * y[j];
        }
        y[i] /= L[i * n + i];
    }
}

void solveUpperTriangular(double U[], double y[], double x[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i * n + j] * x[j];
        }
        x[i] /= U[i * n + i];
    }
}



// Rutina para definir una matriz tridiagonal
void tridiagonalMatrix(double **matrix, int size, double lower, double main, double upper) {
    // Asegurarse de que la matriz ya ha sido inicializada
    if (matrix == NULL) {
        printf("Error: Matriz no inicializada.\n");
        return;
    }

    // Configurar los elementos de la matriz tridiagonal
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                matrix[i][j] = main; // Elemento diagonal principal
            } else if (j == i - 1) {
                matrix[i][j] = lower; // Diagonal inferior
            } else if (j == i + 1) {
                matrix[i][j] = upper; // Diagonal superior
            } else {
                matrix[i][j] = 0.0; // Resto de la matriz
            }
        }
    }
}
