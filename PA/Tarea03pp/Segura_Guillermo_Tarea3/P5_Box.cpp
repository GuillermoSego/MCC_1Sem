
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

    // Declaración de una función amigo
    friend double volumen(const Box& r);

};

// Definición de la friend function
double volumen(const Box& r) {
    return r.heigth * r.length * r.breadth;
}

int main() {
    Box Cajita_Feliz(3, 4, 5);
    std::cout << "El volumen: " << volumen(Cajita_Feliz) << std::endl; // Usa la función amiga
    return 0;
}