#include <iostream>
#include <vector>
#include <map>
#include <stack>


using namespace std;

int main(int argc, char* argv[])
{

	map<string, vector<string>> graph;

	graph["a"] = {"b", "c"};
	graph["b"] = {"d"};
	graph["c"] = {"e"};
	graph["d"] = {"f"};
	graph["e"] = { };
	graph["f"] = { };







	return 0;
}