#include <iostream>
using namespace std;
void Insertion_Sort(int Arr[], int size )
{
    for (int i = 1; i < size; i++)
    {
        int key = Arr[i];
        int j = i - 1;
        while (j >= 0 && Arr[j] > key)
        {
            Arr[j + 1] = Arr[j];
            j = j - 1;
        }
        Arr[j + 1] = key;
    }
}
int main()
{
    int size;
    cout << "Enter the size of Array: ";
    cin >> size;
    int Arr[size];
    cout << "Please Enter the values for filling the indexes of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for index " << i << ": "; 
        cin >> Arr[i];
    }
    cout << "Unsorted Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    Insertion_Sort(Arr, size);
    cout << "\nSorted Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}

