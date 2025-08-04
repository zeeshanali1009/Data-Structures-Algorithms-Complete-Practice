#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int>& a) {
    int start = 0, end = a.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        // 🧤 Base case: check if mid is the single element
        bool isLeftDifferent = (mid == 0 || a[mid] != a[mid - 1]);
        bool isRightDifferent = (mid == a.size() - 1 || a[mid] != a[mid + 1]);

        if (isLeftDifferent && isRightDifferent)
            return a[mid];

        // ⚙️ Decide direction based on index pattern
        if (mid > 0 && a[mid] == a[mid - 1]) {
            // Pair is (a[mid - 1], a[mid])
            if (mid % 2 == 0)
                end = mid - 2;
            else
                start = mid + 1;
        } else {
            // Pair is (a[mid], a[mid + 1])
            if (mid % 2 == 0)
                start = mid + 2;
            else
                end = mid - 1;
        }
    }

    return -1;  // Should never reach here if input is valid
}

int main() {
    vector<int> a = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    cout << "Single non-duplicate element is: " << singleNonDuplicate(a) << endl;
    return 0;
}
