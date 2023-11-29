
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz 5x5
    Eigen::Matrix<double, 5, 5> mat;  
    mat.setRandom();  // Valores aleatorios

    std::cout << "Matriz original 5x5:" << std::endl;
    std::cout << mat << std::endl;

    // Extraer un bloque 3x3 de la matriz
    Eigen::Matrix3d block3x3 = mat.block<3, 3>(1, 1);  // Extraer el bloque que comienza en (1,1)

    std::cout << "Bloque 3x3 extraído de la matriz:" << std::endl;
    std::cout << block3x3 << std::endl;

    // Reemplazar un bloque 2x2 en la matriz con la matriz identidad
    mat.block<2, 2>(0, 0).setIdentity();  // Reemplazar el bloque que comienza en (0,0)

    std::cout << "Matriz después de reemplazar un bloque 2x2 con la matriz identidad:" << std::endl;
    std::cout << mat << std::endl;

    return 0;
}
