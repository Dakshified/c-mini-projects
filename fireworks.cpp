#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int width = 40;
const int height = 20;

int main() {
    srand(time(0));
    while (true) {
        system("clear");
        int fx = rand() % width;
        int fy = rand() % height;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == fy && j == fx)
                    cout << "\033[1;31m*\033[0m"; // red explosion
                else if (rand() % 30 == 0)
                    cout << ".";
                else
                    cout << " ";
            }
            cout << "\n";
        }
        usleep(150000);
    }
}
