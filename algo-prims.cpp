#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <functional>

using namespace std;


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

    pair <int, int> p;

    priority_queue < p, vector <p>, greater <p> > pq;

	return 0;
}

