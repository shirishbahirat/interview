#include <iostream>

using namespace std;

void swap(int arr[], int a, int b)
{

	if (a == b) return;

	int temp = arr[a];

	arr[a] = arr[b];

	arr[b] = temp;

	return;

}

void trickle_up(int arr[], int idx)
{

	if (idx <= 0) return;

	int parent = (idx - 1)/2;

	if (arr[idx] > arr[parent]) swap(arr, idx, parent);

	trickle_up(arr, parent);

	return;
}

int main(int argc, char* argv[])
{

	int arr[] = {8, 7, 4, 5, 3, 2 , 1, 15};



	return 0;
}