#include <iostream>
using namespace std;

// Class to represent a complex number
class Complex
{
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload the '+' operator for addition
    Complex operator+(const Complex &other)
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload the '-' operator for subtraction
    Complex operator-(const Complex &other)
    {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload the '*' operator for multiplication
    Complex operator*(const Complex &other)
    {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    // Function to display the complex number
    void display() const
    {
        cout << real << (imag >= 0 ? " + " : " - ") << abs(imag) << "i" << endl;
    }
};

int main()
{
    double real1, imag1, real2, imag2;

    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin >> real1 >> imag1;

    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin >> real2 >> imag2;

    // Create two Complex objects
    Complex c1(real1, imag1);
    Complex c2(real2, imag2);

    // Perform operations
    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    cout << "Sum: ";
    sum.display();

    cout << "Difference: ";
    difference.display();

    cout << "Product: ";
    product.display();

    return 0;
}
