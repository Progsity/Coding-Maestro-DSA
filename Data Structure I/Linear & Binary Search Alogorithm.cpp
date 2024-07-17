#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] == key){
			return i;
		}
	}
	return -1;
}
int binarySearch(int arr[], int n, int key)
{
	int low = 0, high = n;
	while(low <= high)
	{
		int mid = (low+high)/2;
		if(arr[mid] == key) return mid;
		else if(arr[mid] > key) high = mid - 1;
		else low = mid + 1;
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int arr[10], n, key;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cin >> key;

	sort(arr, arr+n);
	cout << "Sorted array: ";
	for (int i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	cout << endl;

	int idx = binarySearch(arr, n, key);
	if(idx >= 0)
		printf("%d is found in the index %d\n", key, idx);
	else
		cout << "Not found!\n";
	return 0;
}
