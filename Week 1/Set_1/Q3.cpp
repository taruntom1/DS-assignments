#include <iostream>
#include <vector>
using namespace std;


double add(const vector<double>& operands);
double subtract(const vector<double>& operands);
double multiply(const vector<double>& operands);
double divide(const vector<double>& operands);

int main() {
    int numOperands;
    char operation;
    vector<double> operands;

    cout << "Enter the operation you want to perform (+, -, *, /): ";
    cin >> operation;

    // Validate operation
    while (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
        cout << "Invalid operation. Try again\n";
    }

    cout << "How many operands do you want to use? ";
    cin >> numOperands;

    if (numOperands < 2) {
        cout << "You need at least two operands to perform an operation.\n";
        return 1;
    }

    cout << "Enter the operands:\n";
    for (int i = 0; i < numOperands; ++i) {
        double value;
        cin >> value;
        operands.push_back(value);
    }

    double result;
    switch (operation) {
    case '+':
        result = add(operands);
        break;
    case '-':
        result = subtract(operands);
        break;
    case '*':
        result = multiply(operands);
        break;
    case '/':
        result = divide(operands);
        break;
    default:
        cout << "Unexpected error.\n";
        return 1;
    }

    cout << "The result is: " << result << endl;
    return 0;
}


double add(const vector<double>& operands) {
    double sum = 0;
    for (double op : operands) {
        sum += op;
    }
    return sum;
}

double subtract(const vector<double>& operands) {
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

double multiply(const vector<double>& operands) {
    double product = 1;
    for (double op : operands) {
        product *= op;
    }
    return product;
}

double divide(const vector<double>& operands) {
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            cout << "Error: Division by zero detected.\n";
            exit(1);
        }
        result /= operands[i];
    }
    return result;
}
