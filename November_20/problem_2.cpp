#include <iostream>

using namespace std;

class Rectangle {
private:
    double width;
    double height;

public:
    Rectangle() : width(0.0), height(0.0) {}
    Rectangle(double side) : width(side), height(side) {}
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculate_area() {
        return width * height;
    }

    double get_width() {
        return width;
    }

    double get_height() {
        return height;
    }
};

int main() {
    Rectangle default_rectangle;
    Rectangle rectangle_of_square(5.0);
    Rectangle custom_rectangle(4.0, 6.0);

    cout << "Default Rectangle: " << default_rectangle.calculate_area() << endl;
    cout << "Square Rectangle: " << rectangle_of_square.calculate_area() << endl;
    cout << "Custom Rectangle: " << custom_rectangle.calculate_area() << endl;

    return 0;
}