#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;


int main(int argc, const char* argv[])
{

	vector < pair <int, int> > edge[10];

    edge[1].push_back(make_pair(0,4));
    edge[0].push_back(make_pair(1,4));

    edge[7].push_back(make_pair(0,8));
    edge[0].push_back(make_pair(7,8));

    edge[2].push_back(make_pair(1,8));
    edge[1].push_back(make_pair(2,8));

    edge[7].push_back(make_pair(1,11));
    edge[1].push_back(make_pair(7,11));

    edge[3].push_back(make_pair(2,7));
    edge[2].push_back(make_pair(3,7));

    edge[8].push_back(make_pair(2,2));
    edge[2].push_back(make_pair(8,2));

    edge[5].push_back(make_pair(2,4));
    edge[2].push_back(make_pair(5,4));

    edge[4].push_back(make_pair(3,9));
    edge[3].push_back(make_pair(4,9));

    edge[5].push_back(make_pair(3,14));
    edge[3].push_back(make_pair(5,14));

    edge[5].push_back(make_pair(4,10));
    edge[4].push_back(make_pair(5,10));

    edge[6].push_back(make_pair(5,2));
    edge[5].push_back(make_pair(6,2));

    edge[7].push_back(make_pair(6,1));
    edge[6].push_back(make_pair(7,1));

    edge[8].push_back(make_pair(6,6));
    edge[6].push_back(make_pair(8,6));

    edge[8].push_back(make_pair(7,7));
    edge[7].push_back(make_pair(8,7));

    typedef pair <int, int> p;

    int src = 0;

    priority_queue < p, vector <p>, greater <p> > pq;

    vector <int> key (10, INT_MAX);

    vector<int> parent(10, -1);
 
    vector<bool> in_mst(10, false);
 
    pq.push(make_pair(0, src));

    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(in_mst[u] == true) continue;

        in_mst[u] = true;

        for (auto x : edge[u])
        {

            int v = x.first;
            int weight = x.second;
 
            if (in_mst[v] == false && key[v] > weight)
            {

                key[v] = weight;

                pq.push(make_pair(key[v], v));

                parent[v] = u;
            }
        }

    }

    for (int i = 1; i < 10; ++i)
        printf("%d - %d\n", parent[i], i);

	return 0;
}

