
# include <iostream>
# include <fstream>
# include <string>

int main() {

    std::string filename, word;
    std::cout << "Ingrese el nombre del archivo: ";
    std::cin >> filename;
    std::cout << "Ingrese la palabra a buscar: ";
    std::cin >> word;

    std::ifstream file(filename);
    if (file.is_open()) {

        std::string line;
        int lineNumber = 0;
        size_t pos;

        // Leer el archivo línea por línea
        while (getline(file, line)) {

            lineNumber++;
            pos = line.find(word, 0);

            // Buscar todas las ocurrencias de la palabra en la línea actual
            while (pos != std::string::npos) {

                std::cout << "Palabra encontrada en línea " << lineNumber << ", posición " << pos << std::endl;
                pos = line.find(word, pos + 1);

            }
        }
        file.close();

    } else {

        std::cerr << "No se pudo abrir el archivo." << std::endl;

    }

    return 0;

    
}
