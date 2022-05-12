#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct flit {
	uint32_t surc_x;
	uint32_t surc_y;

	uint32_t dest_x;
	uint32_t dest_y;

	uint32_t data;

	uint32_t time;
};

struct control_interface
{
	virtual void connect_n(control_interface* nc) = 0;

	virtual void connect_s(control_interface* sc) = 0;
	
	virtual void connect_e(control_interface* ec) = 0;
	
	virtual void connect_w(control_interface* wc) = 0;
	
	virtual void connect_p(control_interface* pc) = 0;

	virtual void is_ready(void) = 0;
};

class router: public control_interface
{
public:
	router(uint32_t x, uint32_t y):
		idx(x), idy(y), ready(true){}

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
	
	virtual void connect_w(control_interface* wc){west = wc;};
	
	virtual void connect_p(control_interface* pc){local = pc;};

	virtual void check_links(void)
	{

		north->is_ready();

		south->is_ready();

		east->is_ready();

		west->is_ready();

	}


	virtual void is_ready(void)
	{
		cout << "check" << endl;
		cout << "x:" << idx;
		cout << " y:" << idy;
		cout << endl;
	}

private:
	uint32_t idx;
	uint32_t idy;

	control_interface* north;

	control_interface* south;

	control_interface* east;

	control_interface* west;

	control_interface* local;

	queue <flit*> incoming_north;

	queue <flit*> incoming_south;

	queue <flit*> incoming_east;

	queue <flit*> incoming_west;

	queue <flit*> virtual_north;

	queue <flit*> virtual_south;

	queue <flit*> virtual_east;

	queue <flit*> virtual_west;

	bool ready;

};



int main(int argc, const char* argv[])
{

	uint32_t x_nodes = 8;
	uint32_t y_nodes = 8;

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


	for (int i = 1; i < x_nodes - 1; ++i)
	{
		for (int j = 1; j < y_nodes - 1; ++j)
		{
			noc[i][j]->connect_n(noc[i - 1][j]);
			noc[i][j]->connect_s(noc[i + 1][j]);
			noc[i][j]->connect_e(noc[i][j - 1]);
			noc[i][j]->connect_w(noc[i][j + 1]);
		}

	}


	for (int i = 0; i < x_nodes; ++i)
	{

	}

	for (int i = 0; i < x_nodes; ++i)
	{
		for (int j = 0; j < y_nodes; ++j)
		{
			noc[i][j]->get_id();
		}
	}

	noc[1][1]->check_links();

	return 0;
}