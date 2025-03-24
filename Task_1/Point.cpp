#include <iostream>
using namespace std;

class Point {
private:
    double x;
    double y;

public:
    // Default constructor - creates origin point (0,0)
    Point() : x(0.0), y(0.0) {}
    
    // Parameterized constructor
    Point(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}
    
    // Setters
    void setX(double xCoord) {
        x = xCoord;
    }
    
    void setY(double yCoord) {
        y = yCoord;
    }
    
    // Getters
    double getX() const {
        return x;
    }
    
    double getY() const {
        return y;
    }
    
    // Calculate squared distance from origin (0,0)
    double squaredDistanceFromOrigin() const {
        return x*x + y*y;
    }
    
    // Calculate distance from origin without sqrt
    // We'll mention that this is an approximation
    double distanceFromOrigin() const {
        double squared = squaredDistanceFromOrigin();
        
        // Newton's method for approximating square root
        if (squared == 0) return 0;
        
        double guess = squared / 2.0;
        for (int i = 0; i < 10; i++) {
            guess = 0.5 * (guess + squared / guess);
        }
        
        return guess;
    }
    
    // Calculate squared distance from another point
    double squaredDistanceFrom(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return dx*dx + dy*dy;
    }
    
    // Calculate distance from another point without sqrt
    double distanceFrom(const Point& other) const {
        double squared = squaredDistanceFrom(other);
        
        // Newton's method for approximating square root
        if (squared == 0) return 0;
        
        double guess = squared / 2.0;
        for (int i = 0; i < 10; i++) {
            guess = 0.5 * (guess + squared / guess);
        }
        
        return guess;
    }
    
    // Display point information
    void displayPoint() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
        cout << "Distance from origin: " << distanceFromOrigin() << endl;
    }
};

// Example usage
int main() {
    // Create a point at origin using default constructor
    Point origin;
    cout << "Origin point:" << endl;
    origin.displayPoint();
    
    // Create a point using parameterized constructor
    Point p1(3.0, 4.0);
    cout << "\nPoint 1:" << endl;
    p1.displayPoint();
    
    // Create another point
    Point p2(1.0, 1.0);
    cout << "\nPoint 2:" << endl;
    p2.displayPoint();
    
    // Calculate and display distance between p1 and p2
    cout << "\nDistance between Point 1 and Point 2: " << p1.distanceFrom(p2) << endl;
    
    // Modify p1 coordinates
    p1.setX(5.0);
    p1.setY(12.0);
    cout << "\nModified Point 1:" << endl;
    p1.displayPoint();
    
    return 0;
}