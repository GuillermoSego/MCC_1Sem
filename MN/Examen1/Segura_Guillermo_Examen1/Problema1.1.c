
/*

Guillermo Segura Gómez. 16 de octubre de 2023
Primer examen parcial. Problema 1.1

*/

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
    double exp_calculados[20];  // Almacena los valores calculados de e para diferentes k

    valor = exp(1.0);  // El valor verdadero de e


    // Utilizamos el contador del for como el valor de k para llamar la función y aproximar e
    for (int k = 1; k <= 20; k++) {
        exp_calculados[k - 1] = exponencial(k); // Calcula e para k = 1, 2, ..., 20 y almacena en exp_calculados
    }

    // Imprime la tabla
    printf("------------------------------------------------------------------\n");
    printf("|    k    |     e calculado    |  Error absoluto | Error relativo |\n");
    printf("------------------------------------------------------------------\n");

    // Calculamos los errores en un ciclo for y los vamos imprimiendo para no tener que almacenarlos
    for (int k = 1; k <= 20; k++) {
        // Calculo del error absoluto
        error_absoluto = fabs(exp_calculados[k - 1] - valor);

        // Calculo del error relativo
        error_relativo = error_absoluto / valor;

        printf("| %7d | %17.15lf | %15.15lf | %14.15lf |\n", k, exp_calculados[k - 1], error_absoluto, error_relativo);
    }

    printf("--------------------------------------------------------------------\n");

   return 0;
}
