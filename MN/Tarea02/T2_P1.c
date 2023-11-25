
# include <stdio.h>
# include <math.h>

// Funcion para calcular el numero e
double exponencial( int k ){

    // Calcula n
    int n = pow(10, k); 

    // Declaramos el valor donde guardaremos e
    double e;

    // Calculamos e por la formula del limite
    e = pow(1.0 + 1.0 / (double)n, n);

    return e;
}

int main(){

    int k;
    double exp_calculado, valor, error_absoluto, error_relativo;

    valor = exp(1.0);  // El valor verdadero de e

    k = 2;

    exp_calculado = exponencial(k);

    // Calculo del error absoluto
    error_absoluto = fabs(exp_calculado - valor);

    // Calculo del error relativo
    error_relativo = error_absoluto / valor;

    printf("Valor de k: %d\n", k);
    printf("Valor del exponencial calculado: %.15lf\n", exp_calculado);
    printf("Valor del exponencial por math.h: %.15lf\n", valor);
    printf("Error absoluto: %.15lf\n", error_absoluto);
    printf("Error relativo: %.15lf\n", error_relativo);

    return 0;
}
