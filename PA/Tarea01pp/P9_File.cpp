
# include <iostream>
# include <fstream>
# include <vector>
# include <numeric> 

int main() {
    std::string inputFilename = "numbers.txt";   // Nombre del archivo de entrada
    std::string outputFilename = "output.txt"; // Nombre del archivo de salida
    std::ifstream inputFile(inputFilename);    // Abrir archivo de entrada
    std::ofstream outputFile(outputFilename);  // Crear archivo de salida

    // Verificar si los archivos se abrieron correctamente
    if (!inputFile.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada\n";
        return 1;
    }
    if (!outputFile.is_open()) {
        std::cerr << "No se pudo crear el archivo de salida\n";
        return 2;
    }

    std::vector<double> numbers; // Vector para almacenar los números
    double number;

    // Leer números del archivo y almacenarlos en el vector
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    // Calcular la suma utilizando std::accumulate
    double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);

    // Calcular el promedio
    double average = numbers.empty() ? 0.0 : sum / numbers.size();

    // Escribir la suma y el promedio en el archivo de salida
    outputFile << "Suma: " << sum << std::endl;
    outputFile << "Promedio: " << average << std::endl;

    // Cerrar ambos archivos
    inputFile.close();
    outputFile.close();

    std::cout << "Programa terminado con éxito. Outputfile: " << outputFilename << std::endl;

    return 0;
}
