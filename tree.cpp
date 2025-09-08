#include <iostream>
#include <unistd.h>
using namespace std;

void drawTree(int depth, int spaces) {
    if (depth == 0) return;

    for (int i = 0; i < spaces; i++) cout << " ";
    cout << "\033[1;32m" << "*" << "\033[0m" << endl;

    drawTree(depth - 1, spaces + 2);
    drawTree(depth - 1, spaces + 2);
}

int main() {
    system("clear");
    cout << "🌳 Recursive Fractal Tree 🌳\n\n";
    drawTree(5, 10);  // Depth = 5

    return 0;
}
