

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

void saveMatrixToFile(double *A, int n, int m, const char *filename);

void Conjugate_gradient(double *A, double *B, double *x, int rows, int cols);

int isSolution(double *A, double *X, double *b, int size, double tolerance);

double ConditionCheck(double ta[], double td[], int n);

// Incializar la matriz como se indicó en el problema
void Matrix_Initialize(double A[], double B[], int size);

// Función para resolver un sistema Ax = b dado L en la descomposición Cholesky A = LL^T
void solveCholesky(double L[], double b[], double x[], int n);

// Función para realizar la factorización de Cholesky (A = L * L^T)
int cholesky(double A[], double L[], int n);

// Esta rutina calcula el metodo de potencias.
void PowerMethod(double M[], double U[], double l[], int ST);
