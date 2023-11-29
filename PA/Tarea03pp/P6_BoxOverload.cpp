
# include <iostream>

class Box {

private:

    // Atributos
    double heigth;
    double length;
    double breadth;

public:

    // Constructor
    Box(double heigth, double length, double breadth) 
        : heigth(heigth), length(length), breadth(breadth) {}

    // Sobrecarga del operador +
    Box operator+(const Box& b) const {
        return Box(heigth + b.heigth, length + b.length, breadth + b.breadth);
    }

    // Método para calcular el volumen
    double volume() const {
        return heigth * length * breadth;
    }
};

int main() {
    Box box1(3, 4, 5);
    Box box2(2, 3, 1);

    Box boxSum = box1 + box2; // Uso de la sobrecarga del operador +
    std::cout << "El volumen de la primera caja: " << box1.volume() << std::endl;
    std::cout << "El volumen de la segunda caja: " << box2.volume() << std::endl;
    std::cout << "El volumen de la caja sumada: " << boxSum.volume() << std::endl;

    return 0;
}
