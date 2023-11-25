
#include <stdio.h>

// Función que compara lexicográficamente dos cadenas
int compara_str(const char* str1Ptr, const char* str2Ptr) {

    // Recorremos ambas cadenas hasta que encontremos un carácter nulo en alguna de ellas
    while (*str1Ptr != '\0' && *str2Ptr != '\0') {

        // Si los caracteres en las posiciones actuales son diferentes, retornamos la diferencia
        /* Todos los caracteres en la computadora corresponden a 1 byte de memoria, cuando
        el valor de un caracter se maneja como entero, podemos hacer operaciones normales de enteros
        Al retornar el valor de la diferencia en entero estamos comparand las cadenas */
        if (*str1Ptr != *str2Ptr) {
            return (int)(*str1Ptr - *str2Ptr);
        }

        str1Ptr++;
        str2Ptr++;
    }

    // Al salir del bucle, uno o ambos strings han llegado al final
    // Retornamos la diferencia de los últimos caracteres comparados
    return (int)(*str1Ptr - *str2Ptr);
}

int main() {

    /* Declaramos dos cadenas como apuntadores
    Como solo vamos a comparar los datos declaramos apuntadores no constantes a 
    datos constantes  */
    const char* str1Ptr = "Jose el padrino";
    const char* str2Ptr = "Comparacion";

    // Llamamos a la función para comparar las cadenas y almacenamos el resultado en n
    int n = compara_str(str1Ptr, str2Ptr);

    // Evaluamos el resultado de la comparación para imprimir el mensaje correspondiente
    if (n == 0) {
        printf("La cadena str1: \"%s\", es igual a la cadena \"%s\"\n", str1Ptr, str2Ptr);
    } else if (n > 0) {
        printf("La cadena str1: \"%s\", es mayor que la cadena \"%s\"\n", str1Ptr, str2Ptr);
    } else {
        printf("La cadena str1: \"%s\", es menor que la cadena \"%s\"\n", str1Ptr, str2Ptr);
    }

    return 0;
}
