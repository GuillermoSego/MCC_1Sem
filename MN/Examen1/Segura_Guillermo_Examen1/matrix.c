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

  double* VecPtr = Vec;
  double* vPtr = v;

  int i = 0, j = 0;
 
  do {

    do {
        
       *VecPtr = *vPtr;

        VecPtr ++; 

        vPtr += m;

      j ++;
    } while (j<n);   

    vPtr = v + (i+1);

    j = 0;
    i ++;
  } while (i<m);


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

// Esta rutina calcula la suma de dos matrices cuadradas
void MatrixSum(double m1[], double m2[], double mout[], int n)
{

  double* m1Ptr = m1;
  double* m2Ptr = m2;
  double* outPtr = mout;

  int i = 0;

  do {

    *outPtr = *m1Ptr - *m2Ptr;
    m2Ptr ++;
    m1Ptr ++;
    outPtr ++;

    i ++;

  } while( i < (n*n) );

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

// Rutina que implementa el metodo del gradiente
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
            printf("El método convergió con %d iteraciones\n", k);
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

// Rutina que indica si un vector X es solución de un sistema Ax = b
int isSolution(double *A, double *X, double *b, int size, double tolerance) {
    double *AX = malloc(size * sizeof(double));

    // Calcular AX
    MatrixProduct(A, X, AX, size, size, 1);

    // Comparar AX con b
    for (int i = 0; i < size; i++) {
        if (fabs(AX[i] - b[i]) > tolerance) {
            free(AX);
            return 1;  // Si alguna componente difiere de la tolerancia, X no es solución
        }
    }

    free(AX);
    return 0;  // Si todas las componentes son cercanas, X es solución
}

double ConditionCheck(double ta[], double td[], int n)
{

    // Definiimos el error
    double error = 1*exp(-5);
    
    // Apuntamos
    double* taPtr = ta;
    double* tdPtr = td;

    int count = 0, r = 0, i = 0;

    do {

        // El posible resultado de r es 0 o 1. Si se cumple (1) si no (0)
        r = fabs(*tdPtr ++ - *taPtr ++) <= error;
        count += r;

        i++;

    } while(i<n && r != 0 );

    // Regresamos un valor binario, 1 si son iguales 0 si no
    return count == n;


}

// Incializar la matriz como se indicó en el problema
void Matrix_Initialize(double A[], double B[], int size){
    

    // Inicializar la matriz a cero
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            A[i*size + j] = 0;
        }
    }

    // Llenar la matriz con los valores de la ecuación
    for(int i = 0; i < size; i++) {
        // Diagonal principal
        A[i*size + i] = 40;

        // Diagonal -1 y +1 (respecto a la principal)
        if (i-1 >= 0) {
            A[i*size + i-1] = -8;
        }
        if (i+1 < size) {
            A[i*size + i+1] = -8;
        }

        // Diagonal -2 y +2 (respecto a la principal)
        if (i-2 >= 0) {
            A[i*size + i-2] = -4;
        }
        if (i+2 < size) {
            A[i*size + i+2] = -4;
        }
    }

    // Inicializar el vector B
    for (int i = 0; i < size; i++){
        if (i == 0) { 
            B[i] = 20;
        } else if (i == (size-1)) { 
            B[i] = 20; 
        } else{
            B[i] = 50;
        }
        
    }

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

// Esta rutina calcula el metodo de potencias.
void PowerMethod(double M[], double U[], double l[], int ST)
{

    // Inicializamos las matrices
    // Asignamos memoria en el heap para nuestras matrices
    double* St = (double*) malloc(ST * sizeof(double));
    double* t = (double*) malloc(ST * sizeof(double));
    double* nt = (double*) malloc(ST * sizeof(double));
    double* v = (double*) malloc(ST * sizeof(double));
    double* vprime = (double*) malloc(ST * sizeof(double));
    double* vvp = (double*) malloc(ST * ST * sizeof(double));
    double* Snew = (double*) malloc(ST * ST * sizeof(double));

    // Apuntamos
    double* lPtr = l;
    double* UPtr = U;

    // Declaramos un nuevo vector en el que guardaremos la nueva S
    Divide(M, 1, Snew, ST*ST);


    int i = 0, j = 0, k; 

    do {

        // Calculamos St = sum(S)
        Sum(Snew,St, ST);
        // Incializamos la matriz de unos
        Ones(t, ST);

        do {
          
          // nt = St/max(St)
          Divide(St, maximus(St, ST), nt, ST);

          // Condicion de paro
          k = ConditionCheck(t, nt, ST);
          if (k == 1) {
            break;

          }

          // t = nt
          MatrixT(ST, 1, nt, t);
          // St = S*t
          MatrixProduct(Snew, t, St, ST, ST, 1);
          j ++;

        } while(j<1000);

        // Calculamos las U(:,i) = t/norm(t)
        Divide(t, sqrt(DotProd(t, t, ST)), UPtr, ST);

        // Calculamos las v(:,i) = sqrt(max(St)) * U(:,i)
        Divide(UPtr, 1/sqrt(maximus(St, ST)), v, ST);

        // Calculamos las l(i) = max(St)
        *lPtr = maximus(St, ST);

        // Redefinimos la matriz S = S - v(:,i)*v(:,i)'
        MatrixT( ST, 1, v, vprime );
        MatrixProduct( v, vprime, vvp, ST, 1, ST );
        // Copiamos la version de la matriz Snew en Scov
        // Divide(Snew, 1, M, ST*ST);
        MatrixSum(Snew, vvp, Snew, ST);

        UPtr += ST;
        lPtr ++;

        j = 0;
        i++;

    } while(i<ST);

    // Libera la memoria
    free(St);
    free(t);
    free(nt);
    free(v);
    free(vprime);
    free(vvp);
    free(Snew);

}
