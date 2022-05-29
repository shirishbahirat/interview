#include <iostream>
#include <stack>

using namespace std;


int main(int argc, const char* argv[])
{

	int arr[6][6] = {{0,1,1,0,0,0},
				     {0,0,0,1,0,0},
				     {0,0,0,0,1,0},
				     {0,0,0,0,0,1},
				     {0,0,0,0,0,0},
				     {0,0,0,0,0,0}};

	string nme[] = {"a","b","c","d","e","f"};


	stack <string> sta;

	sta.push("a");

	int idx = 0;

	while(!sta.empty() && idx < 6)
	{

		string c = sta.top();
		cout << c << endl;
		sta.pop();

		for (int i = 0; i < 6; ++i)
		{
			if (arr[idx][i] == 1)
			{
				sta.push(nme[i]);
			}
		}
		idx++;
	}

	return 0;
}