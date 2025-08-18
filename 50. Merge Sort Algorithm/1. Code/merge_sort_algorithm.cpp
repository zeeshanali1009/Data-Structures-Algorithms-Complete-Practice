#include <bits/stdc++.h>
using namespace std;

// Function to merge two halves
void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> temp; 
    int i = start, j = mid + 1;

    // Compare elements from both halves and store in temp
    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {   // Ascending order
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements from left half
    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements from right half
    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy back to original array
    for(int idx = 0; idx < temp.size(); idx++) {
        arr[start + idx] = temp[idx];
    }
}

// Recursive function for merge sort
void mergeSort(vector<int>& arr, int start, int end) {
    if(start >= end) return; // Base case: single element

    int mid = start + (end - start) / 2;

    // Recursively sort two halves
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Merge sorted halves
    merge(arr, start, mid, end);
}

int main() {
    vector<int> arr = {8, 4, 2, 5, 3, 1, 7, 6};

    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    cout << "Sorted array: ";
    for(int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
