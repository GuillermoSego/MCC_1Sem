/*

Biblioteca para manejo de estructuras

*/

# include "STRuct.h" // Para la declaracion de las estructuras
# include <stdio.h>
# include <math.h>
#include <string.h>
# include <stdlib.h>


/*
Lee una estructura desde un archivo.

Parametros:
    - filename: Nombre del archivo desde donde se leerá.
    - array: Puntero doble al arreglo de estudiantes.
    - numEstudiantes: Número de estudiantes a leer.

Retorno:
    - 0 en caso de éxito.
    - 1 si no se pudo abrir el archivo.
    - 2 si hubo un error en la asignación de memoria.
*/
int ReadStruct(const char *filename, struct estudiante **array, int numEstudiantes) {
    FILE *file;
    int i;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo\n");
        return 1;
    }

    // Asginamos memoria al arreglo de estructuras
    *array = malloc((numEstudiantes) * sizeof(struct estudiante));
    if (*array == NULL) {
        printf("Fallo en la asignación de memoria\n");
        fclose(file);
        return 2;
    }

    // Llenamos el arreglo
    for (i = 0; i < numEstudiantes; i++) {
        fscanf(file, "%50s %s %d %c %s", 
               (*array)[i].nombre, 
               (*array)[i].calif_promedio, 
               &((*array)[i].edad),
               &((*array)[i].E.grupo), 
               (*array)[i].E.turno);
    }

    fclose(file);
    return 0;
}

/*
Muestra el menú al usuario y retorna la opción seleccionada.

Retorno:
    - Opción seleccionada por el usuario.
*/
int mostrarMenu() {
    int opcion;
    printf("----- MENÚ -----\n");
    printf("1) Imprimir archivo\n");
    printf("2) Ordenar por nombre\n");
    printf("3) Ordenar por edad\n");
    printf("4) Ordenar por promedio\n");
    printf("5) Número de estudiantes por grupo\n");
    printf("6) Número de estudiantes por turno\n");
    printf("7) Baja estudiante\n");
    printf("8) Alta estudiante\n");
    printf("9) Fin\n");
    printf("Selecciona una opción: ");
    scanf("%d", &opcion);
    return opcion;
}

/*
Imprime la lista de estudiantes.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEstudiantes: Número de estudiantes.
*/
void imprimirEstudiantes(struct estudiante *array, int numEstudiantes) {
    for(int i = 0; i < numEstudiantes; i++) {
        printf("Nombre: %s\n", array[i].nombre);
        printf("Calificación Promedio: %s\n", array[i].calif_promedio);
        printf("Edad: %d\n", array[i].edad);
        printf("Grupo: %c\n", array[i].E.grupo);
        printf("Turno: %s\n\n", array[i].E.turno);
    }
}

/*
Comparador para qsort que compara dos estudiantes por su nombre.

Parámetros:
    - a, b: Punteros a los estudiantes a comparar.

Retorno:
    - < 0 si el nombre de 'a' es menor que el de 'b'.
    - 0 si son iguales.
    - > 0 si el nombre de 'a' es mayor que el de 'b'.
*/
int compararPorNombre(const void *a, const void *b) {
    struct estudiante *estudianteA = (struct estudiante *)a;
    struct estudiante *estudianteB = (struct estudiante *)b;
    return strcmp(estudianteA->nombre, estudianteB->nombre);
}

/*
Comparador para qsort que compara dos estudiantes por su edad.

Parámetros:
    - a, b: Punteros a los estudiantes a comparar.

Retorno:
    - < 0 si la edad de 'a' es menor que la de 'b'.
    - 0 si son iguales.
    - > 0 si la edad de 'a' es mayor que la de 'b'.
*/
int compararPorEdad(const void *a, const void *b) {
    struct estudiante *estudianteA = (struct estudiante *)a;
    struct estudiante *estudianteB = (struct estudiante *)b;
    return estudianteA->edad - estudianteB->edad;  // Puede ser inverso si quieres orden descendente
}

/*
Comparador para qsort que compara dos estudiantes por su calificación promedio.

Parámetros:
    - a, b: Punteros a los estudiantes a comparar.

Retorno:
    - < 0 si el promedio de 'a' es menor que el de 'b'.
    - 0 si son iguales.
    - > 0 si el promedio de 'a' es mayor que el de 'b'.
*/
int compararPorPromedio(const void *a, const void *b) {
    struct estudiante *estudianteA = (struct estudiante *)a;
    struct estudiante *estudianteB = (struct estudiante *)b;
    return strcmp(estudianteA->calif_promedio, estudianteB->calif_promedio);
}

/*
Ordena un arreglo de estudiantes por nombre usando qsort.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEstudiantes: Número de estudiantes.
*/
void ordenarPorNombre(struct estudiante *array, int numEstudiantes) {
    qsort(array, numEstudiantes, sizeof(struct estudiante), compararPorNombre);
}


/*
Ordena un arreglo de estudiantes por edad usando qsort.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEstudiantes: Número de estudiantes.
*/
void ordenarPorEdad(struct estudiante *array, int numEstudiantes) {
    qsort(array, numEstudiantes, sizeof(struct estudiante), compararPorEdad);
}

/*
Ordena un arreglo de estudiantes por promedio usando qsort.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEstudiantes: Número de estudiantes.
*/
void ordenarPorPromedio(struct estudiante *array, int numEstudiantes) {
    qsort(array, numEstudiantes, sizeof(struct estudiante), compararPorPromedio);
}

/*
Muestra el número de estudiantes por grupo.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEst: Número de estudiantes.
*/
void numeroEstudiantesPorGrupo(struct estudiante *array, int numEst) {
    char grupos[] = "ABCDEF"; 
    for (int i = 0; i < strlen(grupos); i++) {
        int count = 0;
        for (int j = 0; j < numEst; j++) {
            if (array[j].E.grupo == grupos[i]) {
                count++;
            }
        }
        printf("Grupo %c: %d estudiantes\n", grupos[i], count);
    }
}

/*
Muestra el número de estudiantes por turno.

Parámetros:
    - array: Arreglo de estudiantes.
    - numEst: Número de estudiantes.
*/
void numeroEstudiantesPorTurno(struct estudiante *array, int numEst) {
    int matutino = 0;
    int vespertino = 0;

    for (int i = 0; i < numEst; i++) {
        if (strcmp(array[i].E.turno, "Matutino") == 0) {
            matutino++;
        } else if (strcmp(array[i].E.turno, "Vespertino") == 0) {
            vespertino++;
        }
    }

    printf("Turno Matutino: %d estudiantes\n", matutino);
    printf("Turno Vespertino: %d estudiantes\n", vespertino);
}

/*
Elimina un estudiante del arreglo dada su nombre.

Parámetros:
    - array: Puntero doble al arreglo de estudiantes.
    - numEst: Puntero al número de estudiantes.
    - nombre: Nombre del estudiante a eliminar.
*/
void bajaEstudiante(struct estudiante **array, int *numEst, const char *nombre) {
    int index = -1;

    for (int i = 0; i < *numEst; i++) {
        if (strcmp((*array)[i].nombre, nombre) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Estudiante no encontrado.\n");
        return;
    }


    for (int i = index; i < *numEst - 1; i++) {
        (*array)[i] = (*array)[i + 1];
    }

    *numEst -= 1;

    printf("Estudiante %s eliminado.\n", nombre);
}

/*
Agrega un nuevo estudiante al arreglo.

Parámetros:
    - array: Puntero doble al arreglo de estudiantes.
    - numEst: Puntero al número de estudiantes.
    - nuevoEstudiante: Estructura con los datos del nuevo estudiante.
*/
void altaEstudiante(struct estudiante **array, int *numEst, struct estudiante nuevoEstudiante) {
    *array = realloc(*array, (*numEst + 1) * sizeof(struct estudiante));
    if (*array == NULL) {
        perror("Error reallocating memory");
        exit(EXIT_FAILURE);
    }

    // Copiar el nuevo estudiante a la última posición del arreglo
    (*array)[*numEst] = nuevoEstudiante;

    *numEst += 1;

    printf("Estudiante %s agregado.\n", nuevoEstudiante.nombre);
}