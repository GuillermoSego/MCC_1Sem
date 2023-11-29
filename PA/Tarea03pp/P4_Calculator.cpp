
# include <iostream>
# include <complex>

class Calculator {

public:
    // Constructor
    Calculator() {}

    // Suma sobrecargados
    double Sum(double d1, double d2) {
        return d1 + d2;
    }

    int Sum(int e1, int e2) {
        return e1 + e2;
    }

    std::complex<double> Sum(const std::complex<double>& c1, const std::complex<double>& c2) {
        return c1 + c2;
    }
}; 

int main() {
    Calculator calc;

    // Enteros
    std::cout << "Suma de enteros: " << calc.Sum(5, 3) << std::endl;

    // Doubles
    std::cout << "Suma de doubles: " << calc.Sum(2.512, 3.53) << std::endl;

    // Complejos
    std::complex<double> c1(2, 3), c2(3, 4);
    std::complex<double> Result = calc.Sum(c1, c2);
    std::cout << "Suma de complejos: " << Result.real() << " + " << Result.imag() << "i" << std::endl;

    return 0;
}
