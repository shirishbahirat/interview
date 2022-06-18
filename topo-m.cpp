#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main(int argc, const char* argv[])
{
	
	vector <int> nodes = {0,1,2,3,4,5,6};

	vector <int> parent(7, -1);

	vector <int> degree = {0, 1, 2, 2, 3, 3};
	queue <int> topo;
	map <int, vector<int>> graph = {
		{0, {1, 2}},
		{1, {2, 3, 4,}},
		{2, {3, 4, 5}},
		{3, {4, 5}},
		{4, {5}},
		{5, {}}
	};

	topo.push(0);

	while (!topo.empty())
	{
		int a = topo.front();
		topo.pop();

		cout << a << endl;

		vector <int> temp = graph[a];

		for (int i = 0; i < temp.size(); ++i)
		{
			int x = temp[i];

			degree[x]--;

			if (degree[x] == 0) topo.push(x);
		}

	}

	return 0;
}