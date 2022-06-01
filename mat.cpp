#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>



using namespace std;

int main(int argc, char* argv[])
{

	int mat[4][4] = {
		{2,4,6,4},
		{1,4,3,7},
		{3,5,7,8},
		{5,3,4,7}
	};


	for (int i = 0; i < 4; ++i)
	{
		int t = mat[0][i];
		mat[0][i] = mat[i][0];
		mat[i][0] = t;
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << mat[i][j] << " ";
		}

		cout << endl;
	}


}