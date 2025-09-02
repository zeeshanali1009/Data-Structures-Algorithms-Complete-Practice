#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    // Insert at back
    dq.push_back(10);
    dq.push_back(20);

    // Insert at front
    dq.push_front(5);

    cout << "Front: " << dq.front() << endl; // 5
    cout << "Back: " << dq.back() << endl;   // 20

    // Delete from front
    dq.pop_front();
    cout << "Front after pop_front: " << dq.front() << endl; // 10

    // Delete from back
    dq.pop_back();
    cout << "Back after pop_back: " << dq.back() << endl; // 10

    return 0;
}
