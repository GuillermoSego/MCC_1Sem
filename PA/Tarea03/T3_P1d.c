
#include <stdio.h>
#include <string.h>

// Función para concatenar tres strings en str1
int concatena_str(char* str1Ptr, const char* str2Ptr, const char* str3Ptr, int maxSize) {
    
    // Longitud de la cadena resultante
    int longitud = 0;

    // Guardamos el apuntador original a str1 para verificar superposición
    char* str1_inicio = str1Ptr;

    // Calculamos la longitud actual de str1
    while (*str1Ptr) {
        str1Ptr++;
        longitud++;
    }

    // Verificamos si los strings están superpuestos
    if ((str2Ptr <= str1Ptr && str2Ptr >= str1_inicio) ||
        (str3Ptr <= str1Ptr && str3Ptr >= str1_inicio)) {
        printf("Los strings están superpuestos, no se puede copiar\n");
        return longitud;
    }

    // Añadimos un espacio entre str1 y str2 si str1 no está vacío
    if (longitud > 0 && longitud + 1 < maxSize) {
        *str1Ptr++ = ' ';
        longitud++;
    }

    // Copiamos str2 en str1
    while (*str2Ptr && longitud + 1 < maxSize) {
        *str1Ptr++ = *str2Ptr++;
        longitud++;
    }

    // Añadimos un espacio entre str2 y str3
    if (longitud + 1 < maxSize) {
        *str1Ptr++ = ' ';
        longitud++;
    }

    // Copiamos str3 en str1
    while (*str3Ptr && longitud + 1 < maxSize) {
        *str1Ptr++ = *str3Ptr++;
        longitud++;
    }

    // Añadimos el carácter nulo al final
    *str1Ptr = '\0';

    return longitud;
}

int main() {

    // Declaramos tres cadenas como apuntadores.
    char str1[10] = "Hola";  // Asegúrate de que str1 tenga suficiente espacio
    char* str1Ptr = str1; // Apuntamos a str1
    const char* str2Ptr = "Mundo";
    const char* str3Ptr = "OMG";
    int maxSize = sizeof(str1) / sizeof(char);

    // Concatenamos las cadenas y obtenemos la nueva longitud
    int longitud = concatena_str(str1Ptr, str2Ptr, str3Ptr, maxSize);

    // Imprimimos la cadena resultante y su nueva longitud
    printf("La cadena resultante es: %s\n", str1Ptr);
    printf("La nueva longitud de la cadena es: %d\n", longitud);

    return 0;
}
