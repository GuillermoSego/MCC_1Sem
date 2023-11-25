/*

Biblioteca para integración

*/

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

// Newton-Cotes Abierto de orden 0 (Punto Medio)
double nc_open_0(double a, double b, double (*f)(double)) {
    double h = b - a;
    double midpoint = a + h / 2.0;
    return h * f(midpoint);
}

// Newton-Cotes Abierto de orden 1
double nc_open_1(double a, double b, double (*f)(double)) {
    double h = (b - a) / 3.0;
    return (3.0 / 2.0) * h * (f(a + h) + f(a + 2 * h));
}

// Newton-Cotes Abierto de orden 2
double nc_open_2(double a, double b, double (*f)(double)) {
    double h = (b - a) / 4.0;
    return (4.0 / 3.0) * h * (2 * f(a + h) - f(a + 2 * h) + 2 * f(a + 3 * h));
}

// Newton-Cotes Abierto de orden 3
double nc_open_3(double a, double b, double (*f)(double)) {
    double h = (b - a) / 5.0;
    return (5.0 / 24.0) * h * (11 * f(a + h) + f(a + 2 * h) + f(a + 3 * h) + 11 * f(a + 4 * h));
}

#include <math.h>

// Newton-Cotes Cerrado para n=1 (Regla del Trapecio)
double nc_closed_1(double a, double b, double (*f)(double)) {
    return (b - a) * (f(a) + f(b)) / 2;
}

// Newton-Cotes Cerrado para n=2 (Regla de Simpson)
double nc_closed_2(double a, double b, double (*f)(double)) {
    double h = (b - a) / 2;
    return (h / 3) * (f(a) + 4 * f(a + h) + f(b));
}

// Newton-Cotes Cerrado para n=3 (Regla de Simpson 3/8)
double nc_closed_3(double a, double b, double (*f)(double)) {
    double h = (b - a) / 3;
    return (3 * h / 8) * (f(a) + 3 * f(a + h) + 3 * f(a + 2 * h) + f(b));
}

// Newton-Cotes Cerrado para n=4 (Regla de Bode)
double nc_closed_4(double a, double b, double (*f)(double)) {
    double h = (b - a) / 4;
    return (2 * h / 45) * (7 * f(a) + 32 * f(a + h) + 12 * f(a + 2 * h) + 32 * f(a + 3 * h) + 7 * f(b));
}

// Cambio de variable de [a, b] a [-1, 1]
double changeOfInterval(double x, double a, double b) {
    return ((b - a) / 2) * x + (a + b) / 2;
}

// Cuadratura Gaussiana para n=1
double gauss_quad_1(double a, double b, double (*f)(double)) {
    double c1 = (b - a) / 2;
    double w1 = 2.0;
    double x1 = 0.0; // Nodo para n=1

    return c1 * w1 * f(changeOfInterval(x1, a, b));
}

// Cuadratura Gaussiana para n=2
double gauss_quad_2(double a, double b, double (*f)(double)) {
    double c2 = (b - a) / 2;
    double w1 = 1.0, w2 = 1.0;
    double x1 = -1 / sqrt(3), x2 = 1 / sqrt(3);

    return c2 * (w1 * f(changeOfInterval(x1, a, b)) + w2 * f(changeOfInterval(x2, a, b)));
}

// Cuadratura Gaussiana para n=3
double gauss_quad_3(double a, double b, double (*f)(double)) {
    double c3 = (b - a) / 2;
    double w1 = 5.0 / 9.0, w2 = 8.0 / 9.0, w3 = 5.0 / 9.0;
    double x1 = -sqrt(3.0 / 5.0), x2 = 0.0, x3 = sqrt(3.0 / 5.0);

    return c3 * (w1 * f(changeOfInterval(x1, a, b)) + w2 * f(changeOfInterval(x2, a, b)) + w3 * f(changeOfInterval(x3, a, b)));
}

// Cuadratura Gaussiana para n=4
double gauss_quad_4(double a, double b, double (*f)(double)) {
    double c4 = (b - a) / 2;
    double w1 = (18 - sqrt(30)) / 36, w2 = (18 + sqrt(30)) / 36;
    double x1 = -sqrt(3.0 / 7.0 + 2.0 / 7.0 * sqrt(6.0 / 5.0)), x2 = -sqrt(3.0 / 7.0 - 2.0 / 7.0 * sqrt(6.0 / 5.0));
    double x3 = -x2, x4 = -x1;

    return c4 * (w1 * f(changeOfInterval(x1, a, b)) + w2 * f(changeOfInterval(x2, a, b)) + w2 * f(changeOfInterval(x3, a, b)) + w1 * f(changeOfInterval(x4, a, b)));
}

// Cuadratura Gaussiana para n=5
double gauss_quad_5(double a, double b, double (*f)(double)) {
    double c5 = (b - a) / 2;
    double w1 = 128.0 / 225.0, w2 = (322.0 + 13.0 * sqrt(70)) / 900.0, w3 = (322.0 - 13.0 * sqrt(70)) / 900.0;
    double x1 = 0.0;
    double x2 = sqrt(5.0 - 2.0 * sqrt(10.0 / 7.0)) / 3.0, x3 = -x2;
    double x4 = sqrt(5.0 + 2.0 * sqrt(10.0 / 7.0)) / 3.0, x5 = -x4;

    return c5 * (w1 * f(changeOfInterval(x1, a, b)) + w2 * f(changeOfInterval(x2, a, b)) + w3 * f(changeOfInterval(x3, a, b)) + w2 * f(changeOfInterval(x4, a, b)) + w3 * f(changeOfInterval(x5, a, b)));
}