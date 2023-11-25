
void linspace(double x[], double init, double end, int n);

void saveMatrixToFile(double *A, int n, int m, const char *filename);

// Función para calcular el polinomio de Lagrange
double polinomioLagrange(int n, double *x_values, double *y_values, double x);

// Función para calcular la interpolación de Neville
double Neville(double x, double x_values[], double y_values[], int n);

// Función para calcular la tabla de diferencias divididas
void calculaDiferenciasDivididas(int n, double x[], double f[], double **F);

// Función para realizar la interpolación de Newton
double interpolacionNewton(int n, double x[], double **F, double valorX);
