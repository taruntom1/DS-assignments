#include <iostream>
using namespace std;

int main()
{
    char string[1000];
    int stringLength = 0;

    cout << "Enter a string: ";
    cin >> string;

    for (stringLength = 0; string[stringLength] != '\0'; stringLength++)
    {
        continue;
    }

    bool *isVowel = new bool[stringLength];
    bool *isNotChar = new bool[stringLength];

    for (int i = 0; i < stringLength; i++)
    {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u')
        {
            isVowel[i] = true;
        }
        else
        {
            isVowel[i] = false;
        }

        if ((string[i] >= 'A' && string[i] <= 'Z') || (string[i] >= 'a' && string[i] <= 'z'))
        {
            isNotChar[i] = false;
        }
        else
        {
            isNotChar[i] = true;
        }
    }

    cout << "Vowels are at positions: ";
    for (int i = 0; i < stringLength; i++)
    {
        if (isVowel[i] == true)
        {
            cout << i + 1 << ", ";
        }
    }

    cout << "\nNon-Characters are at positions: ";
    for (int i = 0; i < stringLength; i++)
    {
        if (isNotChar[i] == true)
        {
            cout << i + 1 << ", ";
        }
    }

    int firstVowel = -1;

    for (int i = 0; i < stringLength; i++)
    {
        if (isVowel[i] == true)
        {
            firstVowel = i + 1;
            break;
        }
    }
    cout << "\nfirst vowel is at position: " << firstVowel;

    return 0;
}