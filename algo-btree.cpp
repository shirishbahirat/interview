#include <iostream>

using namespace std;

int bin_search(int arr[], int lo, int hi, int target)
{
	if ((lo == hi) && arr[lo] == target) return lo;
	if ((lo == hi) && arr[lo] != target) return -1;

	if (lo > hi) return -1;

	int mid = lo + (hi - lo) / 2;

	if (target == arr[mid]) return mid;
	else if (target > arr[mid]) return bin_search(arr, mid + 1, hi, target);
	else if (target < arr[mid]) return bin_search(arr, lo, mid - 1, target);

	return -1;
}

int main(int argc, const char* argv[])
{

	int arr[] = {5,6,8,9,12,15};
	int size = sizeof(arr)/sizeof(arr[0]) - 1;

	cout << "index " << bin_search(arr, 0, size, 5) << endl;

	return 0;
}