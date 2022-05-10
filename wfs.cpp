#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>



using namespace std;

int main(int argc, char* argv[])
{

	map<string, vector<string>> graph = {
		{"a", {"b", "c"}},
		{"b", {"d"}},
		{"c", {"e"}},
		{"d", {"f"}},
		{"e", {}},
		{"f", {}},
	};

	stack <string> dfs;

	dfs.push("a");

	while (!dfs.empty())
	{
		string c = dfs.top();
		cout << c << " ";
		dfs.pop();

		for (int i = 0; i < graph[c].size(); ++i)
		{
			dfs.push(graph[c][i]);
		}
	}

	cout << endl;

	queue <string> bfs;

	bfs.push("a");

	while (!bfs.empty())
	{
		string c = bfs.front();
		cout << c << " ";
		bfs.pop();

		for (int i = 0; i < graph[c].size(); ++i)
		{
			bfs.push(graph[c][i]);
		}

	}

	cout << endl;



	return 0;
}