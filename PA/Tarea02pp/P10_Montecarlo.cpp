
# include <iostream>
# include <cstdlib>
# include <ctime>

int main() {

    int numeroDeTiradas;
    int dentroDelCirculo = 0;
    double x, y;

    std::cout << "Ingrese el número de tiradas para la simulación de Montecarlo: ";
    std::cin >> numeroDeTiradas;

    // Inicializar la semilla de los números aleatorios
    std::srand(std::time(0));

    // Realizar la simulación
    for (int i = 0; i < numeroDeTiradas; i++) {

        x = static_cast<double>(std::rand()) / RAND_MAX;  // Generar un número aleatorio entre 0 y 1
        y = static_cast<double>(std::rand()) / RAND_MAX;  // Generar un número aleatorio entre 0 y 1

        // Verificar si el punto (x, y) está dentro del círculo
        if (x * x + y * y <= 1) {
            dentroDelCirculo++;
        }

    }

    // Calcular la estimación de pi
    double piEstimado = 4.0 * dentroDelCirculo / numeroDeTiradas;
    std::cout << "Estimación de PI con " << numeroDeTiradas << " tiradas: " << piEstimado << std::endl;

    return 0;
}
