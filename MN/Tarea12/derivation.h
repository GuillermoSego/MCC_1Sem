
// Derivación hacia adelante con O(h)
double forwardDerivative(double (*func)(double), double x, double h);

// Derivación hacia atrás con O(h)
double backwardDerivative(double (*func)(double), double x, double h);

// Derivación centrada con O(h^2)
double centralDerivative(double (*func)(double), double x, double h);

// Derivación de tres puntos con O(h^2)
double threePointDerivative(double (*func)(double), double x, double h);

// Derivación de cinco puntos con O(h^4)
double fivePointDerivative(double (*func)(double), double x, double h);

// Segunda derivada con la fórmula del punto medio O(h^2)
double secondDerivativeMidpoint(double (*func)(double), double x, double h);