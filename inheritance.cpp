#include <iostream>
using namespace std;
class Person {
public:
    string name;
    int age;
    void inputPerson() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }
    void displayPerson() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student : private Person {
public:
    int rollNo; 
    void inputStudent() {
        inputPerson();  
        cout << "Enter roll number: ";
        cin >> rollNo;
    }

    void displayStudent() {
        displayPerson();  
        cout << "Roll No: " << rollNo << endl;
    }
};
int main() {
    Student s1;
    s1.inputStudent();
    s1.displayStudent();
    return 0;
}
