#include <iostream>

using namespace std;

void xloop(int **arr, int len)
{

	int *pa = *arr;

	for (int i = 0; i < len; ++i)
	{
		cout << pa[i] << endl;
	}

}


void loop(int *arr, int len)
{

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << endl;
	}

}

void aloop(int arr[], int len)
{

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << endl;
	}

}


int main(int argc, const char* argv[])
{

	int arr[] = {1,2,3,4,5,6,7,8};

	int *parr = &arr[0];

	int **pparr = &parr;

	int len = sizeof(arr)/sizeof(arr[0]);

	loop(arr, len);

	aloop(arr, len);

	xloop(pparr, len);

	return 0;
}