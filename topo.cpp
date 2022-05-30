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
		{"b", {"f", "c"}},
		{"c", {"e"}},
		{"d", {"f","b"}},
		{"e", {}},
		{"f", {"g","e"}},
		{"g", {}}
	};

	map<string, int> degree;

	queue <string> que;

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
			que.push(key);
		}
	}

	cout << endl;

	while (!que.empty())
	{
		string ans = que.front();
		cout << ans << ", ";
		que.pop();

		vector <string> eliminate = graph[ans];

		for (int i = 0; i < eliminate.size(); ++i)
		{
			string dec = eliminate[i];

			degree[dec]--;

			if (degree[dec] == 0)
			{
				que.push(dec);
			}
		}
	}

}