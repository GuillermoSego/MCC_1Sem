
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

double Taylor(double* derivadas, double x0, double z, int n) {
    double resultado = 0.0;

    for (int i = 0; i < n; i++) {
        resultado += (derivadas[i] * pow((z - x0), i)) / factorial(i);
    }

    return resultado;
}

int main() {
    double x0, z;
    int n;

    printf("Introduce el punto x0 donde está centrado el polinomio de Taylor: ");
    scanf("%lf", &x0);

    printf("Introduce el punto z donde se quiere evaluar el polinomio: ");
    scanf("%lf", &z);   

    printf("Introduce el grado n del polinomio de Taylor: ");
    scanf("%d", &n);

    double* nprimes = malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        printf("Introduce la derivada %d: ", i + 1);
        scanf("%lf", &nprimes[i]);
    }

    double valorAproximado = Taylor(nprimes, x0, z, n);
    printf("El valor de Pn(%lf) es: %lf\n", z, valorAproximado);

    // Liberar memoria
    free(nprimes);

    return 0;
}
