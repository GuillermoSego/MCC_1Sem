
# include <stdio.h>
# include <stdlib.h>
# include "STRuct.h"

// Menú principal
int main() {
    printf("Ingrese el tamaño inicial de la tabla Hash: ");
    int size;
    scanf("%d", &size);

    struct HashTable* hashTable = createHashTable(size);

    int option, data;
    while (1) {
        printf("\nMenú:\n");
        printf("1. Insertar Nodo\n");
        printf("2. Imprimir Tabla en orden\n");
        printf("3. Desplegar el índice y árbol con mayor profundidad\n");
        printf("4. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Ingrese el dato a insertar: ");
                scanf("%d", &data);
                insert(hashTable, data);
                break;
            case 2:
                printHashTable(hashTable);
                break;
            case 3:
                deepestTree(hashTable);
                break;
            case 4:
                printf("Saliendo...\n");
                return 0;  // Finalizar programa
            default:
                printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    }

    free(hashTable->table);
    free(hashTable);
    return 0;
}