
// Estructuras

// Nodo para el árbol binario de búsqueda
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Tabla Hash
struct HashTable {
    struct TreeNode** table;  // Array de apuntadores a árboles
    int size;                 // Tamaño de la tabla
};

struct TreeNode* createTreeNode(int data);

struct TreeNode* insertTreeNode(struct TreeNode* root, int data);

struct HashTable* createHashTable(int size);

int hashFunction(int key, int tableSize);

void insert(struct HashTable* table, int data);

void inorder(struct TreeNode* root);

void printHashTable(struct HashTable* table);

int depth(struct TreeNode* node);

void deepestTree(struct HashTable* table);



