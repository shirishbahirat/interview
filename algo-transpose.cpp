#include <iostream>

using namespace std;


int main(int argc, const char* argv[])
{


	int max[2][3] = {10,20,30,40,50,60};

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << *(*(max + j) + i) << " ";
		}
	}

	cout << endl;

	return 0;
}