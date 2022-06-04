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

	int size = sizeof(mat[0])/sizeof(mat[0][0]);

	for (int idx = 0; idx < size - 1; ++idx)
	{
		for (int i = idx; i < size; ++i)
		{
			int t = mat[idx][i];

			mat[idx][i] = mat[i][idx];

			mat[i][idx] = t;
		}
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
