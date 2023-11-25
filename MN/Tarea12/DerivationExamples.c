
# include <stdio.h>
# include <math.h>
# include "derivation.h"

// Función dada
double f(double x) {
    return 3 * x * exp(x) - cos(x);
}

// Función para calcular la derivada verdadera de f en x = 1.3
double trueFirstDerivative(double x) {
    // Calcula la primera derivada analítica de f en x
    // f'(x) = 3e^x + 3xe^x + sin(x)
    return 3 * exp(x) + 3 * x * exp(x) + sin(x);
}

// Función para calcular la segunda derivada verdadera de f en x = 1.3
double trueSecondDerivative(double x) {
    // Calcula la segunda derivada analítica de f en x
    // f''(x) = 6e^x + 3xe^x + cos(x)
    return 6 * exp(x) + 3 * x * exp(x) + cos(x);
}

int main() {
    double x = 1.30;
    double h1 = 0.1, h2 = 0.01;
    
    // Calcula las derivadas usando las funciones proporcionadas
    double forward_h1 = forwardDerivative(f, x, h1);
    double backward_h1 = backwardDerivative(f, x, h1);
    double central_h1 = centralDerivative(f, x, h1);
    double three_point_h1 = threePointDerivative(f, x, h1);
    double five_point_h1 = fivePointDerivative(f, x, h1);
    double second_derivative_h1 = secondDerivativeMidpoint(f, x, h1);

    double forward_h2 = forwardDerivative(f, x, h2);
    double backward_h2 = backwardDerivative(f, x, h2);
    double central_h2 = centralDerivative(f, x, h2);
    double three_point_h2 = threePointDerivative(f, x, h2);
    double five_point_h2 = fivePointDerivative(f, x, h2);
    double second_derivative_h2 = secondDerivativeMidpoint(f, x, h2);

    // Valores verdaderos de las derivadas
    double true_first_derivative = trueFirstDerivative(x);
    double true_second_derivative = trueSecondDerivative(x);

    // Imprime los resultados en formato de tabla
    printf("Comparación de derivada evaluada en x = %lf\n", x);
    printf("| %-15s | %-15s | %-15s | %-15s |\n", "Método", "h=0.1", "h=0.01", "Valor verdadero");
    printf("-----------------------------------------------------------------------\n");
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Hacia adelante", forward_h1, forward_h2, true_first_derivative);
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Hacia atrás", backward_h1, backward_h2, true_first_derivative);
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Centrada", central_h1, central_h2, true_first_derivative);
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Tres Puntos", three_point_h1, three_point_h2, true_first_derivative);
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Cinco Puntos", five_point_h1, five_point_h2, true_first_derivative);
    printf("| %-15s | %-15.10f | %-15.10f | %-15.10f |\n", "Segunda Deriv.", second_derivative_h1, second_derivative_h2, true_second_derivative);

    return 0;
}