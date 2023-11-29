
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

int main() {

    std::vector<std::string> archivos;
    std::string nombreArchivo;
    int opcion;

    // Menú
    while (true) {

        std::cout << "1. Crear archivo\n";
        std::cout << "2. Eliminar archivo\n";
        std::cout << "3. Listar archivos\n";
        std::cout << "4. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {

            case 1:  // Crear archivo
                std::cout << "Ingrese el nombre del archivo a crear: ";
                std::cin >> nombreArchivo;
                archivos.push_back(nombreArchivo);
                break;

            case 2:  // Eliminar archivo
                std::cout << "Ingrese el nombre del archivo a eliminar: ";
                std::cin >> nombreArchivo;
                archivos.erase(std::remove(archivos.begin(), archivos.end(), nombreArchivo), archivos.end());
                break;

            case 3:  // Listar archivos
                std::cout << "Archivos:\n";
                for (const auto& archivo : archivos) {
                    std::cout << archivo << std::endl;
                }
                break;

            case 4:  // Salir
                return 0;
                
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
