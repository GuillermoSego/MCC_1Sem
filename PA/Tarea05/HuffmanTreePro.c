
# include <stdio.h>
# include <ctype.h>  // para tolower y isalpha
# include <stdlib.h>

// Estructura para un nodo del árbol de Huffman.
typedef struct Node {
    char character;         // Caracter representado por el nodo.
    unsigned frequency;     // Frecuencia del caracter.
    struct Node *left, *right;  // Hijos izquierdo y derecho.
} Node;

// Estructura para la cola de prioridad (min-heap).
typedef struct {
    Node** array;  // Arreglo de punteros a nodos.
    int count;     // Número actual de nodos en el heap.
    int capacity;  // Capacidad total del heap.
} PriorityQueue;

// Definición de la estructura para la frecuencia del carácter.
typedef struct {
    char character;
    int frequency;
} CharFrequency;

CharFrequency freqTable[256] = {0};  // Inicializar con ceros


// Funciones auxiliares para el manejo de la cola de prioridad
int getParentIndex(int i) { return (i - 1) / 2; }
int getLeftChildIndex(int i) { return (2 * i) + 1; }
int getRightChildIndex(int i) { return (2 * i) + 2; }
int isLeaf(PriorityQueue* pq, int i) { return getLeftChildIndex(i) >= pq->count; }
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Función para crear una cola de prioridad con capacidad dada.
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->array = (Node**)malloc(capacity * sizeof(Node*));
    pq->count = 0;
    pq->capacity = capacity;
    return pq;
}

// Función para insertar un nodo en la cola de prioridad.
void insert(PriorityQueue* pq, Node* newNode) {
    if (pq->count == pq->capacity) {
        return;  // La cola de prioridad está llena.
    }

    int i = pq->count;
    pq->array[i] = newNode;
    pq->count++;

    while (i && pq->array[i]->frequency < pq->array[getParentIndex(i)]->frequency) {
        swap(&pq->array[i], &pq->array[getParentIndex(i)]);
        i = getParentIndex(i);
    }
}

// Función para extraer el nodo con la menor frecuencia de la cola de prioridad.
Node* extractMin(PriorityQueue* pq) {
    if (pq->count == 0) {
        return NULL;  // La cola de prioridad está vacía.
    }

    Node* min = pq->array[0];
    pq->count--;
    pq->array[0] = pq->array[pq->count];

    int i = 0;
    while (!isLeaf(pq, i)) {
        if (pq->array[i]->frequency > pq->array[getLeftChildIndex(i)]->frequency ||
            (getRightChildIndex(i) < pq->count && pq->array[i]->frequency > pq->array[getRightChildIndex(i)]->frequency)) {

            if (getRightChildIndex(i) < pq->count && pq->array[getRightChildIndex(i)]->frequency < pq->array[getLeftChildIndex(i)]->frequency) {
                swap(&pq->array[i], &pq->array[getRightChildIndex(i)]);
                i = getRightChildIndex(i);
            } else {
                swap(&pq->array[i], &pq->array[getLeftChildIndex(i)]);
                i = getLeftChildIndex(i);
            }
        } else {
            break;  // El heap ya está en orden.
        }
    }

    return min;
}

// Función para crear un nuevo nodo.
Node* newNode(char character, unsigned frequency) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->left = temp->right = NULL;
    temp->character = character;
    temp->frequency = frequency;
    return temp;
}

// Función para construir el árbol de Huffman.
Node* buildHuffmanTree() {
    Node *left, *right, *top;

    // Determinar cuántos caracteres tienen frecuencias no nulas para saber la capacidad inicial de la cola.
    int size = 0;
    for (int i = 0; i < 256; i++) {
        if (freqTable[i].frequency > 0) {
            size++;
        }
    }

    // Crea una cola de prioridad mínima.
    PriorityQueue* pq = createPriorityQueue(size);

    // Crea un nodo para cada caracter con frecuencia no nula y lo inserta en la cola de prioridad.
    for (int i = 0; i < 256; i++) {
        if (freqTable[i].frequency > 0) {
            insert(pq, newNode(freqTable[i].character, freqTable[i].frequency));
        }
    }

    // Itera mientras el tamaño de la cola no sea 1.
    while (pq->count != 1) {
        // Extrae los dos nodos de menor frecuencia.
        left = extractMin(pq);
        right = extractMin(pq);

        // Crea un nuevo nodo interno con estos dos nodos como hijos y con una
        // frecuencia igual a la suma de sus frecuencias. Inserta este nodo en la cola.
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insert(pq, top);
    }

    // El árbol de Huffman se construye y el nodo raíz es el único nodo en la cola.
    return extractMin(pq);
}

void generateHuffmanCodes(Node* root, char* currentCode, int index) {
    if (!root) {
        return;
    }

    // Si es un nodo hoja (tiene un carácter asociado), muestra el carácter y su código.
    if (root->character != '$') {
        currentCode[index] = '\0';  // Termina la cadena actual.
        printf("%c: %s\n", root->character, currentCode);
        return;
    }

    // Si no es un nodo hoja, continúa explorando.

    // Añade un '0' para el hijo izquierdo y explora.
    currentCode[index] = '0';
    generateHuffmanCodes(root->left, currentCode, index + 1);

    // Añade un '1' para el hijo derecho y explora.
    currentCode[index] = '1';
    generateHuffmanCodes(root->right, currentCode, index + 1);
}

// Función para iniciar la generación y mostrar códigos.
void buildAndShowHuffmanCodes(Node* huffmanTree) {
    char code[256];
    generateHuffmanCodes(huffmanTree, code, 0);
}


int main() {
    // Leer el archivo en bloques:
    FILE *file = fopen("Don-Quijote-Ingles.txt", "r");
    if (!file) {
        perror("Error al abrir el archivo");
        return 1;
    }
    
    char buffer[4096];  // Un bloque de 4KB

    while (!feof(file)) {
        size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
        
        for (size_t i = 0; i < bytesRead; ++i) {
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                freqTable[(unsigned char)c].character = c;
                freqTable[(unsigned char)c].frequency++;
            }
        }
    }
    fclose(file);

    // Construir el árbol de Huffman y obtener los códigos de Huffman para cada carácter:
    Node* huffmanTree = buildHuffmanTree();
    printf("Códigos de Huffman:\n");
    buildAndShowHuffmanCodes(huffmanTree);

    // Liberar memoria del árbol de Huffman si es necesario
    // Por simplicidad, no estamos manejando la liberación de memoria en este código, pero en un escenario real, sería bueno hacerlo.

    return 0;
}
