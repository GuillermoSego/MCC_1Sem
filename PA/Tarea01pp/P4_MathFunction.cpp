
# include <iostream>
# include <cstdlib>
# include <ctime>
# include <cmath>

// Funciones matemáticas
double Add(double a, double b) {
    return a + b;
}

double Subtract(double a, double b) {
    return a - b;
}

double Multiply(double a, double b) {
    return a * b;
}

double Divide(double a, double b) {
    // Checar si b es 0
    if (b != 0.0) {
        return (a / b);
    } else {
        std::cout << "No se puede dividir entre cero" << std::endl;;
        return 0.0;
    }
}

double Mod(double a, double b) {
    return std::fmod(a, b);
}

double Pow(double a, double b) {
    return std::pow(a, b);
}

int main() {
    // Declarando un apuntador a función que toma dos doubles y devuelve un double
    double (*operationPtr)(double, double) = nullptr;
    double x, y;
    char operation;

    std::cout << "Ingrese la operación (+, -, *, /, %, ^): ";
    std::cin >> operation;

    std::cout << "Ingrese dos números: ";
    std::cin >> x >> y;

    // Asignar el apuntador a función basado en la entrada del usuario
    switch (operation) {
        case '+':
            operationPtr = &Add;
            break;
        case '-':
            operationPtr = &Subtract;
            break;
        case '*':
            operationPtr = &Multiply;
            break;
        case '/':
            operationPtr = &Divide;
            break;
        case '%':
            operationPtr = &Mod;
            break;
        case '^':
            operationPtr = &Pow;
            break;
        default:
            std::cout << "Operación no válida." << std::endl;
            return 1;
    }

    // Llamar a la función a través del apuntador a función
    double result = operationPtr(x, y);
    std::cout << "Resultado: " << result << std::endl;

    return 0;
}
