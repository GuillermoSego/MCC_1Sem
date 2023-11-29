
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 3x3
    Eigen::Matrix3d A;

    // Llenar la matriz con valores
    A << 4, 3, 8,
         9, 5, 1,
         2, 7, 6;

    // Realizar la descomposición LU de la matriz A
    Eigen::FullPivLU<Eigen::Matrix3d> lu(A);

    // Extraer las matrices L y U
    Eigen::Matrix3d L = lu.matrixLU().triangularView<Eigen::Lower>();
    Eigen::Matrix3d U = lu.matrixLU().triangularView<Eigen::Upper>();

    std::cout << "Matriz L (Triangular Inferior):" << std::endl;
    std::cout << L << std::endl;

    std::cout << "Matriz U (Triangular Superior):" << std::endl;
    std::cout << U << std::endl;

    return 0;
}
