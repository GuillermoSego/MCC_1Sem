
/*

Biblioteca para manejo de estructuras

*/

# include <stdio.h>
# include <stdlib.h>
# include "STRuct.h"

// Crear nodo para el árbol
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insertar en el árbol de forma recursiva
struct TreeNode* insertTreeNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createTreeNode(data);
    }
    if (data < root->data) {
        root->left = insertTreeNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertTreeNode(root->right, data);
    }
    return root;
}

// Crear una tabla de Hash
struct HashTable* createHashTable(int size) {
    struct HashTable* newTable = (struct HashTable*) malloc(sizeof(struct HashTable));
    newTable->table = (struct TreeNode**) malloc(sizeof(struct TreeNode*) * size);
    newTable->size = size;
    for (int i = 0; i < size; i++) {
        newTable->table[i] = NULL;
    }
    return newTable;
}

// Función Hash
int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

// Insertar en la tabla de Hash
void insert(struct HashTable* table, int data) {
    int index = hashFunction(data, table->size);
    table->table[index] = insertTreeNode(table->table[index], data);
}

// Imprimir árbol en orden
void inorder(struct TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

// Imprimir tabla Hash
void printHashTable(struct HashTable* table) {
    for (int i = 0; i < table->size; i++) {
        printf("Cubeta %d: ", i);
        inorder(table->table[i]);
        printf("NULL\n");
    }
}

// Obtener profundidad del árbol
int depth(struct TreeNode* node) {
    if (node == NULL) {
        return 0;
    } else {
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);

        if (leftDepth > rightDepth) {
            return(leftDepth + 1);
        } else {
            return(rightDepth + 1);
        }
    }
}

// Obtener índice y árbol con mayor profundidad
void deepestTree(struct HashTable* table) {
    int maxDepth = -1;
    int index = -1;
    for (int i = 0; i < table->size; i++) {
        int currentDepth = depth(table->table[i]);
        if (currentDepth > maxDepth) {
            maxDepth = currentDepth;
            index = i;
        }
    }
    printf("Árbol con mayor profundidad está en el índice %d con profundidad de %d.\n", index, maxDepth);
}