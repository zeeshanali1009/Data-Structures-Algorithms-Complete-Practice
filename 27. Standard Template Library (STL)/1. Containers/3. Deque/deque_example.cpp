#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> d;

    d.push_back(10);
    d.push_front(5);
    d.push_back(15);
    d.pop_front();  // removes 5
    d.pop_back();   // removes 15

    cout << "Deque: ";
    for (int x : d) cout << x << " ";

    return 0;
}
