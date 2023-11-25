

// Estructuras
struct escuela {
    char grupo; // A, B, C, D, E, F
    char turno[11]; // Matutino o Vespertino (toda la palabra)
};

struct estudiante {
    char nombre[51]; // Hasta 50 caracteres y el carácter nulo
    char calif_promedio[3]; 
    int edad;
    struct escuela E; 
};

// Esta rutina muestra una matriz de mxn
void MatrixShow(int m, int n, double *v);

// Rutina para leer una matriz con un header
int ReadStruct(const char *filename, struct estudiante **array, int numEstudiantes);

int mostrarMenu();

void imprimirEstudiantes(struct estudiante *array, int numEstudiantes);

int compararPorNombre(const void *a, const void *b);

int compararPorEdad(const void *a, const void *b);

int compararPorPromedio(const void *a, const void *b);

void ordenarPorNombre(struct estudiante *array, int numEstudiantes);

void ordenarPorEdad(struct estudiante *array, int numEstudiantes);

void ordenarPorPromedio(struct estudiante *array, int numEstudiantes);

void numeroEstudiantesPorGrupo(struct estudiante *array, int numEst);

void numeroEstudiantesPorTurno(struct estudiante *array, int numEst);

void bajaEstudiante(struct estudiante **array, int *numEst, const char *nombre);

void altaEstudiante(struct estudiante **array, int *numEst, struct estudiante nuevoEstudiante);


