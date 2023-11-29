
# include <iostream>
# include <stack>
# include <string>

bool estaBalanceado(const std::string& expresion) {
    std::stack<char> pila;

    // Recorremos cada caracter de la expresión
    for (char ch : expresion) {

        switch (ch) {

            case '(': case '[': case '{':
                // Si es un paréntesis/llave/corchete abierto, apilar
                pila.push(ch);
                break;

            case ')': case ']': case '}':
                // Si la pila está vacía o el paréntesis no coincide, no está balanceado
                if (pila.empty() || (ch == ')' && pila.top() != '(') ||
                    (ch == ']' && pila.top() != '[') ||
                    (ch == '}' && pila.top() != '{')) {
                    return false;
                }
                // Quitar el paréntesis abierto de la pila
                pila.pop();
                break;
            
        }

    }

    // Si la pila está vacía, está balanceado
    return pila.empty();

}


int main() {

    std::string expresion;
    std::cout << "Ingrese una expresión para verificar su balanceo: ";
    std::getline(std::cin, expresion);

    if (estaBalanceado(expresion)) {
        std::cout << "La expresión está bien balanceada." << std::endl;
    } else {
        std::cout << "La expresión no está balanceada." << std::endl;
    }

    return 0;
}
