#include <iostream>
#include <map>

using namespace std;

int main(int argc, const char* argv[])
{

	int arr[] = {10, 15, 3, 7};

	int size = sizeof(arr)/sizeof(arr[0]);

	int k = 17;

	map <int, int> distance;

	for (int i = 0; i < size; ++i)
	{
		distance[arr[i]] = i;
	}

	for (int i = 0; i < size; ++i)
	{
		int temp = 17 - arr[i];

		map <int, int>::iterator it = distance.find(temp);  

		if (it != distance.end())
		{
			cout << temp << " " << arr[i] << endl;
		}

	}

	return 0;



}