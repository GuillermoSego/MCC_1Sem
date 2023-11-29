
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 4x4
    Eigen::Matrix4d mat;  

    // Llenar la matriz con valores
    mat << 2, 1, 3, -2,
           3, -4, 2, 5,
           1, 6, 2, 1,
           -2, 3, -2, 3;

    // Calcular el determinante de la matriz
    double det = mat.determinant();
    std::cout << "Determinante de la matriz: " << det << std::endl;

    // Verificar si la matriz es invertible (determinante no es cero)
    if (det != 0) {
        // Calcular la inversa de la matriz
        Eigen::Matrix4d inv = mat.inverse();
        std::cout << "Inversa de la matriz:" << std::endl;
        std::cout << inv << std::endl;
    } else {
        // Matriz no invertible
        std::cout << "La matriz no es invertible (determinante es cero)" << std::endl;
    }

    return 0;
}
