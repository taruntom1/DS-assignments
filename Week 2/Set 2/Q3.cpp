#include <iostream>
using namespace std;

class Area {
private:
    double length;
    double breadth;

public:
    // Function to set dimensions of the rectangle
    void setDim(double len, double bre) {
        length = len;
        breadth = bre;
    }

    // Function to calculate and return the area of the rectangle
    double getArea() {
        return length * breadth;
    }
};

int main() {
    Area rectangle;
    double length, breadth;

    // Input length and breadth from the user
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the breadth of the rectangle: ";
    cin >> breadth;

    // Set dimensions and calculate the area
    rectangle.setDim(length, breadth);
    cout << "The area of the rectangle is: " << rectangle.getArea() << endl;

    return 0;
}
