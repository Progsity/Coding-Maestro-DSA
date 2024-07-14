#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int mx = i;
	int left = 2*i+1; //to access left element of i
	int right = 2*i+2; //to access right element of i

	if (left < n && arr[left] > arr[mx])
	{
		mx = left;
	}
	if (right < n && arr[right] > arr[mx])
	{
		mx = right;
	}
	if (mx != i)
	{
		swap(arr[i], arr[mx]);
		heapify(arr, n, mx);
	}

}

void heapSort(int arr[], int n)
{
	//building max heap
	for (int i = n/2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}
	for (int i = n-1; i > 0; i--)
	{
		swap(arr[0], arr[i]); //move root to the end
		heapify(arr, i, 0);
	}

}
int main()
{
	int arr[] = {4, 10, 3, 5, 1};
	int n = sizeof(arr)/sizeof(arr[0]);

	heapSort(arr, n);
	//print the sorted array
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
