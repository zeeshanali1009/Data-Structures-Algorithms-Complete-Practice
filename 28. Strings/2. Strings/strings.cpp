#include <iostream>
#include <string>  // Required for string class
using namespace std;

int main() {
    string s1 = "Hello";
    string s2 = "World";

    //  Print and Length
    cout << "s1: " << s1 << ", Length: " << s1.length() << endl;

    //  Concatenate
    string combined = s1 + " " + s2;
    cout << "Concatenated: " << combined << endl;

    //  Access characters
    cout << "Char at index 1: " << combined[1] << endl;

    //  Insert and Erase
    combined.insert(5, ",");
    cout << "After insert: " << combined << endl;

    combined.erase(5, 1);
    cout << "After erase: " << combined << endl;

    //  Substring
    cout << "Substring (0, 5): " << combined.substr(0, 5) << endl;

    //  Find
    if (combined.find("World") != string::npos)
        cout << "'World' found in the string.\n";

    //  Replace
    combined.replace(6, 5, "Universe");
    cout << "After replace: " << combined << endl;

    //  Read input
    string input1;
    cout << "Enter a word: ";
    cin >> input1;
    cout << "You entered: " << input1 << endl;

    cin.ignore();  // clear buffer
    string input2;
    cout << "Enter a full sentence: ";
    getline(cin, input2);
    cout << "Full sentence: " << input2 << endl;

    return 0;
}
