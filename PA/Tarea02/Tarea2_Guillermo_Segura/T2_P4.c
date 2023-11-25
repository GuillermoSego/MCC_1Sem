
# include <stdio.h>
# include <math.h>

// Funcionq ue calcula el factorial de un numero
float factorial ( float n ){

    float f = 1;

     while (n > 0) {

        f *= n;
        n --;
    } 

    return f;
}

// Funcion que calcula el cos(x)
float coseno(float x, int n, float epsilon) {
    int i = 0;
    float result = 0, term, anterior = 0;

    while (i < n) {
        // Calculamos el valor del cos y lo sumamos a acumulado
        term = (pow(-1, i) * pow(x, 2 * i)) / factorial(2 * i);
        result += term;
        
        // Checamos si el valor es menor al epsilon
        if (fabs(result - anterior) < epsilon) {
            printf("Iteraciones: %d\n", i);
            break;
        }

        anterior = result;
        i++;
    }
    return result;
}

int main(){

    // Declaramos las variables
    float x, epsilon, value;
    int num;

    // Solicitamos los parámetros
    printf("Introduce el valor del cos(x): ");
    scanf("%f", &x);
    printf("Introduce el número de iteraciones: ");
    scanf("%d", &num);
    printf("Introduce el valor del epsilon: ");
    scanf("%f", &epsilon);

    // Encontramos el valor del coseno
    value = coseno(x, num, epsilon);

    printf("cos(x) = %f", value);

    return 0;
}