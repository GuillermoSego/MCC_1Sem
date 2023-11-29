
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 3x3
    Eigen::Matrix3d mat; 

    // Llenar la matriz con valores
    mat << 1, 2, 3,
           4, 5, 6,
           7, 8, 9;

    std::cout << "Matriz original:" << std::endl;
    std::cout << mat << std::endl;

    // Calcular la suma de cada fila
    Eigen::RowVectorXd sumRow = mat.rowwise().sum();
    std::cout << "Suma de cada fila:" << std::endl;
    std::cout << sumRow << std::endl;

    // Calcular la media de cada fila
    Eigen::RowVectorXd meanRow = mat.rowwise().mean();
    std::cout << "Media de cada fila:" << std::endl;
    std::cout << meanRow << std::endl;

    // Normalizar cada columna de la matriz
    // Iterar sobre cada columna y normalizar
    for (int i = 0; i < mat.cols(); ++i) {
        mat.col(i).normalize();
    }

    std::cout << "Matriz después de normalizar cada columna:" << std::endl;
    std::cout << mat << std::endl;

    return 0;
}
