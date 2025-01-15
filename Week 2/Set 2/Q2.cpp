#include <iostream>
#include <cmath>

class Triangle
{
private:
    double side1, side2, side3;

public:
    // Constructor to initialize the sides of the triangle
    Triangle(double s1, double s2, double s3)
    {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    // Function to calculate and print the perimeter
    void printPerimeter()
    {
        double perimeter = side1 + side2 + side3;
        std::cout << "Perimeter: " << perimeter << " units" << std::endl;
    }

    // Function to calculate and print the area
    void printArea()
    {
        double s = (side1 + side2 + side3) / 2;                               // Semi-perimeter
        double area = std::sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Heron's formula
        std::cout << "Area: " << area << " square units" << std::endl;
    }
};

int main()
{
    // Create a Triangle object with sides 3, 4, and 5
    Triangle triangle(3, 4, 5);

    // Print the perimeter and area
    triangle.printPerimeter();
    triangle.printArea();

    return 0;
}