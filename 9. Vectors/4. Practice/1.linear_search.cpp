#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums;  // Empty vector

    // Push elements into vector
    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);
    nums.push_back(40);

    cout << "Vector elements using for-each loop:\n";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    // Size of vector
    cout << "Size of vector: " << nums.size() << endl;

    // Accessing elements
    cout << "First element (front): " << nums.front() << endl;
    cout << "Last element (back): " << nums.back() << endl;
    cout << "Element at index 2: " << nums.at(2) << endl;

    // Pop an element
    nums.pop_back(); // Removes 40

    cout << "Vector after pop_back(): ";
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    // Using begin() and end()
    cout << "Accessing via iterator: ";
    for (auto it = nums.begin(); it != nums.end(); ++it) {
        cout << *it << " ";
    }

    return 0;
}
