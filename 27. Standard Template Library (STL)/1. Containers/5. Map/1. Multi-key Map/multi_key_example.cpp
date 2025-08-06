#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    map<string, int> m;
    m["apple"] = 2;
    m["banana"] = 5;

    cout << "Map values:\n";
    for (auto pair : m)
        cout << pair.first << " => " << pair.second << endl;

    return 0;
}
