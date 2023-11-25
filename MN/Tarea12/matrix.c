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


// Función para cambiar el signo de los elementos de un vector
void NegateVector(double *vec, int length) {
    for (int i = 0; i < length; i++) {
        vec[i] = -vec[i];
    }
}

// Función para calcular la norma Euclidiana de un vector
double Norm(double *vec, int length) {
    double sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += vec[i] * vec[i];
    }
    return sqrt(sum);
}

/*

Gauss-Jordan

*/

// Función para intercambiar dos filas en una matriz
void intercambiaFilas(double **A, double *b, int fila1, int fila2, int n) {
    for (int j = 0; j < n; j++) {
        double temp = A[fila1][j];
        A[fila1][j] = A[fila2][j];
        A[fila2][j] = temp;
    }
    double temp = b[fila1];
    b[fila1] = b[fila2];
    b[fila2] = temp;
}

// Función para encontrar el valor máximo y la fila correspondiente en una columna de una matriz
int encuentraMax(double **A, int columna, int n) {
    double maxValor = fabs(A[columna][columna]);
    int filaMax = columna;
    for (int i = columna + 1; i < n; i++) {
        if (fabs(A[i][columna]) > maxValor) {
            maxValor = fabs(A[i][columna]);
            filaMax = i;
        }
    }
    return filaMax;
}

// Función para realizar la eliminación gaussiana con pivoteo parcial
// Función especial para calcular inversa
void eliminacionGaussianaPivoteo(int n, double **A) {
    for (int k = 0; k < n - 1; k++) {
        int filaMax = encuentraMax(A, k, n);
        if (filaMax != k) {
            intercambiaFilas(A, NULL ,filaMax, k, 2 * n);
        }
        for (int i = k + 1; i < n; i++) {
            double lik = A[i][k] / A[k][k];
            for (int j = k; j < 2 * n; j++) {  // Modificado aquí
                A[i][j] -= lik * A[k][j];
            }
        }
    }
}


// Función para hacer unos la diagonal principal
// Función especial para calcular inversa
void OnesDiagonal(int n, double **A) {
    for (int i = 0; i < n; i++) {
        double diag = A[i][i];
        for (int j = 0; j < 2 * n; j++) {
            A[i][j] /= diag;
        }
    }
}


// Función especial para calcular inversa
void eliminacionHaciaArriba(int n, double **A) {
    for (int k = n - 1; k >= 0; k--) {
        for (int i = k - 1; i >= 0; i--) {
            double factor = A[i][k] / A[k][k];
            for (int j = 2 * n - 1; j >= k; j--) {  // Modificado aquí
                A[i][j] -= factor * A[k][j];
            }
        }
    }
}


void gaussJordan(int n, double **A) {
    eliminacionGaussianaPivoteo(n, A); // Primero, eliminación gaussiana con pivoteo
    OnesDiagonal(n, A);           // Luego, hacemos unos en la diagonal
    eliminacionHaciaArriba(n, A);      // Finalmente, eliminamos hacia arriba
}

// Calcula la inversa con la rutina de Gauss Jordan
void gaussJordanInversa(int n, double **A, double **A_inv) {
    // Crear una matriz aumentada [A|I]
    double **matrizAumentada = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        matrizAumentada[i] = (double *)malloc(2 * n * sizeof(double));
        for (int j = 0; j < 2 * n; j++) {
            if (j < n) matrizAumentada[i][j] = A[i][j]; // Parte A
            else matrizAumentada[i][j] = (j - n == i) ? 1.0 : 0.0; // Parte I
        }
    }

    // Aplicar Gauss-Jordan en la matriz aumentada
    gaussJordan(n, matrizAumentada);


    // Extraer la matriz inversa de la parte derecha de la matriz aumentada
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A_inv[i][j] = matrizAumentada[i][j + n];
        }
    }


    // Liberar memoria de la matriz aumentada
    for (int i = 0; i < n; i++) {
        free(matrizAumentada[i]);
    }
    free(matrizAumentada);
}
