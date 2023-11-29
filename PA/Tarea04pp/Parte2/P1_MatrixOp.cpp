
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 3x3
    Eigen::Matrix3d mat;  // Matrix3d es una matriz 3x3 de doubles

    // Llenar la matriz con valores
    mat << 1, 2, 3,
           4, 5, 6,
           7, 8, 9;

    // Crear un vector de tamaño 3
    Eigen::Vector3d vec;  // Vector3d es un vector de tamaño 3 de doubles
    vec << 1, 2, 3;

    // Multiplicación de la matriz por el vector
    Eigen::Vector3d result = mat * vec;

    std::cout << "Resultado de la multiplicación matriz-vector:" << std::endl;
    std::cout << result << std::endl;

    // Calcular la transpuesta de la matriz
    Eigen::Matrix3d transpuesta = mat.transpose();

    std::cout << "Transpuesta de la matriz:" << std::endl;
    std::cout << transpuesta << std::endl;

    return 0;
}
