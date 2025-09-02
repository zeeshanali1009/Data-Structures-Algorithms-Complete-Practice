#include <iostream>
using namespace std;

void merge(int Array[], int n) {
    int middle = n / 2;
    int start = 0;
    int end = n ;
    int n1 = middle - start + 1;
    int n2 = end - middle;

    int Left[n1];
    int Right[n2];

    for (int i = 0; i < n1; i++) {
        Left[i] = Array[i];
    }
    for (int j = 0; j < n2; j++) {
        Right[j] = Array[middle + j];
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            Array[k] = Left[i];
            i++;
        } else {
            Array[k] = Right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        Array[k] = Left[i];
        i++;
        k++;
    }

    while (j < n2) {
        Array[k] = Right[j];
        j++;
        k++;
    }
}

void mergeSort(int Array[], int n) {
    int start = 0;
    int end = n - 1;
    if (start < end) {
        int middle = start + (end - start) / 2;

        mergeSort(Array, n);
        mergeSort(Array, n);

        merge(Array, n);
    }
}

int main() {
    int n, user_choice;
    while (true) {
        cout << "------------Welcome to the Sortings----------- " << endl;
        cout << "----------Merge Sorting-------- " << endl;
        cout << "1. In Ascending " << endl;
        cout << "2. In Descending " << endl;
        cout << "3. In both ways from the middle " << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> user_choice;

        if (user_choice == 4) {
            return 0;
        }

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
                mergeSort(Array, n);
                cout << "Array after ascending sorting" << endl;
                for (int i = 0; i < n; i++) {
                    cout << Array[i] << "\t";
                }
                cout << endl;
                break;
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}

