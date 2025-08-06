#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;

    v.push_back(10);
    v.emplace_back(20);  // same as push_back but more efficient for objects
    v.push_back(30);

    cout << "Size: " << v.size() << ", Capacity: " << v.capacity() << endl;

    v.insert(v.begin() + 1, 15);  // insert 15 at position 1
    v.erase(v.begin());           // erase first element

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }

    cout << "\nFirst element (at): " << v.at(0) << endl;

    v.clear();
    cout << "Is empty? " << (v.empty() ? "Yes" : "No") << endl;

    return 0;
}
