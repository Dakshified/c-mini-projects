#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string getChoiceName(int choice) {
    if (choice == 1) return "Rock";
    if (choice == 2) return "Paper";
    return "Scissors";
}

int main() {
    srand(time(0));
    int player, cpu;

    cout << "Rock Paper Scissors Game\n";
    cout << "1 = Rock | 2 = Paper | 3 = Scissors\n";
    cout << "Enter your choice: ";
    cin >> player;

    cpu = rand() % 3 + 1;

    cout << "You chose: " << getChoiceName(player) << endl;
    cout << "CPU chose: " << getChoiceName(cpu) << endl;

    if (player == cpu)
        cout << "🤝 It's a Tie!\n";
    else if ((player == 1 && cpu == 3) ||
             (player == 2 && cpu == 1) ||
             (player == 3 && cpu == 2))
        cout << "🎉 You Win!\n";
    else
        cout << "💻 CPU Wins!\n";

    return 0;
}
