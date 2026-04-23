#include <iostream>
#include<stdlib.h>
using namespace std;
void Heapify(int arr[], int n, int i)
{
	int largest = i;
	int left = (2*i) + 1;
	int right = (2 * i) + 2;

	if (left < n && arr[left] > arr[largest])largest = left;
	if (right < n && arr[right] > arr[largest])largest = right;
	if (largest != i)
	{
		swap(arr[largest], arr[i]);
		Heapify(arr, n, largest);
	}



}
void HeapSort(int arr[], int n)
{
	for (int i = n / 2 - 1;i >= 0;i--)
	{
		Heapify(arr, n, i);
	}

	for (int i = n - 1;i > 0;i--)
	{
		swap(arr[0], arr[i]);
		Heapify(arr, i, 0);


	}
}


int main()
{
	int arr[20] ;
	srand(time(NULL));
	for (int v =0; v<20;v++)
	{
		arr[v] = (rand() % 100);
	}
	HeapSort(arr, 20);
	for (int v : arr)
	{
		cout << "\t" << v;
	}

}