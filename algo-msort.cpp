#include <iostream>

using namespace std;

void merge(int arr[], int lo, int mid, int hi)
{

	
}


void mergesort(int arr[], int lo, int hi)
{
	if (hi <= lo) return;

	int mid = lo + (hi - lo) / 2;

	mergesort(arr, lo, mid);
	mergesort(arr, mid+1, hi);
	merge(arr, lo, mid, hi);

}


int main(int argc, char* argv[])
{

	int arr[] = {4, 3, 8, 5, 11, 2};
	int len = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}