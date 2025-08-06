#include <iostream>
#include <cstring>  // For string functions
using namespace std;

int main() {
    char name1[50] = "Hello";
    char name2[50] = "World";

    //  Print and Length
    cout << "name1: " << name1 << ", Length: " << strlen(name1) << endl;

    //  Concatenate
    strcat(name1, name2);  // name1 = HelloWorld
    cout << "After strcat: " << name1 << endl;

    //  Copy
    strcpy(name2, "Everyone");
    cout << "After strcpy: " << name2 << endl;

    //  Compare
    if (strcmp(name1, name2) == 0)
        cout << "Strings are equal.\n";
    else
        cout << "Strings are NOT equal.\n";

    //  Reading input using cin
    char input1[100];
    cout << "Enter a word: ";
    cin >> input1;  // stops at space
    cout << "You entered: " << input1 << endl;

    //  Reading full line using cin.getline
    cin.ignore();  // clear buffer after previous input
    char input2[100];
    cout << "Enter a full sentence: ";
    cin.getline(input2, 100);
    cout << "Full line: " << input2 << endl;

    return 0;
}
