#include <iostream>
using namespace std;

int main() {
    int a = 5;  // 0101

    int result = a >> 1;  // 0010 = 2

    cout << "Right Shift 5 >> 1 = " << result << endl;
    return 0;
}
