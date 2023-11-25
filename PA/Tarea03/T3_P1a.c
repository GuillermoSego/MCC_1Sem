
# include <stdio.h>

int Longitud_str( const char * chainPtr ){

    int length = 0;

    // Mientras no encontremos el caracter nulo
    while( *chainPtr != '\0' ){

        chainPtr ++;
        length ++;
    }

    // Regresamos el valor de la longitud
    return length;    
}

int main(){

    int n;
    /* Declaramos una cadena de caracteres como un apuntador que apunta hacia el primer
    elemento de la cadena. Utilizamos un apuntador no constante que apunta a datos constantes
    ya que no vamos a modificar el valor de los datos solo ocupamos leer su longitud */
    const char* chainPtr = "Hola como estas";
    
    // Llamamos a la funcion y pasamos el valor del apuntador por valor
    n = Longitud_str(chainPtr);

    // Imprimimos la lontitud de la cadena
    printf("La longitud de la candena: %s es %d", chainPtr, n);

    return 0;
}