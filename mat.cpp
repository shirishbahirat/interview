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


	for (int i = 1; i < 4; ++i)
	{
		for (int j = i+1; j <= 4; ++j)
		{
			int t = mat[j][i];
			mat[i][j] = mat[j][i];
			mat[j][i] = t;
		}
	}

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << mat[j][i] << " ";
		}

		cout << endl;
	}


}