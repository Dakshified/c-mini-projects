#include <iostream>
#include <iomanip>
using namespace std;

// Function to calculate index in row-major order
int rowMajorIndex(int row, int col, int totalCols) {
    return row * totalCols + col;
}

// Function to calculate index in column-major order
int colMajorIndex(int row, int col, int totalRows) {
    return col * totalRows + row;
}

// Insert value at (row, col)
void insertValue(int* arr, int row, int col, int val, int rows, int cols, bool isRowMajor = true) {
    int index = isRowMajor ? rowMajorIndex(row, col, cols) : colMajorIndex(row, col, rows);
    *(arr + index) = val;
}

// Delete value at (row, col) -> set to 0
void deleteValue(int* arr, int row, int col, int rows, int cols, bool isRowMajor = true) {
    int index = isRowMajor ? rowMajorIndex(row, col, cols) : colMajorIndex(row, col, rows);
    *(arr + index) = 0;
}

// Print 2D array using pointer arithmetic
void printArray(int* arr, int rows, int cols, bool isRowMajor = true) {
    cout << (isRowMajor ? "Row-Major Order:\n" : "Column-Major Order:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = isRowMajor ? rowMajorIndex(i, j, cols) : colMajorIndex(i, j, rows);
            cout << setw(4) << *(arr + index) << "(" << (void*)(arr + index) << ") ";
        }
        cout << "\n";
    }
    cout << "\n";
}

// Merge two arrays vertically (must have same columns)
int* mergeArrays(int* arr1, int* arr2, int rows1, int rows2, int cols, bool isRowMajor = true) {
    int totalRows = rows1 + rows2;
    int* merged = new int[totalRows * cols];

    // Copy arr1
    for (int i = 0; i < rows1; i++)
        for (int j = 0; j < cols; j++) {
            int index = isRowMajor ? rowMajorIndex(i, j, cols) : colMajorIndex(i, j, rows1);
            insertValue(merged, i, j, *(arr1 + index), totalRows, cols, isRowMajor);
        }

    // Copy arr2
    for (int i = 0; i < rows2; i++)
        for (int j = 0; j < cols; j++) {
            int index = isRowMajor ? rowMajorIndex(i, j, cols) : colMajorIndex(i, j, rows2);
            insertValue(merged, i + rows1, j, *(arr2 + index), totalRows, cols, isRowMajor);
        }

    return merged;
}

int main() {
    const int rows = 2, cols = 3;
    int* A = new int[rows * cols]{0}; // Simulated 2D array
    int* B = new int[rows * cols]{0}; // Another array

    // Insert values
    insertValue(A, 0, 0, 1, rows, cols);
    insertValue(A, 0, 1, 2, rows, cols);
    insertValue(A, 0, 2, 3, rows, cols);
    insertValue(A, 1, 0, 4, rows, cols);
    insertValue(A, 1, 1, 5, rows, cols);
    insertValue(A, 1, 2, 6, rows, cols);

    insertValue(B, 0, 0, 10, rows, cols);
    insertValue(B, 0, 1, 20, rows, cols);
    insertValue(B, 0, 2, 30, rows, cols);
    insertValue(B, 1, 0, 40, rows, cols);
    insertValue(B, 1, 1, 50, rows, cols);
    insertValue(B, 1, 2, 60, rows, cols);

    cout << "\nOriginal Array A:\n";
    printArray(A, rows, cols);

    cout << "Original Array B:\n";
    printArray(B, rows, cols);

    // Delete a value from A
    deleteValue(A, 1, 1, rows, cols);

    cout << "Array A after deleting A[1][1]:\n";
    printArray(A, rows, cols);

    // Merge A and B
    int* Merged = mergeArrays(A, B, rows, rows, cols);
    cout << "Merged Array (A + B vertically):\n";
    printArray(Merged, rows * 2, cols);

    // Print in column-major order
    cout << "Merged Array in Column-Major Order:\n";
    printArray(Merged, rows * 2, cols, false);

    delete[] A;
    delete[] B;
    delete[] Merged;

    return 0;
}
