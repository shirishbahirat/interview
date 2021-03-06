#include <iostream>


using namespace std;

void swap(int arr[], int a, int b)
{

	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;

}

int partition(int arr[], int low, int high)
{
	
	int pivot = low;

	while (low < high)
	{
		while(arr[low] <= arr[pivot]) 
		{
			low++;
		}
		while(arr[high] > arr[pivot])
		{
			high--;
		}
	
		if (low < high)
		{
			swap(arr, low, high);
		}

		for (int i = 0; i < 9; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	swap(arr, pivot, high);

	return high;
}

void quicksort(int arr[], int low, int hi)
{

	if (low >= hi) return;

	int mid = partition(arr, low, hi);

	quicksort(arr, low, mid);

	quicksort(arr, mid+1, hi);

}

int main(int argc, char* argv[])
{

	int arr[] = {6, 7, 5, 4, 2, 1, 8, 9, 3};

	int len = sizeof(arr)/sizeof(arr[0]);

	quicksort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}