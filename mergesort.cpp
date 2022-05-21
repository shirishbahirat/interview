#include <iostream>

using namespace std;

int mergesort(int arr[], int low, int high)
{

	if (low < high)
	{
		int mid = low + (high - low)/2;

		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);

	}


	return 0;
}


int main(int argc, char* argv[])
{

	int arr[] = {4, 3, 8, 5, 11, 2};
	int len = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, len - 1);

	return 0;
}