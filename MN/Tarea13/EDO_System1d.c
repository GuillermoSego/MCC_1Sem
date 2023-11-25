

# include <stdio.h>
# include <math.h>
# include "EDO.h"
# include "matrix.h"

double y_prime(double t, double *xy) {
    return xy[0] - pow(t, 2) + 1;
}

double y_prime_x(double t, double *xy) {
    return -2*t;
}

double y_prime_y(double t, double *xy) {
    return 1;
}


int main() {
    double a = 0;  // Punto inicial
    double b = 2; // Punto final
    int N = 10;    // Número de pasos

    // Sistema
    int dim = 1;

    // Condiciones iniciales
    double alpha[] = {0.5}; // x(0) = 30, y(0) = 4

    // Creación de matrices para almacenar las soluciones
    double **w_euler = createMatrix(dim, N + 1);
    double **w_heun = createMatrix(dim, N + 1);
    double **w_taylor = createMatrix(dim, N + 1);
    double **w_rk4 = createMatrix(dim, N + 1);

    // Arreglo de apuntadores a las funciones del sistema
    double (*system_functions[])(double, double*) = {y_prime};
    double (*derivative_functions_x[])(double, double*) = {y_prime_x};
    double (*derivative_functions_y[])(double, double*) = {y_prime_y};

    // Llamadas a los métodos
    EulerSystem(a, b, N, alpha, system_functions, dim, w_euler);
    HeunSystem(a, b, N, alpha, system_functions, dim, w_heun);
    Taylor2System(a, b, N, alpha, system_functions, derivative_functions_x, derivative_functions_y, dim, w_taylor);
    RK4System(a, b, N, alpha, system_functions, dim, w_rk4);

    // Mostrar resultados
    printf("t\t Euler\t\t Heun\t\t Taylor2\t RK4\t\t\n");
    for (int i = 0; i <= N; i++) {
        double t = a + i * (b - a) / N;
        printf("%.2f\t %.6f\t %.6f\t %.6f\t %.6f\n",
            t, w_euler[0][i], w_heun[0][i], w_taylor[0][i], w_rk4[0][i]);
    }

    // Limpieza de memoria
    freeMatrix(w_euler, dim);
    freeMatrix(w_heun, dim);
    freeMatrix(w_taylor, dim);
    freeMatrix(w_rk4, dim);

    return 0;
}

