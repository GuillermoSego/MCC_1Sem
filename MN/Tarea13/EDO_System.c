
# include <stdio.h>
# include <math.h>
# include "EDO.h"
# include "matrix.h"

double x_prime(double t, double *xy) {
    return 0.4 * xy[0] - 0.018 * xy[0] * xy[1];
}

double y_prime(double t, double *xy) {
    return -0.8 * xy[1] + 0.023 * xy[0] * xy[1];
}

double x_prime_x(double t, double *xy) {
    return 0.4 - 0.018 * xy[1];
}

double x_prime_y(double t, double *xy) {
    return -0.018 * xy[0];
}

double y_prime_x(double t, double *xy) {
    return 0.023 * xy[1];
}

double y_prime_y(double t, double *xy) {
    return -0.8 + 0.023 * xy[0];
}


int main() {
    double a = 0;  // Punto inicial
    double b = 25; // Punto final
    int N = 10;    // Número de pasos

    // Sistema
    int dim = 2;

    // Condiciones iniciales
    double alpha[] = {30, 4}; // x(0) = 30, y(0) = 4

    // Creación de matrices para almacenar las soluciones
    double **w_euler = createMatrix(dim, N + 1);
    double **w_heun = createMatrix(dim, N + 1);
    double **w_taylor = createMatrix(dim, N + 1);
    double **w_rk4 = createMatrix(dim, N + 1);

    // Arreglo de apuntadores a las funciones del sistema
    double (*system_functions[])(double, double*) = {x_prime, y_prime};
    double (*derivative_functions_x[])(double, double*) = {x_prime_x, y_prime_x};
    double (*derivative_functions_y[])(double, double*) = {x_prime_y, y_prime_y};

    // Llamadas a los métodos
    EulerSystem(a, b, N, alpha, system_functions, dim, w_euler);
    HeunSystem(a, b, N, alpha, system_functions, dim, w_heun);
    Taylor2System(a, b, N, alpha, system_functions, derivative_functions_x, derivative_functions_y, dim, w_taylor);
    RK4System(a, b, N, alpha, system_functions, dim, w_rk4);

    // Mostrar resultados
    printf(" t\t x(Euler)\t y(Euler)\t x(Heun)\t y(Heun)\t x(Taylor)\t y(Taylor)\t x(RK4)\t y(RK4)\n");
    for (int i = 0; i <= N; i++) {
        double t = a + i * (b - a) / N;
        printf("%.2f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\n",
            t, w_euler[0][i], w_euler[1][i], w_heun[0][i], w_heun[1][i], w_taylor[0][i], w_taylor[1][i], w_rk4[0][i], w_rk4[1][i]);
    }

    // Guardar resultados en archivos
    double *w_euler_flat = FlattenMatrix(w_euler, dim, N + 1);
    double *w_heun_flat = FlattenMatrix(w_heun, dim, N + 1);
    double *w_taylor_flat = FlattenMatrix(w_taylor, dim, N + 1);
    double *w_rk4_flat = FlattenMatrix(w_rk4, dim, N + 1);

    saveMatrixToFile(w_euler_flat, dim, N + 1, "euler_results.txt");
    saveMatrixToFile(w_heun_flat, dim, N + 1, "heun_results.txt");
    saveMatrixToFile(w_taylor_flat, dim, N + 1, "taylor_results.txt");
    saveMatrixToFile(w_rk4_flat, dim, N + 1, "rk4_results.txt");

    // Limpieza de memoria
    freeMatrix(w_euler, dim);
    freeMatrix(w_heun, dim);
    freeMatrix(w_taylor, dim);
    freeMatrix(w_rk4, dim);

    return 0;
}