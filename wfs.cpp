#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>



using namespace std;

int main(int argc, char* argv[])
{

	map<string, vector<string>> graph = {
		{"a", {"c", "b"}},
		{"b", {"d"}},
		{"c", {"e"}},
		{"d", {"f"}},
		{"e", {}},
		{"f", {}},
	};

	stack <string> dfs;

	map <string, int> distance;

	dfs.push("a");

	while (!dfs.empty())
	{
		string c = dfs.top();
		cout << c << " ";
		dfs.pop();

		for (int i = 0; i < graph[c].size(); ++i)
		{
			dfs.push(graph[c][i]);
			distance[graph[c][i]] = distance[c] + 1;
		}
	}

	cout << endl;

	for(auto const& [key, value]: distance)
    {
	    cout << key << " " << value << endl;
    }

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