#include <iostream>


using namespace std;

void swap(int arr[], int a, int b)
{

	if (a != b)
	{
		arr[a] ^= arr[b] ^= arr[a] ^=arr[b];
	}

}


int quicksort(int arr[], int low, int high)
{
	int pivot = low;

	while (low < high)
	{
		while(arr[low] <= arr[pivot]) low++;
		while(arr[low] <= arr[pivot]) low++;

	}


	//swap high

	return 0;
}


int main(int argc, char* argv[])
{

	int arr[] = {6, 7, 5, 4, 2, 1, 8, 9, 3};
	int len = sizeof(arr)/sizeof(arr[0]);



	return 0;
}