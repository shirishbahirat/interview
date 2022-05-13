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

struct gateway_interface
{
    virtual void launch_n(gateway_interface* ng) = 0;

    virtual void launch_s(gateway_interface* sg) = 0;

    virtual void launch_e(gateway_interface* eg) = 0;

    virtual void launch_w(gateway_interface* wg) = 0;
};


class router: public control_interface, 
              public gateway_interface
{
public:
    router(uint32_t x, uint32_t y):
        idx(x), idy(y), ready(true), 
        north(nullptr), south(nullptr),
        east(nullptr), west(nullptr),
        local(nullptr) {}

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

    virtual void launch_n(gateway_interface* ng){gt_north = ng;};

    virtual void launch_s(gateway_interface* sg){gt_south = sg;};

    virtual void launch_e(gateway_interface* eg){gt_east = eg;};

    virtual void launch_w(gateway_interface* wg){gt_west = wg;};

    virtual void check_links(void)
    {

        if (north) north->is_ready();

        if (south) south->is_ready();

        if (east) east->is_ready();

        if (west) west->is_ready();

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

    gateway_interface* gt_north;

    gateway_interface* gt_south;

    gateway_interface* gt_east;

    gateway_interface* gt_west;

    queue <flit*> incoming_north;

    queue <flit*> incoming_south;

    queue <flit*> incoming_east;

    queue <flit*> incoming_west;

    queue <flit*> virtual_north;

    queue <flit*> virtual_south;

    queue <flit*> virtual_east;

    queue <flit*> virtual_west;

    queue <flit*> gateway_north;

    queue <flit*> gateway_south;

    queue <flit*> gateway_east;

    queue <flit*> gateway_west;

    queue <flit*> virt_gt_north;

    queue <flit*> virt_gt_south;

    queue <flit*> virt_gt_east;

    queue <flit*> virt_gt_west;

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

    for (int j = 0; j < y_nodes; ++j)
    {
        noc[0][j]->connect_s(noc[1][j]);
    }

    for (int j = 0; j < y_nodes; ++j)
    {
        noc[x_nodes - 1][j]->connect_n(noc[x_nodes - 2][j]);
    }

    for (int i = 0; i < x_nodes; ++i)
    {
        noc[i][0]->connect_w(noc[i][1]);
    }

    for (int i = 0; i < x_nodes; ++i)
    {
        noc[i][y_nodes - 1]->connect_e(noc[i][y_nodes - 2]);
    }

    for (int i = 0; i < x_nodes; ++i)
    {
        for (int j = 0; j < y_nodes; ++j)
        {
            noc[i][j]->get_id();
        }
    }


    vector<uint32_t> gtx = {2, 5};
    vector<uint32_t> gty = {2, 5};

    for (int i = 0; i < gtx.size(); ++i)
    {
        for (int j = 0; j < gty.size(); ++j)
        { 
            cout << gtx[i] << " " << gty[j] << endl;
            noc[gtx[i]][gty[j]]->launch_n(noc[gtx[i] - 1][gty[j]]);
            noc[gtx[i]][gty[j]]->launch_s(noc[gtx[i] + 1][gty[j]]);
            noc[gtx[i]][gty[j]]->launch_e(noc[gtx[i]][gty[j] - 1]);
            noc[gtx[i]][gty[j]]->launch_w(noc[gtx[i]][gty[j] + 1]);
        }
    }   


    noc[1][1]->check_links();

    return 0;
}