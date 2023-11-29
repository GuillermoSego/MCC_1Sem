
# include <iostream>

int main(){

    // Estoy utilizando MacOS. Para gestionar los memory leaks usamos 'leaks'

    /*
    Una fuga de memoria ocurre cuando reservamos memoria que posteriormente no
    es liberada. Es memoria que ya no se necesita, entonces 'perdemos' esa memoria,
    es decir, no es posible utilizar esa memoria
    */

   // Para probar leaks primero necesitamos una fuga de memoria

    int* leakyPtr = new int(5);  // Asignación dinámica de memoria

    leakyPtr[0] = 1;

    // No liberamos la memoria asignada a leakyPtr, ie. una fuga de memoria

    // Mantenemos la ejecución del programa para probar leaks
    std::cout << "Presiona ENTER para salir...";
    std::cin.get();  // Espera a que el usuario presione ENTER

    return 0;
}
