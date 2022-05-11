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

    cout << links.size() << endl;

    for (int i = 0; i < links.size(); ++i)
    {
        
        if ( auto it{ graph.find(links[i][0])}; it == end( graph ) ) 
        {
            graph[links[i][0]] = {};
            cout << "insert" << endl;
        }

       if ( auto it{ graph.find(links[i][1])}; it == end( graph ) ) 
        {
            graph[links[i][1]] = {};
            cout << "insert" << endl;
        }

        graph[links[i][0]].push_back(links[i][1]);
        graph[links[i][1]].push_back(links[i][0]);
        
    }

}


int main(int argc, char* argv[])
{

    links2graph();



    return 0;
}