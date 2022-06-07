#include <iostream>

using namespace std;

int bin_search(int arr[], int lo, int hi, int number)
{
	//if ((lo == hi) && arr[lo] == number) return lo;
	//if ((lo == hi) && arr[lo] != number) return -1;

	if (lo < high) return -1;

	int mid = lo + (hi - lo) / 2;

	if (number == arr[mid]) return mid;
	else if (number > arr[mid]) bin_search(arr, mid + 1, hi, number);
	else if (number < arr[mid]) bin_search(arr, lo, mid - 1, number);

	return -1;
}

int main(int argc, const char* argv[])
{

	int arr[] = {5,6,8,9,12,15};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << bin_search(arr, 0, size - 1, 6) << endl;

	return 0;
}