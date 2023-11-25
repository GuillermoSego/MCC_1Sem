# include <stdio.h>
# include <math.h>

// Funcion para encontrar el tercer elemento mas grande
int findThird(int num, int length) {
    int first = -1, second = -1, third = -1, digit;
    int i = 0;

    do {
        digit = num % 10;

        if (digit > first) {
            third = second;
            second = first;
            first = digit;
        } else if (digit > second && digit < first) {
            third = second;
            second = digit;
        } else if (digit > third && digit < second) {
            third = digit;
        }

        num /= 10;
        i++;

    } while (i < length);

    return third;
}

// Funcion para contar elementos pares e impares
int paroimpar(int num, int length) {
    int digit, evenCount = 0, oddCount = 0;
    int i = 0;

    do {
        digit = num % 10;
        evenCount += (digit % 2 == 0);
        oddCount += (digit % 2 != 0);

        num /= 10;
        i++;

    } while (i < length);

    // Compactamos los dos conteos en un solo número
    return 10 * evenCount + oddCount;
}

int main() {
    // Declaramos las variables
    int array, length;

    printf("Introduce N elementos como un solo numero: \n");
    scanf("%d", &array);

    // Calculamos la longitud del numero
    length = log10(array) + 1;

    // Encontrar el tercer elemento más grande
    int thirdLargest;
    thirdLargest = findThird(array, length);

    if (thirdLargest == -1) {
        printf("No hay un tercer elemento más grande.\n");
    } else {
        printf("El tercer elemento más grande es: %d\n", thirdLargest);
    }

    // Contar elementos pares e impares
    int counts = paroimpar(array, length);
    printf("Numero de elementos pares: %d\n", counts / 10);
    printf("Numero de elementos impares: %d\n", counts % 10);

    return 0;
}
