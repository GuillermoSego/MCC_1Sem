
# include <iostream>
# include <Eigen/Sparse>
# include <Eigen/Dense>
# include <chrono>

int main() {
    
    // Crear una matriz dispersa de tamaño 100x100
    Eigen::SparseMatrix<double> sparseMat(100, 100);

    
    // Llenar la matriz dispersa con algunos elementos no cero
    for (int i = 0; i < 100; ++i) {
        sparseMat.insert(i, i) = 2; // llenar la diagonal con 2
    }

    // Crear un vector denso de tamaño 100
    Eigen::VectorXd vec = Eigen::VectorXd::Random(100);

    // Multiplicación matriz - vector con la matriz dispersa
    auto startSparse = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd resultSparse = sparseMat * vec;
    auto endSparse = std::chrono::high_resolution_clock::now();

    // Convertir la matriz dispersa a un formato denso
    Eigen::MatrixXd denseMat = Eigen::MatrixXd(sparseMat);


    // Multiplicación matriz-vector con la matriz densa
    auto startDense = std::chrono::high_resolution_clock::now();
    Eigen::VectorXd resultDense = denseMat * vec;
    auto endDense = std::chrono::high_resolution_clock::now();


    // Comparar el tiempo tomado para cada operación
    auto durationSparse = std::chrono::duration_cast<std::chrono::microseconds>(endSparse - startSparse).count();
    auto durationDense = std::chrono::duration_cast<std::chrono::microseconds>(endDense - startDense).count();

    std::cout << "Tiempo para la multiplicación con la matriz dispersa: " << durationSparse << " microsegundos" << std::endl;
    std::cout << "Tiempo para la multiplicación con la matriz densa: " << durationDense << " microsegundos" << std::endl;

    return 0;
}
