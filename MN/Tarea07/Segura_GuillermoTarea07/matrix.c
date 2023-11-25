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

double ConditionCheck(double ta[], double td[], int n)
{

    // Definiimos el error
    double error = 1*exp(-10);
    
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

// Esta rutina calcula el metodo de potencias.
void PowerMethod(double M[], double U[], double l[], int ST)
{

    // Inicializamos las matrices
    double St[ST];
    double t[ST];
    double nt[ST];

    double* UPtr = U;

    double v[ST];
    double vprime[ST];
    double vvp[ST*ST];

    double* lPtr = l;
    
    // Declaramos un nuevo vector en el que guardaremos la nueva S
    double Snew[ST*ST];
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


}

// Función para realizar la eliminación gaussiana y transformar A en una matriz U
void eliminacionGaussiana(int n, double *A, double *b) {
    for (int k = 0; k < n - 1; k++) {
        for (int i = k + 1; i < n; i++) {
            double lik = A[i*n + k] / A[k*n + k];

            for (int j = k + 1; j < n; j++) {
                A[i*n + j] -= lik * A[k*n + j];
            }

            b[i] -= lik * b[k];
        }
    }
}

// Función para resolver un sistema Ux = b donde U es una matriz triangular superior
void resuelveSistema(int n, double *U, double *b, double *x) {
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = n - 1; j > i; j--) {
            sum += U[i*n + j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i*n + i];
    }
}

void InversePowerMethod(double *M, double *U, double *l, int ST, double sigma)
{
    double t[ST];
    double nt[ST];
    double tmpM[ST * ST];
    
    int i = 0, j = 0, k; 

    do {
        // Copiamos M a tmpM y luego modificamos tmpM para ser (M - sigma * I) 
        for(int m = 0; m < ST * ST; m++) {
            tmpM[m] = M[m];
        }
        for(int m = 0; m < ST; m++) {
            tmpM[m*ST + m] -= sigma;
        }

        // Inicializamos la matriz de unos
        Ones(t, ST);

        do {
            // Inicializamos la matriz de unos sólo en la primera iteración
            if (i == 0) {
                Ones(nt, ST);
            }

            // Resolvemos el sistema de ecuaciones para el vector t usando la eliminación gaussiana
            eliminacionGaussiana(ST, tmpM, nt);
            resuelveSistema(ST, tmpM, nt, t);

            // Normalizamos t
            Divide(t, sqrt(DotProd(t, t, ST)), t, ST);

            // Condición de paro
            k = ConditionCheck(nt, t, ST);
            if (k == 1) {
                break;
            }

            // Copiamos t a nt para la próxima iteración
            for (int c = 0; c < ST; c++) {
                nt[c] = t[c];
            }

            j++;

        } while(j < 10000);

        // Guardamos el vector propio
        for(int m = 0; m < ST; m++) {
            U[i*ST + m] = t[m];
        }

        // Calculamos el valor propio asociado
        double tmp[ST];
        MatrixProduct(M, t, tmp, ST, ST, 1);
        l[i] = DotProd(t, tmp, ST);

        i++;

    } while(i < ST);
}

void JacobiEigenvalues(double *A, double *eigenvectors, double *eigenvalues, int n) {
    double threshold = 1e-10;  // Puedes cambiar este valor según la precisión requerida
    int maxIterations = 1000;  // Número máximo de iteraciones
    double maxOffDiagonal;
    int p, q;
    double *J = (double *)malloc(n * n * sizeof(double)); 
    double *temp = (double *)malloc(n * n * sizeof(double)); 

    // Inicializar eigenvectors como matriz identidad
    Initialize(eigenvectors, n*n);
    for(int i = 0; i < n; i++) {
        eigenvectors[i*n + i] = 1.0;
    }

    for(int iteration = 0; iteration < maxIterations; iteration++) {
        maxOffDiagonal = 0.0;

        // Buscar el elemento de magnitud más grande fuera de la diagonal
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(fabs(A[i*n + j]) > maxOffDiagonal) {
                    maxOffDiagonal = fabs(A[i*n + j]);
                    p = i;
                    q = j;
                }
            }
        }

        // Si todos los elementos fuera de la diagonal son pequeños, salimos del bucle
        if(maxOffDiagonal < threshold) {
            break;
        }

        // Calcular el ángulo de rotación
        double theta;
        double diff = A[p*n + p] - A[q*n + q];
        if(fabs(diff) < threshold) {
            theta = M_PI / 4.0;
        } else {
            theta = 0.5 * atan2(2.0 * A[p*n + q], diff);
        }

        // Construir la matriz de rotación
        Initialize(J, n*n);
        for(int i = 0; i < n; i++) {
            J[i*n + i] = 1.0;
        }
        J[p*n + p] = cos(theta);
        J[p*n + q] = -sin(theta);
        J[q*n + p] = sin(theta);
        J[q*n + q] = cos(theta);

        // Aplicar la rotación
        MatrixProduct(A, J, temp, n, n, n);
        MatrixT(n, n, J, J);  // Transponer J
        MatrixProduct(J, temp, A, n, n, n);

        // Actualizar la matriz de eigenvectores
        MatrixProduct(eigenvectors, J, temp, n, n, n);
        for(int i = 0; i < n*n; i++) {
            eigenvectors[i] = temp[i];
        }
    }

    // Los valores propios están en la diagonal de A
    for(int i = 0; i < n; i++) {
        eigenvalues[i] = A[i*n + i];
    }

    free(J);
    free(temp);
}
