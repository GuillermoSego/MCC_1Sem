
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 3x3
    Eigen::Matrix3d A; 

    // Llenar la matriz con valores
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 10;

    // Crear un vector de tamaño 3
    Eigen::Vector3d b;  // Vector3d es un vector de tamaño 3 de doubles
    b << 3, 3, 4;

    // Resolver el sistema lineal Ax = b
    Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);

    std::cout << "Solución del sistema lineal Ax = b:" << std::endl;
    std::cout << x << std::endl;

    return 0;
}
