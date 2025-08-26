#include <iostream>
using namespace std;

int main() {
    int n, reversed = 0, remainder, original;
    cout << "Enter a number: ";
    cin >> n;
    original = n;

    while (n != 0) {
        remainder = n % 10;
        reversed = reversed * 10 + remainder;
        n /= 10;
    }

    if (original == reversed)
        cout << "Palindrome Number";
    else
        cout << "Not a Palindrome";
    return 0;
}
