
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función que separa un string en tokens basados en un carácter especial
char **tokens(char *str, char ch) {
    // Contamos cuántos tokens tenemos
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    count++;  // Agregamos uno más para el último token

    // Si no hay tokens, regresamos NULL
    if (count == 0) {
        return NULL;
    }

    // Reservamos memoria para los apuntadores a los tokens
    char **result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }

    // Inicializamos el primer token
    result[0] = str;
    int j = 1;

    // Separamos los tokens
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            str[i] = '\0';
            result[j] = str + i + 1;
            j++;
        }
    }

    // Terminamos el arreglo con NULL para saber dónde acaba
    result[j] = NULL;

    return result;
}

int main() {
    char str[] = "Hola/mundo/soy/un/arbol";
    char ch = '/';

    // Obtenemos los tokens
    char **result = tokens(str, ch);

    // Imprimimos los tokens
    if (result != NULL) {
        printf("Tokens separados por '%c':\n", ch);
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
        }
    } else {
        printf("No se encontraron tokens.\n");
    }

    // Liberamos la memoria
    free(result);

    return 0;
}
