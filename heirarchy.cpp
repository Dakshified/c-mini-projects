#include <iostream>
using namespace std;

// Base Class
class Number {
protected:
    int num1, num2;   // data members
public:
    void setData(int a, int b) {
        num1 = a;
        num2 = b;
    }
};

// Derived Class for Addition
class Add : public Number {
public:
    void display() {
        cout << "Addition = " << (num1 + num2) << endl;
    }
};

// Derived Class for Subtraction
class Subtract : public Number {
public:
    void display() {
        cout << "Subtraction = " << (num1 - num2) << endl;
    }
};

int main() {
    Add a1;
    Subtract s1;

    // Set values
    a1.setData(10, 5);
    s1.setData(10, 5);

    // Show results
    a1.display();
    s1.display();

    return 0;
}
