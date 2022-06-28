#include <iostream>

using namespace std;

int main(int argc, const char* argv[])
{
	int arr[] = {1, 2, 3, 4, 5};

	int size = sizeof(arr)/sizeof(arr[0]);
	
	int mult = 1;

	for (int i = 0; i < size; ++i)
	{
		mult *= arr[i];
	}

	for (int i = 0; i < size; ++i)
	{
		arr[i] = mult/arr[i];
	}

	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " " << endl;
	}

	return 0;
}