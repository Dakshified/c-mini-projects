#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number = rand() % 100 + 1;
    int guess;
    int tries = 0;

    cout << "Guess the number (1 to 100):\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > number)
            cout << "Too high!\n";
        else if (guess < number)
            cout << "Too low!\n";
        else
            cout << "🎉 Correct! Number is " << number << ". You took " << tries << " tries.\n";

    } while (guess != number);

    return 0;
}
