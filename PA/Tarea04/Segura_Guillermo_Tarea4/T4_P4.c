
#include <stdio.h>
#include <stdlib.h>

// Definición del nodo para la lista ligada
struct Node {
    int data;             
    struct Node* next;     
};

// Definición de la tabla de hash
struct HashTable {
    struct Node** table;   
    int size;             
};

// Crear una nueva tabla de hash con 'size' cubetas
struct HashTable* createHashTable(int size) {
    struct HashTable* newTable = (struct HashTable*) malloc(sizeof(struct HashTable));  // Reservar memoria para la tabla
    newTable->table = (struct Node**) malloc(sizeof(struct Node*) * size);  // Reservar memoria para el arreglo de apuntadores
    newTable->size = size;  // Establecer el tamaño de la tabla
    for (int i = 0; i < size; ++i) {
        newTable->table[i] = NULL;  // Inicializar todas las cubetas como vacías (NULL)
    }
    return newTable;
}

// Función hash simple: residuo de la división
int hashFunction(int key, int tableSize) {
    return key % tableSize;  // Devolver el índice de la cubeta correspondiente al valor de la clave
}

// Insertar un elemento en la tabla de hash
void insert(struct HashTable* table, int data) {
    int index = hashFunction(data, table->size);  // Obtener el índice de la cubeta donde insertar
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  // Crear nuevo nodo
    newNode->data = data;  // Asignar el valor al nuevo nodo
    newNode->next = table->table[index];  // Establecer el siguiente nodo como el que estaba en la cubeta
    table->table[index] = newNode;  // Actualizar el inicio de la lista de la cubeta
}

// Buscar un elemento en la tabla de hash
struct Node* search(struct HashTable* table, int data) {
    int index = hashFunction(data, table->size);  // Obtener el índice de la cubeta donde buscar
    struct Node* current = table->table[index];  // Inicializar apuntador al inicio de la lista en la cubeta
    while (current != NULL) {  // Recorrer la lista
        if (current->data == data) {  // Si se encuentra el dato
            return current;
        }
        current = current->next;  // Avanzar al siguiente nodo
    }
    return NULL;  // Si no se encuentra el dato, devolver NULL
}

// Imprimir la tabla de hash
void printHashTable(struct HashTable* table) {
    for (int i = 0; i < table->size; ++i) {  // Iterar sobre todas las cubetas
        struct Node* current = table->table[i];  // Apuntador al inicio de la lista en la cubeta actual
        printf("Cubeta %d: ", i);  // Imprimir índice de la cubeta
        while (current != NULL) {  // Recorrer la lista en la cubeta
            printf("%d -> ", current->data);  // Imprimir cada elemento
            current = current->next;  // Avanzar al siguiente nodo
        }
        printf("NULL\n");  // Indicar el final de la lista en la cubeta
    }
}

// Programa principal
int main() {
    struct HashTable* hashTable = createHashTable(10);  // Crear una tabla de hash con 10 cubetas
    
    // Insertar algunos elementos
    insert(hashTable, 1);
    insert(hashTable, 11);
    insert(hashTable, 21);
    insert(hashTable, 31);
    insert(hashTable, 22);
    
    // Imprimir la tabla de hash
    printf("Tabla de hash:\n");
    printHashTable(hashTable);

    // Buscar elementos
    int searchKey = 11;  // Clave a buscar
    struct Node* result = search(hashTable, searchKey);  // Realizar la búsqueda
    if (result != NULL) {
        printf("Elemento %d encontrado.\n", searchKey);  // Elemento encontrado
    } else {
        printf("Elemento %d no encontrado.\n", searchKey);  // Elemento no encontrado
    }

    return 0;
}
