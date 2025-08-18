#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string &str) {
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l] != str[r]) return false;
        l++, r--;
    }
    return true;
}

void getPal(string s, vector<string> &partition, vector<vector<string>> &ans) {
    // Base case
    if (s.size() == 0) {
        ans.push_back(partition);
        return;
    }

    // Try all possible prefixes
    for (int i = 0; i < s.size(); i++) {
        string part = s.substr(0, i + 1);

        if (isPalindrome(part)) {
            // choose
            partition.push_back(part);

            // explore remainder of string
            getPal(s.substr(i + 1), partition, ans);

            // backtrack
            partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> partition;
    getPal(s, partition, ans);
    return ans;
}

int main() {
    string s = "aab";
    vector<vector<string>> result = partition(s);

    cout << "Palindrome partitions:\n";
    for (auto &vec : result) {
        cout << "[ ";
        for (auto &p : vec) cout << p << " ";
        cout << "]\n";
    }

    return 0;
}
