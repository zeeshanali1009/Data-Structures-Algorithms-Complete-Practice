#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    unordered_set<int> us = {3, 1, 4, 2};
    cout << "\nUnordered Set: ";
    for (int x : us) cout << x << " ";

    return 0;
}
