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

/*
Declaración de las matrices que constructoras de Phi
*/

// Construcción matriz Phi para ajuste polinomial
void MatrixBuild(double* Phi, int rows, int cols, double* x, int n) {
  // Para cada observación
  for (int i = 0; i < rows; i++) { 
      // Término constante, x^0
      Phi[i * cols] = 1.0;
      // Para cada término del polinomio
      for (int j = 1; j < cols; j++) { 
          // x^j para la observación i
          Phi[i * cols + j] = pow(x[i], j); 
      }
  }
}

// // Construcción matriz Phi para ajuste trigonométrico
#include <math.h>
void MatrixBuildTrig(double* Phi, int rows, int cols, double* x) {
    const double pi_over_6 = M_PI / 6.0;
    int i, j;
  
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            Phi[i * cols + j] = cos(j * pi_over_6 * x[i]);
        }
    }
}


// Construcción matriz Phi para ajuste con función de base radial
void MatrixBuildRBF(double* Phi, int rows, int cols, double* x) {
    // Para cada observación
    for (int i = 0; i < rows; i++) {
        // Para cada función base
        for (int j = 0; j < cols; j++) {
            // r = (x - x_j)
            double r = x[i] - x[j];
            // Phi_ij = exp(-r^2)
            Phi[i * cols + j] = exp(-r * r);
        }
    }
}


// Función que construye el sistema Aw = b. 
// El valor option determina que tipo de función se utiliza.
// 1. Polinomial
// 2. Trigonométrico
// 3. Radial
void buildSystem(int m, int n, double *x, double *y, double*A, double *b, double lambda, int option){

  // Asignamos memoria para la matriz Phi de n*m elementos
  double* Phi = malloc(n * m * sizeof(double)); 
  if (Phi == NULL) {
      fprintf(stderr, "Error al asignar memoria.\n");
      exit(1);
  }

  // Opción de ajuste
  switch (option)
  {
  case 1:
    MatrixBuild(Phi, n, m, x, n);
    break;
  case 2:
    MatrixBuildTrig(Phi, n, m, x);
    break;
  case 3:
    MatrixBuildRBF(Phi, n, m, x);
    break;
  default:
    printf("Error. Ajuste no reconocido");
    exit(1);
  }


  // MatrixShow(n, m, Phi);

  // Asignamos memoria para la matriz transpuesta PhiT de m*n elementos
  double* PhiT = malloc(n * m * sizeof(double)); 
  if (PhiT == NULL) {
      fprintf(stderr, "Error al asignar memoria para PhiT.\n");
      free(Phi);
      exit(1);
  }
  MatrixT(n, m, Phi, PhiT);

  // MatrixShow(m, n, PhiT);
  
  // lambda
  // double lambda = 0.0;

  // Construimos la matriz Alpha (de tamaño m*m)
  double* Alpha = calloc(m * m, sizeof(double));
  if (Alpha == NULL) {
      fprintf(stderr, "Error al asignar memoria para Alpha.\n");
      free(Phi);
      free(PhiT);
      exit(1);
  }
  for (int i = 0; i < m; i++) {
      Alpha[i * m + i] = lambda; // Asignamos lambda a los elementos diagonales
  }

  // Asignamos memoria para las matrices del sistema
  // double* A = malloc(m * m * sizeof(double)); // A = Phi^T * Phi + Alpha
  double* PhiProd = malloc(m * m * sizeof(double)); // PhiProd = Phi^T * Phi

  MatrixProduct(PhiT, Phi, PhiProd, m, n, m);
  MatrixSum(PhiProd, Alpha, A, m, m);


  // Construcción de b = Phi^T * y
  // double* b = malloc(m * sizeof(double));
  if (b == NULL) {
      fprintf(stderr, "Error al asignar memoria para b.\n");
      free(Phi);
      free(PhiT);
      free(Alpha);
      free(A);
      free(PhiProd);
      exit(1);
  }
  MatrixProduct(PhiT, y, b, m, n, 1);
  
  // MatrixShow(m,1, b);

  // Liberar memoria de la función
  free(Phi);
  free(PhiT);
  free(Alpha);
  free(PhiProd);

}


double sutherland(double T, double m0, double T0, double Su) {
  return m0 * pow((1000 * T / T0), 1.5) * ((T0 + Su) / (1000 * T + Su));
}

double EvaluatePol(double *coefficients, int degree, double x) {
  double sum = 0.0;

  for (int i = 0; i <= degree; i++) {
      sum += coefficients[i] * pow(x, i);
  }

  return sum;
}

double EvaluateTrig(double *coefficients, int n, double x) {
  double sum = coefficients[0] * cos(0.0); 

  for (int i = 1; i <= n; i++) {
      sum += coefficients[i] * cos(i * M_PI * x / 6.0);
  }

  return sum;
}

double EvaluateRBF(double *coefficients, double *centers, int n, double x) {
  double sum = 0.0;
  double r;

  for (int i = 0; i <= n; i++) {
      r = x - centers[i]; // r es la distancia entre x y el centro xi
      sum += coefficients[i] * exp(-r * r);
  }

  return sum;
}
