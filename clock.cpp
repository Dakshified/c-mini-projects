#include <iostream>
#include <ctime>
#include <thread>
using namespace std;

int main() {
    while (true) {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        system("clear"); // use "cls" if on Windows
        cout << "⏰ Digital Clock\n";
        cout << (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour << ":"
             << (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min << ":"
             << (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec << endl;

        this_thread::sleep_for(chrono::seconds(1));
    }
    return 0;
}
