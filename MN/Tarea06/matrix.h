

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double *v);

// Rutina para leer una matriz con un header
int ReadMatrix(const char *filename, double **A, int *rows, int *cols);

// Esta rutina implementa el Método de Jacobi para resolver sistemas lineales de ecuaciones Ax = b.
double* jacobiMethod(double *A, double *b, int n, int maxIter, double tol);

// Esta rutina implementa el Método de Gauss-Seidel para resolver sistemas lineales de ecuaciones Ax = b.
double* gaussSeidelMethod(double *A, double *b, int n, int maxIter, double tol);
