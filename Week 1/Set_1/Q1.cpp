#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Define items and prices
    string items[5] = { "Tomatoes", "Potatoes", "Onions", "Carrots", "Spinach" };
    double prices[5] = { 200, 180, 260, 190, 110 }; // per kg
    double quantities[5];  //kg                       
    double total = 0.0;

    // Get quantities from the user
    cout << "Enter the quantity (in kg) for each item:\n";
    for (int i = 0; i < 5; i++) {
        cout << items[i] << " (Rs " << prices[i] << "/kg): ";
        cin >> quantities[i];
        total += prices[i] * quantities[i];
    }

    // Print the bill
    cout << "\n========== BILL ==========\n";
    cout << setw(15) << left << "Item"
        << setw(10) << "Price"
        << setw(10) << "Quantity"
        << setw(10) << "Total" << endl;

    cout << setprecision(2) << fixed;
    for (int i = 0; i < 5; i++) {
        cout << setw(15) << left << items[i]
            << setw(10) << prices[i]
            << setw(10) << quantities[i]
            << setw(10) << prices[i] * quantities[i] << endl;
    }

    cout << "==========================\n";
    cout << setw(35) << "Grand Total: Rs" << total << endl;

    return 0;
}
