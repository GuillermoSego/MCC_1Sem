
// Estructura del nodo.
typedef struct Node {
    char character;
    int frequency;
    struct Node *left, *right;
} Node;

Node* newNode(char character, int frequency);

int compareNodes(const void* a, const void* b);

Node* buildHuffmanTree(Node* nodes[], int size);

void generateHuffmanCodes(Node* root, char* code, int depth, int* totalChars, double* expectedCompression);

void freeHuffmanTree(Node* root);