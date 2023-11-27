
# include <iostream>
# include <cmath> 

// Clase base abstracta para formas geométricas
class Shape {
public:
    // Destructor virtual para permitir un comportamiento de destrucción adecuado en clases hijas
    virtual ~Shape() {}

    // Método virtual para calcular el área. Debe ser implementado por las clases hijas
    virtual double area() const = 0;
};

// Clase círculo
class Circle : public Shape {
private:
    double radius;  

public:
    // Constructor para inicializar el círculo con un radio específico
    Circle(double r) : radius(r) {}

    // Implementación del método de área para calcular el área de un círculo
    double area() const {
        return M_PI * radius * radius;  // Área = π * r^2
    }
};

// Clase rectángulo
class Rectangle : public Shape {
private:
    double width, height; 

public:
    // Constructor para inicializar el rectángulo con un ancho y un alto específicos
    Rectangle(double w, double h) : width(w), height(h) {}

    // Implementación del método de área para calcular el área de un rectángulo
    double area() const {
        return width * height;  // Área = ancho * alto
    }
};

// Clase triángulo
class Triangle : public Shape {
private:
    double base, height; 

public:
    // Constructor para inicializar el triángulo con una base y una altura específicas
    Triangle(double b, double h) : base(b), height(h) {}

    // Implementación del método de área para calcular el área de un triángulo
    double area() const {
        return 0.5 * base * height;  // Área = 1/2 * base * altura
    }
};

// Clase polígono regular
class Polygon : public Shape {
private:
    int n_sides;      
    double side_len; 

public:
    // Constructor para inicializar el polígono con un número de lados y una longitud de lado específicos
    Polygon(int n, double s) : n_sides(n), side_len(s) {}

    // Implementación del método de área para calcular el área de un polígono regular
    double area() const {
        // Área = (1/4) * n * s^2 * (1/tan(π/n))
        return (1/4.0) * n_sides * side_len * side_len * (1 / tan(M_PI / n_sides));
    }
};


int main() {
    // Crear objetos de las clases derivadas
    Circle circle(5);               
    Rectangle rectangle(4, 5);      
    Triangle triangle(3, 4);        
    Polygon hexagon(6, 3);          

    // Imprimir el área de cada objeto utilizando el método de área correspondiente
    std::cout << "Área del círculo: " << circle.area() << std::endl;
    std::cout << "Área del rectángulo: " << rectangle.area() << std::endl;
    std::cout << "Área del triángulo: " << triangle.area() << std::endl;
    std::cout << "Área del hexágono: " << hexagon.area() << std::endl; 

    return 0;
}
