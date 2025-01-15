#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveCharacters(const char *input, char *output, int &originalCount, int &processedCount)
{
    originalCount = strlen(input);
    int j = 0;

    for (int i = 0; i < originalCount; ++i)
    {
        if (i == 0 || input[i] != input[i - 1])
        {
            output[j++] = input[i];
        }
    }

    output[j] = '\0';
    processedCount = j;
}

int main()
{
    char input[1000];
    char output[1000];

    cout << "Enter a string: ";
    cin.getline(input, 1000);

    int originalCount = 0;
    int processedCount = 0;

    removeConsecutiveCharacters(input, output, originalCount, processedCount);

    cout << "Original string: " << input << endl;
    cout << "Original character count: " << originalCount << endl;
    cout << "Processed string: " << output << endl;
    cout << "Processed character count: " << processedCount << endl;

    return 0;
}
