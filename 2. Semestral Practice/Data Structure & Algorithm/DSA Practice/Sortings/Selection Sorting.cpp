#include <iostream>
using namespace std;

void Bubble_Sorting_Ascending(int Array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (Array[j] > Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
    cout << "Array after ascending sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}

void Bubble_Sorting_Descending(int Array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (Array[j] < Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }
    cout << "Array after descending sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}

void Bubble_Sorting_BothWays(int Array[], int n) {
    int middle = n / 2;

    // Sort the left half in ascending order
    for (int i = 0; i < middle - 1; i++) {
        for (int j = 0; j < middle - 1 - i; j++) {
            if (Array[j] > Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }

    // Sort the right half in descending order
    for (int i = middle; i < n - 1; i++) {
        for (int j = middle; j < n - 1 - (i - middle); j++) {
            if (Array[j] < Array[j + 1]) {
                int temp = Array[j];
                Array[j] = Array[j + 1];
                Array[j + 1] = temp;
            }
        }
    }

    cout << "Array after sorting both ways" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}

int main() {
    int n, user_choice;
    while (true) {
        cout << "------------Welcome to the Sortings----------- " << endl;
        cout << "----------Bubble Sorting-------- " << endl;
        cout << "1. In Ascending " << endl;
        cout << "2. In Descending " << endl;
        cout << "3. In both ways from the middle " << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;
        cout << "Enter the size of the array: ";
        cin >> n;
        int Array[n];

        cout << "Now enter the values in the array: " << endl;
        for (int i = 0; i < n; i++) {
            cout << "Enter the value: ";
            cin >> Array[i];
        }
        cout << "Array before sorting: " << endl;
        for (int i = 0; i < n; i++) {
            cout << Array[i] << "\t";
        }
        cout << endl;

        switch (user_choice) {
            case 1:
                Bubble_Sorting_Ascending(Array, n);
                break;
            case 2:
                Bubble_Sorting_Descending(Array, n);
                break;
            case 3:
                Bubble_Sorting_BothWays(Array, n);
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}

