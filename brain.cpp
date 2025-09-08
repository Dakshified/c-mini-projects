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
        system("clear");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (rand() % 50 == 0)
                    cout << "\033[1;36m" << (char)(65 + rand() % 26) << "\033[0m";  // A-Z cyan
                else
                    cout << " ";
            }
            cout << "\n";
        }

        usleep(100000);
    }

    return 0;
}
