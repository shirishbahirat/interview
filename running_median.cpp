#include <iostream>

using namespace std;



int main(int argc, const char* argv[])
{

	int arr[] = {2, 1, 5, 7, 2, 0, 5};
	int size = sizeof(arr)/sizeof(arr[0]);

	int sum = 0;

	for (int i = 0; i < size; ++i)
	{
		sum += arr[i];
		cout << sum << endl;
	}


	return 0;
}