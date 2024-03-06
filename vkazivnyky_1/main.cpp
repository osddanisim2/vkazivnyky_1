#include <iostream>

using namespace std;

void fillMatrix(int** matrix, int rows, int cols) {
    srand(time_t(nullptr));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = rand() % 100;
        }
    }
}

void printMainDiagonal(int** matrix, int rows, int cols) {
    cout << "Елементи на головній діагоналі: ";
    for (int i = 0; i < rows; i++) {
        cout << *(*(matrix + i) + i) << " ";
    }
    cout << endl;
}

void printSecondaryDiagonal(int** matrix, int rows, int cols) {
    cout << "Елементи на побічній діагоналі: ";
    for (int i = 0; i < rows; i++) {
        cout << *(*(matrix + i) + cols - 1 - i) << " ";
    }
    cout << endl;
}

void countEvenOdd(int** matrix, int rows, int cols, int& evenCount, int& oddCount) {
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (*(*(matrix + i) + j) % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << *(*(matrix + i) + j) << "\t";
        }
        cout << endl;
    }
}

int main() {
    int rows = 0, cols = 0, evenCount = 0, oddCount = 0;
    
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;
    
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    fillMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);
    printMainDiagonal(matrix, rows, cols);
    printSecondaryDiagonal(matrix, rows, cols);
    countEvenOdd(matrix, rows, cols, evenCount, oddCount);

    cout << "Кількість парних елементів: " << evenCount << endl;
    cout << "Кількість непарних елементів: " << oddCount << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

