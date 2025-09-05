#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int width = 80;
const int height = 25;

int main() {
    srand(time(0));
    while (true) {
        system("clear"); // use "cls" on Windows
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (rand() % 7 == 0) {
                    char c = (char)(33 + rand() % 94);
                    cout << "\033[1;32m" << c << "\033[0m"; // bright green
                } else {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        usleep(80000); // speed
    }
    return 0;
}
