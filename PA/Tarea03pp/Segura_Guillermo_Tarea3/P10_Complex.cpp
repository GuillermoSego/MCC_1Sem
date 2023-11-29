
# include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double real, double imag) : real(real), imag(imag) {}

    // Sobrecarga del operador +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Sobrecarga del operador -
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Sobrecarga del operador *
    Complex operator*(const Complex& other) const {
        double newReal = real * other.real - imag * other.imag;
        double newImag = real * other.imag + imag * other.real;
        return Complex(newReal, newImag);
    }

    // Sobrecarga del operador /
    Complex operator/(const Complex& other) const {
        double divisor = other.real * other.real + other.imag * other.imag;
        double newReal = (real * other.real + imag * other.imag) / divisor;
        double newImag = (imag * other.real - real * other.imag) / divisor;
        return Complex(newReal, newImag);
    }

    // Función amiga para imprimir el número complejo
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real << " + " << c.imag << "i";
    return os;
}

int main() {
    Complex c1(3, 4), c2(1, 2);

    std::cout << "c1 + c2: " << c1 + c2 << std::endl;
    std::cout << "c1 - c2: " << c1 - c2 << std::endl;
    std::cout << "c1 * c2: " << c1 * c2 << std::endl;
    std::cout << "c1 / c2: " << c1 / c2 << std::endl;

    return 0;
}
