

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double *v);

// Esta rutina calcula la matriz transpuesta de un vector y la guarda en otro
void MatrixT(int n, int m, double v[], double Vec[] );

// Esta rutina inicializa a cero un arreglo
void Initialize(double in[], int n);

// Esta rutina calcula la suma de dos matrices cuadradas
void MatrixSum(double m1[], double m2[], double mout[], int n);

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

void eliminacionGaussiana(int n, double *A, double *b);

void resuelveSistema(int n, double *U, double *b, double *x);