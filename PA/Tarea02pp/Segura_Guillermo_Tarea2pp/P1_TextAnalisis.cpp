
# include <iostream>
# include <fstream>
# include <string>
# include <map>
# include <cctype>

int main() {

    std::string filename;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (file.is_open()) {
        std::string word;
        int wordCount = 0;
        int charCount = 0;
        std::map<char, int> letterCount;

        // Leer palabra por palabra
        while (file >> word) {
            wordCount++;  // Contar palabras
            for (char ch : word) {
                if (std::isalpha(ch)) {  // Verificar si el caracter es una letra
                    ch = std::tolower(ch);  // Convertir a minúscula para contar sin distinguir mayúsculas y minúsculas
                    charCount++;  // Contar caracteres
                    letterCount[ch]++;  // Contar la ocurrencia de la letra
                }
            }
        }


        // Mostrar los resultados
        std::cout << "Número de palabras: " << wordCount << std::endl;
        std::cout << "Número de caracteres: " << charCount << std::endl;
        std::cout << "Frecuencia de cada letra:" << std::endl;
        for (const auto &pair : letterCount) {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }

    } else {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
    }

    return 0;
}
