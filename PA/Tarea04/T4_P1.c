
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXLENGTH 100
#define MAXVALUE  255

// Funcion para leer una imagen
unsigned char **pgmRead(char *fileName,int *rows,int *cols)
{
      FILE *filePointer;   
      char line[MAXLENGTH]; /* for character input from file */
      int maximumValue = 0; /* max value from header */
      int binary;           /* flag to indicate if file is binary (P5) or ascii (P2)*/
      long numberRead = 0;  /* counter for number of pixels read */
      long i,j;             /* (i,j) for loops */
      int test,temp;        /* for detecting EOF(test) and temp storage */
      unsigned char *tempPtr, **image;

      /* Open the file, return an error if necessary. */
      if ((filePointer = fopen(fileName,"r")) == NULL) {
	   printf ("ERROR: cannot open file\n\n");
	   fclose (filePointer);
	   return (0);
      }
    
      *cols = *rows =0;

      /* Check the file signature ("Magic Numbers" P2 and P5); skip comments
         and blank lines (CR with no spaces before it).*/
      fgets (line,MAXLENGTH,filePointer);
      while (line[0]=='#' || line[0]=='\n') 
           fgets (line,MAXLENGTH,filePointer);

      if (line[0]=='P' && (line[1]=='2')) {
	   binary = 0;
	 /*   printf ("\nFile Format: P2\n"); */
      }
      else if (line[0]=='P' && (line[1]=='5')) {
	   binary = 1;
	  /*  printf ("\nFORMAT: P5\n"); */
      }
      else {
	   printf ("ERROR: incorrect file format\n\n");
	   fclose (filePointer);
	   return (0);
      } 

      /* Input the width, height and maximum value, skip comments and blank
       * lines. */
      fgets (line,MAXLENGTH,filePointer);
      while (line[0]=='#' || line[0]=='\n') 
         fgets (line,MAXLENGTH,filePointer);
      sscanf (line,"%d %d",cols,rows);

      fgets (line,MAXLENGTH,filePointer);
      while (line[0]=='#' || line[0]=='\n') 
         fgets(line,MAXLENGTH,filePointer);
      sscanf (line,"%d",&maximumValue);

      if ((*cols)<1 ||(*rows)<1 || maximumValue<0 || maximumValue>MAXVALUE){
	   printf ("ERROR: invalid file specifications (cols/rows/max value)\n\n");
	   fclose (filePointer);
	   return (0);
      }

      // creating memory for the input image
      image = (unsigned char **)malloc((*rows) * sizeof(unsigned char *));
      if (image == NULL)
      {
         puts("\nFailure to allocate room for pointers");
         return(NULL);
      }

      tempPtr = (unsigned char *) malloc((*rows)*(*cols)*sizeof(unsigned char));
      if (tempPtr == NULL)
      {
         puts("\nFailure to allocate room for the array");
         return(NULL);
      }
      for (i = 0; i < *rows; i++)
      {
        image[i] = tempPtr + ( i * (*cols) );
      }


      /* Read in the data for binary (P5) or ascii (P2) PGM formats   */
      if (binary) {
	   for (i = 0; i < (*rows); i++) {
	        numberRead += fread((void *)&(image[i][0]),
		  sizeof(unsigned char),(*cols),filePointer); 
		if (feof(filePointer)) break;
	   }
      }
      else {
	   for (i= 0; i < (*rows); i++) {
	        for (j =0; j < (*cols); j++) { 
	             test = fscanf (filePointer,"%d",&temp);
		     if (test == EOF) break;
		     image[i][j] = (unsigned char)temp;

		     numberRead++;
		}
		if (test == EOF) break;
	   }
      }

      /* close the file and return 1 indicating success */
      fclose (filePointer);
      return (image);
}



/* INPUT: a filename (char*), the dimensions of the pixmap (rows,cols of
 *   type long), and a pointer to a 2D array (MAXROWS x MAXCOLS) in row
 *   major order.
 * OUTPUT: an integer is returned indicating if the desired file was written
 *   (in P5 PGM format (binary)).  A 1 is returned if the write was completed
 *   and 0 if it was not.  An error message is returned if the file is not
 *   properly opened.  
 */ 
int pgmWrite(char* filename, int rows,int cols,unsigned char **image,char* comment_string)
{
      FILE* file;        /* pointer to the file buffer */
      int maxval;        /* maximum value in the image array */
      long nwritten = 0; /* counter for the number of pixels written */
      long i,j;          /* for loop counters */

      /* open the file; write header and comments specified by the user. */
      if ((file = fopen(filename, "w")) == NULL)	{
           printf("ERROR: file open failed\n");
	   return(0);
      }
      fprintf(file,"P5\n");

      if (comment_string != NULL) fprintf(file,"# %s \n", comment_string);
    
      /* write the dimensions of the image */	
      fprintf(file,"%d %d \n", cols, rows);

      /* NOTE: MAXIMUM VALUE IS WHITE; COLOURS ARE SCALED FROM 0 - */
      /* MAXVALUE IN A .PGM FILE. */
      
      /* WRITE MAXIMUM VALUE TO FILE */
      fprintf(file, "%d\n", (int)255);

      /* Write data */
      for (i = 0;i < rows;i++) {
          nwritten += fwrite((void*)image[i],sizeof(unsigned char),cols,file);
      }
      printf("nwritten = %ld,",nwritten);
      	
      fclose(file);
      return(1);
}

// Función para calcular el promedio en una ventana de n x n alrededor del punto (i, j)
unsigned char calcularPromedio(unsigned char **image, int i, int j, int rows, int cols, int n) {
    int sum = 0, count = 0;  // Inicializar suma y contador
    int offset = n / 2;     // Tamaño de la mitad de la ventana deslizante

    // Iterar a través de la ventana deslizante centrada en (i, j)
    for (int x = -offset; x <= offset; x++) {
        for (int y = -offset; y <= offset; y++) {
            int newX = i + x, newY = j + y;
            // Verificar si estamos dentro de los límites de la imagen
            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                sum += image[newX][newY];  // Agregar el valor al total
                count++;  // Incrementar el contador de píxeles sumados
            }
        }
    }
    return sum / count;  // Devolver el promedio
}

// Función que toma un array y su tamaño, y lo ordena
void sort_array(unsigned char *array, int size) {
    // Implementación del algoritmo de ordenación por inserción
    int i, j;
    unsigned char key;
    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Función para calcular la mediana en una ventana de n x n alrededor del punto (i, j)
unsigned char calcularMediana(unsigned char **image, int i, int j, int rows, int cols, int n) {
    unsigned char *window = (unsigned char *)malloc(n * n * sizeof(unsigned char));
    int count = 0;  // Inicializar contador
    int offset = n / 2;  // Tamaño de la mitad de la ventana deslizante

    // Iterar a través de la ventana deslizante centrada en (i, j)
    for (int x = -offset; x <= offset; x++) {
        for (int y = -offset; y <= offset; y++) {
            int newX = i + x, newY = j + y;
            // Verificar si estamos dentro de los límites de la imagen
            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                window[count] = image[newX][newY];  // Almacenar el valor en el array window
                count++;  // Incrementar el contador
            }
        }
    }

    // Ordenar el array y encontrar la mediana
    sort_array(window, count);
    unsigned char median = window[count / 2];
    free(window);  // Liberar memoria
    return median;  // Devolver la mediana
}

// Función para calcular el gradiente en una ventana de 3x3 alrededor del punto (i, j)
// Usaremos el operador Sobel en este ejemplo
unsigned char calcularGradiente(unsigned char **image, int i, int j, int rows, int cols) {
    // Inicializar las matrices de Sobel para los ejes X y Y
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int sumX = 0, sumY = 0;  // Inicializar las sumas para los ejes X y Y

    // Iterar a través de la ventana deslizante centrada en (i, j)
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            int newX = i + x, newY = j + y;
            // Verificar si estamos dentro de los límites de la imagen
            if (newX >= 0 && newY >= 0 && newX < rows && newY < cols) {
                sumX += gx[x + 1][y + 1] * image[newX][newY];  // Calcular el componente X del gradiente
                sumY += gy[x + 1][y + 1] * image[newX][newY];  // Calcular el componente Y del gradiente
            }
        }
    }
    // Calcular la magnitud del gradiente usando la raíz cuadrada de la suma de los cuadrados
    return (unsigned char)sqrt(sumX * sumX + sumY * sumY);
}



int main() {
    int i, j, max, ok, rows, cols;
    int count = 0;
    unsigned char **image;
    char file_in[80], file_out[80];

    // Archivo de entrada
    printf("Archivo pgm de entrada: ");
    gets(file_in);
    image = pgmRead(file_in,&rows,&cols);
    if (image == NULL) {
        printf("Error pgmRead\n");
        exit(1);
    }

    // Procesamiento de la imagen: MedianFilter, meanFilter, gradient 
    

    unsigned int n = 3; // Tamaño de la ventana deslizante

    // Crear matrices para guardar los resultados de los cálculos. Incializamos
    unsigned char **mean = (unsigned char **)malloc(rows * sizeof(unsigned char *));
    unsigned char **median = (unsigned char **)malloc(rows * sizeof(unsigned char *));
    unsigned char **gradient = (unsigned char **)malloc(rows * sizeof(unsigned char *));
    for (i = 0; i < rows; ++i) {
        mean[i] = (unsigned char *)malloc(cols * sizeof(unsigned char));
        median[i] = (unsigned char *)malloc(cols * sizeof(unsigned char));
        gradient[i] = (unsigned char *)malloc(cols * sizeof(unsigned char));
    }

    // Calcular los valores de media, mediana y gradiente
    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            mean[i][j] = calcularPromedio(image, i, j, rows, cols, n);
            median[i][j] = calcularMediana(image, i, j, rows, cols, n);
            gradient[i][j] = calcularGradiente(image, i, j, rows, cols);
        }
    }

    // Archivo de salida
    printf("Archivo pgm de salida para media: ");
    gets(file_out);
    ok = pgmWrite(file_out, rows, cols, mean, "Resultado de media");
    
    printf("Archivo pgm de salida para mediana: ");
    gets(file_out);
    ok = pgmWrite(file_out, rows, cols, median, "Resultado de mediana");
    
    printf("Archivo pgm de salida para gradiente: ");
    gets(file_out);
    ok = pgmWrite(file_out, rows, cols, gradient, "Resultado de gradiente");


    // Liberar memoria
    for (i = 0; i < rows; ++i) {
        free(mean[i]);
        free(median[i]);
        free(gradient[i]);
    }
    free(mean);
    free(median);
    free(gradient);

}