#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int id;
    char grade;

public:
    // Default constructor
    Student() : name(""), id(0), grade('N') {}
    
    // Parameterized constructor
    Student(string studentName, int studentId, char studentGrade) : 
        name(studentName), id(studentId), grade(studentGrade) {}
    
    // Setters
    void setName(string studentName) {
        name = studentName;
    }
    
    void setId(int studentId) {
        id = studentId;
    }
    
    void setGrade(char studentGrade) {
        grade = studentGrade;
    }
    
    // Getters
    string getName() const {
        return name;
    }
    
    int getId() const {
        return id;
    }
    
    char getGrade() const {
        return grade;
    }
    
    // Display student information
    void displayInfo() const {
        cout << "Student Information:" << endl;
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Grade: " << grade << endl;
    }
};

// Example usage
int main() {
    // Create a student using the default constructor and set values
    Student student1;
    student1.setName("John Doe");
    student1.setId(10001);
    student1.setGrade('A');
    
    // Display student1's information
    cout << "Student 1:" << endl;
    student1.displayInfo();
    
    // Create another student using the parameterized constructor
    Student student2("Jane Smith", 10002, 'B');
    
    // Display student2's information
    cout << "\nStudent 2:" << endl;
    student2.displayInfo();
    
    // Update student2's grade and display the updated information
    student2.setGrade('A');
    cout << "\nAfter updating Student 2's grade:" << endl;
    student2.displayInfo();
    
    return 0;
}