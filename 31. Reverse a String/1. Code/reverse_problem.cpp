#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end()); // Step 1: Reverse the whole string

    string word = "";
    string ans = "";
    int i = 0;

    while (i < s.length()) {
        // Skip spaces
        if (s[i] == ' ') {
            i++;
            continue;
        }

        word = "";

        // Collect characters of a word
        while (i < s.length() && s[i] != ' ') {
            word += s[i];
            i++;
        }

        // Reverse the current word
        reverse(word.begin(), word.end());

        // Append to final answer if non-empty
        if (word.length() > 0) {
            ans += " " + word;
        }
    }

    // Remove initial space and return
    return ans.substr(1);
}

int main() {
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);

    string result = reverseWords(s);
    cout << "Reversed sentence: " << result << endl;

    return 0;
}
