#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars) {
    int idx = 0;  // Index for compressed result
    int i = 0;

    while (i < chars.size()) {
        char ch = chars[i];
        int count = 0;

        // Count how many times ch repeats
        while (i < chars.size() && chars[i] == ch) {
            count++;
            i++;
        }

        // Place the character
        chars[idx++] = ch;

        // If count > 1, convert it to string and place digits
        if (count > 1) {
            string str = to_string(count);
            for (char digit : str) {
                chars[idx++] = digit;
            }
        }
    }

    // Optional: resize to remove trailing characters
    chars.resize(idx);

    return idx;  // New length of compressed array
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    int newLength = compress(chars);

    cout << "Compressed Characters: ";
    for (int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}
