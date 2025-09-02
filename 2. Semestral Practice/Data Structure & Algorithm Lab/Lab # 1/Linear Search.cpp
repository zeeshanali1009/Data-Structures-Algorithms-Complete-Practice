#include <iostream>
using namespace std;
int Linear_Search(int Arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (Arr[i] == key)
        {
            cout << "Match has found at index " <<  i << "." << endl; 
        }
    }
    return -1; 
}

int main()
{
    int size;
    cout << "Enter the size of Array" << endl;
    cin >> size;
    int Arr[size];
    cout << "Please Enter the values for filling the indexes of the array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value for index " << i << ": ";
        cin >> Arr[i];
    }
    cout << "Given Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << Arr[i] << " ";
    }
    int key;
    cout << "\nPlease Enter the number you want to search in the array" << endl;
    cin >> key;

    int index = Linear_Search(Arr, size, key);



    return 0;
}

