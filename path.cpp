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

        if ( auto it{ graph.find(links[i][0])}; it == std::end( graph ) ) 
        {
            graph[links[i][0]] = {};
        }

        graph[links[i][j]].push()
    }

}


int main(int argc, char* argv[])
{





    return 0;
}