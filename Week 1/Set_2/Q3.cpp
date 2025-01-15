#include <iostream>
using namespace std;

int numUpto = 5;
void MakePattern(char *pattern, int line);
void align(char *pattern, int line);

int main()
{

    for (int i = 0; i <= numUpto; i++)
    {
        char *pattern = new char[numUpto + i + 2];

        align(pattern, i);
        MakePattern(pattern, i);
        pattern[numUpto + i + 1] = '\0';

        cout << pattern << endl;

        delete[] pattern;
    }

    return 0;
}

void MakePattern(char *pattern, int line)
{
    for (int i = 0; i <= line; i++)
    {
        pattern[numUpto + i] = '0' + i;
        pattern[numUpto - i] = '0' + i;
    }
}

void align(char *pattern, int line)
{
    for (int i = 0; i < numUpto - line; i++)
    {
        pattern[i] = ' ';
    }
}
