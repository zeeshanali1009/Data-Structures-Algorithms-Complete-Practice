#include <iostream>
using namespace std;
void Insertion_Sorting(int Array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
    cout << "Array after ascending sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}
void Insertion_Sorting_Descending(int Array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] < key) {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
    cout << "Array after descending sorting" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}
void Insertion_Sorting_bothways(int Array[], int n) {
    int middle = n / 2;
    for (int i = 0; i > middle - 1; i--) {
        int key = Array[i];
        int j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j--;
        }
        Array[j + 1] = key;
    }
    for (int i = middle; i < n - 1; i++) {
        int key = Array[i];
        int j = i + 1;
        while (j < n && Array[j] < key) {
            Array[j - 1] = Array[j];
            j++;
        }
        Array[j - 1] = key;
    }
    cout << "Array after sorting both ways from the middle" << endl;
    for (int i = 0; i < n; i++) {
        cout << Array[i] << "\t";
    }
    cout << endl;
}
int main() {
    int n, user_choice;
    while (true) {
        cout << "------------Welcome to the Sortings----------- " << endl;
        cout << "----------Insertion Sorting-------- " << endl;
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
                Insertion_Sorting(Array, n);
                break;
            case 2:
                Insertion_Sorting_Descending(Array, n);
                break;
            case 3:
                Insertion_Sorting_bothways(Array, n);
                break;
            case 4 :
                return 0;	
            default:
                cout << "Invalid choice. Please select a valid option." << endl;
        }
    }
}
