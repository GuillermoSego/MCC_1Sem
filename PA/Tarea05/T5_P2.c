
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STRuct.h"



int main(int argc, char *argv[]) {

    // Validación de número de argumentos pasados por la línea de comandos
    if(argc != 2) {
        printf("Uso: %s <nombre_archivo>\n", argv[0]);
        return 1;
    }

    // Asignación del nombre del archivo a una variable constante
    const char* filename = argv[1];
    
    // Inicialización de arreglo de estudiantes y su tamaño
    struct estudiante *array = NULL;
    int numEst = 15;

    // Llamada a función para leer el archivo y cargar datos en el arreglo
    if (ReadStruct(filename, &array, numEst) != 0) {
        // En caso de error, liberar memoria y terminar
        if (array != NULL) {
            free(array); 
        }
        return 1;
    }

    // Variables necesarias para el menú y su lógica
    int opcion;
    char nombreEstudiante[100];

    // Variables para almacenar información temporal del estudiante
    char nombre[100];
    char calif_promedio[5];
    int edad;
    char grupo;
    char turno[15];
    struct estudiante nuevoEstudiante;

        
    do {
        opcion = mostrarMenu();
        switch(opcion) {
            case 1:
                imprimirEstudiantes(array, numEst);
                break;
            case 2:
                ordenarPorNombre(array, numEst);
                break;
            case 3:
                ordenarPorEdad(array, numEst);
                break;
            case 4:
                ordenarPorPromedio(array, numEst);
                break;
            case 5:
                numeroEstudiantesPorGrupo(array, numEst);
                break;
            case 6:
                numeroEstudiantesPorTurno(array, numEst);
                break;
            case 7:
                printf("Ingrese el nombre del estudiante para dar de baja: ");
                scanf("%s", nombreEstudiante);
                bajaEstudiante(&array, &numEst, nombreEstudiante);
                break;
            case 8:
                printf("Introduce el nombre del estudiante: ");
                scanf(" %[^\n]s", nombre);
                strcpy(nuevoEstudiante.nombre, nombre);

                printf("Introduce la calificación promedio del estudiante (Formato: A+, A, A-, ... F-): ");
                scanf(" %s", calif_promedio);
                strcpy(nuevoEstudiante.calif_promedio, calif_promedio);

                printf("Introduce la edad del estudiante: ");
                scanf("%d", &edad);
                nuevoEstudiante.edad = edad;

                printf("Introduce el grupo del estudiante (A, B, C, D, E, F): ");
                scanf(" %c", &grupo);
                nuevoEstudiante.E.grupo = grupo;

                printf("Introduce el turno del estudiante (Matutino/Vespertino): ");
                scanf(" %[^\n]s", turno);

                // Llamada a la función
                altaEstudiante(&array, &numEst, nuevoEstudiante);
                break;
            case 9:
                imprimirEstudiantes(array, numEst);
                break;
            default:
                printf("Opción no válida. Intenta de nuevo.\n");
        }
    } while(opcion != 9);

    // Liberar la memoria
    free(array);


    return 0;
}

