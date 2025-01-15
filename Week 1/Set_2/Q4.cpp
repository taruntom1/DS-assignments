#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    char num1[7];
    char num2[7];
    char num3[7];

    char num1rev[7] = "000000";
    char num2rev[7] = "000000";
    char num3rev[7] = "000000";

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "Enter third number: ";
    cin >> num3;

    // Reverse the numbers
    for (int i = 0; i < 6; i++)
    {
        num1rev[i] = num1[5 - i];
        num2rev[i] = num2[5 - i];
        num3rev[i] = num3[5 - i];
    }

    // Convert the numbers to integers
    int num1Int = atoi(num1rev);
    int num2Int = atoi(num2rev);
    int num3Int = atoi(num3rev);

    // Print the reversed numbers
    cout << "Reversed first number: ";
    cout << num1rev << endl;
    cout << "Reversed second number: ";
    cout << num2rev << endl;
    cout << "Reversed third number: ";
    cout << num3rev << endl;

    // Finding the largest of the reversed

    int largest = num1Int;
    if (num2Int > largest)
        largest = num2Int;
    if (num3Int > largest)
        largest = num3Int;
    cout << "Largest number among the reversed numbers: " << largest << endl;

    return 0;
}
