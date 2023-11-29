
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear una matriz simétrica 3x3
    Eigen::Matrix3d mat; 

    // Llenar la matriz con valores
    mat << 5.0, -1.778, 0.0,
    -1.778, 9.0, -1.778,
    0.0, -1.778, 10.0;

    // Calcular los eigenvalores y autovectores de la matriz
    // Utilizamos Eigen::SelfAdjointEigenSolver para matrices simétricas
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> solver(mat);

    // Verificar si el cálculo fue exitoso
    if (solver.info() == Eigen::Success) {
        // Imprimir los eigenvalores
        std::cout << "eigenvalores:" << std::endl;
        std::cout << solver.eigenvalues() << std::endl;

        // Imprimir los eigenvectores
        std::cout << "Eigenvectores:" << std::endl;
        std::cout << solver.eigenvectors() << std::endl;
    } else {
        // Informar si no se pudo calcular
        std::cout << "La descomposición de eigenvalores no tuvo éxito" << std::endl;
    }

    return 0;
}
