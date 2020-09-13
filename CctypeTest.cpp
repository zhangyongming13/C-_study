#include <cctype>
#include <iostream>

using namespace std;

void CharacterClassification()
{
    char c1 = '4';
    char c2 = '?';
    if (isalnum(c1)) {
        cout << c1 << " is number or letter." << endl;
    }
    if (!isalnum(c2)) {
        cout << c2 << " is not number or letter." << endl;
    }

    char c3 = 'a';
    char c4 = '5';
    if (isalpha(c3)) {
        cout << c3 << " is letter." << endl;
    }
    if (!isalpha(c4)) {
        cout << c4 << " is not letter." << endl;
    }

    char c5 = 'a';
    char c6 = 'A';
    if (islower(c5)) {
        cout << c5 << " is lower letter." << endl;
    }
    if (isupper(c6)) {
        cout << c6 << " is upper letter." << endl;
    }

    char c7 = '9';
    if (isdigit(c7)) {
        cout << c7 << " is digit." << endl;
    }
}

void ToggleCase()
{
    char c1 = 'a';
    char c2 = 'G';
    if (islower(c1)) {
        char c3 = toupper(c1);
        cout << c1 << " changed to " << c3 << endl;
    }
    if (isupper(c2)) {
        char c4 = tolower(c2);
        cout << c2 << " changed to " << c4 << endl;
    }
}

int main()
{
    CharacterClassification();
    ToggleCase();
    return 0;
}