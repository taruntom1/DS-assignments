#include <iostream>
using namespace std;

char *CreateExpression(int line, int pos);

int main()
{
	for (int i = 1; i < 6; i++)
	{
		static char line[30];

		int offset = 15 - 3 * i;
		for (int j = 0; j < offset; j++)
		{
			line[j] = ' ';
		}

		for (int j = 0; j < i; j++)
		{
			char *expression = CreateExpression(i, j + 1);
			for (int k = 0; k < 5; k++)
			{
				line[j * 6 + k + offset] = expression[k];
			}
			line[j * 6 + 5 + offset] = ' ';
		}
		line[6 * i - 1 + offset] = '\0';
		cout << line;
		cout << "\n";
	}

	return 0;
}

char *CreateExpression(int line, int pos)
{
	char expression[5] = {'x', '^', line + '0', '+', pos + '0'};

	return expression;
}