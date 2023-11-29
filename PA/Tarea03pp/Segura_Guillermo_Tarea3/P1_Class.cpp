
# include <iostream>
# include <string>

class Car {

// Atributos privados
private:
    std::string make;
    std::string model;
    int year;

// Métodos públicos
public:
    // Constructor de la clase
    Car()
        : make("Desconocido"), model("Desconocido"), year(0) { // Inicializamos
    }

    // Metodos para get
    int getYear() const {
        return year;
    }

    std::string getMake() const {
        return make;
    }

    std::string getModel() const {
        return model;
    }

    // Métodos para set
    void setYear(int newYear) {
        this->year = newYear;
    }

    void setMake(const std::string& newMake) {
        this->make = newMake;
    }

    void setModel(const std::string& newModel) {
        this->model = newModel;
    }


};

int main() {
    // Crear un objeto Car
    Car myCar;

    // Acceder a los datos usando getters
    // Imprimir valores default
    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    // Agregar datos usando setters
    myCar.setMake("Honda");
    myCar.setModel("Civic");
    myCar.setYear(2020);

    // Acceder a los datos
    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    return 0;
}