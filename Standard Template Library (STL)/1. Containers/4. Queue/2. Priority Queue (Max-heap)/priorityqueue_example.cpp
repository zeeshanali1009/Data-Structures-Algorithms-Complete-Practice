#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(30);

    cout << "Top element (max): " << pq.top() << endl;

    pq.pop();

    cout << "After pop, new top: " << pq.top() << endl;

    return 0;
}
