
#include <stdio.h>

#define M 3
#define N 3

// Función para encontrar el máximo valor en cada columna y cada renglón
void findMaxInRowsAndCols(int arr[M][N], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        int rowMax = arr[i][0];
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] > rowMax) {
                rowMax = arr[i][j];
            }
        }
        printf("El máximo en el renglón %d es %d\n", i + 1, rowMax);
    }

    for (int j = 0; j < cols; j++) {
        int colMax = arr[0][j];
        for (int i = 1; i < rows; i++) {
            if (arr[i][j] > colMax) {
                colMax = arr[i][j];
            }
        }
        printf("El máximo en la columna %d es %d\n", j + 1, colMax);
    }
}

// Función para contar el número de bytes del arreglo bidimensional con valor 0
int countZeroBytes(int arr[M][N], int rows, int cols) {
    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                count += 4;  // Cada entero está representado por 4 bytes
            }
        }
    }
    return count;
}

int main() {
    // Declaramos un arreglo bidimensional de enteros MxN como ejemplo
    int arr[M][N] = {
        {1, 2, 0},
        {4, 5, 6},
        {7, 0, 9}
    };

    // Encontramos el máximo valor en cada columna y cada renglón
    findMaxInRowsAndCols(arr, M, N);

    // Contamos el número de bytes del arreglo con valor 0
    int zeroBytes = countZeroBytes(arr, M, N);
    printf("Número de bytes con valor 0: %d\n", zeroBytes);

    return 0;
}
