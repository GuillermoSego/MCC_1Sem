
# include <iostream>
# include <vector>

const int size = 3;

// Función para verificar si es seguro colocar un número
bool eSeguro(std::vector<std::vector<int>>& sudoku, int fila, int columna, int num) {

    // Verificar fila y columna
    for (int i = 0; i < size; i++) {
        if (sudoku[fila][i] == num || sudoku[i][columna] == num) {
            return false;
        }
    }

    // Verificar cuadrícula 3x3
    int inicioFila = fila - fila % 3;
    int inicioColumna = columna - columna % 3;
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {

            if (sudoku[i + inicioFila][j + inicioColumna] == num) {
                return false;
            }
        }
    }


    return true;

}

// Función para resolver el Sudoku usando backtracking
bool resolverSudoku(std::vector<std::vector<int>>& sudoku) {

    int fila, columna;
    bool espacioLibre = false;

    for (fila = 0; fila < size; fila++) {
        for (columna = 0; columna < size; columna++) {

            if (sudoku[fila][columna] == 0) {
                espacioLibre = true;
                break;
            }
        }

        if (espacioLibre) {
            break;
        }
    }

    // Si no hay espacios libres, el Sudoku está resuelto
    if (!espacioLibre) {
        return true;
    }

    // Intentar colocar números del 1 al 9 en el espacio libre
    for (int num = 1; num <= 9; num++) {

        if (eSeguro(sudoku, fila, columna, num)) {
            sudoku[fila][columna] = num;

            // Recursividad
            if (resolverSudoku(sudoku)) {
                return true;
            }
            sudoku[fila][columna] = 0;
        }
    }
    return false;
}



int main() {

    std::vector<std::vector<int>> sudoku(size, std::vector<int>(size));
    std::cout << "Ingrese el Sudoku (use 0 para espacios vacíos):" << std::endl;

    // Leer el Sudoku del usuario
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> sudoku[i][j];
        }
    }

    if (resolverSudoku(sudoku)) {
        std::cout << "Sudoku resuelto:" << std::endl;
        for (const auto& fila : sudoku) {
            for (int num : fila) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No se pudo resolver el Sudoku." << std::endl;
    }

    return 0;

}
