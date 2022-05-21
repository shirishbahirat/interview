#include <iostream>

using namespace std;

int merge(int xarr[], int low, int mid, int high)
{

	int zarr[high - low + 1];

	int idx = low, idy = mid + 1, idz = 0;

	while ((idx <= mid) && (idy <= high))
	{
		if (xarr[idx] <= xarr[idy])
		{
			zarr[idz++] = xarr[idx++];
		}
		else
		{
			zarr[idz++] = xarr[idy++];
		}
	}

	while (idx <= mid)
	{
		zarr[idz++] = xarr[idx++];
	}

	while (idy <= high)
	{
		zarr[idz++] = xarr[idy++];
	}

	for (int i = 0; i < idz; ++i)
	{
		cout << zarr[i] << " ";
	}

	cout << endl;

	for (int i = low, j = 0; i <= high; ++i, ++j)
	{
		xarr[i] = zarr[j];
	}

	return 0;

}

int mergesort(int arr[], int low, int high)
{

	cout << low << " " << high << endl;

	if (low < high)
	{
		int mid = low + (high - low)/2;

		mergesort(arr, low, mid);
		mergesort(arr, mid + 1, high);
		merge(arr, low, mid, high);

	}

	return 0;
}

int main(int argc, char* argv[])
{

	int arr[] = {4, 3, 8, 5, 11, 2};
	int len = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}