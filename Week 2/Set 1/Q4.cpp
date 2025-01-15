#include <iostream>
using namespace std;

// Base class for polygons
class Polygon {
protected:
    double length, breadth; // Dimensions of the polygon
public:
    // Constructor
    Polygon(double l = 0, double b = 0) : length(l), breadth(b) {}

    // Virtual functions for area and perimeter
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Virtual destructor
    virtual ~Polygon() {}
};

// Derived class for Rectangle
class Rectangle : public Polygon {
public:
    // Constructor
    Rectangle(double l, double b) : Polygon(l, b) {}

    // Overridden function to calculate area
    double area() const override {
        return length * breadth;
    }

    // Overridden function to calculate perimeter
    double perimeter() const override {
        return 2 * (length + breadth);
    }
};

// Function to calculate charges
void calculateCharges(Polygon* polygon, double fencingCostPerUnit, double lawnCostPerUnit) {
    double perimeter = polygon->perimeter();
    double area = polygon->area();

    double fencingCost = perimeter * fencingCostPerUnit;
    double lawnCost = area * lawnCostPerUnit;

    cout << "Fencing Cost: $" << fencingCost << endl;
    cout << "Lawn Laying Cost: $" << lawnCost << endl;
}

int main() {
    // Input dimensions of the rectangle
    double length, breadth;
    cout << "Enter the length and breadth of the rectangle: ";
    cin >> length >> breadth;

    // Input costs
    double fencingCostPerUnit, lawnCostPerUnit;
    cout << "Enter the cost per unit for fencing: ";
    cin >> fencingCostPerUnit;
    cout << "Enter the cost per unit for laying lawn: ";
    cin >> lawnCostPerUnit;

    // Create a Rectangle object
    Rectangle rect(length, breadth);

    // Calculate and display charges
    calculateCharges(&rect, fencingCostPerUnit, lawnCostPerUnit);

    return 0;
}
