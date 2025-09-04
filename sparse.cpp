#include <iostream>
#include <iomanip>
using namespace std;

const int MAX = 100;

struct Triple {
    int row, col, value;
};

struct SparseMatrix {
    Triple data[MAX];
    int rows, cols, nonZero;
};

// Convert normal 2D array to sparse 3-tuple representation
SparseMatrix createSparseMatrix(int arr[][MAX], int r, int c) {
    SparseMatrix s;
    s.rows = r;
    s.cols = c;
    s.nonZero = 0;

    int k = 1; // First index for data (index 0 holds metadata)
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (arr[i][j] != 0) {
                s.data[k].row = i;
                s.data[k].col = j;
                s.data[k].value = arr[i][j];
                k++;
            }

    s.nonZero = k - 1;
    s.data[0].row = r;
    s.data[0].col = c;
    s.data[0].value = s.nonZero;

    return s;
}

// Print sparse matrix (3-tuple format)
void printSparse(const SparseMatrix& s) {
    cout << "Row Col Val\n";
    for (int i = 0; i <= s.nonZero; ++i)
        cout << setw(3) << s.data[i].row << setw(4) << s.data[i].col << setw(5) << s.data[i].value << '\n';
}

// 1. Simple Transpose (Time Complexity: O(n * t), Space: O(t))
SparseMatrix simpleTranspose(const SparseMatrix& s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;
    t.data[0] = { t.rows, t.cols, t.nonZero };

    int k = 1;
    for (int col = 0; col < s.cols; ++col)
        for (int i = 1; i <= s.nonZero; ++i)
            if (s.data[i].col == col) {
                t.data[k].row = s.data[i].col;
                t.data[k].col = s.data[i].row;
                t.data[k].value = s.data[i].value;
                ++k;
            }
    return t;
}

// 2. Fast Transpose (Time Complexity: O(n + t), Space: O(t))
SparseMatrix fastTranspose(const SparseMatrix& s) {
    SparseMatrix t;
    int rowTerms[MAX] = {0};
    int startPos[MAX] = {0};

    t.rows = s.cols;
    t.cols = s.rows;
    t.nonZero = s.nonZero;
    t.data[0] = { t.rows, t.cols, t.nonZero };

    // Count terms in each column
    for (int i = 1; i <= s.nonZero; ++i)
        rowTerms[s.data[i].col]++;

    // Starting position of each term in transposed matrix
    startPos[0] = 1;
    for (int i = 1; i < s.cols; ++i)
        startPos[i] = startPos[i - 1] + rowTerms[i - 1];

    // Place elements in correct position
    for (int i = 1; i <= s.nonZero; ++i) {
        int pos = startPos[s.data[i].col]++;
        t.data[pos].row = s.data[i].col;
        t.data[pos].col = s.data[i].row;
        t.data[pos].value = s.data[i].value;
    }

    return t;
}

// 3. Addition of Sparse Matrices
SparseMatrix addSparse(const SparseMatrix& a, const SparseMatrix& b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        throw invalid_argument("Matrices dimensions do not match.");
    }

    SparseMatrix sum;
    sum.rows = a.rows;
    sum.cols = a.cols;
    sum.nonZero = 0;

    int i = 1, j = 1, k = 1;

    while (i <= a.nonZero && j <= b.nonZero) {
        if (a.data[i].row == b.data[j].row &&
            a.data[i].col == b.data[j].col) {
            int value = a.data[i].value + b.data[j].value;
            if (value != 0) {
                sum.data[k] = {a.data[i].row, a.data[i].col, value};
                k++;
            }
            i++; j++;
        }
        else if (a.data[i].row < b.data[j].row ||
                (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        } else {
            sum.data[k++] = b.data[j++];
        }
    }

    // Remaining terms
    while (i <= a.nonZero) sum.data[k++] = a.data[i++];
    while (j <= b.nonZero) sum.data[k++] = b.data[j++];

    sum.nonZero = k - 1;
    sum.data[0] = { sum.rows, sum.cols, sum.nonZero };
    return sum;
}

// Example usage
int main() {
    int arr1[MAX][MAX] = {
        {0, 0, 3, 0},
        {0, 0, 5, 7},
        {0, 0, 0, 0},
        {0, 2, 6, 0}
    };

    int arr2[MAX][MAX] = {
        {0, 0, 0, 0},
        {0, 0, 5, 1},
        {0, 0, 0, 0},
        {0, 2, 3, 0}
    };

    cout << "Matrix 1:\n";
    SparseMatrix s1 = createSparseMatrix(arr1, 4, 4);
    printSparse(s1);

    cout << "\nMatrix 2:\n";
    SparseMatrix s2 = createSparseMatrix(arr2, 4, 4);
    printSparse(s2);

    cout << "\nSimple Transpose of Matrix 1:\n";
    SparseMatrix st = simpleTranspose(s1);
    printSparse(st);

    cout << "\nFast Transpose of Matrix 1:\n";
    SparseMatrix ft = fastTranspose(s1);
    printSparse(ft);

    cout << "\nAddition of Matrix 1 and Matrix 2:\n";
    SparseMatrix sum = addSparse(s1, s2);
    printSparse(sum);

    return 0;
}
