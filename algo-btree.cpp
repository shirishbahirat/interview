#include <iostream>
#include <vector>


using namespace std;

int bin_search(vector<int> arr, int lo, int hi, int target)
{

	if (lo > hi) return -1;

	int mid = lo + (hi - lo) / 2;

	if (target == arr[mid]) return mid;
	else if (target > arr[mid]) return bin_search(arr, mid + 1, hi, target);
	else if (target < arr[mid]) return bin_search(arr, lo, mid - 1, target);

	return -1;
}

int bin_search(vector<int> arr, int target)
{
	int lo = 0, hi = arr.size() - 1;

	while (lo <= hi)
	{
		int mid = lo + (hi - lo) / 2;

		if (arr[mid] == target) return mid;
		else if (arr[mid] > target) hi = mid - 1;
		else if (arr[mid] < target) lo = mid + 1;
	}

	return - 1;
}

int main(int argc, const char* argv[])
{

	vector<int> arr = {5,6,8,9,12,15};

	int target = 15;

	cout << "index " << bin_search(arr, 0, arr.size() - 1, target) << endl;

	cout << "index " << bin_search(arr, target) << endl;

	return 0;
}