
# include <stdio.h>
# include <math.h>
# include "EDO.h"
# include "matrix.h"


// Ejemplo Burden
double f(double t, double y) {
    return y - pow(t, 2) + 1;
}

double dfdy (double t, double y){
    return 1;
}

double dfdt (double t, double y){
    return -2 * t;
}

double f_Real(double t) {
    return pow((t + 1), 2) - 0.5 * exp(t);
}


// Problema 1
// double f(double t, double y) {
//     return y;
// }

// double dfdy (double t, double y){
//     return 1;
// }

// double dfdt (double t, double y){
//     return 0;
// }

// double f_Real(double t) {
//     return exp(t);
// }

int main() {
    double a = 0; // Punto inicial
    double b = 2; // Punto final
    int N = 10; // Número de pasos
    double alpha = 0.5; // Condición inicial y(0) = alpha

    double w_euler[N + 1];
    double w_heun[N + 1];
    double w_taylor[N + 1];
    double w_rk4[N + 1];

    Euler(a, b, N, alpha, f, w_euler);
    Heun(a, b, N, alpha, f, w_heun);
    Taylor2(a, b, N, alpha, f, dfdt, dfdy, w_taylor);
    RK4(a, b, N, alpha, f, w_rk4);

    // double t, real, error_euler, error_heun, error_taylor, error_rk4;
    // printf(" t\t Euler\t\t Heun\t\t Taylor2\t RK4\t\t Real\t\t Error(E)\t Error(H)\t Error(T)\t Error(RK)\n");
    // for (int i = 0; i <= N; i++) {
    //     t = a + i * (b - a) / N;
    //     real = f_Real(t);
    //     error_euler = fabs(w_euler[i] - real);
    //     error_heun = fabs(w_heun[i] - real);
    //     error_taylor = fabs(w_taylor[i] - real);
    //     error_rk4 = fabs(w_rk4[i] - real);

    //     printf("%.2f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\t %.6f\n", 
    //            t, w_euler[i], w_heun[i], w_taylor[i], w_rk4[i], real, error_euler, error_heun, error_taylor, error_rk4);
    // }

    // Mostrar resultados sin error
    printf("t\t Euler\t\t Heun\t\t Taylor2\t RK4\t\t\n");
    for (int i = 0; i <= N; i++) {
        double t = a + i * (b - a) / N;
        printf("%.2f\t %.6f\t %.6f\t %.6f\t %.6f\n",
            t, w_euler[i], w_heun[i], w_taylor[i], w_rk4[i]);
    }

    // Guardar para grafica
    saveMatrixToFile(w_euler, N+1, 1, "Euler.txt");
    saveMatrixToFile(w_heun, N+1, 1, "Heun.txt");
    saveMatrixToFile(w_taylor, N+1, 1, "Taylor2.txt");
    saveMatrixToFile(w_rk4, N+1, 1, "RK4.txt");

    return 0;
}