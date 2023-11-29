
# include <iostream>
# include <string>

// Clase base: Vehicle
class Vehicle {
protected:
    std::string brand;

public:

    // Constructor
    Vehicle(const std::string& brand) 
        : brand(brand) {}

    // Metodo para mostrar el atributo brand
    void display() const {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Clase derivada: Car
class Car : public Vehicle {
private:
    int numDoors;

public:

    // Constructor
    /*
    La clase derivada tiene los mismos métodos y atributos que la clase base, por lo que
    el atributo brand se puede utilizar para un constructor a pesar de no estar declarado
    en los atributos locales de esta clase.
    */
    Car(const std::string& brand, int numDoors) 
        : Vehicle(brand), numDoors(numDoors) {}

    // Modificación del método display
    void display() const {
        Vehicle::display();
        // Se añade característica especial
        std::cout << "Número de puertas: " << numDoors << std::endl;
    }
};

// Clase derivada: Bike
class MotorBike : public Vehicle {
private:
    bool hasBasket;

public:

    // Constructor
    MotorBike(const std::string& brand, bool hasBasket) 
        : Vehicle(brand), hasBasket(hasBasket) {}

    // Modificación del método display de la clase base
    void display() const {
        Vehicle::display();
        std::cout << "Es estándar: " << (hasBasket ? "Si" : "No") << std::endl;
    }

};

int main() {

    Vehicle Example("Porshe");
    Example.display();

    Car Car1("Toyota", 4);
    Car1.display();

    MotorBike Bike1("Susuki", true);
    Bike1.display();

    return 0;
}
