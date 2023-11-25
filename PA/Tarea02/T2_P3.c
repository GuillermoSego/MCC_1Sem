
# include <stdio.h>
# include <math.h>

// Funcion para escribir un numero al reves
int reves(int num, int length) {

    // Declaramos las variables
    // La variable new va guardando el nuevo numero al reves
    /* La variable exp tiene el exponente al cual tenemos que elevar 
    un numero para sumar el nuevo numero */
    int i = 0, new = 0;

    do {

        /* Vamos calculando los ultimos digitos y guardandolos en una 
        nueva variable */
        new = (num % 10) + new * 10;

        // Quitamos el ultimo digito del num
        num = num/10;

        i ++;

    } while (i<length);

    return new;
}

int main(){

    // Declaramos las variables
    int num, length, new;

    // Pruebas
    // num = 454;

    // Se escanea el numero
    printf("Introduce un numero\n");
    scanf("%d", &num);

    // Calculamos la longitud del numero
    length = log10(num) + 1;

    // Calculamos el numero al reves con la funcion
    new = reves(num, length);

    // Imprimimos el numero
    printf("El numero al reves es: %d\n", new);

    // Se verifica el palindromo
    if (num == new){
        printf("El numero es un palindromo");
    } else{
        printf("El numero no es un palindromo");
    }
    

    return 0;
}