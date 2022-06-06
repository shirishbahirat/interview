#include <iostream>

using namespace std;

int arr[] = {-1,0,0,0,1,-1,5,5,6};

int get_abs_root(int arr[], int base)
{
	if (arr[base] == -1) 
	{
		cout << base << endl;
		return base;
	}
	else
	{
		return get_abs_root(arr, arr[base]);
	}	

	return -1;

}

int main(int argc, const char* argv[])
{

	get_abs_root(arr, 8);

	return 0;
}