#include <iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int getMax(int arr[], int n)
{
	int m = arr[0];
	for (int i =0;i<n;i++)
	{
		if (m < arr[i])m = arr[i];
	}
	return m;
}

void CountSort(int arr[], int exp, int n)
{
	int count[10] = { 0 };
	vector<int>output(n);
	for (int i = 0;i < n;i++)
	{
		count[(arr[i] / exp) % 10]++;
	}

	for (int i = 1;i < 10;i++)
	{
		count[i]+= count[i-1];
	}
	for (int i = n - 1;i >= 0;i--)
	{
		int digit = (arr[i] / exp) % 10;
		output[count[digit] - 1] = arr[i];
		count[digit]--;
	}

	for (int i =0;i<n;i++)
	{
		arr[i] = output[i];
	}
}

void RadixFunction(int arr[],  int n)
{
	int m = getMax(arr,n);
	for (int exp = 1;m / exp > 0;exp *= 10)
	{
		CountSort(arr, exp, n);
	}
}

int main()
{
	srand(time(NULL));
	int arr[20];
	for (int i = 0;i < 20;i++)
	{
		arr[i] = rand() % 100;
	}
	RadixFunction(arr, 20);
	for (int i = 0; i < 20; i++)
	{
		cout << arr[i] << " ";
	}
}