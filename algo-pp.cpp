#include <iostream>

using namespace std;


void prnt(int** arr, int size)
{

	cout << *arr << endl;

	return;
}



int main(int argc, const char* argv[])
{

	int arr[] = {3,5,6,2,1,7};
	int size = sizeof(arr)/sizeof(arr[0]);
	int* parr = &arr[0]; 

	prnt(&parr, size);





	return 0;
}