#include <iostream>


using namespace std;

void swap(int arr[], int a, int b)
{

	int temp = arr[a];

	arr[a] = arr[b];
	arr[b] = temp;

}

int partition(int arr[], int lo, int hi)
{

	int pivot = lo;


	while(lo < hi)
	{

		while (arr[lo] <= arr[pivot]) lo++;

		while (arr[high] > arr[pivot]) --hi;

		if (lo < hi) swap(arr,lo, hi);

	}

	swap(arr, hi, pivot);

	return hi;

}

void quicksort(int arr[], int lo, int hi)
{

	if (lo >= hi) return;

	int mid = partition(arr, lo, hi);

	quicksort(arr, lo, mid - 1);

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
