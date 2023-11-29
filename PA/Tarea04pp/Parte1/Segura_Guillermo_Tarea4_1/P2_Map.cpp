
# include <iostream>
# include <map>
# include <string>

int main() {
    // Crear un mapa para contar la ocurrencia de cada palabra
    std::map<std::string, int> wordCount;
    std::string word; // Para terminar el bucle

    std::cout << "Ingresa palabras, escribe 'fin' para terminar:" << std::endl;

    // Leer palabras y se cuentan las ocurrencias
    while (std::cin >> word) {
        if (word == "fin") {
            break;  // Termina el bucle si el usuario escribe 'fin'
        }
        ++wordCount[word];
    }

    // Iterar sobre el mapa e imprimir cada palabra con su conteo.
    std::cout << "\nConteo de palabras:" << std::endl;
    for (const auto& pair : wordCount) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
