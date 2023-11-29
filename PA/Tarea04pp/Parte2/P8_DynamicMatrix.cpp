
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Dimensiones de la matriz y el vector
    int rows = 4;
    int cols = 3;

    // Crear una matriz de tamaño dinámico
    Eigen::MatrixXd mat(rows, cols);  // MatrixXd es una matriz de tamaño dinámico de doubles
    // xd

    // Llenar la matriz con valores
    mat << 1, 0, 0,
           0, 1, 0,
           0, 0, 1,
           0, 0, 1;

    // Crear un vector de tamaño dinámico
    Eigen::VectorXd vec(cols); 
    vec << 1, 2, 3;

    // Realizar la multiplicación de la matriz por el vector
    Eigen::VectorXd result = mat * vec;

    std::cout << "Resultado de la multiplicación matriz-vector:" << std::endl;
    std::cout << result << std::endl;

    return 0;
}
