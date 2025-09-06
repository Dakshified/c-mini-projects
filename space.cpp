#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

struct Star { int x, y, z; };
const int width = 80, height = 25, numStars = 150;

int main() {
    srand(time(0));
    vector<Star> stars(numStars);

    for (int i = 0; i < numStars; i++) {
        stars[i].x = rand() % width - width/2;
        stars[i].y = rand() % height - height/2;
        stars[i].z = rand() % width;
    }

    while (true) {
        system("clear");
        for (int i = 0; i < numStars; i++) {
            int sx = (stars[i].x * width) / stars[i].z + width/2;
            int sy = (stars[i].y * height) / stars[i].z + height/2;

            if (sx >= 0 && sx < width && sy >= 0 && sy < height)
                cout << "\033[" << sy+1 << ";" << sx+1 << "H" << "*";

            stars[i].z -= 1;
            if (stars[i].z <= 0) {
                stars[i].x = rand() % width - width/2;
                stars[i].y = rand() % height - height/2;
                stars[i].z = width;
            }
        }
        usleep(5000);
        cout << "\033[0;0H"; // move cursor to top
    }
}
