
void Euler(double a, double b, int N, double alpha, double (*f)(double, double), double *w);

void Heun(double a, double b, int N, double alpha, double (*f)(double, double), double *w);

void Taylor2(double a, double b, int N, double alpha, double (*f)(double, double), double (*dfdt)(double, double), double (*dfdy)(double, double), double *w);

void RK4(double a, double b, int N, double alpha, double (*f)(double, double), double *w);

void EulerSystem(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w);

void HeunSystem(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w);

void Taylor2System(double a, double b, int N, double *alpha, double (**f)(double, double*), double (**dfdt)(double, double*), double (**dfdy)(double, double*), int dim, double **w);

void RK4System(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w);