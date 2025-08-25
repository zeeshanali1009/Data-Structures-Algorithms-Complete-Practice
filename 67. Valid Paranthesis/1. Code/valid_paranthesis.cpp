#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check if parentheses are valid
bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        // If opening bracket → push onto stack
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack empty → invalid
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // Matching check
            if ( (ch == ')' && top != '(') ||
                 (ch == '}' && top != '{') ||
                 (ch == ']' && top != '[') ) {
                return false;
            }
        }
    }

    // Valid if stack is empty (all matched)
    return st.empty();
}

int main() {
    string expr1 = "({[]})";
    string expr2 = "([)]";

    cout << expr1 << " → " 
         << (isValid(expr1) ? "Valid" : "Invalid") << endl;

    cout << expr2 << " → " 
         << (isValid(expr2) ? "Valid" : "Invalid") << endl;

    return 0;
}
