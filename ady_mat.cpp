#include <iostream>
#include <queue>

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

	int visited[] = {0,0,0,0,0,0};


	queue <string> sta;

	sta.push("a");

	int idx = 0;

	visited[0] = 1;

	while(!sta.empty() && idx < 6)
	{

		string c = sta.front();
		cout << c << endl;
		sta.pop();

		for (int i = 0; i < 6; ++i)
		{
			if ((arr[idx][i] == 1) && visited[i] == 0)
			{
				sta.push(nme[i]);
			}
		}
		idx++;
	}

	return 0;
}