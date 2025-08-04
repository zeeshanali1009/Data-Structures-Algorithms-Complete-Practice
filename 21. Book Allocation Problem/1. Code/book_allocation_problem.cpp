#include <iostream>
using namespace std;

// 🔍 Function to check if we can allocate books such that
// no student gets more than 'maxPages'
bool isValid(int arr[], int n, int students, int maxPages) {
    int count = 1;       // Number of students
    int pages = 0;       // Pages assigned to current student

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return false;  // A single book exceeds allowed limit

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            count++;
            pages = arr[i];

            if (count > students)
                return false;
        }
    }
    return true;
}

// 🧮 Main function to apply binary search
int allocateBooks(int arr[], int n, int students) {
    if (students > n)
        return -1;  // Not enough books

    // 🧾 Calculate search space
    int start = arr[0], end = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > start)
            start = arr[i];  // max element
        end += arr[i];       // sum of all pages
    }

    int answer = -1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (isValid(arr, n, students, mid)) {
            answer = mid;
            end = mid - 1;  // try for better (less pages)
        } else {
            start = mid + 1;  // need more pages
        }
    }

    return answer;
}

int main() {
    int books[] = {12, 34, 67, 90};
    int n = 4;
    int students = 2;

    int result = allocateBooks(books, n, students);
    if (result == -1)
        cout << "Not enough books for all students.\n";
    else
        cout << "Minimum maximum pages = " << result << endl;

    return 0;
}
