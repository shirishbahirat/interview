#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector <vector<string>> links = {
    {"i", "j"},
    {"i", "k"},
    {"k", "l"},
    {"j", "l"},
    {"k", "m"}
};

map <string, vector<string>> graph;

void links2graph(void)
{
    if (links.size() == 0) return;

    for (int i = 0; i < links.size(); ++i)
    {
        
        if ( auto it{ graph.find(links[i][0])}; it == end( graph ) ) 
        {
            graph[links[i][0]] = {};
        }

       if ( auto it{ graph.find(links[i][1])}; it == end( graph ) ) 
        {
            graph[links[i][1]] = {};
        }

        graph[links[i][0]].push_back(links[i][1]);
        graph[links[i][1]].push_back(links[i][0]);
        
    }

}

void print(void)
{
    for(auto it = graph.cbegin(); it != graph.cend(); ++it)
    {
        cout << it->first << endl;

        vector <string> nodes = graph[it->first];

        for (int i = 0; i < nodes.size(); ++i)
        {
            cout << nodes[i] << " ";
        }

        cout << endl;

    }
}


int main(int argc, char* argv[])
{

    links2graph();
    print();



    return 0;
}