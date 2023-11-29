
# include <iostream>
# include <Eigen/Dense>

int main() {
    
    // Crear un vector aleatorio de tamaño 5
    Eigen::VectorXd vec(5);  
    vec.setRandom();  // Llenamos el vector con valores aleatorios

    std::cout << "Vector original:" << std::endl;
    std::cout << vec << std::endl;

    // Calcular la norma Euclidiana (L2) del vector
    double l2Norm = vec.norm();
    std::cout << "Norma Euclidiana (L2) del vector: " << l2Norm << std::endl;

    // Normalizar el vector
    Eigen::VectorXd normalizedVec = vec.normalized();
    std::cout << "Vector normalizado:" << std::endl;
    std::cout << normalizedVec << std::endl;

    return 0;
}
