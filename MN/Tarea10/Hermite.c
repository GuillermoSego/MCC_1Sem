# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void calculaDiferenciasDivididasHermite(int n, double x[], double z[], double f[], double fp[], double **F) {
    int zlen = 2*n; 

    // Duplicamos los puntos x y f(x)
    for (int i = 0, j = 0; i < n; i++, j+=2) {
        z[j] = x[i];
        z[j+1] = x[i];

        F[j][0] = f[i];
        F[j+1][0] = f[i];
    }

    // Llenamos la fila de las derivadas (2da columna de F)
    for (int i = 1; i < zlen; i++) {
        if (i % 2 == 0) {
            F[i][1] = (F[i][0] - F[i-1][0]) / (z[i] - z[i-1]);
        } else {
            F[i][1] = fp[i/2];
        }
    }

    // Llenamos las demás columnas de F
    for (int j = 2; j < zlen; j++) {
        for (int i = j; i < zlen; i++) {
            F[i][j] = (F[i][j-1] - F[i-1][j-1]) / (z[i] - z[i-j]);
        }
    }

    // Imprimir la tabla
    for (int i = 0; i < zlen; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%.5lf ", F[i][j]);
        }
        printf("\n");
    }
}

double interpolacionNewtonHermite(int n, double z[], double **F, double valorX) {
    int zlen = 2*n;
    double resultado = F[0][0];
    double terminoPolinomio = 1.0;

    for (int i = 1; i < zlen; i++) {
        terminoPolinomio *= (valorX - z[i-1]);
        resultado += (terminoPolinomio * F[i][i]);
    }

    return resultado;
}

int main() {
    int n; 

    printf("Ingrese el número de puntos n: ");
    scanf("%d", &n);

    double *x = (double *)malloc(n * sizeof(double));
    double *f = (double *)malloc(n * sizeof(double));
    double *fp = (double *)malloc(n * sizeof(double));  
    double **F = (double **)malloc(2*n * sizeof(double *));
    double *z = (double *)malloc(2*n * sizeof(double));

    for (int i = 0; i < 2*n; i++) {
        F[i] = (double *)malloc(2*n * sizeof(double));
    }

    printf("Ingrese los valores de x, f(x) y f'(x):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%lf", &x[i]);
        printf("f[%d] = ", i);
        scanf("%lf", &f[i]);
        printf("f'[%d] = ", i);
        scanf("%lf", &fp[i]);
    }

    double valorX;
    printf("Ingrese el valor de x para interpolar: ");
    scanf("%lf", &valorX);

    calculaDiferenciasDivididasHermite(n, x, z, f, fp, F);
    double resultado = interpolacionNewtonHermite(n, z, F, valorX);
    printf("El valor interpolado en x = %.7lf es: %.7lf\n", valorX, resultado);

    // Caso sin(x)
    // Calculamos el error absoluto
    double valor_real = sin(0.34);

    printf("El error absoluto de la aproximación de sin(0.34) es: %.9lf", fabs(valor_real - resultado));

    free(x);
    free(f);
    free(fp);
    free(z);
    for (int i = 0; i < 2*n; i++) {
        free(F[i]);
    }
    free(F);

    return 0;
}
