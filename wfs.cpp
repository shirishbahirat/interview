#include <iostream>
#include <vector>
#include <map>
#include <stack>


using namespace std;

int main(int argc, char* argv[])
{

	map<string, vector<string>> graph;

	graph = {
		{"a", {"b", "c"}};
		{"b", {"d"}};
		{"c", {"e"}};
		{"d", {"f"}};
		{"e", {}};
		{"f", {}};
	};

	stack <string> dfs;

	dfs.push







	return 0;
}