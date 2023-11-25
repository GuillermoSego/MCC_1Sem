
#include <stdio.h>
#include <stdlib.h> 

// Función para encontrar la frecuencia de cada caracter en un string
int **frecuencia(const char *str, int *len) {

    // Reservamos memoria para el array bidimensional
    int **frecuencias = (int **)malloc(128 * sizeof(int *));
    for (int i = 0; i < 128; ++i) {
        frecuencias[i] = (int *)malloc(2 * sizeof(int));
        frecuencias[i][0] = i;  // Código ASCII del caracter
        frecuencias[i][1] = 0;  // Frecuencia inicializada a 0
    }

    // Calculamos la frecuencia de cada caracter en el string
    int index = 0;
    while (str[index] != '\0') {
        int ascii_val = (int)str[index];
        frecuencias[ascii_val][1]++;  // Incrementamos la frecuencia
        index++;
    }

    // Contamos el número de caracteres únicos encontrados
    int unique_count = 0;
    for (int i = 0; i < 128; i++) {
        if (frecuencias[i][1] > 0) {
            unique_count++;
        }
    }

    // Actualizamos la longitud para el caller
    *len = unique_count;

    return frecuencias;
}

int main() {
    // Declaramos el string como un apuntador a datos constantes
    const char *str = "wwwwrrrrssssrrrrwwwwrrr";

    // Variable para almacenar la longitud del arreglo resultado
    int len = 0;

    // Llamamos a la función frecuencia
    int **result = frecuencia(str, &len);

    // Imprimimos el resultado
    printf("Salida:\n");
    for (int i = 0; i < 128; i++) {
        if (result[i][1] > 0) {
            printf("%c - %d, ", result[i][0], result[i][1]);
        }
    }
    printf("\n");

    // Liberamos la memoria reservada
    for (int i = 0; i < 128; i++) {
        free(result[i]);
    }
    free(result);

    return 0;
}
