#include <iostream>

using namespace std;


void prnt(int** arr, int size)
{

	int* temp = *arr;

	for (int i = 0; i < size; ++i)
	{
		*arr = new int();
		**arr = 10+i;

		cout << **arr << endl;
	}

	arr = &temp;

	return;
}



int main(int argc, const char* argv[])
{

	int** parr = new int*()[5]; 

	int arr[] = {2,3,4,5,6};
	int *p = arr;

	prnt(parr, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << *parr[i] << endl;
	}



	return 0;
}