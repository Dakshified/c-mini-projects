#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>   // for usleep
using namespace std;

const int width = 80;   // terminal width
const int height = 20;  // terminal height

int main() {
    srand(time(0));

    while (true) {
        // Clear screen (Mac/Linux)
        system("clear");  
        // use "cls" instead of "clear" on Windows

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                // Randomly print either a space or a random character
                if (rand() % 5 == 0) {
                    char c = (char)(33 + rand() % 94); // printable ASCII
                    cout << c;
                } else {
                    cout << " ";
                }
            }
            cout << "\n";
        }

        usleep(100000); // 0.1 second delay
    }
    return 0;
}
