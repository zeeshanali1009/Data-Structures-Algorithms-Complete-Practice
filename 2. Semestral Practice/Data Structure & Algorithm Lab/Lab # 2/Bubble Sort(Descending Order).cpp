#include <iostream>
using namespace std;
void Bubble_Sort (int Arr[], int n )
{
for (int i =0 ; i < n-1 ; i++)
{
	for (int j =0 ; j < n-i-1 ; j++)
	{
		if (Arr[j] < Arr[j+1])
		{
			int temp = Arr[j];
			Arr[j]= Arr[j+1];
			Arr[j+1] = temp ;
		}
	}

}
    cout << "Array after bubble sorting " << endl;
	for (int i = 0 ; i < n ; i++)
{
	cout << Arr[i] <<" "  ;
}
}
int main()
{
	int n ;
	cout << "Enter the size of the array " << endl;
	cin >> n ;
	int Array[n];
	for (int i = 0 ; i < n ; i++)
{
	cout << "Enter the element ";
	cin >> Array[i];
}
cout << "Array before sorting " << endl;
	for (int i = 0 ; i < n ; i++)
{
	cout << Array[i] <<" "  ;
}
cout << endl;
Bubble_Sort(Array , n);
}
