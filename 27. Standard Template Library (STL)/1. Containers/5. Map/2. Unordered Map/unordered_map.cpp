#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, string> um;
    um[1] = "one";
    um[2] = "two";

    cout << "Unordered Map:\n";
    for (auto pair : um)
        cout << pair.first << ": " << pair.second << endl;

    return 0;
}
