
# include <stdio.h>
# include <math.h>

// Funcion que calcula el valor de una funcion
double function(double x){

    double value;
    value = pow(x, 3) + x - 6.0;

    return value;
}

double bisection(double a, double b, double epsilon, int *iteraciones){

    double fa, fb, fc, c;
    int i = 0;

    do {

        // Calcula el punto medio del intervalo
        c = (b + a) / 2.0; 

        fa = function(a);
        fb = function(b);
        fc = function(c);

        if(fc == 0.0 || fabs(b - a) < epsilon) {
            break; 
        }

        // Decide qué subintervalo tomar
        if(fa * fc < 0) {
            b = c;
        }
        else {
            a = c;
        }

        i++;

    } while(i < 1000);

    *iteraciones = i; // Asigna el número de iteraciones
    return c; // Retorna la raíz aproximada
}


int main(){

    double a, b, epsilon, root;
    int iteraciones;

    a = 1.55;
    b = 1.75;
    epsilon = 0.0001;

    root = bisection(a, b, epsilon, &iteraciones);

    printf("Raíz aproximada: %lf\n", root);
    printf("Número de iteraciones: %d\n", iteraciones);

    return 0;
}