
# include <stdio.h>
# include <math.h>
# include "integration.h"

// Funciones para las integrales.
double f1(double x) { return sin(x); }
double f2(double x) { return x * x * log(x); }
double f3(double x) { return x * x * exp(-x); }

int main() {
    // Límites de integración para cada función.
    double a1 = 0, b1 = M_PI / 4;
    double a2 = 1, b2 = 1.5;
    double a3 = 0, b3 = 1;

    // Tabla de encabezados.
    printf("Method                  | Integral of sin(x)    | Integral of x^2 * ln(x) | Integral of x^2 * e^(-x)\n");
    printf("------------------------|-----------------------|-------------------------|-------------------------\n");

    // Calcular y mostrar resultados de cada método.
    printf("NC Open Order 0         | %.10f            | %.10f               | %.10f\n", nc_open_0(a1, b1, f1), nc_open_0(a2, b2, f2), nc_open_0(a3, b3, f3));
    printf("NC Open Order 1         | %.10f            | %.10f               | %.10f\n", nc_open_1(a1, b1, f1), nc_open_1(a2, b2, f2), nc_open_1(a3, b3, f3));
    printf("NC Open Order 2         | %.10f            | %.10f               | %.10f\n", nc_open_2(a1, b1, f1), nc_open_2(a2, b2, f2), nc_open_2(a3, b3, f3));
    printf("NC Open Order 3         | %.10f            | %.10f               | %.10f\n", nc_open_3(a1, b1, f1), nc_open_3(a2, b2, f2), nc_open_3(a3, b3, f3));

    printf("NC Closed Order 1       | %.10f            | %.10f               | %.10f\n", nc_closed_1(a1, b1, f1), nc_closed_1(a2, b2, f2), nc_closed_1(a3, b3, f3));
    printf("NC Closed Order 2       | %.10f            | %.10f               | %.10f\n", nc_closed_2(a1, b1, f1), nc_closed_2(a2, b2, f2), nc_closed_2(a3, b3, f3));
    printf("NC Closed Order 3       | %.10f            | %.10f               | %.10f\n", nc_closed_3(a1, b1, f1), nc_closed_3(a2, b2, f2), nc_closed_3(a3, b3, f3));
    printf("NC Closed Order 4       | %.10f            | %.10f               | %.10f\n", nc_closed_4(a1, b1, f1), nc_closed_4(a2, b2, f2), nc_closed_4(a3, b3, f3));

    printf("Gauss Quadrature Order 1| %.10f            | %.10f               | %.10f\n", gauss_quad_1(a1, b1, f1), gauss_quad_1(a2, b2, f2), gauss_quad_1(a3, b3, f3));
    printf("Gauss Quadrature Order 2| %.10f            | %.10f               | %.10f\n", gauss_quad_2(a1, b1, f1), gauss_quad_2(a2, b2, f2), gauss_quad_2(a3, b3, f3));
    printf("Gauss Quadrature Order 3| %.10f            | %.10f               | %.10f\n", gauss_quad_3(a1, b1, f1), gauss_quad_3(a2, b2, f2), gauss_quad_3(a3, b3, f3));
    printf("Gauss Quadrature Order 4| %.10f            | %.10f               | %.10f\n", gauss_quad_4(a1, b1, f1), gauss_quad_4(a2, b2, f2), gauss_quad_4(a3, b3, f3));
    printf("Gauss Quadrature Order 5| %.10f            | %.10f               | %.10f\n", gauss_quad_5(a1, b1, f1), gauss_quad_5(a2, b2, f2), gauss_quad_5(a3, b3, f3));


    return 0;
}
