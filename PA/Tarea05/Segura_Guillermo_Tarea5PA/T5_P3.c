# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <ctype.h>
# include "Hofman3.h"

// Definición del tamaño de buffer y la tabla de frecuencias.
#define BUFFER_SIZE 4096
typedef struct {
    char character;
    int frequency;
} FreqItem;

// Inicializa todas las frecuencias a 0.
FreqItem freqTable[256] = {0};

int main() {
    // Abre el archivo para lectura.
    FILE* file = fopen("Don-Quijote-Ingles.txt", "r");
    // Buffer para leer el archivo en bloques.
    char buffer[BUFFER_SIZE];
    // Para almacenar nodos iniciales basados en frecuencias.
    Node* nodes[256];  
    int nodeCount = 0;

    // Verifica si el archivo se abrió correctamente.
    if (!file) {
        printf("No se pudo abrir el archivo.\n");
        return 1;
    }

    // Procesa el archivo hasta que se llegue al final.
    while (!feof(file)) {
        // Lee el archivo en bloques.
        size_t bytesRead = fread(buffer, 1, sizeof(buffer), file);
        for (size_t i = 0; i < bytesRead; ++i) {
            // Convierte el carácter a minúscula y verifica si es alfabético.
            char c = tolower(buffer[i]);
            if (isalpha(c)) {
                // Actualiza la tabla de frecuencias.
                freqTable[(unsigned char)c].character = c;
                freqTable[(unsigned char)c].frequency++;
            }
        }
    }
    // Cierra el archivo después de procesarlo.
    fclose(file);

    // Crea nodos iniciales para cada carácter con frecuencia mayor que cero.
    for (int i = 0; i < 256; ++i) {
        if (freqTable[i].frequency) {
            nodes[nodeCount++] = newNode(freqTable[i].character, freqTable[i].frequency);
        }
    }

    // Construye el árbol de Huffman con los nodos iniciales.
    Node* huffmanTreeRoot = buildHuffmanTree(nodes, nodeCount);

    // Prepara variables para generación de códigos Huffman.
    char code[256];
    int totalChars = 0;
    for (int i = 0; i < 256; ++i) {
        totalChars += freqTable[i].frequency;
    }
    double expectedCompression = 0.0;
    // Genera y muestra códigos Huffman.
    generateHuffmanCodes(huffmanTreeRoot, code, 0, &totalChars, &expectedCompression);

    // Muestra la compresión esperada por carácter.
    printf("\nCompresión esperada por carácter: %lf bits\n", 8.0 - expectedCompression);

    // Libera la memoria del árbol al final.
    freeHuffmanTree(huffmanTreeRoot);

    return 0;
}
