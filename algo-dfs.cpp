#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main(int argc, char* argv[])
{


    int nodes = 5;

    int graph[nodes][nodes] = { {0, 1, 4, 0, 0, 0},
                                {1, 0, 4, 2, 7, 0},
                                {4, 4, 0, 3, 5, 0},
                                {0, 2, 3, 0, 4, 6},
                                {0, 7, 5, 4, 0, 7},
                                {0, 0, 0, 6, 7, 0} };

    stack <int> dfs;

    dfs.push(graph[0][1]);


    return 0;
}
