#include <iostream>
#include <cmath>
#include <unistd.h>
using namespace std;

int main() {
    const double pi = 3.14159;
    double angle = 0;

    while (true) {
        system("clear");
        for (double y = -1; y <= 1; y += 0.05) {
            for (double x = -1; x <= 1; x += 0.025) {
                double val = cos(angle) * x - sin(angle) * y;
                if (val > -0.05 && val < 0.05)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << "\n";
        }
        angle += 0.1;
        usleep(80000);
    }
}
