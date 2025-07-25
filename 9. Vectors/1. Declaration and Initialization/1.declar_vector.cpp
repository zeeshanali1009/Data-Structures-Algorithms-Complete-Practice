#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  // empty vector

    // You can also initialize directly
    vector<int> nums = {1, 2, 3, 4};
     vector<int> v(4, 7);  // size = 4, each element = 7

    return 0;
}
