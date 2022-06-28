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
		int temp = 17 - arr[i];

		map[temp] = i;
	}

	for (int i = 0; i < size; ++i)
	{
		int temp = 17 - arr[i];

		auto it = distance.find(temp);  

	}

	return 0;

}