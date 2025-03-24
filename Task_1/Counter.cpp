#include <iostream>
using namespace std;

class Counter {
private:
    int count;

public:
    // Default constructor
    Counter() : count(0) {}
    
    // Parameterized constructor to initialize with a specific value
    Counter(int initialValue) : count(initialValue) {}
    
    // Increment the counter by 1
    void increment() {
        count++;
    }
    
    // Increment the counter by a specified amount
    void increment(int value) {
        count += value;
    }
    
    // Decrement the counter by 1
    void decrement() {
        count--;
    }
    
    // Decrement the counter by a specified amount
    void decrement(int value) {
        count -= value;
    }
    
    // Reset counter to 0
    void reset() {
        count = 0;
    }
    
    // Get the current count
    int getCount() const {
        return count;
    }
    
    // Display the current count
    void displayCount() const {
        cout << "Current count: " << count << endl;
    }
};

// Example usage
int main() {
    // Create a counter with default value (0)
    Counter counter1;
    cout << "Initial count: " << counter1.getCount() << endl;
    
    // Increment a few times
    counter1.increment();
    counter1.increment();
    counter1.increment();
    counter1.displayCount();
    
    // Increment by a specific value
    counter1.increment(5);
    counter1.displayCount();
    
    // Decrement
    counter1.decrement();
    counter1.displayCount();
    
    // Decrement by a specific value
    counter1.decrement(2);
    counter1.displayCount();
    
    // Create a counter with an initial value
    Counter counter2(10);
    cout << "\nCounter 2 initial value: " << counter2.getCount() << endl;
    
    // Increment counter2
    counter2.increment();
    counter2.displayCount();
    
    // Reset counter2
    counter2.reset();
    cout << "After reset: " << counter2.getCount() << endl;
    
    return 0;
}