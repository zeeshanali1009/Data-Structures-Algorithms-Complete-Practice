#include <iostream>
using namespace std;
int main() {
    int x = 5;
    bool flag = true;
    cout << "Original x: " << x << endl;
    cout << "Post-increment x++: " << x++ << endl;
    cout << "After post-increment: " << x << endl;
    cout << "Pre-increment ++x: " << ++x << endl;
    cout << "Negation -x: " << -x << endl;
    cout << "Logical NOT (!flag): " << !flag << endl;
    return 0;
}
