#include <iostream>
#include <string>

using namespace std;

// Class definition for Student
class Student
{
private:
    string name;      // Student name
    int rollNo;       // Roll number
    float totalMarks; // Total marks obtained

public:
    // Method to input student details
    void inputDetails()
    {
        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter roll number: ";
        cin >> rollNo;
        cout << "Enter total marks obtained: ";
        cin >> totalMarks;
        cin.ignore(); // Clear input buffer for next getline
    }

    // Method to display student details
    void displayDetails() const
    {
        cout << "\nStudent Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Total Marks: " << totalMarks << endl;
    }
};

int main()
{
    // Create a Student object
    Student student;

    // Input and display details
    student.inputDetails();
    student.displayDetails();

    return 0;
}
