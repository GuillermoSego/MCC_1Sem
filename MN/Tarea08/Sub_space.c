
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "matrix.h"

int main(int argc, char *argv[]){

    if(argc != 2) {
        printf("Uso: %s <nombre_archivo_matriz>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    double *A;
    int rows, cols;

    if (ReadMatrix(filename, &A, &rows, &cols) == 1) {
        free(A);
        return 0;
    }

    if(rows != cols) {
        printf("La matriz no es cuadrada.\n");
        free(A);
        return 1;
    }


    

    return 0;

}