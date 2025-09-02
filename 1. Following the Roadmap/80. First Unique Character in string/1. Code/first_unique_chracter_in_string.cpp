#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

char firstUniqueChar(string s) {
    unordered_map<char, int> freq; // frequency map
    queue<char> q;                 // to track order

    // Traverse the string
    for (char c : s) {
        freq[c]++;       // increase frequency
        q.push(c);       // push into queue

        // Maintain only valid unique chars at front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }
    }

    // After processing
    if (!q.empty()) {
        return q.front(); // first unique character
    }
    return '#'; // return special symbol if none exists
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    char result = firstUniqueChar(s);
    if (result == '#')
        cout << "No unique character found!" << endl;
    else
        cout << "First unique character: " << result << endl;

    return 0;
}
