#include <iostream>

using namespace std;

int bin_search(int arr[], int lo, int hi, int target)
{
	if ((lo == hi) && arr[lo] == target) return lo;
	if ((lo == hi) && arr[lo] != target) return -1;

	if (lo < hi) return -1;

	int mid = lo + (hi - lo) / 2;

	if (target == arr[mid]) return mid;
	else if (target > arr[mid]) bin_search(arr, mid + 1, hi, target);
	else if (target < arr[mid]) bin_search(arr, lo, mid, target);

	return -1;
}

int main(int argc, const char* argv[])
{

	int arr[] = {5,6,8,9,12,15};
	int size = sizeof(arr)/sizeof(arr[0]);

	cout << bin_search(arr, 0, 5, 6) << endl;

	return 0;
}