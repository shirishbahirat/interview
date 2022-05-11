#include <iostream>
#include <vector>

using namespace std;


class router
{
public:
	router(uint32_t x, uint32_t y):idx(x), idy(y){}

	~router(){}

	virtual void get_id(void)
	{
		cout << "x:" << idx;
		cout << " y:" << idy;
		cout << endl;

	}

private:
	uint32_t idx;
	uint32_t idy;
};



int main(int argc, const char* argv[])
{

	uint32_t x_nodes = 4;
	uint32_t y_nodes = 4;

	vector<vector<router*>> noc;

	for (int i = 0; i < x_nodes; ++i)
	{
		
		noc.push_back({});

		for (int j = 0; j < y_nodes; ++j)
		{
			router* r = new router(i, j);
			noc[i].push_back(r);
		}
	}


	for (int i = 0; i < x_nodes; ++i)
	{
		for (int j = 0; j < y_nodes; ++j)
		{
			noc[i][j]->get_id();
		}
	}



	return 0;
}