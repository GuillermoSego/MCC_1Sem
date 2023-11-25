

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double *v);

// Esta rutina calcula la matriz transpuesta de un vector y la guarda en otro
void MatrixT(int n, int m, double v[], double Vec[] );

// Esta rutina inicializa a cero un arreglo
void Initialize(double in[], int n);

// Esta rutina calcula la suma de dos matrices m x n 
void MatrixSum(double* m1, double* m2, double* mout, int m, int n);

// Esta rutina calcula el producto punto entre dos vectores
double DotProd(double x[], double y[], int n);

// Esta rutina hace el producto entre dos matrices
void MatrixProduct(double m1[], double m2[], double Matrix[], int M, int N, int O);

// Rutina para leer una matriz con un header
int ReadMatrix(const char *filename, double **A, int *rows, int *cols);

// Este programa calcula el valor maxino de un arreglo
double maximus(double v[], int s);

// Este programa suma todos los elementos de un vector, y los pone en otro vec
void Sum(double in[], double out[], int n);

// Este programa divide un arreglo por un escalar
void Divide(double matrix[], double scalar, double out[], int s);

// Esta rutina inicializa un arreglo de unos
void Ones(double t[], int n);

// Rutina para restar v2 de v1 (v1 = v1 - v2)
void SubtractVector(double *v1, double *v2, int n);

void Conjugate_gradient(double *A, double *B, double *x, int rows, int cols);

double *FlattenMatrix(double **matrix, int rows, int cols);

void NegateVector(double *vec, int length);

double Norm(double *vec, int length);

/*

Gauss-Jordan

*/

// Función para intercambiar dos filas en una matriz
void intercambiaFilas(double **A, double *b, int fila1, int fila2, int n);

// Función para encontrar el valor máximo y la fila correspondiente en una columna de una matriz
int encuentraMax(double **A, int columna, int n);

// Función para realizar la eliminación gaussiana con pivoteo parcial
void eliminacionGaussianaPivoteo(int n, double **A, double *b);

// Función para hacer unos la diagonal principal
void OnesDiagonal(int n, double **A, double *b);

void eliminacionHaciaArriba(int n, double **A, double *b);

// Rutina para calcular el método de Gauss - Jordan
void gaussJordan(int n, double **A, double *b);

// Calcula la inversa con la rutina de Gauss Jordan
void gaussJordanInversa(int n, double **A, double **A_inv);

