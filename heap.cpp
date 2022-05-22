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

void trickle_down(int arr[], int idx, int len)
{
	int left = 2*idx + 1;
	int right = 2*idx + 2;

	int max = idx;

	if (left < len && arr[left] > arr[max]) max = left;
	if (right < len && arr[right] > arr[max]) max = right;

	if (max != idx)
	{
		swap(arr, max, idx);
		trickle_down(arr, max, len);
	}


	return;
}


void heap_sort(int arr[], int len)
{

	int parent = (len - 1)/2;

	for (int i = parent; i >= 0; --i)
	{
		trickle_down(arr, i, len);
	}



	for (auto i : arr1)
	{
		cout << i << " ";
	}
	cout << endl;

}


int main(int argc, char* argv[])
{

	int arr[] = {8, 7, 4, 5, 3, 2 , 1, 15};

	trickle_up(arr, 7);

	for (auto i : arr)
	{
		cout << i << " ";
	}
	cout << endl;

	int arr1[] = {1, 8, 7, 4, 5, 3, 2 , 0};

	trickle_down(arr1, 0, 7);

	for (auto i : arr1)
	{
		cout << i << " ";
	}
	cout << endl;

	heap_sort(arr, 7);

	return 0;
}