#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, part;
    
    cout << "Enter the main string: ";
    getline(cin, s);

    cout << "Enter the part to remove: ";
    cin >> part;

    int length = part.length();  // length of part
    size_t sp = s.find(part);    // position of part in s

    // Keep removing while found and string is non-empty
    while (s.length() > 0 && sp < s.length()) {
        s.erase(sp, length);        // remove the part from index sp
        sp = s.find(part);          // find next occurrence
    }

    cout << "Result after removal: " << s << endl;

    return 0;
}
