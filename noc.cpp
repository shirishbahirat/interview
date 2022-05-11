#include <iostream>
#include <vector>

using namespace std;

struct control_interface
{
	virtual void connect_n(control_interface* nc) = 0;

	virtual void connect_s(control_interface* sc) = 0;
	
	virtual void connect_e(control_interface* ec) = 0;
	
	virtual void connect_w(control_interface* wc) = 0;
	
	virtual void connect_p(control_interface* pc) = 0;
};

class router: public control_interface
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

	virtual void connect_n(control_interface* nc){north = nc;};

	virtual void connect_s(control_interface* sc){south = sc;};
	
	virtual void connect_e(control_interface* ec){east = ec;};
	
	virtual void connect_w(control_interface* wc){west = wd;};
	
	virtual void connect_p(control_interface* pc){local = pc;};


private:
	uint32_t idx;
	uint32_t idy;

	control_interface* north;

	control_interface* south;

	control_interface* east;

	control_interface* west;

	control_interface* local;

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