
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para inicializar la matriz
void inicializarMatriz(char matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = '.';
        }
    }
}

// Función para imprimir la matriz
void imprimirMatriz(char matriz[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Función para realizar la caminata aleatoria
void caminataAleatoria(char matriz[10][10]) {
    int x = 0, y = 0, direccion;
    char letra = 'A';

    // Punto de partida
    matriz[x][y] = letra++;

    // Generamos la semilla para números aleatorios
    srand(time(NULL));

    while (letra <= 'Z') {
        int intentos = 0;
        int bloqueado = 1;  // Bandera para verificar si estamos bloqueados (1 = true, 0 = false)

        while (intentos < 4) {
            direccion = rand() % 4;  // Generamos un número aleatorio entre 0 y 3

            int nuevaX = x, nuevaY = y;

            // Actualizamos las coordenadas según la dirección
            switch (direccion) {
                case 0: nuevaX = x - 1; break;  // Arriba
                case 1: nuevaX = x + 1; break;  // Abajo
                case 2: nuevaY = y - 1; break;  // Izquierda
                case 3: nuevaY = y + 1; break;  // Derecha
            }

            // Verificamos que no nos salimos de la matriz y que no visitamos el mismo lugar
            if (nuevaX >= 0 && nuevaX < 10 && nuevaY >= 0 && nuevaY < 10 && matriz[nuevaX][nuevaY] == '.') {
                x = nuevaX;
                y = nuevaY;
                matriz[x][y] = letra++;
                bloqueado = 0;  // Marcamos que no estamos bloqueados
                break;
            } else {
                intentos++;  // Incrementamos el número de intentos fallidos
            }
        }

        // Si estamos bloqueados, terminamos la caminata
        if (bloqueado) {
            break;
        }
    }
}

int main() {
    char matriz[10][10];

    // Inicializamos la matriz
    inicializarMatriz(matriz);

    // Realizamos la caminata aleatoria
    caminataAleatoria(matriz);

    // Imprimimos la matriz
    imprimirMatriz(matriz);

    return 0;
}
