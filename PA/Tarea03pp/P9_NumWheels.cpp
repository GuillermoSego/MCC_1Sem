
# include <iostream>
# include <string>

// Clase base abstracta: Vehicle
class Vehicle {
protected:
    std::string brand;

public:
    Vehicle(const std::string& brand) : brand(brand) {}

    void display() const {
        std::cout << "Brand: " << brand << std::endl;
    }

    virtual double fuelEfficiency() const {
        return 0.0;
    }

    virtual int numWheels() const = 0; // Función virtual pura
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

    double fuelEfficiency() const override {
        return 15.0;
    }

    int numWheels() const override {
        return 4;
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

    double fuelEfficiency() const override {
        return 35.0;
    }

    int numWheels() const override {
        return 2;
    }
};

int main() {
    // La clase Vehicle ahora es abstracta y no se pueden crear instancias directamente
    // Vehicle example("Porshe"); // Esto provocará un error de compilación

    Car car1("Toyota", 4);
    car1.display();
    std::cout << "Eficiencia de combustible: " << car1.fuelEfficiency() << ", Número de ruedas: " << car1.numWheels() << std::endl;

    MotorBike bike1("Susuki", true);
    bike1.display();
    std::cout << "Eficiencia de combustible: " << bike1.fuelEfficiency() << ", Número de ruedas: " << bike1.numWheels() << std::endl;

    return 0;
}
