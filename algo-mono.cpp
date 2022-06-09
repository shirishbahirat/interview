#include <iostream>
#include <stack>

using namespace std;

int main(int argc, const char* argv[])
{

	int arr[] = {4,3,2,6,9,1,10,7,5};

	int size = sizeof(arr)/sizeof(arr[0]);

	int ans[size];

	stack <int> mono;

	for (int i = 0; i < size; ++i)
	{

		while(!mono.empty() && mono.top() < arr[i])
		{
			mono.pop();
		}

		ans[i] = mono.empty() ? -1 : mono.top();

		mono.push(arr[i]);

	}

	for (int i = 0; i < size; ++i)
	{
		cout << ans[i] << " ";
	}

	cout << endl;

	return 0;

}