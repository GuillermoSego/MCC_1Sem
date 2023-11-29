
# include <iostream>
# include <vector>
# include <string>
# include <algorithm>

// Estructura para almacenar nombres y edades
struct Persona {
    std::string nombre;
    int edad;
};


int main() {

    std::vector<Persona> personas;
    std::string nombre;
    int edad;

    std::cout << "Ingrese nombres y edades (Escriba 'fin' para terminar):" << std::endl;
    while (true) {
        std::cout << "Nombre: ";
        std::cin >> nombre;
        if (nombre == "fin") break;

        std::cout << "Edad: ";
        std::cin >> edad;

        personas.push_back({nombre, edad});

    }

    // Ordenar por edad
    std::sort(personas.begin(), personas.end(), [](const Persona &a, const Persona &b) {
        return a.edad < b.edad;
    });

    std::cout << "\nLista ordenada por edad:" << std::endl;
    for (const auto &persona : personas) {
        std::cout << persona.nombre << " " << persona.edad << std::endl;
    }

    // Ordenar por nombre
    std::sort(personas.begin(), personas.end(), [](const Persona &a, const Persona &b) {
        return a.nombre < b.nombre;
    });

    std::cout << "\nLista ordenada por nombre:" << std::endl;
    for (const auto &persona : personas) {
        std::cout << persona.nombre << " " << persona.edad << std::endl;
    }

    return 0;
}
