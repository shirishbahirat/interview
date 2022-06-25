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

	int** parr = new int*; 

	int arr[] = {2,7,4,9,6};

	int mat[2][3] = {{1,2,3},{4,5,6}};

	int max[2][3] = {1,2,3,4,5,6};


	int *m = mat[1];

	cout << m[0] << " " << m[1];
	cout << " " << m[2] << endl;

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << *(*(mat + j) + i) << " ";
		}
	}

	cout << endl;

	int *p = arr;

	int **x = &p;

	prnt(parr, 5);

	for (int i = 0; i < 5; ++i)
	{
		cout << (*(*x + i)) << endl;
	}

	return 0;
}