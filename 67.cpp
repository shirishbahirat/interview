#include <iostream>
#include <map>


using namespace std;

struct node {
	int data;
	int key;
	int idx;
};

node arr[10];
int siz = 10;
int idx = 0;

map <int, int> lfu;


void update(void)
{
	if (idx < siz)
	{
		idx++;
	}
	else
	{

	}

}

void insert(int key, int data)
{
	int idy = idx;

	if (lfu.find(key) == lfu.end())
	{
		lfu[key] = idx;
	}
	else
	{
		idy = lfu[key];
	}

	arr[idy].data = data;
	arr[idy].key = key;
	arr[idy].idx = idy;

	update();


}

int main(int argc, const char* argv[])
{





	return 0;
}