#include <iostream>
#include <vector>
#include <map>
#include <stack>


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
		cout << c << endl;
		dfs.pop();

		for (int i = 0; i < dfs[c].size(); ++i)
		{
			dfs.push(dfs[c][i]);
		}
		

	}








	return 0;
}