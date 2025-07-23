#include <iostream>
using namespace std;
int main() {
    char ch;
    cout << "Enter a character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z') {
        cout << "It is an Uppercase letter." << endl;
    } else if (ch >= 'a' && ch <= 'z') {
        cout << "It is a Lowercase letter." << endl;
    } else {
        cout << "It is not a letter." << endl;
    }
    return 0;
}

// #include <iostream>  // For input and output
// using namespace std;

// int main() {
//     char ch;

//     // Ask the user to enter a character
//     cout << "Enter a character: ";
//     cin >> ch;

//     // Check if the character is an uppercase letter (ASCII 65 to 90)
//     if (ch >= 65 && ch <= 90) {
//         cout << "You entered an Uppercase letter." << endl;
//     }
//     // Check if the character is a lowercase letter (ASCII 97 to 122)
//     else if (ch >= 97 && ch <= 122) {
//         cout << "You entered a Lowercase letter." << endl;
//     }
//     // If it's neither uppercase nor lowercase, it's something else
//     else {
//         cout << "You did not enter an English letter." << endl;
//     }

//     return 0;  // Program ends
// }

// 'A' is same as 65
// 'Z' is same as 90
// 'a' is same as 97
// 'z' is same as 122
// When you write:
// if (ch >= 65 && ch <= 90)
// You're comparing the ASCII value of ch, which is an integer under the hood.

