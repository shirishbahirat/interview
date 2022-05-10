#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int main(int argc, char* argv[])
{

	vector<vector<string>> graph = {{"b","c"},{"m", "b"},{"j", "k", "c"}, {"l", "m"}, {"j","n, o, p"}};

	stack <string> stc;

	if (graph.empty()) return 0;

	stc.push(graph[0][0]);

	while (!stc.empty())
	{
		string c = stack.pop();

	}





	return 0;
}