
# include <iostream>
# include <stdexcept> 

// Función para realizar la división de dos números
double divide(double num, double deno) {
    // Intentamos realizar la división
    try {
        if (deno == 0) {
            // Excepción si el denominador es cero
            throw std::runtime_error("Error matemático. División entre cero.");
        }
        return num / deno;
    }
    // Capturamos la excepción si se lanza alguna
    catch (const std::runtime_error& e) {
        // Imprimimos el mensaje de error
        std::cerr << e.what() << std::endl;
        // Terminamos la función
        return 0;  
    }
}

int main() {
    double num1, num2;

    std::cout << "Ingrese el numerador: ";
    std::cin >> num1;

    std::cout << "Ingrese el denominador: ";
    std::cin >> num2;

    double result = divide(num1, num2);
    
    // Imprimimos el resultado solo si la división fue exitosa
    if (num2 != 0) {
        std::cout << "Resultado: " << result << std::endl;
    }

    return 0;
}
