
#include <stdio.h>

// Función que busca un sub-string str1 en str2 y regresa el número de veces que lo encuentra
int encuentra_str(const char* str1, const char* str2) {
    
    // Contador para el número de apariciones
    int count = 0;
    
    // Longitud de str1 y str2
    int len_str1 = 0, len_str2 = 0;

    // Calculamos la longitud de str1
    while (str1[len_str1] != '\0') {
        len_str1++;
    }

    // Calculamos la longitud de str2
    while (str2[len_str2] != '\0') {
        len_str2++;
    }

    // Verificamos si str1 o str2 están vacíos
    if (len_str1 == 0 || len_str2 == 0) {
        printf("Uno de los strings está vacío, regresando 0\n");
        return 0;
    }

    // Iteramos a través de cada caracter en str2
    for (int i = 0; i <= len_str2 - len_str1; i++) {
        
        // Variable para comprobar si el substring coincide
        int isMatch = 1;

        // Comparamos el substring de str2 con str1
        for (int j = 0; j < len_str1; j++) {
            if (str1[j] != str2[i + j]) {
                isMatch = 0;
                break;
            }
        }

        if (isMatch) {
            count++;  // Incrementamos el contador si encontramos una coincidencia
            i += len_str1 - 1;  // Avanzamos en str2 para evitar superposición de coincidencias
        }
    }

    return count;
}

int main() {

    // Declaramos dos cadenas como apuntadores a datos constantes
    const char* str1 = "hola";
    const char* str2 = "holamundo hola mundo holahola";

    // Llamamos a la función encuentra_str y guardamos el resultado en una variable
    int numero_de_veces = encuentra_str(str1, str2);

    printf("El sub-string '%s' aparece %d veces en '%s'\n", str1, numero_de_veces, str2);

    return 0;
}
