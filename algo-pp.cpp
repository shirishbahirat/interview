#include <iostream>

using namespace std;


void prnt(int** arr, int size)
{

	for (int i = 0; i < size; ++i)
	{
		*arr = new int();
		**arr = 10;
	}

	return;
}



int main(int argc, const char* argv[])
{

	int** parr = new int*[5]; 

	prnt(parr, 5);





	return 0;
}