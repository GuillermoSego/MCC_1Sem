
# include <iostream>
# include <fstream>
# include <vector>
# include <string>

struct Contacto {
    std::string nombre;
    std::string telefono;
};


void agregarContacto(const std::string& archivo, const Contacto& contacto) {
    
    std::ofstream file(archivo, std::ios::app);  // Abre el archivo en modo de anexar
    if (file.is_open()) {

        file << contacto.nombre << "," << contacto.telefono << std::endl;  // Escribe el contacto en el archivo
        file.close();

    } else {

        std::cerr << "No se pudo abrir el archivo para agregar un contacto." << std::endl;
    
    }
}

void eliminarContacto(const std::string& archivo, const std::string& nombre) {

    std::vector<Contacto> contactos;
    Contacto temp;
    std::ifstream file(archivo);
    std::ofstream tempFile("temp.txt", std::ios::out);

    // Leer todos los contactos y almacenarlos en un vector. Exceptuando el que se va a eliminar
    if (file.is_open() && tempFile.is_open()) {

        while (file >> temp.nombre >> temp.telefono) {
            if (temp.nombre != nombre) {
                contactos.push_back(temp);
            }
        }

        file.close();

        // Escribir todos los contactos excepto el eliminado en un archivo temporal
        for (const auto& contacto : contactos) {

            tempFile << contacto.nombre << "," << contacto.telefono << std::endl;

        }
        tempFile.close();

        // Reemplazar el archivo original con el archivo temporal
        std::remove(archivo.c_str());
        std::rename("temp.txt", archivo.c_str());

    } else {
        std::cerr << "No se pudo abrir el archivo para eliminar un contacto." << std::endl;
    }
}

void buscarContacto(const std::string& archivo, const std::string& nombre) {

    std::ifstream file(archivo);
    Contacto temp;
    bool encontrado = false;

    if (file.is_open()) {
        while (file >> temp.nombre >> temp.telefono) {
            if (temp.nombre == nombre) {
                std::cout << "Contacto encontrado: " << temp.nombre << " - " << temp.telefono << std::endl;
                encontrado = true;
                break;
            }
        }

        file.close();

        if (!encontrado) {
            std::cout << "Contacto no encontrado." << std::endl;
        }

    } else {

        std::cerr << "No se pudo abrir el archivo para buscar un contacto." << std::endl;

    }
}

void listarContactos(const std::string& archivo) {

    std::ifstream file(archivo);
    Contacto temp;

    if (file.is_open()) {
        std::cout << "Lista de contactos:" << std::endl;
        while (file >> temp.nombre >> temp.telefono) {

            std::cout << temp.nombre << " - " << temp.telefono << std::endl;

        }
        file.close();

    } else {

        std::cerr << "No se pudo abrir el archivo para listar contactos." << std::endl;

    }
}


int main() {

    std::string nombreArchivo = "contactos.txt";
    int opcion;
    Contacto contacto;
    std::string nombre;

    // Menú
    while (true) {
    
        std::cout << "1. Agregar contacto\n";
        std::cout << "2. Eliminar contacto\n";
        std::cout << "3. Buscar contacto\n";
        std::cout << "4. Listar contactos\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                std::cout << "Ingrese el nombre: ";
                std::cin >> contacto.nombre;
                std::cout << "Ingrese el teléfono: ";
                std::cin >> contacto.telefono;
                agregarContacto(nombreArchivo, contacto);
                break;

            case 2:
                std::cout << "Ingrese el nombre del contacto a eliminar: ";
                std::cin >> nombre;
                eliminarContacto(nombreArchivo, nombre);
                break;

            case 3:
                std::cout << "Ingrese el nombre del contacto a buscar: ";
                std::cin >> nombre;
                buscarContacto(nombreArchivo, nombre);
                break;

            case 4:
                listarContactos(nombreArchivo);
                break;

            case 5:
                return 0;
                
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }
}

