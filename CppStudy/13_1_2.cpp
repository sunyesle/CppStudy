#include <iostream>
using namespace std;

template <class T>
T SumArray(T arr[], int len)
{
	T sum =(T) 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	int arr1[] = { 1,2,3,4 };
	double arr2[] = { 1,2,3,4,5,6.44 };
	cout << SumArray<int>(arr1, sizeof(arr1)/sizeof(int)) << endl;
	cout << SumArray<double>(arr2, sizeof(arr2) / sizeof(double)) << endl;
	return 0;
}