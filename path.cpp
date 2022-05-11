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
        for (int j = 0; j < links[i].size(); ++j)
        {
            if ( auto it{ graph.find(links[i][j])}; it == std::end( graph ) ) 
            {
                graph[links[i][j]] = {};
            }
        }
    }

}


int main(int argc, char* argv[])
{





    return 0;
}