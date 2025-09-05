#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

struct Star {
    int x, y, speed;
};

int main() {
    const int width = 80, height = 25, numStars = 100;
    vector<Star> stars(numStars);
    srand(time(0));

    // initialize stars
    for (int i = 0; i < numStars; i++) {
        stars[i].x = rand() % width;
        stars[i].y = rand() % height;
        stars[i].speed = 1 + rand() % 3;
    }

    while (true) {
        system("clear");

        vector<string> screen(height, string(width, ' '));
        for (auto &s : stars) {
            screen[s.y][s.x] = '*';
            s.y += s.speed;
            if (s.y >= height) {
                s.y = 0;
                s.x = rand() % width;
            }
        }

        for (auto &line : screen)
            cout << line << "\n";

        usleep(80000);
    }
    return 0;
}
