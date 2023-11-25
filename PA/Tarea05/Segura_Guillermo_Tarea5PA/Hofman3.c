# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "Hofman3.h"

// Función para crear un nuevo nodo.
Node* newNode(char character, int frequency) {
    // Reserva memoria para un nuevo nodo.
    Node* node = (Node*)malloc(sizeof(Node));
    // Asigna el carácter y la frecuencia al nodo.
    node->character = character;
    node->frequency = frequency;
    // Inicializa hijos a NULL.
    node->left = node->right = NULL;
    return node;
}

// Función de comparación para qsort.
int compareNodes(const void* a, const void* b) {
    return (*(Node**)a)->frequency - (*(Node**)b)->frequency;
}

Node* buildHuffmanTree(Node* nodes[], int size) {
    // Dos listas para gestionar nodos pendientes y nodos combinados.
    Node* listA[size];
    Node* listB[size];
    int countA = size, countB = 0;

    // Inicialización de las listas.
    for (int i = 0; i < size; i++) {
        listA[i] = nodes[i];
        listB[i] = NULL;
    }

    // Construye el árbol de Huffman combinando nodos.
    while (countA + countB > 1) {
        // Ordenamos ambas listas por frecuencia.
        qsort(listA, countA, sizeof(Node*), compareNodes);
        qsort(listB, countB, sizeof(Node*), compareNodes);

        // Seleccionamos los dos nodos con las menores frecuencias.
        Node *min1, *min2;

        // Elige los dos nodos más pequeños de listA o listB.
        if (countB == 0 || (countA > 1 && listA[1]->frequency < listB[0]->frequency)) {
            min1 = listA[0];
            min2 = listA[1];
            memmove(listA, listA + 2, (countA - 2) * sizeof(Node*));
            countA -= 2;
        } else if (countA == 0 || (countB > 1 && listB[1]->frequency < listA[0]->frequency)) {
            min1 = listB[0];
            min2 = listB[1];
            memmove(listB, listB + 2, (countB - 2) * sizeof(Node*));
            countB -= 2;
        } else {
            min1 = listA[0];
            min2 = listB[0];
            memmove(listA, listA + 1, (countA - 1) * sizeof(Node*));
            memmove(listB, listB + 1, (countB - 1) * sizeof(Node*));
            countA--;
            countB--;
        }

        // Creamos un nodo padre y lo insertamos en listB.
        Node* combined = newNode(0, min1->frequency + min2->frequency);
        combined->left = min1;
        combined->right = min2;
        listB[countB] = combined;
        countB++;
    }

    // El árbol de Huffman está completo y el nodo raíz está en listB[0].
    return listB[0];
}

void generateHuffmanCodes(Node* root, char* code, int depth, int* totalChars, double* expectedCompression) {
    if (!root) return;  // Si el nodo es NULL, simplemente regresa.

    // Si es un nodo hoja (tiene un carácter asociado):
    if (root->character) {
        code[depth] = '\0';  // Termina el código actual.
        // Muestra el carácter y su código Huffman.
        printf("Caracter: %c, Code: %s\n", root->character, code);

        // Calcula la contribución a la compresión.
        double probability = (double) root->frequency / (*totalChars);
        *expectedCompression += probability * depth;
    }

    // Recorre y genera códigos para hijos.
    if (root->left) {
        code[depth] = '0';  // Añade '0' para el subárbol izquierdo.
        generateHuffmanCodes(root->left, code, depth + 1, totalChars, expectedCompression);
    }

    if (root->right) {
        code[depth] = '1';  // Añade '1' para el subárbol derecho.
        generateHuffmanCodes(root->right, code, depth + 1, totalChars, expectedCompression);
    }
}

void freeHuffmanTree(Node* root) {
    if (!root) return;  // Si el nodo es NULL, simplemente regresa.

    // Recursivamente libera subárboles.
    freeHuffmanTree(root->left);   // Libera el subárbol izquierdo.
    freeHuffmanTree(root->right);  // Libera el subárbol derecho.

    free(root);  // Libera el nodo actual.
}
