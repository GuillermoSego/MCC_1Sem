
# include <stdio.h>
# include <math.h>
# include "EDO.h"
# include "matrix.h"

// Integral
double f_int(double x) { 
    return pow((1 + pow(x, 3)), 0.5); 
}

// Cambio de variable de [a, b] a [-1, 1]
double changeOfInterval(double x, double a, double b) {
    return ((b - a) / 2) * x + (a + b) / 2;
}

// Cuadratura Gaussiana para n=3
double gauss_quad_3(double a, double b, double (*f)(double)) {
    double c3 = (b - a) / 2;
    double w1 = 5.0 / 9.0, w2 = 8.0 / 9.0, w3 = 5.0 / 9.0;
    double x1 = -sqrt(3.0 / 5.0), x2 = 0.0, x3 = sqrt(3.0 / 5.0);

    return c3 * (w1 * f(changeOfInterval(x1, a, b)) + w2 * f(changeOfInterval(x2, a, b)) + w3 * f(changeOfInterval(x3, a, b)));
}

// Problema 2
double f(double t, double y) { 
    return pow((1 + pow(t, 3)), 0.5); 
}

double dfdy (double t, double y){
    return 0;
}

double dfdt (double t, double y){
    return 0.5 * pow((1 + pow(t, 3)), - 0.5) * (3 * pow(t, 2));
}

int main(){

    /*
    
    Integración
    
    */
    double a = 0, b = 2; // Límites de integración
    
    printf("La integral por Cuadratura gaussiana de orden 3 es: %.10f\n", gauss_quad_3(a, b, f_int));

    /*
    
    Cálculo por EDO
    
    */
    
    int N = 10; // Número de pasos
    double alpha = 0; // Condición inicial y(0) = alpha

    double w_euler[N + 1];
    double w_heun[N + 1];
    double w_taylor[N + 1];
    double w_rk4[N + 1];

    Euler(a, b, N, alpha, f, w_euler);
    Heun(a, b, N, alpha, f, w_heun);
    Taylor2(a, b, N, alpha, f, dfdt, dfdy, w_taylor);
    RK4(a, b, N, alpha, f, w_rk4);

    double t, real, error_euler, error_heun, error_taylor, error_rk4;
    printf(" t\t Euler\t\t Heun\t\t Taylor2\t RK4\n");
    for (int i = 0; i <= N; i++) {
        t = a + i * (b - a) / N;
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