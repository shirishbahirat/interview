#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector <int> rnk{9,0};
vector <int> parent{9,0};

int find(int u)
{
	if (u != parent[u])
		parent[u] = find(parent[u]);

	return parent[u];
}

void merge(int x, int y)
{
	x = find(x);

	y = find(y);

	if (rnk[x] > rnk[y])
		parent[y] = x;
	else
		parent[x] = y;

	if (rnk[x] == rnk[y])
		rnk[y]++;

}

int main(int argc, const char* argv[])
{

	vector < pair <int, pair <int, int>>> edge;
	vector < pair <int, pair <int, int>>>::iterator it;

	edge.push_back({4, {0, 1}});
	edge.push_back({8, {0, 7}});
    edge.push_back({8, {1, 2}});
    edge.push_back({11, {1, 7}});
    edge.push_back({7, {2, 3}});
    edge.push_back({2, {2, 8}});
    edge.push_back({4, {2, 5}});
    edge.push_back({9, {3, 4}});
    edge.push_back({14, {3, 5}});
    edge.push_back({10, {4, 5}});
    edge.push_back({2, {5, 6}});
    edge.push_back({1, {6, 7}});
    edge.push_back({6, {6, 8}});
    edge.push_back({7, {7, 8}});


    sort(edge.begin(), edge.end());

    for (int i = 0; i < 9; ++i)
    {
    	rnk.push_back(0);
    	parent.push_back(i);
    }

    for (int i = 0; i < edge.size(); ++i)
    {
    	cout << edge[i].first << " " << edge[i].second.first << " " << edge[i].second.second << endl; 
    }


    int mst_weight = 0;


    for (it = edge.begin(); it < edge.end(); ++it)
    {
    	int u = it->second.first;
    	int v = it->second.second;

    	int parent_u = find(u);
    	int parent_v = find(v);

    	if (parent_u != parent_v)
    	{
    		
    		cout << u << " - " << v << endl;
 
    		mst_weight = it->first;

    		merge(parent_v, parent_u);
    	}

    }

	return 0;
}

