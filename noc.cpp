#include <iostream>

using namespace std;


class router
{
public:
	router(uint32_t x, uint32_t y):idx(x), idy(y){}

	~router(){}


private:
	uint32_t idx;
	uint32_t idy;
};



int main(int argc, const char* argv[])
{

	uint32_t x_nodes = 8;
	uint32_t y_nodes = 8;

	for (int i = 0; i < x_nodes; ++i)
	{
		for (int j = 0; j < y_nodes; ++j)
		{
			router* r = new router(i, j);
		}
	}



	return 0;
}