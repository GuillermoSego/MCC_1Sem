
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
    // Constructor de la clase con parámetros
    Car(const std::string& make, const std::string& model, int year)
        : make(make), model(model), year(year) {
        if (year < 1886) {
            // Solo se aceptan modelos de +1886
            this->year = 1886;
        }
    }

    // Constructor de la clase por defecto
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
    // Crear un objeto Car usando parámetros
    Car myCar("Toyota", "Corolla", 2015);

    // Crear un objeto Car con el constructor por defecto
    Car myCar2;

    // Acceder a los datos del objeto construido por parámetros
    std::cout << "Objeto construido por parámetros: " << std::endl;;
    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    // Acceder a los datos del objeto construido por default
    std::cout << "Objeto construido por default: " << std::endl;;
    std::cout << "Make: " << myCar2.getMake() << std::endl;
    std::cout << "Model: " << myCar2.getModel() << std::endl;
    std::cout << "Year: " << myCar2.getYear() << std::endl;

    // Modificar los datos usando setters
    myCar.setMake("Honda");
    myCar.setModel("Civic");
    myCar.setYear(2020);

    myCar2.setMake("Lexus");
    myCar2.setModel("LFA");
    myCar2.setYear(2019);

    // Acceder a los datos modificados
    std::cout << "Modificación objeto construido por parámetros" << std::endl;
    std::cout << "Make: " << myCar.getMake() << std::endl;
    std::cout << "Model: " << myCar.getModel() << std::endl;
    std::cout << "Year: " << myCar.getYear() << std::endl;

    std::cout << "Modificación objeto construido por defecto" << std::endl;
    std::cout << "Make: " << myCar2.getMake() << std::endl;
    std::cout << "Model: " << myCar2.getModel() << std::endl;
    std::cout << "Year: " << myCar2.getYear() << std::endl;

    return 0;
}