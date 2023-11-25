# include <stdio.h>
# include <math.h>

# define points 2000

void spin3natural(int n, double *x, double *f, double *a, double *b, double *c, double *d) {
    double alpha[n], h[n], l[n], mu[n], z[n];

    // Paso 1
    for (int i = 0; i < n; i++) {
        h[i] = x[i+1] - x[i];
    }

    // Paso 2
    for (int i = 1; i < n; i++) {
        alpha[i] = (3.0/h[i]) * (f[i+1] - f[i]) - (3.0/h[i-1]) * (f[i] - f[i-1]);
    }

    // Paso 3
    l[0] = 1;
    mu[0] = 0;
    z[0] = 0;

    // Paso 4
    for (int i = 1; i < n; i++) {
        l[i] = 2.0 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    // Paso 5
    l[n] = 1;
    z[n] = 0;
    c[n] = 0;

    // Paso 6
    for (int j = n-1; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (f[j+1] - f[j]) / h[j] - h[j] * (c[j+1] + 2 * c[j]) / 3.0;
        d[j] = (c[j+1] - c[j]) / (3.0 * h[j]);
        a[j] = f[j];
    }

}

double calculate_S(double x_val, int n, double *x, double *a, double *b, double *c, double *d) {
    for (int j = 0; j < n; j++) {
        if (x_val >= x[j] && x_val <= x[j+1]) {
            double dx = x_val - x[j];
            return a[j] + b[j] * dx + c[j] * dx * dx + d[j] * dx * dx * dx;
        }
    }
    return -1; 
}

// Funcion para realizar un arreglo con cierta separacion
void linspace(double x[], double init, double end, int n) {
    double delta = (end - init) / (n - 1);

    for (int i = 0; i < n; i++) {
        x[i] = init + delta * i;
    }
}

// Rutina para guardar una matriz en un archivo
void saveMatrixToFile(double *X, double *Y, int n, const char *filename) {
    FILE *file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        fprintf(file, "%7.8f %7.8f\n", X[i], Y[i]);
    }

    fclose(file);
}


int main() {
    int n;
    double x[] = {0.9, 1.3, 1.9, 2.1, 2.6, 3.0, 3.9, 4.4, 4.7, 5.0, 6.0, 7.0, 8.0, 9.2, 10.5, 11.3, 11.6, 12.0, 12.6, 13.0, 13.3};
    double f[] = {1.3, 1.5, 1.85, 2.1, 2.6, 2.7, 2.4, 2.15, 2.05, 2.1, 2.25, 2.3, 2.25, 1.95, 1.4, 0.9, 0.7, 0.6, 0.5, 0.4, 0.25};

    // Ejemplo burden
    // double x[] = {0, 1, 2, 3};
    // double f[] = {1, exp(1), pow(exp(1), 2), pow(exp(1), 3)};

    // Valor de n
    n = sizeof(x) / sizeof(double) - 1; 

    // Size of arreglos
    double a[n+1], b[n], c[n+1], d[n];

    // Calculamos el spin cubico natural
    spin3natural(n, x, f, a, b, c, d);
    
    // Calculamos ahora el valor del polinomio
    // double x_val = 10; 
    // double S_val = calculate_S(x_val, n, x, a, b, c, d);

    // Imprimimos el polinomio
    // if (S_val != -1) {
    //     printf("S(%lf) = %lf\n", x_val, S_val);
    // } else {
    //     printf("El valor de x = %lf no está dentro del rango proporcionado.\n", x_val);
    // }
    
    // Generamos un arreglo e interpolamos el polinomio
    double samples[points], S_interpolated[points];
    linspace(samples, x[0], x[n], points);
    
    for(int i = 0; i<points; i++) {
        S_interpolated[i] = calculate_S(samples[i], n, x, a, b, c, d);
    } 

    // Guardamos la interpolación en un archivo
    saveMatrixToFile(samples, S_interpolated, points, "DataP2.txt");


    return 0;
}
