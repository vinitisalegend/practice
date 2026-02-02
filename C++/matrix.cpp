#include <iostream>
#include <cstdlib> // Required for exit()

using namespace std;

int main() {
    int r1, c1, r2, c2, i, j, k;
    int A[10][10], B[10][10], C[10][10]; // Using fixed size arrays, adjust as needed

    cout << "Enter number of rows and columns of matrix A: ";
    cin >> r1 >> c1;
    cout << "Enter number of rows and columns of matrix B: ";
    cin >> r2 >> c2;

    // Check if multiplication is possible
    if (c1 != r2) {
        cout << "Matrices cannot be multiplied! Number of columns in A must equal number of rows in B." << endl;
        exit(0); // Terminate program
    }

    // Input elements of matrix A
    cout << "Enter elements of matrix A:" << endl;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            cin >> A[i][j];
        }
    }

    // Input elements of matrix B
    cout << "Enter elements of matrix B:" << endl;
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            cin >> B[i][j];
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            C[i][j] = 0; // Initialize the element to 0
            // Innermost loop performs the dot product
            for (k = 0; k < r2; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the product matrix
    cout << "Product of matrices:" << endl;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
