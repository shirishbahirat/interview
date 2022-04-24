#include <iostream>

using namespace std;





int main(const int argc, const char* argv[])
{

	int arr[] = {2,5,7,8,9,10,11};

	int len = sizeof(arr)/sizeof(arr[0]);

	int left = 0;

	int right = len - 1;

	int val = 10;

	while (left < right)
	{

		int mid = left + (right - left)/2;

		if (val == arr[mid])
		{
			cout << mid << endl;
			return;
		}

		if (val > arr[mid])
		{
			left = mid + 1;
		} 
		else if ( val < arr[mid])
		{
			right = mid;
		}

	}




	return 0;
}