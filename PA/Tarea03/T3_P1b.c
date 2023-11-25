
#include <stdio.h>

char *copia_str(const char *src, char *dst, int size_dst) {
    char *dst_inicio = dst;  // Guardamos la posición inicial de dst para retornarla al final
    int contador = 0;  // Contador para saber cuántos caracteres hemos copiado

    // Verificamos si los strings están superpuestos
    if (src < dst_inicio + size_dst && src >= dst_inicio) {
        printf("Los strings están superpuestos, no se puede copiar\n");
        return NULL;
    }

    // Copiamos la cadena
    do {
        if (contador >= size_dst) {  // Verificamos si queda espacio en dst
            break;
        }

        // Si llegamos al final de la cadena, escribimos solo nulos
        if (*src == '\0') {
            *dst++ = '\0';
        } else {
            // Copiamos el valor desreferenciado del apuntador
            *dst++ = *src++;
        }

        contador++;
    } while (*src != '\0');

    return dst_inicio;  // Retornamos el inicio del apuntador dst
}

int main() {
    // Declaramos apuntadores a dos cadenas diferentes
    const char *sourcePtr = "Hola mundo!";  // La cadena source de datos constantes

    // La cadena destino tiene solo 15 lugares de memoria
    char destino[15];
    char *destinoPtr = destino;  // Apuntamos al inicio de destino

    // Verificamos si hay suficiente espacio en destino para copiar source
    int size_dst = sizeof(destino) / sizeof(char);

    // Le pasamos los valores de los apuntadores y el tamaño de destino a la función
    if (copia_str(sourcePtr, destinoPtr, size_dst) != NULL) {
        printf("Cadena copiada: %s\n", destino);
    }

    return 0;
}
