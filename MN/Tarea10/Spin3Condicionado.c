
# include <stdio.h>
# include <math.h>

# define points 2000

void spin3condicionado(int n, double *x, double *f, double FPO, double FPN, double *a, double *b, double *c, double *d) {
    double alpha[n+1], h[n], l[n+1], mu[n], z[n+1];

    // Paso 1
    for (int i = 0; i < n; i++) {
        h[i] = x[i+1] - x[i];
    }

    // Paso 2
    alpha[0] = 3.0*(f[1]-f[0])/h[0] - 3.0*FPO;
    alpha[n] = 3.0*FPN - 3.0*(f[n]-f[n-1])/h[n-1];

    // Paso 3
    for (int i = 1; i < n; i++) {
        alpha[i] = (3.0/h[i]) * (f[i+1] - f[i]) - (3.0/h[i-1]) * (f[i] - f[i-1]);
    }

    // Paso 4
    l[0] = 2.0 * h[0];
    mu[0] = 0.5;
    z[0] = alpha[0] / l[0];

    // Paso 5
    for (int i = 1; i < n; i++) {
        l[i] = 2.0 * (x[i+1] - x[i-1]) - h[i-1] * mu[i-1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i-1] * z[i-1]) / l[i];
    }

    // Paso 6
    l[n] = h[n-1] * (2.0 - mu[n-1]);
    z[n] = (alpha[n] - h[n-1] * z[n-1]) / l[n];
    c[n] = z[n];

    // Paso 7
    for (int j = n-1; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j+1];
        b[j] = (f[j+1] - f[j]) / h[j] - h[j] * (c[j+1] + 2.0 * c[j]) / 3.0;
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
    double x[] = {27.7, 28, 29, 30};
    double f[] = {4.1, 4.3, 4.1, 3.0};
    double FPO = 0.33 ; 
    double FPN = -1.5 ; 

    // Ejemplo burden
    // double x[] = {0, 1, 2, 3};
    // double f[] = {1, exp(1), pow(exp(1), 2), pow(exp(1), 3)};
    // double FPO = 1 ; 
    // double FPN = 3 ; 


    // Valor de n
    n = sizeof(x) / sizeof(double) - 1; 

    // Size of arreglos
    double a[n+1], b[n], c[n+1], d[n];


    spin3condicionado(n, x, f, FPO, FPN, a, b, c, d);
    
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
    saveMatrixToFile(samples, S_interpolated, points, "Curva3_P3.txt");

    return 0;
}
