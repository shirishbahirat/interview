#include <iostream>
#include <map>


using namespace std;

struct node {
	int data;
	int key;
	int idx;
};

node arr[10];
int size = 10;
int idx = 0;

map <int, int> lfu;


void insert(int key, int data)
{
	if (lfu.find(key) == lfu.end())
	{
		lfu[key] = idx;
		arr[idx].data = data;
		arr[idx].key = key;
		arr[idx].idx = idx;
		idx++;
	}


}

int main(int argc, const char* argv[])
{





	return 0;
}