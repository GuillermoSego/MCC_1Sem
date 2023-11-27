 
# include <iostream>
# include <cmath> 
# include <vector>

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

/*
Función que acepta un puntero a la clase base y utiliza polimorfismo para llamar al 
método de cálculo de área correcto
*/
void printArea(Shape* shape) {
    std::cout << "Área: " << shape->area() << std::endl;
}

int main() {
    // Crear punteros a objetos de las clases derivadas usando memoria dinámica
    Shape* circle = new Circle(5);
    Shape* rectangle = new Rectangle(4, 5);
    Shape* triangle = new Triangle(3, 4);
    Shape* hexagon = new Polygon(6, 3);

    // Crear un vector y añadir los punteros a él
    std::vector<Shape*> shapes;
    shapes.push_back(circle);
    shapes.push_back(rectangle);
    shapes.push_back(triangle);
    shapes.push_back(hexagon);

    // Iterar sobre el vector
    for (std::vector<Shape*>::iterator i = shapes.begin(); i != shapes.end(); ++i) {
        printArea(*i);
    }

    // Liberar la memoria
    for (std::vector<Shape*>::iterator i = shapes.begin(); i != shapes.end(); ++i) {
        delete *i;
    }

    return 0;
}