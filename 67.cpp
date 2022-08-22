#include <iostream>
#include <map>


using namespace std;

struct node {
	int data;
	int key;
	int idx;
};

node arr[10];
int val[10];
int siz = 10;
int idx = 0;

map <int, int> lfu;

void update(int idw)
{
	int min_val = 0xFFFFFFF;

	if (idx < siz)
	{
		idx++;
	}
	else
	{
		for (int i = 0; i < siz; ++i)
		{
			if (val[i] < min_val)
			{
				idx = i;
				min_val = val[i];
			}
			if (i != idw)
			{
				val[i]--;
			}
		}
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

	val[idy]++;

	update(idy);

}

int main(int argc, const char* argv[])
{

	for (int i = 0; i < siz; ++i)
	{
		val[i] = 0;
	}

	return 0;
}