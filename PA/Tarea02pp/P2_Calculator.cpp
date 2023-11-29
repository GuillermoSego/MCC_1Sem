
# include <iostream>
# include <sstream>
# include <string>

int main() {
    
    std::string input;
    std::cout << "Ingrese una expresión aritmética (ej. x1 + x2)" << std::endl;;
    std::cout << "Operaciones soportadas: +, -, *, /: ";
    std::getline(std::cin, input);

    std::istringstream stream(input);
    double total = 0;
    double num;
    char op = '+';

    while (stream >> num) {
        if (op == '+') total += num;
        else if (op == '-') total -= num;
        else if (op == '*') total *= num;
        else if (op == '/') total /= num;
        stream >> op;
    }

    std::cout << "Resultado: " << total << std::endl;
    return 0;
}
