#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;  

public:

    Electric_Field() {
        E = new double[3]{0.0, 0.0, 0.0};
    }

    Electric_Field(double x, double y, double z) {
        E = new double[3]{x, y, z};
    }

    ~Electric_Field() {
        delete[] E;
    }

    
    double getX() const { return E[0]; }
    double getY() const { return E[1]; }
    double getZ() const { return E[2]; }


    void setX(double x) { E[0] = x; }
    void setY(double y) { E[1] = y; }
    void setZ(double z) { E[2] = z; }

    double calculateMagnitude() const {
        return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]);
    }

    double calculateInnerProduct() const {
        return E[0] * E[0] + E[1] * E[1] + E[2] * E[2];
    }
};

class Magnetic_Field {
private:
    double *B;  

public:
    Magnetic_Field() {
        B = new double[3]{0.0, 0.0, 0.0};
    }

    Magnetic_Field(double x, double y, double z) {
        B = new double[3]{x, y, z};
    }

    ~Magnetic_Field() {
        delete[] B;
    }

    double getX() const { return B[0]; }
    double getY() const { return B[1]; }
    double getZ() const { return B[2]; }

    void setX(double x) { B[0] = x; }
    void setY(double y) { B[1] = y; }
    void setZ(double z) { B[2] = z; }

    double calculateMagnitude() const {
        return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]);
    }

    void calculateUnitVector() const {
        double magnitude = calculateMagnitude();
        if (magnitude != 0) {
            std::cout << "Unit Vector: (" << B[0] / magnitude << ", "
                      << B[1] / magnitude << ", " << B[2] / magnitude << ")" << std::endl;
        } else {
            std::cout << "Cannot calculate unit vector of a zero vector." << std::endl;
        }
    }
};

int main() {
    Electric_Field E_default;
    Electric_Field E_components(1e5, 10.9, 1.7e2);

    std::cout << "Electric Field Magnitude: " << E_components.calculateMagnitude() << std::endl;
    std::cout << "Electric Field Inner Product: " << E_components.calculateInnerProduct() << std::endl;

    Magnetic_Field B_default;
    Magnetic_Field B_components(0.2, 0.4, 0.6);

    std::cout << "Magnetic Field Magnitude: " << B_components.calculateMagnitude() << std::endl;
    B_components.calculateUnitVector();

    return 0;
}
