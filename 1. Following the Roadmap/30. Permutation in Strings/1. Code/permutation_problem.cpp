#include <iostream>
#include <string>
using namespace std;

// Compare two frequency arrays of size 26
bool isFreqSame(int a[], int b[]) {
    for (int i = 0; i < 26; i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}

// Check if any permutation of s1 exists in s2
bool checkInclusion(string s1, string s2) {
    int len1 = s1.length();
    int len2 = s2.length();

    if (len1 > len2) return false;

    int freq1[26] = {0}; // Frequency array for s1
    int freq2[26] = {0}; // Frequency array for current window in s2

    // Fill initial frequency arrays
    for (int i = 0; i < len1; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    // Check first window
    if (isFreqSame(freq1, freq2)) return true;

    // Slide window through s2
    for (int i = len1; i < len2; i++) {
        freq2[s2[i] - 'a']++;               // Add new character
        freq2[s2[i - len1] - 'a']--;        // Remove old character

        if (isFreqSame(freq1, freq2)) return true;
    }

    return false;
}

int main() {
    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "Yes, a permutation of s1 is present in s2." << endl;
    } else {
        cout << "No, permutation of s1 is not present in s2." << endl;
    }

    return 0;
}
