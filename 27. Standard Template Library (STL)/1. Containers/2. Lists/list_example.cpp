#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;

    l.push_back(10);
    l.push_front(5);
    l.push_back(20);
    l.pop_front();  // removes 5
    l.pop_back();   // removes 20

    cout << "List: ";
    for (int x : l) cout << x << " ";

    return 0;
}
