#include <stdio.h>

int main() {
    
    float epsilon = 1.0f;
    float prev_epsilon;  // para almacenar el valor anterior de epsilon

    while(1 + epsilon > 1) {
        prev_epsilon = epsilon;  // almacenar el valor actual de epsilon antes de actualizarlo
        epsilon = epsilon / 2;
    }

    printf("Epsilon de la maquina (precisión simple): %e\n", prev_epsilon);

    return 0;
}
