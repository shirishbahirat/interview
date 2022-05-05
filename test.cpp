#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

	int arr[] = {2,5,7,9,11,14,17};

	int len = sizeof(arr)/sizeof(arr[0]);

	int left = 0;
	int right = len - 1;
	int val = 0;

	while (left <= right)
	{
		int mid = left + (right - left) /2;

		if (arr[mid] == val)
		{
			cout << val << endl;
			return 0;
		}
		else if (val > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}

	}

	return 0;
}