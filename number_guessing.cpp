#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {
    srand(time(0));  // seed random number
    int number = rand() % 100 + 1;  // random number between 1 and 100
    int guess, tries = 0;

    cout << "=== Number Guessing Game ===\n";
    cout << "Guess a number between 1 and 100\n";

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        tries++;

        if (guess > number) {
            cout << "Too high! Try again.\n";
        } else if (guess < number) {
            cout << "Too low! Try again.\n";
        } else {
            cout << "🎉 Correct! You guessed it in " << tries << " tries.\n";
        }
    } while (guess != number);

    return 0;
}
