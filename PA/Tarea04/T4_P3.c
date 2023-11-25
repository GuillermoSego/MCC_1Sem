
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

struct Node {
    int data;
    struct Node* next;
};

// Inserta un nodo en una lista ligada ordenada y devuelve la nueva cabeza
struct Node* insertSorted(struct Node* head, int data) {
    // Crear un nuevo nodo y asignar los datos
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // Caso base: la lista está vacía o el nuevo nodo es menor que el nodo cabeza
    if (head == NULL || head->data >= data) {
        newNode->next = head;
        return newNode;
    }

    // Inicializar la variable para recorrer la lista
    struct Node* current = head;
    // Buscar la posición correcta para insertar el nuevo nodo
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insertar el nuevo nodo en la posición correcta
    newNode->next = current->next;
    current->next = newNode;

    return head;
}

// Mezcla N listas ligadas ordenadas en una sola lista ligada ordenada
struct Node* merge(struct Node** listas, int N, int* Dim) {
    // Inicializar la lista ligada que almacenará el resultado
    struct Node* mergedList = NULL;

    // Iterar sobre todas las listas ligadas dadas
    for (int i = 0; i < N; ++i) {
        struct Node* current = listas[i];
        // Insertar todos los elementos de la lista actual en la lista de resultados
        while (current != NULL) {
            mergedList = insertSorted(mergedList, current->data);
            current = current->next;
        }
    }

    // Devolver la cabeza de la lista de resultados
    return mergedList;
}

// Imprimir todos los elementos de una lista ligada
void imprimeLista(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Función para liberar la memoria de una lista ligada
void freeList(struct Node* head) {
    struct Node* temp;
    // Iterar sobre todos los nodos y liberar la memoria
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Genera N listas ligadas con dimensiones específicas en Dim
struct Node** generaListas(int N, int* Dim) {
    // Reservar memoria para los apuntadores de las listas
    struct Node** listas = malloc(N * sizeof(struct Node*));

    // Crear cada lista ligada
    for (int i = 0; i < N; ++i) {
        struct Node* head = NULL;
        // Insertar elementos aleatorios en la lista actual
        for (int j = 0; j < Dim[i]; ++j) {
            head = insertSorted(head, rand() % 100);
        }
        // Almacenar la cabeza de la lista en el arreglo de listas
        listas[i] = head;
    }

    return listas;
}


int main() {
    // Inicializamos la semilla para generar números aleatorios
    srand(time(0));

    // Número de listas ligadas y dimensiones de cada lista
    int N = 3;
    int Dim[] = {5, 3, 4};

    // Generamos las listas ligadas y almacenamos sus cabezas en un arreglo
    struct Node** listas = generaListas(N, Dim);

    // Imprimimos las listas ligadas generadas
    printf("Listas ligadas generadas:\n");
    for (int i = 0; i < N; ++i) {
        imprimeLista(listas[i]);
    }

    // Mezclamos todas las listas ligadas en una nueva lista ligada
    struct Node* listaMezclada = merge(listas, N, Dim);

    // Imprimimos la lista ligada resultante
    printf("Lista ligada mezclada: ");
    imprimeLista(listaMezclada);

    // Liberamos la memoria de cada lista ligada generada
    for (int i = 0; i < N; ++i) {
        freeList(listas[i]);
    }

    // Liberamos la memoria del arreglo que almacena las listas
    free(listas);

    // Liberamos la memoria de la lista ligada mezclada
    freeList(listaMezclada);

    return 0;
}

