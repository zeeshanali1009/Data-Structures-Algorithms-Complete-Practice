#include <iostream>
using namespace std;
void Selection_Sort(int Arr[], int size )
{
    for (int i = 0; i < size - 1; i++)
    {
        int small = i;
        for (int j = i + 1; j < size; j++)
        {
            if (Arr[j] < Arr[small]) 
            {
                small = j;
            }
        }
        if (small != i)
        {
            int temp;
            temp = Arr[small];
            Arr[small] = Arr[i];
            Arr[i] = temp;
        }
    }
}
int main()
{
    int size;
    cout << "Enter the size of Array" << endl;
    cin >> size;
    int Arr[size];
    cout << "Please Enter the values for filling the indexes of the array" << endl;
    for (int i = 0; i < size; i++)
    {       cout << "Enter the value for index " << i << ": "; 
        cin >> Arr[i];
    }
    cout << "Unsorted Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    Selection_Sort(Arr, size);
    cout << "\nSorted Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    return 0;
}

