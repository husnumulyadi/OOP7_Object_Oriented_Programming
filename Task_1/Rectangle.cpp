#include <iostream>
using namespace std;

class Rectangle {
private:
    double length;
    double width;

public:
    // Default constructor
    Rectangle() : length(0.0), width(0.0) {}
    
    // Parameterized constructor
    Rectangle(double l, double w) : length(l), width(w) {}
    
    // Setters
    void setLength(double l) {
        if (l >= 0) {
            length = l;
        } else {
            cout << "Error: Length cannot be negative. Setting to 0." << endl;
            length = 0;
        }
    }
    
    void setWidth(double w) {
        if (w >= 0) {
            width = w;
        } else {
            cout << "Error: Width cannot be negative. Setting to 0." << endl;
            width = 0;
        }
    }
    
    // Getters
    double getLength() const {
        return length;
    }
    
    double getWidth() const {
        return width;
    }
    
    // Calculate area
    double calculateArea() const {
        return length * width;
    }
    
    // Calculate perimeter
    double calculatePerimeter() const {
        return 2 * (length + width);
    }
    
    // Display rectangle information
    void displayInfo() const {
        cout << "Rectangle Information:" << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << calculateArea() << endl;
        cout << "Perimeter: " << calculatePerimeter() << endl;
    }
};

// Example usage
int main() {
    // Create a rectangle using the default constructor and set values
    Rectangle rect1;
    rect1.setLength(5.0);
    rect1.setWidth(3.0);
    
    // Display rectangle information
    cout << "Rectangle 1:" << endl;
    rect1.displayInfo();
    
    // Create another rectangle using the parameterized constructor
    Rectangle rect2(7.5, 4.2);
    
    // Display rectangle information
    cout << "\nRectangle 2:" << endl;
    rect2.displayInfo();
    
    // Calculate and display just the area
    cout << "\nArea of Rectangle 2: " << rect2.calculateArea() << endl;
    
    // Test with invalid input
    Rectangle rect3;
    rect3.setLength(-2.5);
    rect3.setWidth(3.0);
    
    cout << "\nRectangle 3:" << endl;
    rect3.displayInfo();
    
    return 0;
}