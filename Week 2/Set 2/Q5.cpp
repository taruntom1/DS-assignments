#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int rows;
    int cols;
    vector<vector<int>> elements;

public:
    // Constructor to initialize rows, columns, and allocate space for the matrix
    Matrix(int r, int c) : rows(r), cols(c), elements(r, vector<int>(c, 0)) {}

    // Get the number of rows
    int getRows() const {
        return rows;
    }

    // Get the number of columns
    int getCols() const {
        return cols;
    }

    // Set the elements of the matrix at a given position (i, j)
    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            elements[i][j] = value;
        }
        else {
            cerr << "Index out of bounds" << endl;
        }
    }

    // Get the element at a given position (i, j)
    int getElement(int i, int j) const {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            return elements[i][j];
        }
        else {
            cerr << "Index out of bounds" << endl;
            return -1;
        }
    }

    // Add two matrices
    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            cerr << "Matrix dimensions do not match for addition" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.setElement(i, j, elements[i][j] + other.elements[i][j]);
            }
        }

        return result;
    }

    // Multiply two matrices
    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            cerr << "Matrix dimensions do not match for multiplication" << endl;
            return Matrix(0, 0);
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                int sum = 0;
                for (int k = 0; k < cols; ++k) {
                    sum += elements[i][k] * other.elements[k][j];
                }
                result.setElement(i, j, sum);
            }
        }

        return result;
    }

    // Display the matrix
    void display() const {
        for (const auto& row : elements) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage of the Matrix class
    Matrix mat1(2, 3);
    Matrix mat2(2, 3);

    // Initialize mat1
    mat1.setElement(0, 0, 1);
    mat1.setElement(0, 1, 2);
    mat1.setElement(0, 2, 3);
    mat1.setElement(1, 0, 4);
    mat1.setElement(1, 1, 5);
    mat1.setElement(1, 2, 6);

    // Initialize mat2
    mat2.setElement(0, 0, 7);
    mat2.setElement(0, 1, 8);
    mat2.setElement(0, 2, 9);
    mat2.setElement(1, 0, 10);
    mat2.setElement(1, 1, 11);
    mat2.setElement(1, 2, 12);

    // Add matrices
    Matrix sum = mat1.add(mat2);

    // Display the result
    cout << "Matrix 1:" << endl;
    mat1.display();
    cout << "Matrix 2:" << endl;
    mat2.display();
    cout << "Sum of matrices:" << endl;
    sum.display();

    // Multiply matrices (example with compatible dimensions)

    Matrix mat3(3, 2);
    mat3.setElement(0, 0, 1);
    mat3.setElement(0, 1, 2);
    mat3.setElement(1, 0, 3);
    mat3.setElement(1, 1, 4);
    mat3.setElement(2, 0, 5);
    mat3.setElement(2, 1, 6);
    cout << "Matrix 3:" << endl;
    mat3.display();

    Matrix product = mat1.multiply(mat3);
    cout << "Product of matrices 1 and 3:" << endl;
    product.display();

    return 0;
}
