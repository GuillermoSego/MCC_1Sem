
# include <iostream>
# include <string>

// Clase base: Vehicle
class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(const std::string& brand) : brand(brand) {}

    void display() const {
        std::cout << "Brand: " << brand << std::endl;
    }

    // Función virtual fuelEfficiency
    virtual double fuelEfficiency() const {
        return 0.0;  // Valor por defecto o base
    }
};

// Clase derivada: Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& brand, int numDoors) : Vehicle(brand), numDoors(numDoors) {}

    void display() const {
        Vehicle::display();
        std::cout << "Número de puertas: " << numDoors << std::endl;
    }

    // Sobreescritura de fuelEfficiency
    double fuelEfficiency() const override {
        return 15.0;  // Supongamos que este es el valor para un Car
    }
};

// Clase derivada: MotorBike
class MotorBike : public Vehicle {
private:
    bool hasBasket;

public:
    MotorBike(const std::string& brand, bool hasBasket) : Vehicle(brand), hasBasket(hasBasket) {}

    void display() const {
        Vehicle::display();
        std::cout << "Es estándar: " << (hasBasket ? "Si" : "No") << std::endl;
    }

    // Sobreescritura de fuelEfficiency
    double fuelEfficiency() const override {
        return 35.0;  // Supongamos que este es el valor para una MotorBike
    }
};

int main() {
    Vehicle example("Porshe");
    example.display();
    std::cout << "Eficiencia de combustible: " << example.fuelEfficiency() << std::endl;

    Car car1("Toyota", 4);
    car1.display();
    std::cout << "Eficiencia de combustible: " << car1.fuelEfficiency() << std::endl;

    MotorBike bike1("Susuki", true);
    bike1.display();
    std::cout << "Eficiencia de combustible: " << bike1.fuelEfficiency() << std::endl;

    return 0;
}
