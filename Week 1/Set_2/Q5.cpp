#include <iostream>

void generateFibonacci(int *fibArray, int n)
{
    if (n <= 0)
        return;

    if (n >= 1)
        fibArray[0] = 0;
    if (n >= 2)
        fibArray[1] = 1;

    for (int i = 2; i < n; ++i)
    {
        fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
    }
}

static unsigned long factorial(int n)
{
    unsigned long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n;
    std::cout << "Enter the number of Fibonacci numbers to generate: ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "Invalid input. Please enter a positive integer." << std::endl;
        return 1;
    }

    int *fibArray = new int[n];
    generateFibonacci(fibArray, n);

    std::cout << "Num\tFact\n";
    for (int i = 0; i < n; ++i)
    {
        std::cout << fibArray[i] << "\t" << factorial(fibArray[i]) << "\n";
    }
    std::cout << std::endl;

    delete[] fibArray;

    return 0;
}