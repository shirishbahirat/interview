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


	for (int i = 0; i < 3; ++i)
	{
		for (int j = i+1; j <= 3; ++j)
		{
			int t = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = t;
		}
	}

}