
# include <iostream>

int main() {
    // Crear un dangling pointer u operador colgante sucede de varias maneras   
    
    /*
    Un buen ejemplo puede ser:
    Liberar una ubicación de memoria y posteriormente intentamos accesar a ella.
    */
    
    // Creamos un apuntador con memoria dinámica
    int size = 10;
    double* danglingPtr = new double[size];

    // Asignamos valores al apuntador
    for (int i = 0; i < size; i++) {
        danglingPtr[i] = i + 1;
    }

    // Imprimir apuntador
    for (int i = 0; i < size; i++) {
        std::cout << danglingPtr[i] << " "; 
    }
    std::cout << std::endl;
    
    // Liberar la memoria del apuntador
    delete[] danglingPtr;

    // El apuntador ahora es un dangling pointer. 
    // Acceder a él puede llevar a comportamiento indefinido.

    // Ahora intentamos accesar al apuntador
    // Esto es peligroso y puede causar errores
    std::cout << "Intentando acceder al primer valor del apuntador después de liberar la memoria: ";
    std::cout << danglingPtr[0] << std::endl; // Comportamiento indefinido
    
    // Imprimir apuntador
    for (int i = 0; i < size; i++) {
        std::cout << danglingPtr[i] << " "; 
    }
    std::cout << std::endl;

    /*
    Para solucionar el problema del dangling pointer, debemos asegurarnos de no acceder a la memoria 
    después de haberla liberado. Una buena alternativa puede ser asignar nullptr a los apuntadores 
    después de liberar su memoria.
    */

    danglingPtr = nullptr;

    // Ahora, nuevamente tratamos de acceder al apuntador
    // Seguro tendremos un segmentation fault. 
    // std::cout << danglingPtr[0] << std::endl; // Descomentar para comprobación

    return 0;

}
