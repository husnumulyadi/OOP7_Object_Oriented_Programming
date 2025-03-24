# TASK 1: C++ Basic Classes Collection

## Daftar Kelas

- [Calculator](#calculator-class) - Kelas untuk operasi aritmatika dasar
- [Student](#student-class) - Kelas untuk menyimpan informasi mahasiswa
- [Rectangle](#rectangle-class) - Kelas untuk menghitung luas dan keliling persegi panjang
- [Counter](#counter-class) - Kelas penghitung sederhana
- [Point](#point-class) - Kelas yang mewakili titik dalam 2D

## Calculator Class

Kelas `Calculator` menyediakan fungsionalitas untuk melakukan operasi aritmatika dasar (penjumlahan, pengurangan, perkalian, dan pembagian) pada dua angka.

```cpp
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
```

### Penjelasan

- **Data Members:** Menyimpan dua bilangan (num1 dan num2) yang akan dioperasikan.
- **Constructor:**
    - Default constructor menginisialisasi kedua bilangan dengan 0.
    - Parameterized constructor menginisialisasi dengan nilai yang diberikan.
- **Setter & Getter:** Memungkinkan pengaturan dan pengambilan nilai dari num1 dan num2.
- **Operasi Aritmatika:** Metode add(), subtract(), multiply(), dan divide() untuk melakukan operasi dasar. Pada pembagian, terdapat penanganan exception apabila pembagian dengan nol terjadi.

### Contoh Penggunaan

```cpp
int main() {
    // Create calculator with initial values
    Calculator calc(10, 5);
    
    // Perform operations
    cout << "Addition: " << calc.add() << endl;         // 15
    cout << "Subtraction: " << calc.subtract() << endl; // 5
    cout << "Multiplication: " << calc.multiply() << endl; // 50
    
    try {
        cout << "Division: " << calc.divide() << endl;  // 2
    } catch (const char* msg) {
        cout << msg << endl;
    }
    
    return 0;
}
```

## Student Class

Kelas `Student` digunakan untuk menyimpan dan mengelola informasi mahasiswa seperti nama, ID, dan nilai.

```cpp
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
```

### Penjelasan

- Menyimpan informasi siswa (nama, ID, nilai)
- **Data Members:** Menggunakan tipe string untuk nama, int untuk ID, dan char untuk nilai.
- **Constructor:**
  - Default constructor menginisialisasi nilai dengan string kosong, nol, dan nilai default 'N'.
  - Parameterized constructor menerima input untuk nama, ID, dan nilai.
- **Setter & Getter:** Mengatur dan mengambil nilai masing-masing atribut.
- **Display Info:** Method displayInfo() menampilkan informasi mahasiswa dengan format yang terstruktur.

### Contoh Penggunaan

```cpp
int main() {
    // Create student with constructor and set values
    Student student1;
    student1.setName("John Doe");
    student1.setId(10001);
    student1.setGrade('A');
    
    // Display information
    student1.displayInfo();
    
    // Create with parameterized constructor
    Student student2("Jane Smith", 10002, 'B');
    student2.displayInfo();
    
    return 0;
}
```

## Rectangle Class

Kelas `Rectangle` mewakili persegi panjang dan dapat menghitung luas dan keliling.

```cpp
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
```

### Penjelasan

- **Data Members:** Menyimpan panjang dan lebar persegi panjang.
- **Constructor:**
  - Default constructor menginisialisasi panjang dan lebar ke 0.
  - Parameterized constructor menginisialisasi dengan nilai yang diberikan.
- **Setter dengan Validasi:** Setter memastikan panjang dan lebar tidak negatif; jika negatif, secara otomatis diatur ke 0 dan menampilkan pesan error.
- **Method Perhitungan:**
  - calculateArea() untuk menghitung luas.
  - calculatePerimeter() untuk menghitung keliling.
- **Display Info:** Method displayInfo() menampilkan semua informasi terkait persegi panjang.

### Contoh Penggunaan

```cpp
int main() {
    Rectangle rect(5.0, 3.0);
    
    cout << "Area: " << rect.calculateArea() << endl;       // 15
    cout << "Perimeter: " << rect.calculatePerimeter() << endl; // 16
    
    rect.displayInfo();
    
    return 0;
}
```

## Counter Class

Kelas `Counter` menyediakan fungsionalitas penghitung yang dapat diinkremen, didekremen, dan direset.

```cpp
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
```

### Penjelasan

- **Data Members:** Variabel count yang menyimpan nilai penghitung.

- **Constructor:**

  - Default constructor mengatur count ke 0.

  - Parameterized constructor menginisialisasi dengan nilai tertentu.

- **Method Overloading:** Method increment() dan decrement() di-overload untuk menambah atau mengurangi count dengan atau tanpa parameter.

- **Reset & Display:** Method reset() untuk mengembalikan count ke nol dan displayCount() untuk menampilkan nilai saat ini.

### Contoh Penggunaan

```cpp
int main() {
    Counter counter1;
    
    counter1.increment();
    counter1.increment();
    cout << counter1.getCount() << endl;  // 2
    
    counter1.increment(5);
    cout << counter1.getCount() << endl;  // 7
    
    counter1.decrement(2);
    cout << counter1.getCount() << endl;  // 5
    
    counter1.reset();
    cout << counter1.getCount() << endl;  // 0
    
    return 0;
}
```

## Point Class

Kelas `Point` mewakili titik dalam ruang 2D dan dapat menghitung jarak dari titik asal (0, 0) atau titik lainnya.

```cpp
#include <iostream>
#include <cmath>
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
    
    // Calculate distance from origin (0,0)
    double distanceFromOrigin() const {
        return sqrt(x*x + y*y);
    }
    
    // Calculate distance from another point
    double distanceFrom(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return sqrt(dx*dx + dy*dy);
    }
    
    // Display point information
    void displayPoint() const {
        cout << "Point (" << x << ", " << y << ")" << endl;
        cout << "Distance from origin: " << distanceFromOrigin() << endl;
    }
};
```

### Penjelasan

- **Data Members:** Menyimpan koordinat x dan y sebagai tipe double.
- **Constructor:**
  - Default constructor menginisialisasi titik di koordinat (0,0).
  - Parameterized constructor memungkinkan pengaturan posisi titik sesuai nilai input.
- **Method Perhitungan Jarak:**
  - distanceFromOrigin() menghitung jarak dari titik ke asal (0,0) menggunakan Teorema Pythagoras.
  - distanceFrom() menghitung jarak antara dua titik dengan menggunakan perbedaan koordinat.
- **Display Point:** Method displayPoint() menampilkan koordinat dan jarak titik dari asal.

### Contoh Penggunaan

```cpp
int main() {
    Point p1(3.0, 4.0);
    cout << "Distance from origin: " << p1.distanceFromOrigin() << endl;  // 5
    
    Point p2(0.0, 0.0);
    cout << "Distance between points: " << p1.distanceFrom(p2) << endl;  // 5
    
    p1.displayPoint();
    
    return 0;
}
```

## Kesimpulan

Kumpulan kelas dalam file ini memberikan contoh implementasi dasar konsep Pemrograman Berorientasi Objek (OOP) dalam C++ dengan fokus pada:

- **Enkapsulasi:** Penggunaan akses modifier private untuk data members dan akses melalui setter/getter.
- **Constructor & Overloading:** Variasi constructor dan overloading method (seperti pada kelas Counter) untuk fleksibilitas inisialisasi dan operasi.
- **Validasi dan Exception Handling:** Validasi input (misalnya pada kelas Rectangle) dan penanganan error (misalnya pada operasi pembagian di kelas Calculator).
- **Abstraksi dan Modularitas:** Setiap kelas memiliki tanggung jawab yang spesifik sehingga memudahkan pengembangan serta pemeliharaan kode.

Kelas-kelas ini bisa digunakan sebagai dasar untuk pembelajaran lebih lanjut tentang OOP dalam C++.