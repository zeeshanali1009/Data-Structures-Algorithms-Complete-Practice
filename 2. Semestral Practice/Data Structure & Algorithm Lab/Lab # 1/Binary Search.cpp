#include <iostream>
using namespace std;
int binarySearch(int A[], int n, int start, int end) {
    int loc = -1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (A[mid] == n) {
            loc = mid;
            break;
        } else if (n < A[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return loc;
}
int main() {
	int size ;
	cout << "Enter the size of the arraY" << endl;
	cin >> size ;
	int Arr[size];
	  for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for index " << i << ": ";
        cin >> Arr[i];
    }
    int n, loc;
    loc = -1;
    cout << "Enter the number to find: ";
    cin >> n;
    loc = binarySearch(Arr, n, 0, 9);
    if (loc == -1) {
        cout << n << " not found!" << endl;
    } else {
        cout << n << " found at index " << loc << endl;
    }
    return 0;
}

