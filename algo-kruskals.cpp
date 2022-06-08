#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(int argc, const char* argv[])
{

	vector < pair <int, pair <int, int>>> edge; 

	edge.push_back({0, {1, 4}});
	edge.push_back({0, {7, 8}});
	edge.push_back({0, {1, 4}});
    edge.push_back({0, {7, 8}});
    edge.push_back({1, {2, 8}});
    edge.push_back({1, {7, 11}});
    edge.push_back({2, {3, 7}});
    edge.push_back({2, {8, 2}});
    edge.push_back({2, {5, 4}});
    edge.push_back({3, {4, 9}});
    edge.push_back({3, {5, 14}});
    edge.push_back({4, {5, 10}});
    edge.push_back({5, {6, 2}});
    edge.push_back({6, {7, 1}});
    edge.push_back({6, {8, 6}});
    edge.push_back({7, {8, 7}});


	return 0;
}

