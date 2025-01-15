#include <iostream>
using namespace std;

long factorial(int number);
long pow(int base, int exponent);
static double SumofSequence(int x, int count);

int main()
{
	cout << "Enter a number \n";
	int number = 0;
	int count = 0;
	cin >> number;
	cout << "Enter number of terms for the sequence\n";
	cin >> count;
	cout << "sum" << SumofSequence(number, count) << "\n";
	return 0;
}

static double SumofSequence(int x, int count)
{
	double sum = x;
	count = count * 2 - 1;
	bool plusOrMinus = true;

	for (int i = 3; i <= count; i += 2)
	{
		if (plusOrMinus)
		{
			sum += static_cast<double>(pow(x, i)) / factorial(i - 1);
		}
		else
		{
			sum -= static_cast<double>(pow(x, i)) / factorial(i - 1);
		}

		plusOrMinus = !plusOrMinus;
	}
	return sum;
}

long pow(int base, int exponent)
{
	// returns the power of a number
	long result = 1;
	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	return result;
}

long factorial(int number)
{
	// returns the factorial of a number
	long result = 1;
	for (int i = 1; i <= number; i++)
	{
		result *= i;
	}
	return result;
}
