#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int number;

    // Input the 6-digit number
    cout << "Enter a 6-digit number: ";
    cin >> number;

    // Check if the number is a 6-digit number
    if (number < 100000 || number > 999999)
    {
        cout << "The number entered is not a 6-digit number." << endl;
        return 1;
    }

    int reversedNumber = 0, sumOfDigits = 0;
    int originalNumber = number;

    // Reverse the number and calculate the sum of its digits
    while (number > 0)
    {
        int digit = number % 10;
        reversedNumber = reversedNumber * 10 + digit;
        sumOfDigits += digit;
        number /= 10;
    }

    // Output the results
    cout << "Reversed Number: " << reversedNumber << endl;
    cout << "Sum of Digits: " << sumOfDigits << endl;

    return 0;
}
