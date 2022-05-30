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

	map<string, int> degree;

	queue <string> qu;

	for (auto const& [key, value]: graph)
	{
		
		if (degree.find(key) == degree.end())
		{
			degree[key] = 0;
		}

		for (auto c: value)
		{		
			degree[c]++;
		}
	}

	for (auto const& [key, value]: degree)
	{		
		cout << key << " " <<  value << " ";

		if (value == 0)
		{
			qu.push(key);
		}
	}

	cout << endl;

	while (!qu.empty())
	{
		string ans = qu.front();
		cout << ans << ", ";
		qu.pop();
	}

}