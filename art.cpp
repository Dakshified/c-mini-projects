#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int width = 60;
const int height = 20;

int main() {
    srand(time(0));

    while (true) {
        system("clear");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char c = (rand() % 2) ? '*' : '#';
                cout << "\033[1;" << (31 + rand() % 7) << "m" << c << "\033[0m";
            }
            cout << "\n";
        }

        usleep(200000);
    }

    return 0;
}
