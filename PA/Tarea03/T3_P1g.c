
#include <stdio.h>

// Función para encontrar e imprimir palabras en la cadena que no tengan letras repetidas
void sin_repeBr(const char *str) {
    
    char resultado[256];  // Array para almacenar las palabras sin repetición
    char *resultadoPtr = resultado;
    const char *inicioPalabra = str;  // Apuntador para marcar el inicio de cada palabra
    char letras[26] = {0};  // Array para almacenar la frecuencia de cada letra en una palabra
    
    // Bandera para marcar si una palabra tiene letras repetidas (0 = false, 1 = true)
    int repetido = 0;  
    
    while (*str) {
        
        // Reiniciamos las frecuencias de las letras
        for (int i = 0; i < 26; i++) {
            letras[i] = 0;
        }
        
        repetido = 0;  // Reiniciamos la bandera
        
        // Procesamos cada palabra
        while (*str && *str != ' ') {
            
            // Solo procesamos letras minúsculas
            if (*str >= 'a' && *str <= 'z') {
                letras[*str - 'a']++;
                
                // Si una letra aparece más de una vez, marcamos la palabra como repetida
                if (letras[*str - 'a'] > 1) {
                    repetido = 1;
                }
            }
            
            str++;
        }
        
        // Si la palabra no tiene letras repetidas, la imprimimos
        if (!repetido) {
            while (inicioPalabra < str) {
                printf("%c", *inicioPalabra++);
            }
            printf(" ");  // Separamos palabras con espacios
        }
        
        // Si encontramos un espacio, nos preparamos para la siguiente palabra
        if (*str == ' ') {
            inicioPalabra = ++str;
        }
    }
    
    printf("\n");  // Añadimos un salto de línea al final
}

int main() {
    
    const char *testStr = "hola mundo repetido";
    
    // Llamamos a la función
    printf("Palabras sin repetición: ");
    sin_repeBr(testStr);
    
    return 0;
}
