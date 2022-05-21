#include <iostream>

using namespace std;

int merge(int xarr[], int yarr[], int lenx, int leny)
{

	int zarr[lenx + leny];

	int idx = 0, idy = 0, idz = 0;

	while ((idx < lenx) && (idy < leny))
	{
		if (xarr[idx] <= yarr[idy])
		{
			zarr[idz++] = xarr[idx++];
		}
		else
		{
			zarr[idz++] = yarr[idy++];
		}
	}

		while (idx < lenx)
	{
		zarr[idz++] = xarr[idx++];
	}

	while (idy < leny)
	{
		zarr[idz++] = yarr[idy++];
	}
	

	for (int i = 0; i < idz; ++i)
	{
		cout << zarr[i] << " ";
	}

	cout << endl;

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

	}

	return 0;
}

int main(int argc, char* argv[])
{

	int arr[] = {4, 3, 8, 5, 11, 2};
	int len = sizeof(arr)/sizeof(arr[0]);

	mergesort(arr, 0, len - 1);

	int xarr[] = {3, 4, 8, 11};
	int lenx = sizeof(xarr)/sizeof(xarr[0]);

	int yarr[] = {1, 2, 5, 7};
	int leny = sizeof(xarr)/sizeof(xarr[0]);

	merge(xarr, yarr, lenx, leny);


	return 0;
}