#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int matrix[3][3]{};

    cout << "Enter 9 integers for the 3x3 matrix:\n";

    // Input data into the matrix using nested for loops
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    // Output the 3x3 matrix
    cout << "\nThe 3x3 matrix is:\n";
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            cout << setw(5) << left << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
