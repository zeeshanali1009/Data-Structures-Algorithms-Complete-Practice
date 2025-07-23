#include <iostream>
using namespace std;
int main() {
    float num = 7.8;
    // Explicitly cast float to int
    int converted = (int) num;
    cout << "Original: " << num << endl;
    cout << "After casting to int: " << converted << endl;
    return 0;
}
