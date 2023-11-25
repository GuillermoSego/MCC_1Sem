
/*

Biblioteca para cálculo de derivadas

*/

// Derivación hacia adelante con O(h)
double forwardDerivative(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}

// Derivación hacia atrás con O(h)
double backwardDerivative(double (*f)(double), double x, double h) {
    return (f(x) - f(x - h)) / h;
}

// Derivación centrada con O(h^2)
double centralDerivative(double (*f)(double), double x, double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

// Derivación de tres puntos con O(h^2)
double threePointDerivative(double (*f)(double), double x, double h) {
    return (-3 * f(x) + 4 * f(x + h) - f(x + 2 * h)) / (2 * h);
}

// Derivación de cinco puntos con O(h^4)
double fivePointDerivative(double (*f)(double), double x, double h) {
    return (f(x - 2 * h) - 8 * f(x - h) + 8 * f(x + h) - f(x + 2 * h)) / (12 * h);
}

// Segunda derivada con la fórmula del punto medio O(h^2)
double secondDerivativeMidpoint(double (*f)(double), double x, double h) {
    return (f(x - h) - 2 * f(x) + f(x + h)) / (h * h);
}