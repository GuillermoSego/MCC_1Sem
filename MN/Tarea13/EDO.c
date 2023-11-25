
/*

Biblioteca para solución de sistemas de ecuaciones diferenciales

*/


# include <math.h>
# include <stdio.h>
# include <stdlib.h>

// // Funciones unidimensionales
void Euler(double a, double b, int N, double alpha, double (*f)(double, double), double *w) {
    double h = (b - a) / N;
    double t = a;
    w[0] = alpha;

    // printf("t0 = %.2f, w0 = %.2f\n", t, w[0]);
    for (int i = 1; i <= N; i++) {
        // printf("feval = %.6lf\n", f(t, w[i-1]));
        w[i] = w[i-1] + h * f(t, w[i-1]);
        t = a + i * h;
        // printf("t%d = %.2f, w%d = %.6f\n", i, t, i, w[i]);
    }
}

void Heun(double a, double b, int N, double alpha, double (*f)(double, double), double *w) {
    double h = (b - a) / N;
    double t = a;
    double w_star;
    w[0] = alpha;

    for (int i = 1; i <= N; i++) {
        w_star = w[i-1] + h * f(t, w[i-1]);
        w[i] = w[i-1] + (h / 2) * (f(t, w[i-1]) + f(t + h, w_star));
        t = a + i * h;
    }
}

void Taylor2(double a, double b, int N, double alpha, double (*f)(double, double), double (*dfdt)(double, double), double (*dfdy)(double, double), double *w) {
    double h = (b - a) / N;
    double t = a;
    w[0] = alpha;

    for (int i = 1; i <= N; i++) {
        w[i] = w[i-1] + h * f(t, w[i-1]) + (h * h / 2) * (dfdt(t, w[i-1]) + dfdy(t, w[i-1]) * f(t, w[i-1]));
        t = a + i * h;
    }
}

void RK4(double a, double b, int N, double alpha, double (*f)(double, double), double *w) {
    double h = (b - a) / N;
    double t = a;
    double k1, k2, k3, k4;
    w[0] = alpha;

    for (int i = 1; i <= N; i++) {
        k1 = h * f(t, w[i-1]);
        k2 = h * f(t + h / 2, w[i-1] + k1 / 2);
        k3 = h * f(t + h / 2, w[i-1] + k2 / 2);
        k4 = h * f(t + h, w[i-1] + k3);

        w[i] = w[i-1] + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        t = a + i * h;
    }
}

// Sistemas de ecuaciones

void EulerSystem(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w) {
    double h = (b - a) / N;
    double t = a;
    double *current_values = (double *)malloc(dim * sizeof(double));

    // Inicialización de condiciones iniciales y arreglo temporal
    for (int j = 0; j < dim; j++) {
        w[j][0] = alpha[j];
        current_values[j] = alpha[j];
    }

    // Arreglo para almacenar las evaluaciones de las funciones
    double *f_eval = (double *)malloc(dim * sizeof(double));

    for (int i = 1; i <= N; i++) {
        // Actualizar el arreglo temporal con los valores actuales
        for (int j = 0; j < dim; j++) {
            current_values[j] = w[j][i-1];
        }

        // Calcular las evaluaciones de las funciones en el paso actual
        for (int j = 0; j < dim; j++) {
            f_eval[j] = f[j](t, current_values);
        }

        // Actualizar las soluciones para el siguiente paso
        for (int j = 0; j < dim; j++) {
            w[j][i] = w[j][i-1] + h * f_eval[j];
        }

        t = a + i * h;
    }

    free(f_eval);
    free(current_values);
}

void HeunSystem(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w) {
    double h = (b - a) / N;
    double t = a;
    double *current_values = (double *)malloc(dim * sizeof(double));
    double *w_star = (double *)malloc(dim * sizeof(double));
    double *f_eval = (double *)malloc(dim * sizeof(double));

    // Inicializar condiciones iniciales
    for (int j = 0; j < dim; j++) {
        w[j][0] = alpha[j];
        current_values[j] = alpha[j];
    }

    for (int i = 1; i <= N; i++) {
        // Actualizar valores actuales
        for (int j = 0; j < dim; j++) {
            current_values[j] = w[j][i-1];
        }

        // Calcular w_star
        for (int j = 0; j < dim; j++) {
            f_eval[j] = f[j](t, current_values);
            w_star[j] = w[j][i-1] + h * f_eval[j];
        }

        // Actualizar las soluciones para el siguiente paso
        for (int j = 0; j < dim; j++) {
            w[j][i] = w[j][i-1] + (h / 2) * (f_eval[j] + f[j](t + h, w_star));
        }

        t = a + i * h;
    }

    free(current_values);
    free(w_star);
    free(f_eval);
}

void Taylor2System(double a, double b, int N, double *alpha, double (**f)(double, double*), double (**dfdt)(double, double*), double (**dfdy)(double, double*), int dim, double **w) {
    double h = (b - a) / N;
    double t = a;
    double *current_values = (double *)malloc(dim * sizeof(double));

    // Inicializar condiciones iniciales
    for (int j = 0; j < dim; j++) {
        w[j][0] = alpha[j];
        current_values[j] = alpha[j];
    }

    for (int i = 1; i <= N; i++) {
        // Actualizar valores actuales
        for (int j = 0; j < dim; j++) {
            current_values[j] = w[j][i-1];
        }

        // Actualizar las soluciones para el siguiente paso
        for (int j = 0; j < dim; j++) {
            w[j][i] = w[j][i-1] + h * f[j](t, current_values) + 
                      (h * h / 2) * (dfdt[j](t, current_values) + 
                      dfdy[j](t, current_values) * f[j](t, current_values));
        }

        t = a + i * h;
    }

    free(current_values);
}

void RK4System(double a, double b, int N, double *alpha, double (**f)(double, double*), int dim, double **w) {
    double h = (b - a) / N;
    double t = a;
    double *current_values = (double *)malloc(dim * sizeof(double));
    double *k1 = (double *)malloc(dim * sizeof(double));
    double *k2 = (double *)malloc(dim * sizeof(double));
    double *k3 = (double *)malloc(dim * sizeof(double));
    double *k4 = (double *)malloc(dim * sizeof(double));
    double *temp = (double *)malloc(dim * sizeof(double));

    // Inicializar condiciones iniciales
    for (int j = 0; j < dim; j++) {
        w[j][0] = alpha[j];
        current_values[j] = alpha[j];
    }

    for (int i = 1; i <= N; i++) {
        // Actualizar valores actuales
        for (int j = 0; j < dim; j++) {
            current_values[j] = w[j][i-1];
        }

        // Calcular k1, k2, k3, k4
        for (int j = 0; j < dim; j++) {
            k1[j] = h * f[j](t, current_values);
        }

        for (int j = 0; j < dim; j++) {
            temp[j] = w[j][i-1] + k1[j] / 2;
        }
        for (int j = 0; j < dim; j++) {
            k2[j] = h * f[j](t + h / 2, temp);
        }

        for (int j = 0; j < dim; j++) {
            temp[j] = w[j][i-1] + k2[j] / 2;
        }
        for (int j = 0; j < dim; j++) {
            k3[j] = h * f[j](t + h / 2, temp);
        }

        for (int j = 0; j < dim; j++) {
            temp[j] = w[j][i-1] + k3[j];
        }
        for (int j = 0; j < dim; j++) {
            k4[j] = h * f[j](t + h, temp);
        }

        // Actualizar las soluciones para el siguiente paso
        for (int j = 0; j < dim; j++) {
            w[j][i] = w[j][i-1] + (k1[j] + 2 * k2[j] + 2 * k3[j] + k4[j]) / 6;
        }

        t = a + i * h;
    }

    free(current_values);
    free(k1);
    free(k2);
    free(k3);
    free(k4);
    free(temp);
}
