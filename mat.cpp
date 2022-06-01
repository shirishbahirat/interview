#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>



using namespace std;

int main(int argc, char* argv[])
{

	int mat[16] = {
		2,4,6,4,
		1,4,3,7,
		3,5,7,8,
		5,3,4,7
	};


	for (int i = 0; i < 16; ++i)
	{
		cout << mat[i] << " ";

		if (i > 0 && (i%3) == 0)
			cout << endl;
	}

}