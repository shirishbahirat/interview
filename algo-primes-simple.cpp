#include <iostream>

using namespace std;

#define nodes 6

int select_min_vertex(vector<int>& value,vector<bool>& set_mst)
{
    int minimum = INT_MAX;

    int vertex;

    for(int i = 0; i < nodes; ++i)
    {
        if(set_mst[i] == false && value[i] < minimum)
        {
            vertex = i;

            minimum = value[i];
        }
    }

    return vertex;
}

void get_mst(int graph[nodes][nodes])
{

    int parent[nodes];      //Stores MST

    vector<int> value(nodes, INT_MAX);   //Used for edge relaxation

    vector<bool> set_mst(nodes,false);   //TRUE->nodesertex is included in MST

    //Assuming start point as Node-0
    parent[0] = -1; //Start node has no parent
    value[0] = 0;   //start node has value=0 to get picked 1st

    //Form MST with (nodes-1) edges
    for(int i=0; i < nodes - 1; ++i)
    {
        //Select best nodesertex by applying greedy method
        int U = select_min_vertex(value, set_mst);
        set_mst[U] = true;   //Include new nodesertex in MST

        //Relax adjacent vertices (not yet included in MST)
        for(int j=0;j<nodes;++j)
        {
            /* 3 constraints to relax:-
                  1.Edge is present from U to j.
                  2.nodesertex j is not included in MST
                  3.Edge weight is smaller than current edge weight
            */
            if(graph[U][j] != 0 && set_mst[j] == false && graph[U][j] < value[j])
            {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }
    //Print MST
    for(int i=1; i<nodes; ++i)
        cout<< "U->V: " << parent[i] << "->" << i << "  wt = " <<graph[parent[i]][i] << endl;
}




int main(int argc, const char* argv[])
{

    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
                        {4, 0, 6, 3, 4, 0},
                        {6, 6, 0, 1, 8, 0},
                        {0, 3, 1, 0, 2, 3},
                        {0, 4, 8, 2, 0, 7},
                        {0, 0, 0, 3, 7, 0} };

    get_mst(graph); 

    return 0;
}