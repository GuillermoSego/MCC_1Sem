
# include <stdio.h>
# include <math.h>
# include "matrix.h"

int maxOffDiagonalElement (double** A, int size){

    double* APtr = *A;
    int i = 0, j = 0;

    double array[100];
    double* arrayPtr = array;

    do
    {
        do
        {
            
            *arrayPtr ++ = *APtr;
            i ++;
        } while (i<size);

        j ++;
    } while ();
    

}

int main(int argc, char *argv[]){

    // Manejo de argumentos de la línea de comandos
    if(argc != 2) {
        printf("Uso: %s <nombre_archivo_matriz>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];

    // No tenemos certeza del tamaño de la matriz
    // Declaramos un apuntador hacia un bloque de memoria específico de la matriz A
    double *A;
    int rows, cols;

    // Leemos la matriz en el archivo, pasamos por referencia el valor del apuntador
    if (ReadMatrix(filename ,&A, &rows, &cols) == 1) {
        free(A); // Liberamos memoria
        return 0;
    }

    // Comprobar si la matriz es cuadrada
    if (rows != cols) {
        printf("La matriz debe ser cuadrada para el método de la potencia.\n");
        free(A);
        return 1;
    }


    // Definimos la tolerancia 

    // Funcion para calcular el elemento mas grande fuera de la diagonal


    // Liberar memoria
    free(A);
    return 0;
}