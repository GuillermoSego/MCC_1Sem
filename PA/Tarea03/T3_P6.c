
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función que genera N arreglos con dimensiones especificadas en Dim
int** generaArreglos(int N, int *Dim) {
    // Reservamos memoria para N apuntadores a arreglos
    int **arr = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        // Reservamos memoria para cada arreglo individual con su tamaño correspondiente
        arr[i] = (int *)malloc(Dim[i] * sizeof(int));
        for (int j = 0; j < Dim[i]; j++) {
            // Llenamos el arreglo con números aleatorios entre 0 y 99
            arr[i][j] = rand() % 100;
        }
    }
    return arr;
}

// Función que mezcla N arreglos en un solo arreglo ordenado
int* merge(int **arr, int N, int *Dim) {
    int totalSize = 0;
    // Calculamos el tamaño total del arreglo resultante
    for (int i = 0; i < N; i++) {
        totalSize += Dim[i];
    }

    // Reservamos memoria para el arreglo resultante
    int *mergedArray = (int *)malloc(totalSize * sizeof(int));

    int index = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < Dim[i]; j++) {
            // Copiamos los elementos de los arreglos originales en el arreglo resultante
            mergedArray[index++] = arr[i][j];
        }
    }

    // Ordenamos el arreglo resultante usando un algoritmo de ordenación burbuja
    for (int i = 0; i < totalSize; i++) {
        for (int j = i + 1; j < totalSize; j++) {
            if (mergedArray[i] > mergedArray[j]) {
                int temp = mergedArray[i];
                mergedArray[i] = mergedArray[j];
                mergedArray[j] = temp;
            }
        }
    }

    return mergedArray;
}

// Función para imprimir un solo arreglo
void imprimeArreglo(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        // Imprimimos cada elemento del arreglo seguido de un espacio
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Función para imprimir N arreglos
void imprimeArreglos(int **arr, int N, int *Dim) {
    for (int i = 0; i < N; i++) {
        // Llamamos a imprimeArreglo para cada uno de los N arreglos
        imprimeArreglo(arr[i], Dim[i]);
    }
}

int main() {
    srand(time(0));  // Establecemos la semilla para generar números aleatorios

    int N = 3;  // Número de arreglos
    int Dim[] = {5, 3, 4};  // Dimensiones de los arreglos

    // Generamos los arreglos y los imprimimos
    int **arreglos = generaArreglos(N, Dim);
    printf("Arreglos generados:\n");
    imprimeArreglos(arreglos, N, Dim);

    // Mezclamos los arreglos en un solo arreglo ordenado
    int *arregloMezclado = merge(arreglos, N, Dim);

    // Calculamos el tamaño total del arreglo mezclado
    int totalSize = 0;
    for (int i = 0; i < N; i++) {
        totalSize += Dim[i];
    }

    // Imprimimos el arreglo mezclado
    printf("Arreglo mezclado: ");
    imprimeArreglo(arregloMezclado, totalSize);

    // Liberamos la memoria reservada
    for (int i = 0; i < N; i++) {
        free(arreglos[i]);
    }
    free(arreglos);
    free(arregloMezclado);

    return 0;
}
