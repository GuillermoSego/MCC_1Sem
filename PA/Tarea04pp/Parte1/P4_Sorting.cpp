
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

// Función para comparar pares
// Ordena primero por la longitud de la cadena y luego por el número
bool customCompare(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {

    if (a.second.length() == b.second.length()) {
        return a.first < b.first; // Ordena por número si las longitudes de las cadenas son iguales
    }

    return a.second.length() < b.second.length(); // Ordena por longitud de cadena
}

int main() {

    // Crear un vector de pares. Cada par contiene un número y una string
    std::vector<std::pair<int, std::string>> vec = {
        {3, "Tre"},
        {1, "Uno"},
        {4, "Cuatro"},
        {2, "Dos"},
        {5, "Cinco"}
    };

    // Ordenar el vector usando la función personalizada.
    std::sort(vec.begin(), vec.end(), customCompare);
    std::cout << "Ordenado por función personalizada:" << std::endl;
    for (const auto& p : vec) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    
    // Ordenar el vector usando una expresión lambda
    // La lambda sigue la misma lógica que la función declarada arriba fuera del main
    std::sort(vec.begin(), vec.end(), [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        if (a.second.length() == b.second.length()) {
            return a.first < b.first; // Ordena por número si las longitudes de las cadenas son iguales
        }
        return a.second.length() < b.second.length(); // Ordena por longitud de cadena
    });

    std::cout << "Ordenado por expresión lambda:" << std::endl;
    for (const auto& p : vec) {
        std::cout << p.first << ": " << p.second << std::endl;
    }

}

