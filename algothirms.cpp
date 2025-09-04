#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int comparisons = 0;

// Linear Search
int linearSearch(const vector<int>& arr, int key) {
    comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Sentinel Search
int sentinelSearch(vector<int> arr, int key) {
    comparisons = 0;
    int n = arr.size();
    int last = arr[n - 1];
    arr[n - 1] = key;

    int i = 0;
    while (true) {
        comparisons++;
        if (arr[i] == key)
            break;
        i++;
    }

    arr[n - 1] = last;
    if (i < n - 1 || key == last)
        return i;
    return -1;
}

// Binary Search (sorted array only)
int binarySearch(const vector<int>& arr, int key) {
    comparisons = 0;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Fibonacci Search (sorted array only)
int fibonacciSearch(const vector<int>& arr, int key) {
    comparisons = 0;
    int n = arr.size();

    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        comparisons++;
        int i = min(offset + fib2, n - 1);

        if (arr[i] < key) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > key) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else
            return i;
    }

    if (fib1 && offset + 1 < n && arr[offset + 1] == key) {
        comparisons++;
        return offset + 1;
    }

    return -1;
}

// Utility Functions
void displayArray(const vector<int>& arr) {
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}

void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    vector<int> data;
    int choice, n, key, index;
    bool sorted = false;

    do {
        cout << "\n=== SEARCH ALGORITHM COMPARATOR ===\n";
        cout << "1. Input Array\n";
        cout << "2. Display Array\n";
        cout << "3. Sort Array\n";
        cout << "4. Linear Search\n";
        cout << "5. Sentinel Search\n";
        cout << "6. Binary Search (Sorted Only)\n";
        cout << "7. Fibonacci Search (Sorted Only)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter number of elements: ";
            cin >> n;
            data.resize(n);
            cout << "Enter elements:\n";
            for (int i = 0; i < n; i++)
                cin >> data[i];
            sorted = false;
            break;

        case 2:
            cout << "Current Array: ";
            displayArray(data);
            break;

        case 3:
            sortArray(data);
            cout << "Array sorted.\n";
            displayArray(data);
            sorted = true;
            break;

        case 4:
            cout << "Enter element to search: ";
            cin >> key;
            index = linearSearch(data, key);
            (index != -1) ? cout << "Found at index " << index : cout << "Not found";
            cout << " | Comparisons: " << comparisons << endl;
            break;

        case 5:
            cout << "Enter element to search: ";
            cin >> key;
            index = sentinelSearch(data, key);
            (index != -1) ? cout << "Found at index " << index : cout << "Not found";
            cout << " | Comparisons: " << comparisons << endl;
            break;

        case 6:
            if (!sorted) {
                cout << "Array must be sorted. Sort it first.\n";
                break;
            }
            cout << "Enter element to search: ";
            cin >> key;
            index = binarySearch(data, key);
            (index != -1) ? cout << "Found at index " << index : cout << "Not found";
            cout << " | Comparisons: " << comparisons << endl;
            break;

        case 7:
            if (!sorted) {
                cout << "Array must be sorted. Sort it first.\n";
                break;
            }
            cout << "Enter element to search: ";
            cin >> key;
            index = fibonacciSearch(data, key);
            (index != -1) ? cout << "Found at index " << index : cout << "Not found";
            cout << " | Comparisons: " << comparisons << endl;
            break;

        case 8:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    return 0;
}
