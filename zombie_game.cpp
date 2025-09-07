#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int width = 20;
const int height = 10;

int main() {
    srand(time(0));

    int playerX = width / 2;
    int playerY = height / 2;
    int zombieX = rand() % width;
    int zombieY = rand() % height;
    char input;

    cout << "🧟‍♂️ Zombie Survival Game 🧟‍♂️\n";
    cout << "Controls: w = up | s = down | a = left | d = right\n";

    while (true) {
        system("clear");

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (x == playerX && y == playerY)
                    cout << "\033[1;32mP\033[0m";  // Player (Green)
                else if (x == zombieX && y == zombieY)
                    cout << "\033[1;31mZ\033[0m";  // Zombie (Red)
                else
                    cout << ".";
            }
            cout << "\n";
        }

        cout << "\nMove (w/a/s/d): ";
        cin >> input;

        // Player movement
        if (input == 'w' && playerY > 0) playerY--;
        if (input == 's' && playerY < height - 1) playerY++;
        if (input == 'a' && playerX > 0) playerX--;
        if (input == 'd' && playerX < width - 1) playerX++;

        // Zombie follows player
        if (playerX < zombieX) zombieX--;
        else if (playerX > zombieX) zombieX++;
        if (playerY < zombieY) zombieY--;
        else if (playerY > zombieY) zombieY++;

        // Check if caught
        if (playerX == zombieX && playerY == zombieY) {
            cout << "\n💀 You were caught by the zombie! Game Over!\n";
            break;
        }

        usleep(150000);
    }

    return 0;
}
