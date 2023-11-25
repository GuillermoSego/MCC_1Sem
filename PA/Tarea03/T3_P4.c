
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para crear el arreglo de apuntadores para los nombres
char **crea_arreglo(int n) {
    // Reservamos memoria para 'n' apuntadores a char
    char **arr = (char **)malloc(n * sizeof(char *));
    if (arr == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    return arr;
}

// Función para llenar el arreglo con nombres
void llena_arreglo(char **arr, int n) {
    char buffer[100];  // Buffer temporal para leer cada nombre
    for (int i = 0; i < n; i++) {
        printf("Introduce el nombre %d: ", i + 1);
        scanf("%s", buffer);

        // Reservamos memoria justa para el nombre actual
        arr[i] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
        if (arr[i] == NULL) {
            printf("Error al asignar memoria.\n");
            exit(1);
        }

        // Copiamos el nombre al arreglo
        strcpy(arr[i], buffer);
    }
}

// Función para ordenar los nombres alfabéticamente
void ordena(char **arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                // Intercambiamos los apuntadores si están fuera de orden
                char *temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Función para liberar la memoria
void libera_arreglo(char **arr, int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main() {
    int n;

    // Pide al usuario el número de nombres
    printf("Introduce el número de nombres: ");
    scanf("%d", &n);

    // Creamos y llenamos el arreglo de nombres
    char **arr = crea_arreglo(n);
    llena_arreglo(arr, n);

    // Ordenamos los nombres
    ordena(arr, n);

    // Mostramos los nombres ordenados
    printf("Nombres ordenados:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    // Liberamos la memoria
    libera_arreglo(arr, n);

    return 0;
}
