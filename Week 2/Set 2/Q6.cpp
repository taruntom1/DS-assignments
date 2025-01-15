#include <iostream>
#include <string>
using namespace std;

class REPORT {
private:
    int adno; //admission number
    char name[21]; // 20 characters + 1 for null terminator
    float marks[5]; // Array of 5 floating point values
    float average; // Average marks obtained

    // Private function to compute the average of marks
    void GETAVG() {
        float sum = 0;
        for (int i = 0; i < 5; ++i) {
            sum += marks[i];
        }
        average = sum / 5;
    }

public:
    // Function to accept values for adno, name, and marks
    void READINFO() {
        cout << "Enter 4-digit admission number: ";
        cin >> adno;
        cin.ignore(); // Clear the input buffer

        cout << "Enter name (max 20 characters): ";
        cin.getline(name, 21);

        cout << "Enter marks for 5 subjects: \n";
        for (int i = 0; i < 5; ++i) {
            cout << "Mark " << (i + 1) << ": ";
            cin >> marks[i];
        }

        // Compute the average marks
        GETAVG();
    }

    // Function to display all data members
    void DISPLAYINFO() {
        cout << "\nAdmission Number: " << adno;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for (int i = 0; i < 5; ++i) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage Marks: " << average << endl;
    }
};

int main() {
    REPORT student;

    // Read information for the student
    student.READINFO();

    // Display the information
    student.DISPLAYINFO();

    return 0;
}
