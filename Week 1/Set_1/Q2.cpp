#include <iostream>
using namespace std;

int main() {
    int marks;
    char grade;

    cout << "Enter the marks obtained (0-100): ";
    cin >> marks;

    // Determine the grade based on marks using switch
    switch (marks / 10) {
    case 10:
    case 9:
        grade = 'S';
        break;
    case 8:
        grade = 'A';
        break;
    case 7:
        grade = 'B';
        break;
    case 6:
        grade = 'C';
        break;
    case 5:
        grade = 'D';
        break;
    case 4:
        grade = 'E';
        break;
    default:
        grade = 'F';
    }

    cout << "The grade is: " << grade << endl;

    return 0;
}
