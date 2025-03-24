#include <iostream>
using namespace std;

class Calculator {
private:
    double num1;
    double num2;

public:
    // Default constructor
    Calculator() : num1(0), num2(0) {}
    
    // Parameterized constructor
    Calculator(double a, double b) : num1(a), num2(b) {}
    
    // Setters
    void setNum1(double a) {
        num1 = a;
    }
    
    void setNum2(double b) {
        num2 = b;
    }
    
    // Getters
    double getNum1() const {
        return num1;
    }
    
    double getNum2() const {
        return num2;
    }
    
    // Arithmetic operations
    double add() const {
        return num1 + num2;
    }
    
    double subtract() const {
        return num1 - num2;
    }
    
    double multiply() const {
        return num1 * num2;
    }
    
    double divide() const {
        if (num2 == 0) {
            throw "Error: Division by zero";
        }
        return num1 / num2;
    }
};

// Example usage
int main() {
    // Create calculator with initial values
    Calculator calc(10, 5);
    
    // Perform operations
    cout << "Number 1: " << calc.getNum1() << endl;
    cout << "Number 2: " << calc.getNum2() << endl;
    cout << "Addition: " << calc.add() << endl;
    cout << "Subtraction: " << calc.subtract() << endl;
    cout << "Multiplication: " << calc.multiply() << endl;
    
    try {
        cout << "Division: " << calc.divide() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    
    // Change values and perform another operation
    calc.setNum1(20);
    calc.setNum2(4);
    cout << "\nAfter changing values:" << endl;
    cout << "Number 1: " << calc.getNum1() << endl;
    cout << "Number 2: " << calc.getNum2() << endl;
    cout << "Division: " << calc.divide() << endl;
    
    // Test division by zero
    Calculator calc2(10, 0);
    try {
        cout << "\nTesting division by zero:" << endl;
        cout << "Division: " << calc2.divide() << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }
    
    return 0;
}