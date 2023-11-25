
#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura para un nodo de la lista ligada
struct Node {
    int data;  // Valor que almacena el nodo
    struct Node* next;  // Puntero al siguiente nodo en la lista
};

// Función para insertar un nuevo nodo al principio de la lista ligada
void insert(struct Node** head, int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));  // Crear nuevo nodo
    newNode->data = data;  // Asignar el dato al nuevo nodo
    newNode->next = *head;  // Conectar el nuevo nodo al antiguo primero
    *head = newNode;  // Establecer el nuevo nodo como el nuevo primer nodo
}

// Función para eliminar un nodo con un valor específico de la lista ligada
void delete(struct Node** head, int data) {
    struct Node* temp = *head, *prev;  // Inicializar punteros para el nodo actual y el anterior

    // Caso especial: eliminar el nodo principal
    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Cambiar la cabeza de la lista
        free(temp);  // Liberar el nodo eliminado
        return;
    }

    // Buscar el nodo que contiene el dato
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Si el dato no se encuentra, salir de la función
    if (temp == NULL) return;

    // Eliminar el nodo encontrado
    prev->next = temp->next;
    free(temp);
}

// Función para contar el número de nodos en la lista ligada
int countNodes(struct Node* head) {
    int count = 0;  // Inicializar contador de nodos
    struct Node* current = head;  // Nodo actual para la iteración
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Función para buscar un valor específico en la lista ligada
struct Node* search(struct Node* head, int data) {
    struct Node* current = head;  // Nodo actual para la iteración
    while (current != NULL) {
        if (current->data == data) {  // Comprobar si el nodo actual contiene el dato buscado
            return current;  // Retornar el nodo encontrado
        }
        current = current->next;
    }
    return NULL;  // Retornar NULL si el valor no se encuentra
}

// Función para invertir el orden de la lista ligada
void reverse(struct Node** head) {
    struct Node* prev = NULL;  // Nodo previo durante la iteración
    struct Node* current = *head;  // Nodo actual para la iteración
    struct Node* next = NULL;  // Nodo siguiente durante la iteración

    // Revertir las conexiones entre nodos
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;  // Establecer el último nodo como la nueva cabeza de la lista
}

// Función para ordenar los nodos de la lista ligada
void sort(struct Node** head) {
    struct Node* current = *head;  // Nodo actual para la iteración externa
    struct Node* index = NULL;  // Nodo para la iteración interna
    int temp;  // Variable temporal para intercambio

    if (*head == NULL) {
        return;  // Salir si la lista está vacía
    }

    // Algoritmo de ordenación por selección
    while (current != NULL) {
        index = current->next;
        while (index != NULL) {
            if (current->data > index->data) {  // Comparar datos de los nodos
                // Intercambiar los datos
                temp = current->data;
                current->data = index->data;
                index->data = temp;
            }
            index = index->next;  // Mover al siguiente nodo interno
        }
        current = current->next;  // Mover al siguiente nodo externo
    }
}

// Función para imprimir los nodos de la lista ligada
void printList(struct Node* head) {
    struct Node* current = head;  // Nodo actual para la iteración
    while (current != NULL) {
        printf("%d ", current->data);  // Imprimir el valor del nodo actual
        current = current->next;  // Mover al siguiente nodo
    }
    printf("\n");
}

// Función principal para ejecutar el programa
int main() {
    struct Node* head = NULL;  // Inicializar la lista ligada vacía
    int choice, data;  // Variables para almacenar la opción del menú y el dato a operar

    // Bucle infinito para el menú interactivo
    while (1) {
        // Mostrar menú y obtener elección
        printf("\nMenu:\n");
        printf("a. Inserta nodo\n");
        printf("b. Elimina nodo\n");
        printf("c. No. de nodos\n");
        printf("d. Busca valor\n");
        printf("e. Invertir orden\n");
        printf("f. Ordena\n");
        printf("g. Imprime\n");
        printf("h. Fin\n");
        printf("Elige una opcion: ");
        scanf(" %c", &choice);

        // Realizar acción según la elección
        switch (choice) {
            case 'a':
                printf("Introduce el valor a insertar: ");
                scanf("%d", &data);
                insert(&head, data);
                break;
            case 'b':
                printf("Introduce el valor a eliminar: ");
                scanf("%d", &data);
                delete(&head, data);
                break;
            case 'c':
                printf("Numero de nodos: %d\n", countNodes(head));
                break;
            case 'd':
                printf("Introduce el valor a buscar: ");
                scanf("%d", &data);
                if (search(head, data)) {
                    printf("Valor encontrado.\n");
                } else {
                    printf("Valor no encontrado.\n");
                }
                break;
            case 'e':
                reverse(&head);
                break;
            case 'f':
                sort(&head);
                break;
            case 'g':
                printList(head);
                break;
            case 'h':
                return 0;
            default:
                printf("Opcion no valida.\n");
        }
    }
}
