#include <iostream>
using namespace std;
int main() {
    int choice;
    double value;
    do {
        cout << "\n1. KM to Miles\n2. Miles to KM\n3. Exit\nChoose: ";
        cin >> choice;
        
        if (choice == 1) {
            cout << "Enter distance in KM: ";
            cin >> value;
            cout << value << " km = " << value * 0.621371 << " miles\n";
        }
        else if (choice == 2) {
            cout << "Enter distance in Miles: ";
            cin >> value;
            cout << value << " miles = " << value / 0.621371 << " km\n";
        }
    } while (choice != 3);
    
    return 0;
}
