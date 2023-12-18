#include <iostream>

class Shape {
public:
    virtual double calculateArea() const = 0; 
};

class Rectangle : public Shape {
public:
    double length;
    double width;

    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }
};

class Cuboid : public Rectangle {
public:
    double height;

    Cuboid(double l, double w, double h) : Rectangle(l, w), height(h) {}

    double calculateVolume() const {
        return length * width * height;
    }
};

int main() {
   
    Cuboid myCuboid(5, 6, 7);

    
    std::cout << "Rectangle Area: " << myCuboid.calculateArea() << std::endl;

    
    std::cout << "Cuboid Volume: " << myCuboid.calculateVolume() << std::endl;

    return 0;
}