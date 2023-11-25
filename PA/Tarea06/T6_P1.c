
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "STRuct.h"


// Funcion que encripta/desencripta una imagen
void cript(double x_0, int rows, int cols, unsigned char **encripted_image, unsigned char **image) {
    // Variables para el valor anterior y el valor actual del mapa logístico
    double x_ant = x_0, f_n;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Calculamos el valor actual del mapa logístico
            f_n = 4 * x_ant * (1 - x_ant);
            
            // Encriptamos el pixel utilizando XOR y el valor entero de f_n * 255
            encripted_image[i][j] = image[i][j] ^ (int)(f_n * 255);

            // Actualizamos el valor anterior del mapa
            x_ant = f_n;
        }
    }
}

int main() {
    int rows, cols, ok;
    unsigned char **image;
    char file_in[80], file_out[80];

    printf("Archivo pgm de entrada: ");
    scanf("%79s", file_in);  // Lee hasta 79 caracteres (para dejar espacio al '\0') y guarda en file_in
    getchar();  // Consumir el '\n' restante

    image = pgmRead(file_in, &rows, &cols);
    if (image == NULL) {
        printf("Error pgmRead\n");
        exit(1);
    }

    // Reservamos memoria para la imagen encriptada
    unsigned char **cripted_image = (unsigned char **)malloc(rows * sizeof(unsigned char *));
    for (int i = 0; i < rows; i++) {
        cripted_image[i] = (unsigned char *)malloc(cols * sizeof(unsigned char));
    }

    // Verificamos que la memoria se haya reservado correctamente
    if (!cripted_image) {
        printf("Error al asignar memoria para la imagen cifrada.");
        exit(1);
    }

    // Leemos un numero entre 0 y 1
    double num_encriptado;
    while(1){
        printf("Escoge un número entre 0 y 1 para encriptar la imagen: ");
        scanf("%lf", &num_encriptado);
        getchar();  // para consumir el '\n' restante
        if (num_encriptado > 0.0 && num_encriptado < 1.0){
            break;
        } else {
            printf("Numero no válido, escoge otra vez. \n");
        }
    }

    // Encriptamos la imagen
    cript(num_encriptado, rows, cols, cripted_image, image);

    // Solicitamos al usuario el nombre del archivo de salida
    printf("Archivo pgm de salida encriptado: ");
    scanf("%79s", file_out);
    getchar();  // Consumir el '\n' restante

    // Escribimos la imagen encriptada en un archivo
    ok = pgmWrite(file_out, rows, cols, cripted_image, "Resultado encriptado");

    // Liberamos la memoria de la imagen original y de la imagen encriptada
    free(image);
    free(cripted_image);

    return 0;
}
