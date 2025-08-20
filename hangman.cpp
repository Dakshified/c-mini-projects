#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to select a random word from a predefined list
string getRandomWord() {
    vector<string> words = {"PROGRAMMING", "COMPUTER", "ALGORITHM", "DATABASE", "NETWORK"};
    return words[rand() % words.size()];
}

// Function to display current game state
void displayGame(const string& word, const vector<bool>& guessed, int wrongGuesses) {
    // Display hangman ASCII based on wrong guesses
    cout << "\nWrong guesses left: " << 6 - wrongGuesses << endl;
    cout << "  _____\n";
    cout << "  |   |" << (wrongGuesses >= 1 ? " O" : "") << endl;
    cout << "  |" << (wrongGuesses >= 3 ? "/" : " ") << (wrongGuesses >= 2 ? "|" : " ") << (wrongGuesses >= 4 ? "\\" : "") << endl;
    cout << "  |" << (wrongGuesses >= 5 ? " /" : "") << (wrongGuesses >= 6 ? " \\" : "") << endl;
    cout << "  =====" << endl;

    // Display word with underscores for unguessed letters
    cout << "Word: ";
    for (size_t i = 0; i < word.length(); ++i) {
        if (guessed[i]) {
            cout << word[i] << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Function to check if the word is fully guessed
bool isWordGuessed(const vector<bool>& guessed) {
    for (bool g : guessed) {
        if (!g) return false;
    }
    return true;
}

int main() {
    srand(time(0)); // Seed random number generator
    string word = getRandomWord();
    vector<bool> guessed(word.length(), false); // Track guessed letters
    vector<char> wrongLetters; // Track wrong guesses
    int wrongGuesses = 0;
    char guess;

    cout << "Welcome to Hangman!\n";
    cout << "Guess the word by entering one letter at a time.\n";

    while (wrongGuesses < 6 && !isWordGuessed(guessed)) {
        displayGame(word, guessed, wrongGuesses);
        cout << "Wrong guesses: ";
        for (char c : wrongLetters) cout << c << " ";
        cout << "\nEnter a letter: ";
        cin >> guess;
        guess = toupper(guess); // Convert to uppercase for consistency

        // Validate input
        if (!isalpha(guess)) {
            cout << "Error: Please enter a valid letter.\n";
            continue;
        }

        // Check if letter was already guessed
        bool alreadyGuessed = false;
        for (char c : wrongLetters) {
            if (c == guess) alreadyGuessed = true;
        }
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) alreadyGuessed = true;
        }
        if (alreadyGuessed) {
            cout << "Error: Letter already guessed.\n";
            continue;
        }

        // Check if guess is in the word
        bool found = false;
        for (size_t i = 0; i < word.length(); ++i) {
            if (word[i] == guess) {
                guessed[i] = true;
                found = true;
            }
        }

        if (!found) {
            wrongLetters.push_back(guess);
            wrongGuesses++;
            cout << "Letter not in word!\n";
        }
    }

    // Display final result
    displayGame(word, guessed, wrongGuesses);
    if (isWordGuessed(guessed)) {
        cout << "Congratulations! You guessed the word: " << word << endl;
    } else {
        cout << "Game Over! The word was: " << word << endl;
    }

    return 0;
}