#include <iostream>
using namespace std;
int main() {
    int arr[] = {10, 20, 30};
    int* p1 = &arr[0];
    int* p2 = &arr[2];

    if (p1 < p2) {
        cout << "p1 points to an earlier element than p2" << endl;
    }
    return 0;
}
