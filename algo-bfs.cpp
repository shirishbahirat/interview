#include <iostream>
#include <queue>
#include <stack>

using namespace std;

#define nodes 6

int main(int argc, char* argv[])
{

    int graph[nodes][nodes] = { {0, 1, 4, 0, 0, 0},
                                {1, 0, 4, 2, 7, 0},
                                {4, 4, 0, 3, 5, 0},
                                {0, 2, 3, 0, 4, 6},
                                {0, 7, 5, 4, 0, 7},
                                {0, 0, 0, 6, 7, 0} };

    bool visited[nodes] =  {false, false, false, false, false, false};

    queue <int> dfs;

    dfs.push(0);
    visited[0] = true;

    while(!dfs.empty())
    {

        int n = dfs.front();
        cout << n << endl;
        dfs.pop();

        for (int i = 0; i < nodes; ++i)
        {
            if (graph[n][i] > 0 && visited[i] == false)
            {
                dfs.push(i);
                visited[i] = true;
            }
        }

    }

    return 0;
}
